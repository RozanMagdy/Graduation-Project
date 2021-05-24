#include "Motion_App.h"
#include "../Pwm_driver/PWM.h"
#include "../Gpio_driver/GPIO.h"


const Motion_Commands_Type 	Motion_App_Configrations =
{
		 Stop_Command_Id	   , Stop_Command_Type ,
		 Forward_Command_Id  , Forward_Command_Type ,
		 Backword_Command_Id , Backword_Command_Type ,
};





void Motor_Speed(uint8_t 	Command_Type , uint8_t	Data)
{
	
		switch (Command_Type)
		{
			
				case Stop_Command_Type:
					GPIO_voidSetPinValue(Motor_Pin_0_PORT ,Motor_Pin_0 ,GPIO_SET);
					GPIO_voidSetPinValue(Motor_Pin_0_PORT ,Motor_Pin_1 ,GPIO_SET);
				case Forward_Command_Type:
					GPIO_voidSetPinValue(Motor_Pin_0_PORT ,Motor_Pin_0 ,GPIO_RESET);
					GPIO_voidSetPinValue(Motor_Pin_0_PORT ,Motor_Pin_1 ,GPIO_SET);
				break;
				
				
				case Backword_Command_Type:
					GPIO_voidSetPinValue(Motor_Pin_0_PORT ,Motor_Pin_0 ,GPIO_SET);
					GPIO_voidSetPinValue(Motor_Pin_0_PORT ,Motor_Pin_1 ,GPIO_RESET);	
				break;
				
				default:
					break;
						
		}
		PWM_voidDuty_Cycle(PWM_TIMER_2 ,PWM_CHANNEL_1 ,Data);

}


