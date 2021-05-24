#include "GPIO.h"
#include "CAN.h"
#include "UART.h"


CanRxMsg	myRxMsg;
uint32_t temp=0;

void test_0()
{
		myRxMsg.StdId = 0;
		CAN_Receive(CAN1,CAN_FIFO0,&myRxMsg);
		CAN_FIFORelease(CAN1 ,CAN_FIFO0);
	
	
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
			UART_voidSendChar(UART_1, ',');
			
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


void test_1()
{
		myRxMsg.StdId = 0;
		CAN_Receive(CAN1,CAN_FIFO1,&myRxMsg);
		CAN_FIFORelease(CAN1 ,CAN_FIFO1);
	
	
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
			UART_voidSendChar(UART_1, ',');
			
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

int main()
{
	
	GPIO_voidInit();
	CAN_voidInit();
	UART_voidInit();
	
	CAN_voidConfigFilter(0 ,CAN_FilterMode_IdList ,CAN_FilterScale_16bit ,0x140 ,0x150 ,CAN_FilterFIFO0);
	CAN_voidConfigFilter(0 ,CAN_FilterMode_IdList ,CAN_FilterScale_16bit ,0x103 ,0x123 ,CAN_FilterFIFO1);
	
	CAN_voidInterruptEnable();
	
	CAN_FIFO_0_FMP_IRQ(test_0);
	CAN_FIFO_1_FMP_IRQ(test_1);
	
	
	
	
	while(1);


}
