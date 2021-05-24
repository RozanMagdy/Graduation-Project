#include "GPIO.h"
#include "CAN.h"
#include "UART.h"


CanRxMsg	myRxMsg;

int main()
{
	Delay_voidInit();
	GPIO_voidInit();
	CAN_voidInit();
	UART_voidInit();
	
	CAN_voidConfigFilter(0 ,CAN_FilterMode_IdList ,CAN_FilterScale_16bit ,0x103 ,0x123 ,CAN_FilterFIFO0);
	
	uint32_t temp=0;
	while(1)
	{	
		
		GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);
		Delay(550);
		
		myRxMsg.StdId = 0;
		CAN_Receive(CAN1,CAN_FIFO0,&myRxMsg);
		CAN_FIFORelease(CAN1 ,CAN_FIFO0);
		
		
		if(myRxMsg.StdId == 0x123)
		{
			Led_Tog(100,1 ,GPIOC ,GPIO_PIN_13);
		
			UART_voidPrintString(UART_1 ,"-----\n");
			
							/* Filter_index */
			UART_voidPrintString(UART_1 ,"Filter_index: ");
			
			temp = CAN_voidGetFilterIndex(CAN_FilterFIFO0);
			UART_voidSendChar(UART_1, temp+'0');
			UART_voidSendChar(UART_1, ',');

			
						/* data */	
			UART_voidPrintString(UART_1 ," Data: ");
			
			temp = myRxMsg.Data[0];
			UART_voidSendChar(UART_1, temp);
			UART_voidSendChar(UART_1, ',');
			
			
						/* std_id */					
			UART_voidPrintString(UART_1 ," std_id: ");
			
			temp = myRxMsg.StdId;
			UART_voidPrintString(UART_1 ,"0x");
			UART_voidPrintHexNumber(UART_1 ,temp);
			
			USART_SendData(USART1,',');
			while(  ((USART1->SR) & USART_SR_TXE) == 0 );
			
						/* DLC */				
			UART_voidPrintString(UART_1 ," DLC: ");
			
			temp = myRxMsg.DLC;
			UART_voidSendChar(UART_1, temp+'0');
			UART_voidSendChar(UART_1, ',');

			
							/* RTR */					
			UART_voidPrintString(UART_1 ," RTR:- ");
			
			temp = myRxMsg.RTR;
			UART_voidSendChar(UART_1, temp+'0');
			UART_voidSendChar(UART_1, 10);
			UART_voidSendChar(UART_1, 13);
		
		}
		
		
		else 
		{
			UART_voidPrintString(UART_1 ," None ");
			Led_Tog(1000,1 ,GPIOC ,GPIO_PIN_13);
		}
		
	}		

}
