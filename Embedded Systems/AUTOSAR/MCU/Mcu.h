/**
  ******************************************************************************
  *
  * @Module: MCU
  * @FileName: Mcu.h
  * @Description: Header file for MCU Module.
  * @version: 1.0.0
  * @date:    xx-xx-2020
  * @Authors: Ahmed Mohamed Gamal  && Omar Hisham && Ahmed Mohsen
  *
  ******************************************************************************
  */
#ifndef Mcu_h
#define Mcu_h

#include "Std_Types.h"
#include "Mcu_Cfg.h"
#include "Common_Macros.h"

#define MCU_VENDOR_ID    							(1000U)
#define MCU_MODULE_ID    							(101U)
#define MCU_INSTANCE_ID  							(0U)

#define MCU_SW_MAJOR_VERSION 					(1U)
#define MCU_SW_MINOR_VERSION 					(0U)
#define MCU_SW_PATCH_VERSION 					(0U)

#define MCU_INITIALIZED               (0U)
#define MCU_NOT_INITIALIZED           (1U)

/*
 * AUTOSAR Version 4.0.3
 */
#define MCU_AR_RELEASE_MAJOR_VERSION  (4U)
#define MCU_AR_RELEASE_MINOR_VERSION  (0U)
#define MCU_AR_RELEASE_PATCH_VERSION  (3U)

/* AUTOSAR checking between Std Types and MCU Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != MCU_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* AUTOSAR Version checking between MCU_Cfg.h and MCU.h files */
#if ((MCU_CFG_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION)\
 ||  (MCU_CFG_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION)\
 ||  (MCU_CFG_AR_RELEASE_PATCH_VERSION != MCU_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of MCU_Cfg.h does not match the expected version"
#endif

/* Software Version checking between MCU_Cfg.h and MCU.h files */
#if ((MCU_CFG_SW_MAJOR_VERSION != MCU_SW_MAJOR_VERSION)\
 ||  (MCU_CFG_SW_MINOR_VERSION != MCU_SW_MINOR_VERSION)\
 ||  (MCU_CFG_SW_PATCH_VERSION != MCU_SW_PATCH_VERSION))
  #error "The SW version of MCU_Cfg.h does not match the expected version"
#endif


/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
#define MCU_INIT_SID           							((uint8)0x00)/* Service ID for MCU_INIT_SID */
#define MCU_INIT_RAM_SECTION_SID            ((uint8)0x01)/* Service ID for MCU_INIT_RAM_SECTION_SID */
#define MCU_INIT_CLOCK_SID              		((uint8)0x02)/* Service ID for MCU_INIT_CLOCK_SID */
#define MCU_DISTRIBUTE_PLL_CLOCK_SID        ((uint8)0x03)/* Service ID for MCU_DISTRIBUTE_PLL_CLOCK_SID */
#define MCU_GET_PLL_STATUS_SID     					((uint8)0x04)/* Service ID for MCU_GET_PLL_STATUS_SID */
#define MCU_GET_RESET_REASON_SID    				((uint8)0x05)/* Service ID for MCU_GET_RESET_REASON_SID */
#define MCU_GET_RESET_RAW_VALUE_SID       	((uint8)0x06)/* Service ID for MCU_GET_RESET_RAW_VALUE_SID */
#define MCU_PERFORM_RESET_SID               ((uint8)0x07)/* Service ID for MCU_PERFORM_RESET_SID */
#define MCU_SET_MODE_SID           					((uint8)0x08)/* Service ID for MCU_SET_MODE_SID */
#define MCU_GET_VERSION_INFO_SID           	((uint8)0x09)/* Service ID for MCU_GET_VERSION_INFO_SID */

//Wrong ID in the SWS file
#define MCU_GET_RAM_STATE_SID           		((uint8)0x10)/* Service ID for MCU_GET_RAM_STATE_SID  */


/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report NULL ConfigPtr pointer  */
#define MCU_E_PARAM_CONFIG 			 ((uint8)0x0A)

/* DET code for passing parameters not within the " ClockSetting " data structure */
#define MCU_E_PARAM_CLOCK            ((uint8)0x0B)

/* DET code for passing parameters not within the " McuMode " data structure */
#define MCU_E_PARAM_MODE    		 ((uint8)0x0C)

/* DET code for passing parameters not within the " RamSection " data structure */
#define MCU_E_PARAM_RAMSECTION       ((uint8)0x0D)

/* DET code to report the PLL is not locked yet */
#define MCU_E_PLL_NOT_LOCKED         ((uint8)0x0E)

