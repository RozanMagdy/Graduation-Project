#include "Det.h"
#include "Dem.h"
#include "SchM_Mcu.h"
#include "Mcu_Cbk.h"
#include "MemMap.h"
#include "Mcu.h"
#include "MCU_Regs.h"

static void Initialize(void);
static void Flash_Init(void);

//McuClockReferencePoint
uint32 SYS_CLK_VALUE = 0;

uint32 CAN_CPU_CLOCK_REFERENCE = 0;

#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* AUTOSAR Version checking between Det and MCU Modules */
#if ((DET_AR_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != MCU_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif
static Mcu_ConfigClock * Mcu_ClockSettings = NULL_PTR;
static Mcu_ConfigPeripherals * Mcu_PeripheralsSettings = NULL_PTR;
static uint8 Mcu_Status = MCU_NOT_INITIALIZED;
/************************************************************************************
* Service Name: MCU_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the MCU module.
************************************************************************************/

void Mcu_Init(const Mcu_ConfigType* ConfigPtr)
{
	//Error check
	#if (MCU_DEV_ERROR_DETECT == STD_ON)
	{
		// check if the inpurt pionter is not Null
		if (ConfigPtr == NULL_PTR)
		{
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_INIT_SID,DIO_E_PARAM_CONFIG);
		}
		else 
		{
			
		}
	#endif
	Mcu_Status       = MCU_INITIALIZED;
	Mcu_ClockSettings = ConfigPtr->ClockConfigurations;
	Mcu_PeripheralsSettings = ConfigPtr->Peripherals;
	
	/////////////////////////////////////////////////////////////////////////////////////
	Initialize();

}

static void Initialize(void){
	/* Reset the RCC clock configuration to the default reset state(for debug purpose) */
  /* Set HSION bit */
  RCC_CR |= (uint32)0x00000001;

  /* Reset SW, HPRE, PPRE1, PPRE2, ADCPRE and MCO bits */
  RCC_CFGR &= (uint32)0xF8FF0000;

  /* Reset HSEON, CSSON and PLLON bits */
  RCC_CR &= (uint32)0xFEF6FFFF;

  /* Reset HSEBYP bit */
  RCC_CR &= (uint32)0xFFFBFFFF;

  /* Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE/OTGFSPRE bits */
  RCC_CFGR &= (uint32)0xFF80FFFF;

  /* Disable all interrupts and clear pending bits  */
  RCC_CIR = 0x009F0000;

  SCB_VTOR = FLASH_BASE | 0; /* Vector Table Relocation in Internal FLASH. */
}

/************************************************************************************
* Service Name: Mcu_InitRamSection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): RamSection - Selects RAM memory section provided in configuration set
* Parameters (inout): None
* Parameters (out): None
* Return value: Std_ReturnType (E_OK - E_NOT_OK)
* Description: This service initializes the RAM section wise.
************************************************************************************/
Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection){
	return 0;
}

