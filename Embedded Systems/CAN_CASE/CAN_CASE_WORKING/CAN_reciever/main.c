#include "GPIO.h"
#include "CAN.h"
#include "USART.h"

CanRxMsg	myRxMsg;

int main()
{
	TIMER_voidInit();
	GPIO_voidInit();
	CAN_voidInit();
	USART_voidInit();

	CAN_voidConfigFilter(3 ,CAN_FilterMode_IdList ,CAN_FilterScale_16bit ,0x103 ,0x123 ,CAN_FilterFIFO0);
	CAN_voidConfigFilter(2 ,CAN_FilterMode_IdList ,CAN_FilterScale_16bit ,0x200 ,0x210 ,CAN_FilterFIFO1);

	uint32_t temp=0;
	while(1)
	{

		GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);
		Delay(500);

		CAN_Receive(CAN1,CAN_FIFO0,&myRxMsg);
		CAN_FIFORelease(CAN1 ,CAN_FIFO0);
		Led_Tog(100,1);

		USART_PrintString("-----\n");
		Delay(1);
						/* Filter_index */
		USART_PrintString("Filter_index: ");
		Delay(1);
		temp = CAN_voidGetFilterIndex(CAN_FilterFIFO0);
		USART_SendData(USART1,temp+'0');
		Delay(1);
		USART_SendData(USART1,',');
		Delay(1);

					/* data */
		USART_PrintString(" Data: ");
		Delay(1);
		temp = myRxMsg.Data[0];
		USART_SendData(USART1,temp);
		Delay(1);
		USART_SendData(USART1,',');
		Delay(1);

					/* std_id */
		USART_PrintString(" std_id: ");
		Delay(1);
		temp = myRxMsg.StdId;
		USART_PrintString("0x");
		USART_voidPrintNumber(temp);
		Delay(1);
		USART_SendData(USART1,',');
		Delay(1);

					/* DLC */
		USART_PrintString(" DLC: ");
		Delay(1);
		temp = myRxMsg.DLC;
		USART_SendData(USART1,temp+'0');
		Delay(1);
		USART_SendData(USART1,',');
		Delay(1);

						/* RTR */
		USART_PrintString(" RTR:- ");
		Delay(1);
		temp = myRxMsg.RTR;
		USART_SendData(USART1,temp+'0');
		Delay(1);

		USART_SendData(USART1,10);
		USART_SendData(USART1,13);
		Delay(1);

	}

}
