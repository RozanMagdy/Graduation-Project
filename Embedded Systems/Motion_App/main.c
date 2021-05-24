#include "Can_driver/CAN.h"
#include "Pwm_driver/PWM.h"
#include "Gpio_driver/GPIO.h"
#include "Motion_driver/Motion_App.h"


const Motion_Command_Type* Motion_Command;
CanRxMsg	myRxMsg;



void Fifo_0_Int()
{
	
	uint8_t Motion_Command_counter = 0;
	Motion_Command = Motion_App_Configrations.Motion_Command;

	
	CAN_Receive(CAN1 , CAN_FIFO0 , &myRxMsg);
	CAN_FIFORelease(CAN1 , CAN_FIFO0);
	
	for(Motion_Command_counter=0 ; Motion_Command_counter<Number_Of_Commands ; Motion_Command_counter++)
	{
		
			if(Motion_Command[Motion_Command_counter].Command_Id == myRxMsg.StdId)
			{
				
				Motor_Speed(Motion_Command[Motion_Command_counter].Command_Type , myRxMsg.Data[0]);
				break;
				
			}
			
			else
			{
					/* Do Nothing */
			}
		
	}
	
}





int main()
{

	
	
	Motion_Command = Motion_App_Configrations.Motion_Command;
	
	GPIO_voidInit();
	PWM_voidInit();
	CAN_voidInit();
	
	//PWM_voidDuty_Cycle(PWM_TIMER_2 ,PWM_CHANNEL_1 ,0);
	PWM_voidTIM_ENABLE(PWM_TIMER_2);
	
	CAN_voidConfigFilter(Filter_0 , CAN_FilterMode_IdList , CAN_FilterScale_32bit , Motion_Command[0].Command_Id , Default_Command_Id , CAN_FilterFIFO0);
	CAN_voidConfigFilter(Filter_1 , CAN_FilterMode_IdList , CAN_FilterScale_32bit , Motion_Command[1].Command_Id , Default_Command_Id , CAN_FilterFIFO0);
	CAN_voidConfigFilter(Filter_2 , CAN_FilterMode_IdList , CAN_FilterScale_32bit , Motion_Command[2].Command_Id , Default_Command_Id , CAN_FilterFIFO0);
	
	CAN_voidInterruptEnable();
	CAN_FIFO_0_FMP_IRQ(Fifo_0_Int);
	

	while(1);
}