//Configrable (ON/OFF) functions
/************************************************************************************
* Service Name: Mcu_InitClock
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ClockSetting - Clock Setting
* Parameters (out): None
* Return value: Std_ReturnType (E_OK - E_NOT_OK)
* Description: This service initializes the PLL and other MCU specific clock options.
************************************************************************************/
#if (MCU_INIT_CLOCK == STD_ON)
Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting){
	
	Flash_Init();
	
	///////////////////////////////////////////////////////////////////////////////////
	//first, the initial value for the status is NOK, in case there was an error
	Std_ReturnType command_status = E_NOT_OK;
	#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	boolean error = FALSE;
	if (MCU_NOT_INITIALIZED == Mcu_Status)
	{
		Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
				MCU_INIT_CLOCK_SID, MCU_E_UNINIT);
		error = TRUE;
	}
	#endif	
	if(Mcu_ClockSettings != NULL_PTR){
		// if we passed the error checking step and the " Mcu_ClockSettings " does not point to NUll, set to OK
		command_status = E_OK;
	}else{
		// return the status in both cases: OK or NOK
		return command_status;
		// we will execute this " else " if we called a function before the " Init_clock " function
	}

	//Bus Capacity Protection
	/*in case the OSC_freq = 8MHz and SYSCLK_FREQ= 72MHZ
	 * AND
	 * ( AHB_Min_Prescaler  x APB1_Min_Prescaler ) is less than 2; ie: = 1
	 * ; there must be a protection for APB1 bus (because it is limited to a 36MHz max freq)
	 * So, the " APB1_Prescalar " is FORCED to be " /2 " which is (0b100) = (4U) from " RCC_CFGR " register.
	 */
	if((Mcu_ClockSettings[ClockSetting].SYSCLK_Frequency == SYSCLK_FREQ_72MHZ) &&\
			((Mcu_ClockSettings[ClockSetting].AHB_Prescalar == AHB_PR_1) && (Mcu_ClockSettings[ClockSetting].APB1_Prescalar == APB1_PR_1)))
	{
		//IF The previous condition is true And we entered here; then the User has entered 
		// a wrong Configration (prescaler). in another way, the user has enrered a Clk freq that the 
		// bus can't withstand.
		//hence, we have to either change the structure manually or to report an Error.
		// and because WE MUST NOT CHANGE THE structure --> (const); so, we only need to report an error.
		//Mcu_ClockSettings[ClockSetting].APB1_Prescalar = APB1_PR_2;
		Det_ReportError(MCU_MODULE_ID,MCU_INSTANCE_ID,MCU_INIT_CLOCK_SID,MCU_E_PARAM_CLOCK);
	}
	
	uint8 Pll_Multiplication;
	uint8 HSE_Divider;
	uint8 Clock_Switch;
	
	// "HSE Divider " initialization: PLLXTPRE (HSE divider for PLL entry) bit in " RCC_CFGR " register
	if(Mcu_ClockSettings[ClockSetting].SYSCLK_Frequency%8 != 0)
	/*if the SYSCLK_freq is not dividable by 8 (ie: remainder != 0 )
	 * which is the range from [4-7] MHz and [9-15] MHz
	 */
	{
		//setting value for " PLLXTPRE " bit in RCC_CFGR
		HSE_Divider = HSE_DIV_2;
	}else{
		HSE_Divider = HSE_DIV_1;
	}
	
	//Pll_Multiplication and Clock_Switch initializations / Settings
	if(Mcu_ClockSettings[ClockSetting].SYSCLK_Frequency == SYSCLK_FREQ_8MHZ){
			//if the desired freq after the PLL multiplier is 8MHz
      //choose the clock source that the user enters whether it is HSI or HSE
			Clock_Switch = Mcu_ClockSettings[ClockSetting].Clock_Source;
	}else{
		if(Mcu_ClockSettings[ClockSetting].SYSCLK_Frequency%8 != 0)
		{
			Pll_Multiplication = PLL_MUL_VALUE_DIV2;
		}else{
			Pll_Multiplication = PLL_MUL_VALUE_DIV1;
		}
		
		Clock_Switch = SW_PLLCLK;
	}
	
	//Clock Source
	if(Mcu_ClockSettings[ClockSetting].Clock_Source == CLK_SRC_HSE){
		RCC_CR |= HSEON;
		while((RCC_CR & HSERDY) == 0);
	}else if(Mcu_ClockSettings[ClockSetting].Clock_Source == CLK_SRC_HSI){
		RCC_CR |= HSION;
		while((RCC_CR & HSIRDY) == 0);
	}
	
	//AHB, APB1, APB2 Prescalars set ----> RCC_CFGR register
	CLR_AHB_APB1_APB2_BITS; // clear previous data in AHP & APB1 & APB2 bits in RCC_CFGR register
	MOD_AHB_PRESCALAR;
	MOD_APB1_PRESCALAR;
	MOD_APB2_PRESCALAR;
	
	if(Mcu_ClockSettings[ClockSetting].SYSCLK_Frequency != SYSCLK_FREQ_8MHZ){
		//PLL Source (PLLSRC)
		/*this bit is either 0 or 1
		 * 0: HSI oscillator clock / 2 selected as PLL input clock
		 * 1: Clock from PREDIV1 selected as PLL input clock
		 *
		 * for our purposes, PREDIV1 is HSE divider (check the "2" clock trees)
		 */
		
		//PLL Source
		CLR_PLL_SRC;
		MOD_PLL_SRC;
		
		//HSE Divider
		CLR_HSE_DIV;
		MOD_HSE_DIV;
		
		//PLL Multiplication register set ----> RCC_CFGR register
    CLR_PLL_MUL_BITS;
    MOD_PLL_MUL_BITS;
		
		//PLL enable set and check if ready ----> RCC_CR register
		PLL_ENABLE;
		while(PLL_NOT_RDY);
	}

	//Clock Switch ----> RCC_CFGR register bits {0,1}
	CLR_SW_BITS;
	MOD_SW_BITS;
	
	//McuClockReferencePoint
	SYS_CLK_VALUE = Mcu_ClockSettings[ClockSetting].SYSCLK_Frequency;
	
	//Calculate CAN_CPU_CLOCK_REFERENCE
	switch(Mcu_ClockSettings[ClockSetting].AHB_Prescalar){
		case AHB_PR_1:
			CAN_CPU_CLOCK_REFERENCE = SYS_CLK_VALUE / 1;
			break;
		case AHB_PR_2:
			CAN_CPU_CLOCK_REFERENCE = SYS_CLK_VALUE / 2;
			break;
		case AHB_PR_4:
			CAN_CPU_CLOCK_REFERENCE = SYS_CLK_VALUE / 4;
			break;
		case AHB_PR_8:
			CAN_CPU_CLOCK_REFERENCE = SYS_CLK_VALUE / 8;
			break;
		case AHB_PR_16:
			CAN_CPU_CLOCK_REFERENCE = SYS_CLK_VALUE / 16;
			break;
		case AHB_PR_64:
			CAN_CPU_CLOCK_REFERENCE = SYS_CLK_VALUE / 64;
			break;
		case AHB_PR_128:
			CAN_CPU_CLOCK_REFERENCE = SYS_CLK_VALUE / 128;
			break;
		case AHB_PR_256:
			CAN_CPU_CLOCK_REFERENCE = SYS_CLK_VALUE / 256;
			break;
		case AHB_PR_512:
			CAN_CPU_CLOCK_REFERENCE = SYS_CLK_VALUE / 512;
			break;
	}
	switch(Mcu_ClockSettings[ClockSetting].APB1_Prescalar){
		case APB1_PR_1:
			CAN_CPU_CLOCK_REFERENCE = CAN_CPU_CLOCK_REFERENCE / 1;
			break;
		case APB1_PR_2:
			CAN_CPU_CLOCK_REFERENCE = CAN_CPU_CLOCK_REFERENCE / 2;
			break;
		case APB1_PR_4:
			CAN_CPU_CLOCK_REFERENCE = CAN_CPU_CLOCK_REFERENCE / 4;
			break;
		case APB1_PR_8:
			CAN_CPU_CLOCK_REFERENCE = CAN_CPU_CLOCK_REFERENCE / 8;
			break;
		case APB1_PR_16:
			CAN_CPU_CLOCK_REFERENCE = CAN_CPU_CLOCK_REFERENCE / 16;
			break;
	}
	
	//Peripherals Configuration Section
	RCC_APB2ENR |= (Mcu_PeripheralsSettings->SPI1 * SPI1_EN) | (Mcu_PeripheralsSettings->USART1 * USART1_EN)\
									| (Mcu_PeripheralsSettings->GPIOA * GPIOA_EN) | (Mcu_PeripheralsSettings->GPIOB * GPIOB_EN)\
									| (Mcu_PeripheralsSettings->GPIOC * GPIOC_EN);
	
	RCC_APB1ENR |= (Mcu_PeripheralsSettings->SPI2 * SPI2_EN) | (Mcu_PeripheralsSettings->USART2 * USART2_EN)\
									| (Mcu_PeripheralsSettings->bxCAN * bxCAN_EN) | (Mcu_PeripheralsSettings->TIM2 * TIM2_EN)\
									| (Mcu_PeripheralsSettings->TIM3 * TIM3_EN) | (Mcu_PeripheralsSettings->TIM4 * TIM4_EN);
	
	if(Mcu_PeripheralsSettings->SPI1 == STD_ON || Mcu_PeripheralsSettings->SPI2 == STD_ON\
		|| Mcu_PeripheralsSettings->USART1 == STD_ON || Mcu_PeripheralsSettings->USART2 == STD_ON\
		|| Mcu_PeripheralsSettings->bxCAN == STD_ON || Mcu_PeripheralsSettings->TIM2 == STD_ON\
		|| Mcu_PeripheralsSettings->TIM3 == STD_ON || Mcu_PeripheralsSettings->TIM3 == STD_ON){
		RCC_APB2ENR |= AF_EN;
	}
	

	return command_status;
	// this will return OK to us
}
#endif

