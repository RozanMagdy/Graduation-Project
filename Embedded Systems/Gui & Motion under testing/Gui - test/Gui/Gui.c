#include "Gui.h"




CanRxMsg	myRxMsg;



void Gui_Init(void)
{

	Gpio_Init();
	Can_Init();
	Uart_Init();
	
	
	Can_ConfigFilter(0 ,CAN_FilterMode_IdList ,CAN_FilterScale_16bit ,0x010 ,0x000 ,CAN_FilterFIFO0);
	
	
	Can_InterruptEnable();
	Can_FIFO_0_FMP_IRQ(Gui_Can_RxMsg);

}







void Gui_Can_RxMsg(void)
{
		
		myRxMsg.StdId = 0;
		CAN_Receive(CAN1,CAN_FIFO0,&myRxMsg);
		CAN_FIFORelease(CAN1 ,CAN_FIFO0);
	
	
		Uart_PrintString(Gui_Uart ,"-----\n");
			
	
		/* Motors_Id */					
		Uart_PrintString(Gui_Uart ," Motors_Id : ");
		Uart_PrintString(Gui_Uart ,"0x");
		Uart_PrintHexNumber(Gui_Uart ,myRxMsg.StdId);			
		Uart_SendChar(Gui_Uart, ',');
		
		
		/* Motors_DLC */				
		Uart_PrintString(Gui_Uart ," Motors_DLC : ");
		Uart_SendChar(Gui_Uart, myRxMsg.DLC+'0');
		Uart_SendChar(Gui_Uart, ',');

		
		/* RTR */					
		Uart_PrintString(Gui_Uart ," RTR:- ");
		Uart_SendChar(Gui_Uart, myRxMsg.RTR+'0');
		
		
		/* DCMotor_Direction */	
		Uart_PrintString(Gui_Uart ," DCMotor_Direction : ");
		Uart_PrintHexNumber(Gui_Uart, myRxMsg.Data[0]);
		Uart_SendChar(Gui_Uart, ',');
		
		
		/* DCMotor_Speed */	
		Uart_PrintString(Gui_Uart ," DCMotor_Speed : ");
		Uart_PrintHexNumber(Gui_Uart, myRxMsg.Data[1]);
		Uart_SendChar(Gui_Uart, ',');
		
		
		/* Stepper_Direction */	
		Uart_PrintString(Gui_Uart ," Stepper_Direction : ");
		Uart_PrintHexNumber(Gui_Uart, myRxMsg.Data[2]);
		Uart_SendChar(Gui_Uart, ',');
		
		
		/* Stepper_Speed */	
		Uart_PrintString(Gui_Uart ," Stepper_Speed : ");
		Uart_PrintHexNumber(Gui_Uart, myRxMsg.Data[3]);
		Uart_SendChar(Gui_Uart, ',');	
			
		Uart_SendChar(Gui_Uart, 10);
		Uart_SendChar(Gui_Uart, 13);
		
		

}







