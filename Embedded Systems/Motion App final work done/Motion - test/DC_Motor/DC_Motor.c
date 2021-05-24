#include "DC_Motor.h"



void DCMotor_Init(void)
{

	Gpio_Init();
	
	Pwm_Init();
	Pwm_SetDutyCycle(DCMotor_Timer ,DCMotor_Timer_Channel ,0);
	Pwm_Timer_Enable(DCMotor_Timer);
	
}




void DCMotor_SetSpeed(uint8_t 	Direction , uint8_t	Speed)
{
	
		switch (Direction)
		{
			case(DCMotor_Forward):
				Gpio_SetPinValue(DCMotor_Dirction_Port ,DCMotor_Dirction_Pin ,GPIO_RESET);
			break;
			
			case(DCMotor_Backward):
				Gpio_SetPinValue(DCMotor_Dirction_Port ,DCMotor_Dirction_Pin ,GPIO_SET);
			break;
			
						
		}
		Pwm_SetDutyCycle(DCMotor_Timer ,DCMotor_Timer_Channel ,Speed);

}