static void Flash_Init(void){
	/* Enable Prefetch Buffer */
	FLASH_ACR |= FLASH_ACR_PRFTBE;

	/* Flash 2 wait state */
	FLASH_ACR &= (uint32)((uint32)~FLASH_ACR_LATENCY);
	FLASH_ACR |= (uint32)FLASH_ACR_LATENCY_2;
}

/************************************************************************************
* Service Name: Mcu_DistributePllClock
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This Service activates the PLL and MCU clock Distribution.
************************************************************************************/
#if (MCU_NO_PLL == STD_OFF)	
void Mcu_DistributePllClock(void){
/*
	The function Mcu_DistributePllClock shall return without affecting
	the MCU hardware if the PLL clock has been automatically activated by the MCU
	hardware.
*/	
}
#endif

/************************************************************************************
* Service Name: Mcu_GetPllStatus
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: Mcu_PllStatusType (PLL Status)
* Description: This service provides the lock status of the PLL.
************************************************************************************/

Mcu_PllStatusType Mcu_GetPllStatus(void){
#if (MCU_NO_PLL == STD_ON)
	return MCU_PLL_STATUS_UNDEFINED;
#endif
	Mcu_PllStatusType pll_state = MCU_PLL_UNLOCKED;
	if(PLL_RDY){
				pll_state = MCU_PLL_LOCKED;
	}else{
				pll_state = MCU_PLL_UNLOCKED;
	}
 return pll_state;
}

