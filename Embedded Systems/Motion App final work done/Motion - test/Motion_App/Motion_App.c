#include "Motion_App.h"


CanRxMsg	Motion_App_Rx_Msg;

void _delay_(void);

void Motion_App_Init(void)
{

	
	Can_Init();
	Can_ConfigFilter(Filter_0 , CAN_FilterMode_IdList , CAN_FilterScale_32bit , Motion_App_Motors_Can_Id , Motion_App_Motors_Can_Mask_Id , CAN_FilterFIFO0);
	Can_InterruptEnable();
	Can_FIFO_0_FMP_IRQ(&Motion_App_Can_Fifo_0_Receive_Interrupt);

	
	
	DCMotor_Init();
	Stepper_Init();



}








void Motion_App_Can_Fifo_0_Receive_Interrupt(void)
{
		
	CAN_Receive(CAN1 , CAN_FIFO0 , &Motion_App_Rx_Msg);
	CAN_FIFORelease(CAN1 , CAN_FIFO0);
	
	
	
	
	DCMotor_SetSpeed(Motion_App_Rx_Msg.Data[0] , Motion_App_Rx_Msg.Data[1]);
	
	
	//if(!Gpio_GetPinValue(GPIOB,GPIO_PIN_6)){
		Stepper_SetAngle(Motion_App_Rx_Msg.Data[2] , Motion_App_Rx_Msg.Data[3]);
	//}
}