/* DET code to report any function call before executing McuInit
 * Exception : Mcu_GetVersionInfo function */
#define MCU_E_UNINIT                 ((uint8)0x0F)

/* DET code to report if versionInfo paramaeter is NULL */
#define MCU_E_PARAM_POINTER          ((uint8)0x10)

//#define MCU_E_CLOCK_FAILURE

/*******************************************************************************
 *                       Magic numbers Macro definitions                       *
 *******************************************************************************/
/*Mcu.h file ---------> " Mcu_ResetType " enum
 *Mcu.c file ---------> " Mcu_GetResetReason " function */
#define LPWRRSTF (31U) //RCC_CSR :  Low-power reset flag
#define WWDGRSTF (30U) //RCC_CSR :  Window watchdog reset flag
#define IWDGRSTF (29U) //RCC_CSR :  Independent watchdog reset flag
#define SFTRSTF  (28U) //RCC_CSR :  Software reset flag
#define PORRSTF  (27U) //RCC_CSR :  POR/PDR  reset flag
#define PINRSTF  (26U) //RCC_CSR :  NRST PIN reset flag

//Mcu.c file ---------> " Mcu_InitClock " function
#define APB1_Bus_Pretection_Variable        (2U) //minimum product of ( AHB_Min_Prescaler  x APB1_Min_Prescaler )


#define SW_PLLCLK           ((uint8)0x02) //RCC_CFGR register
#define PLL_MUL_VALUE_DIV1  ((Mcu_ClockSettings[ClockSetting].SYSCLK_Frequency/(HSE_FREQ_VALUE/1)) - 2)
#define PLL_MUL_VALUE_DIV2  ((Mcu_ClockSettings[ClockSetting].SYSCLK_Frequency/(HSE_FREQ_VALUE/2)) - 2)


#define HSEON                        (1<<16) //RCC_CR register
#define HSERDY                       (1<<17)
#define HSION                        (1<<0)
#define HSIRDY                       (1<<1)

#define CLR_AHB_APB1_APB2_BITS       (RCC_CFGR &= ~(0x3FF << 4)) //RCC_CFGR register
#define MOD_AHB_PRESCALAR            (RCC_CFGR |= ((Mcu_ClockSettings[ClockSetting].AHB_Prescalar) << 4) )
#define MOD_APB1_PRESCALAR           (RCC_CFGR |= ((Mcu_ClockSettings[ClockSetting].APB1_Prescalar) << 8))
#define MOD_APB2_PRESCALAR           (RCC_CFGR |= ((Mcu_ClockSettings[ClockSetting].APB2_Prescalar) << 11))

#define PLLSRC												(1<<16)
#define CLR_PLL_SRC										(RCC_CFGR &= ~PLLSRC)
#define MOD_PLL_SRC										(RCC_CFGR |= ((Mcu_ClockSettings[ClockSetting].Clock_Source) << 16))
#define PLLXTPRE											(1<<17)
#define CLR_HSE_DIV										(RCC_CFGR &= ~PLLXTPRE)
#define MOD_HSE_DIV										(RCC_CFGR |= HSE_Divider << 17)


//
#define CLR_PLL_MUL_BITS             (RCC_CFGR &= ~(0x0F << 18)) //RCC_CFGR register
#define MOD_PLL_MUL_BITS             (RCC_CFGR |= (Pll_Multiplication << 18))

#define PLL_ENABLE                   (RCC_CR |= (1<<24)) //RCC_CR register
#define PLLRDY                       (1<<25)        //PLL clock ready flag
#define PLL_NOT_RDY                  ((RCC_CR & PLLRDY) == 0)

#define CLR_SW_BITS                  (RCC_CFGR &= ~(0x03 << 0))//RCC_CFGR register
#define MOD_SW_BITS                  (RCC_CFGR |= Clock_Switch)
//
//
//
/* Mcu_GetPllStatus function Macros ----------> RCC_CSR  register*/
#define PLL_RDY                      ((RCC_CR & (1<<25)) == (1<<25)) //RCC_CR register


/* Mcu_GetResetReason function Macros ----------> RCC_CSR  register*/
/* Mcu_GetResetRawValue function Macros ----------> RCC_CSR  register*/
#define RESET_FLAGS_BITS              ((uint32)0xFC000000)
                    /* this is a Hex value to be ANDed with the RCC_CSR register in order to only get
                        only the 6 bits of the reset bits.*/

#define CLR_RESET_FLAGS								(RCC_CSR |= (1<<24))