/************************************************************************************
* Service Name: Mcu_GetResetReason
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: Mcu_ResetType
* Description: The service reads the reset type from the hardware, if supported.
************************************************************************************/
Mcu_ResetType Mcu_GetResetReason(void){
	if(Mcu_Status == MCU_NOT_INITIALIZED){
		return MCU_RESET_UNDEFINED;
	}

	Mcu_ResetType reset_source = MCU_RESET_UNDEFINED;

	//Read all reset flags
	uint32 csr = RCC_CSR; // storing the RCC_CSR register in a variable
    csr &= (RESET_FLAGS_BITS); //clearing the 26 bits before the reset flags
    reset_source = csr; // return the reset reason in the form of a uint32.
	//Clear all reset flags
	CLR_RESET_FLAGS;

	if (    (reset_source != MCU_RESET_IWATCHDOG) && (reset_source != MCU_RESET_LOW_POWER)\
           && (reset_source != MCU_RESET_PIN) && (reset_source != MCU_RESET_POWER_ON)\
					 && (reset_source != MCU_RESET_SW) && (reset_source != MCU_RESET_WWATCHDOG))
        {
         reset_source = MCU_RESET_UNDEFINED;
        }
	return reset_source;
	
}

/************************************************************************************
* Service Name: Mcu_GetResetRawValue
* Service ID[hex]: 0x06
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: Mcu_RawResetType (Reset raw value)
* Description: The service reads the reset type from the hardware register, if supported.
************************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue(void){
	uint32 reset_source = RCC_CSR;
	//Clear all reset flags
	CLR_RESET_FLAGS;

	return reset_source;
}

/************************************************************************************
* Service Name: Mcu_PerformReset
* Service ID[hex]: 0x07
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: The service performs a microcontroller reset.
************************************************************************************/
#if (MCU_PERFORM_RESET_API == STD_ON)
void Mcu_PerformReset(void){
	if(Mcu_Status == MCU_NOT_INITIALIZED){
		APP_INT_AND_RST_CTRL |= (1<<2);
	}
}
#endif

/************************************************************************************
* Service Name: Mcu_SetMode
* Service ID[hex]: 0x08
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): McuMode - Sets different MCU Power modes configured in the configuration set
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This service activates the MCU power modes..
************************************************************************************/
void Mcu_SetMode(Mcu_ModeType McuMode){
	
}




/************************************************************************************
* Service Name: Mcu_GetVersionInfo
* Service ID[hex]: 0x09
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): VersionInfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: Function to get the version information of this module.
************************************************************************************/

#if (MCU_VERSION_INFO_API == STD_ON)
void Mcu_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (MCU_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
				MCU_GET_VERSION_INFO_SID, MCU_E_PARAM_POINTER);
	}
	else
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)MCU_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)MCU_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)MCU_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)MCU_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)MCU_SW_PATCH_VERSION;
	}	
}
#endif

/************************************************************************************
* Service Name: Mcu_GetRamState
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: Mcu_RamStateType (Status of the RAM content)
* Description: This service provides the actual status of the microcontroller Ram. (if supported).
************************************************************************************/
#if (MCU_GET_RAM_STATE_API == STD_ON)
Mcu_RamStateType Mcu_GetRamState(void){
	
}
#endif


