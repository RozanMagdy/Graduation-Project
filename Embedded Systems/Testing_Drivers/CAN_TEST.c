//Libraries should be included :
//RCC(stm32f10x_rcc.h) - GPIO(stm32f10x_gpio.h) - TIMER(stm32f10x_tim.h)

#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_can.h"

GPIO_InitTypeDef GPIO_InitStructure;
TIM_TimeBaseInitTypeDef TIM_InitStructure;
CAN_InitTypeDef CAN_InitStructure;
CanTxMsg myTxMsg;
CanRxMsg myRxMsg;

void InitGPIO(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void InitTIM(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	// Get the clock frequencies
	RCC_ClocksTypeDef RCC_Clocks;
	RCC_GetClocksFreq(&RCC_Clocks);
	
	TIM_InitStructure.TIM_Prescaler = 1000;
	TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_InitStructure.TIM_Period = 0xFFFF;
	
	TIM_TimeBaseInit(TIM2,&TIM_InitStructure);

	TIM_Cmd(TIM2, ENABLE); // start counting by enabling CEN in CR1 */
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); // enable so we can track each period
}

void InitCAN(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
	CAN_InitStructure.CAN_ABOM = DISABLE;
	CAN_InitStructure.CAN_AWUM = DISABLE;
	CAN_InitStructure.CAN_BS1 = CAN_BS1_4tq;
	CAN_InitStructure.CAN_BS2 = CAN_BS2_2tq;
	CAN_InitStructure.CAN_Mode = CAN_Mode_Silent_LoopBack;
	CAN_InitStructure.CAN_NART = DISABLE;
	//CAN_InitStructure.CAN_Prescaler = 8;
	CAN_InitStructure.CAN_Prescaler = 1;
	CAN_InitStructure.CAN_RFLM = DISABLE;
	CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
	CAN_InitStructure.CAN_TTCM = DISABLE;
	CAN_InitStructure.CAN_TXFP = DISABLE;
	
	CAN_Init(CAN1,&CAN_InitStructure);
	
}

void CAN_FilterConfig(void){
	CAN_FilterInitTypeDef myFilter;
	
	myFilter.CAN_FilterNumber = 0;
	myFilter.CAN_FilterActivation = ENABLE;
	myFilter.CAN_FilterFIFOAssignment = CAN_Filter_FIFO0;
	myFilter.CAN_FilterIdHigh = 0x0010 << 5;
	myFilter.CAN_FilterIdLow = 0x0000;
	myFilter.CAN_FilterMaskIdHigh = 0x0000;
	myFilter.CAN_FilterMaskIdLow = 0x0000;
	myFilter.CAN_FilterMode = CAN_FilterMode_IdList;
	myFilter.CAN_FilterScale = CAN_FilterScale_32bit;
	
	CAN_FilterInit(&myFilter);
}

void CAN_SetMailBox(void){
	myTxMsg.StdId = 0x10;
	myTxMsg.IDE = CAN_Id_Standard;
	myTxMsg.RTR = CAN_RTR_Data;
	myTxMsg.DLC = 1;
	myTxMsg.Data[0] = 5;
}

int main(void){
	char i = 0;
	InitGPIO();
	InitTIM();
	CAN_OperatingModeRequest(CAN1,CAN_OperatingMode_Initialization);
	InitCAN();
	CAN_FilterConfig();
	CAN_ITConfig(CAN1,CAN_IT_FMP0,ENABLE);
	CAN_OperatingModeRequest(CAN1,CAN_OperatingMode_Normal);
	
	CAN_SetMailBox();
	
	while(1){
		if(TIM_GetCounter(TIM2) == 0x7FFF){
			myTxMsg.Data[0] = i++%2;
			CAN_Transmit(CAN1,&myTxMsg);
			CAN_Receive(CAN1,CAN_FIFO0,&myRxMsg);
			
			if(myRxMsg.StdId == 0x10){
				if(myRxMsg.Data[0] == 1){
					GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);
					while(TIM_GetCounter(TIM2) < 0x8FFF);
				}else{
					GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);
					while(TIM_GetCounter(TIM2) < 0xCFFF);
				}
			}
		}else{
			GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_SET);
		}
	}		
	
	return 0;
}