/* Mcu_PerformReset function Macros ----------> register*/
#define SYS_RESET_REQ    (1<<2)

//Peripherals Enable
#define GPIOA_EN										(1<<2)
#define GPIOB_EN										(1<<3)
#define GPIOC_EN										(1<<4)
#define SPI1_EN											(1<<12)
#define SPI2_EN											(1<<14)
#define USART1_EN										(1<<14)
#define USART2_EN										(1<<17)
#define bxCAN_EN										(1<<25)
#define TIM2_EN											(1<<0)
#define TIM3_EN											(1<<1)
#define TIM4_EN											(1<<2)
#define AF_EN												(1<<0)


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
 
//This is a status value returned by the function Mcu_GetPllStatus of the MCU module
typedef enum{
	MCU_PLL_LOCKED,
	MCU_PLL_UNLOCKED,
	MCU_PLL_STATUS_UNDEFINED
}Mcu_PllStatusType;

//This is the type of the reset enumerator containing the subset of reset types. It is not
//required that all reset types are supported by hardware
typedef enum{
	MCU_RESET_LOW_POWER =  ( 1<<LPWRRSTF ),
	MCU_RESET_WWATCHDOG =  ( 1<<WWDGRSTF ),
	MCU_RESET_IWATCHDOG =  ( 1<<IWDGRSTF ),
	MCU_RESET_SW =         ( 1<<SFTRSTF ),
	MCU_RESET_POWER_ON =   ( 1<<PORRSTF ),
	MCU_RESET_PIN =        ( 1<<PINRSTF ),
	MCU_RESET_UNDEFINED = 0 // a variable to state that there are no reset flags risen
}Mcu_ResetType;

//Specifies the identification (ID) for a clock setting, which is configured in the configuration structure
typedef uint8 Mcu_ClockType;
typedef uint32 Mcu_RawResetType;
typedef uint8 Mcu_ModeType;
typedef uint32 Mcu_RamSectionType;
typedef uint8 Mcu_RamStateType;

typedef struct{
	uint8 GPIOA;
	uint8 GPIOB;
	uint8 GPIOC;
	uint8 SPI1;
	uint8 SPI2;
	uint8 USART1;
	uint8 USART2;
	uint8 bxCAN;
	uint8 TIM2;
	uint8 TIM3;
	uint8 TIM4;	
}Mcu_ConfigPeripherals;

typedef struct{
	uint8 Clock_Source;
	/*Note: for Clock source switch, the allowed values are only : 0b00 (HSI), 0b01 (HSE), 0b10 (PLL).
	 * 0b11 is not allowed*/
	uint32 SYSCLK_Frequency;
	uint8 AHB_Prescalar;
	uint8 APB1_Prescalar;
	uint8 APB2_Prescalar;
}Mcu_ConfigClock;



typedef struct{
	uint8 Ram_Base_Address;
	uint8 Ram_Size;
	uint8 Data;
}Mcu_ConfigRam;


typedef struct{
	Mcu_ConfigPeripherals Peripherals[NUMBER_OF_PERIPHERALS_CONGIFURATION];
	Mcu_ConfigClock ClockConfigurations[NUMBER_OF_CLOCK_CONGIFURATION];
	Mcu_ConfigRam RamConfigurations[NUMBER_OF_RAM_CONGIFURATION];
	
	Mcu_ModeType Mcu_Mode_Settings;
	Mcu_ResetType Reset_Settings;
}Mcu_ConfigType;


/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/
 
void Mcu_Init(const Mcu_ConfigType* ConfigPtr);
Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection);
//Configrable (ON/OFF) functions
#if (MCU_INIT_CLOCK == STD_ON)
Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting);
#endif
void Mcu_DistributePllClock(void);
#if (MCU_NO_PLL == STD_OFF)
Mcu_PllStatusType Mcu_GetPllStatus(void);
#endif
Mcu_ResetType Mcu_GetResetReason(void);
Mcu_RawResetType Mcu_GetResetRawValue(void);
void Mcu_SetMode(Mcu_ModeType McuMode);


#if (MCU_PERFORM_RESET_API == STD_ON)
void Mcu_PerformReset(void);
#endif
#if (MCU_VERSION_INFO_API == STD_ON)
void Mcu_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif
#if (MCU_GET_RAM_STATE_API == STD_ON)
Mcu_RamStateType Mcu_GetRamState(void);
#endif

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Dio and other modules */
extern const Mcu_ConfigType Mcu_Configuration;
extern uint32 SYS_CLK_VALUE;
extern uint32 CAN_CPU_CLOCK_REFERENCE;

#endif

