#include "Motion_App/Motion_App.h"





int main()
{	
	Motion_App_Init();
	
	
	
	while(1)
	{
		if(Gpio_GetPinValue(GPIOB,GPIO_PIN_6))
		{
			if(Gpio_GetPinValue(GPIOB,GPIO_PIN_7))
			{
				Stepper_SetAngle(Stepper_Clk , 1);
			}
			
			else
			{
				Stepper_SetAngle(Stepper_Anti_Clk , 1);
			}	
		
		}
		
		else 
		{
		
		}
	
		
	
	}
	
	
}

