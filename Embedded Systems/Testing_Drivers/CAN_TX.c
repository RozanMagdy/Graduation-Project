#include "stm32f10x.h"                  // Device header
#include "stm32f10x_can.h"              // Keil::Device:StdPeriph Drivers:CAN
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM
#include "stm32f10x_usart.h"            // Keil::Device:StdPeriph Drivers:USART

void USART1_Init(void);
void USART_PrintString(char* string);
void USART_PrintNumber(u32 number);
/************************/


void USART1_Init(void)
{
    /* USART configuration structure for USART1 */
    USART_InitTypeDef usart1_init_struct;
    /* Bit configuration structure for GPIOA PIN9 and PIN10 */
    GPIO_InitTypeDef gpioa_init_struct;
     
    /* Enalbe clock for USART1, AFIO and GPIOA */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_AFIO | 
                           RCC_APB2Periph_GPIOA, ENABLE);
                            
    /* GPIOA PIN9 alternative function Tx */
    gpioa_init_struct.GPIO_Pin = GPIO_Pin_9;
    gpioa_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
    gpioa_init_struct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &gpioa_init_struct);
    /* GPIOA PIN9 alternative function Rx */
    gpioa_init_struct.GPIO_Pin = GPIO_Pin_10;
    gpioa_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
    gpioa_init_struct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &gpioa_init_struct);
 
    /* Enable USART1 */
    USART_Cmd(USART1, ENABLE);  
    /* Baud rate 9600, 8-bit data, One stop bit
     * No parity, Do both Rx and Tx, No HW flow control
     */
    usart1_init_struct.USART_BaudRate = 9600;   
    usart1_init_struct.USART_WordLength = USART_WordLength_8b;  
    usart1_init_struct.USART_StopBits = USART_StopBits_1;   
    usart1_init_struct.USART_Parity = USART_Parity_No ;
    usart1_init_struct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    usart1_init_struct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    /* Configure USART1 */
    USART_Init(USART1, &usart1_init_struct);
    /* Enable RXNE interrupt */
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
    /* Enable USART1 global interrupt */
    NVIC_EnableIRQ(USART1_IRQn);
}


/*************************************/
void USART_PrintString(char* string);

GPIO_InitTypeDef GPIO_InitStructure;
TIM_TimeBaseInitTypeDef TIM_InitStructure;
CAN_InitTypeDef CAN_InitStructure;
CanTxMsg myTxMsg;

static __IO uint32_t TimingDelay;
/************************/

void InitGPIO(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

/*********************/

void CAN_GPIO_INIT(void)
{
	
	// can_RX is input
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// can_TX is output
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//REMAPPING
	// can_RX is input
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//REMAPPING
	// can_TX is output
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	//GPIO_PinRemapConfig(GPIO_Remap1_CAN1, ENABLE); // disable remapping means we will use PIN_A_11  , PIN_A_12
	
}	

/*********************/
void InitTimer()
{
        SysTick_Config(SystemCoreClock / 1000);
}
void SysTick_Handler(void)
{
        if (TimingDelay != 0x00)
        {
                TimingDelay--;
        }
}
void Delay(__IO uint32_t nTime)
{
         TimingDelay = nTime;
         while(TimingDelay != 0);
}

/****************************/
void InitCAN(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
	CAN_GPIO_INIT();
	
	CAN_InitStructure.CAN_ABOM = DISABLE;
	CAN_InitStructure.CAN_AWUM = DISABLE; 
	CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;
	CAN_InitStructure.CAN_NART = DISABLE;
	CAN_InitStructure.CAN_Prescaler = 1024;
	CAN_InitStructure.CAN_RFLM = DISABLE;
	CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
	CAN_InitStructure.CAN_BS1 = CAN_BS1_4tq;
	CAN_InitStructure.CAN_BS2 = CAN_BS2_4tq;
	CAN_InitStructure.CAN_TTCM = DISABLE;
	CAN_InitStructure.CAN_TXFP = ENABLE;
	
	if(CAN_Init(CAN1,&CAN_InitStructure) == CAN_InitStatus_Success){
		USART_PrintString("CAN_Init : SUCCEEDED\n");
	}
}

/************************/

void CAN_SetMailBox(void){
	myTxMsg.StdId = 0x110;
	myTxMsg.IDE = CAN_Id_Standard;
	myTxMsg.RTR = CAN_RTR_Data;
	myTxMsg.DLC = 1;
}

/************************/

void Led_Tog(int ms)
{
		GPIOC->BSRR = GPIO_Pin_13;
    Delay(ms);
    GPIOC->BRR  = GPIO_Pin_13;
    Delay(ms);
}

/************************/

int main(void){
	int i = 0;
	
	InitGPIO();
	InitTimer();
	USART1_Init();
	
	InitCAN();
	CAN_SetMailBox();
	
	if(CAN_OperatingModeRequest(CAN1,CAN_OperatingMode_Normal) == CAN_ModeStatus_Success){
		USART_PrintString("CAN_Mode : SUCCEEDED\n");
	};
	
	CAN1->MCR |= CAN_MCR_ABOM;
	
	while(1)
	{
		//GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_SET);
		//Delay(3000);
		
		myTxMsg.Data[0] = '3';
		i = CAN_Transmit(CAN1,&myTxMsg);
		USART_PrintString("i = ");
		USART_PrintNumber(i);
		USART_PrintString(", State = ");
		USART_PrintNumber(CAN_TransmitStatus(CAN1,i));
		USART_PrintString(", RQCP = ");
		USART_PrintNumber(CAN_GetFlagStatus(CAN1,CAN_FLAG_RQCP0));
		USART_PrintString(", BOF = ");
		USART_PrintNumber(CAN_GetFlagStatus(CAN1,CAN_FLAG_BOF));
		USART_PrintString(", LEC = ");
		USART_PrintNumber(CAN_GetFlagStatus(CAN1,CAN_FLAG_LEC));
		USART_PrintString(", TEC = ");
		USART_PrintNumber(((CAN1->ESR)>>16)&0x00FF);
		USART_SendData(USART1,'\n');
		Delay(500);
		
		
	}		
	
	return 0;
}

void USART_PrintString(char* string){
	int i = 0;
	while(string[i] != '\0'){
		USART_SendData(USART1,string[i]);
		Delay(1);
		i++;
	}
}

void USART_PrintNumber(u32 number){
	char string[16] = {0};
	int i = 1;
	u8 j = 0;
	if(number == 0){
		USART_SendData(USART1,'0');
		Delay(1);
		return;
	}
	
	while(number / i != 0){
		i = i*10;
	}

	do{
		i = i/10;
		string[j++] = (number/i) + '0';
		number = number - ((number/i)*i);
	}while(number != 0);
	
	string[j] = '\0';
	USART_PrintString(string);
}
