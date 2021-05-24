#include "GPIO.h"


int main()
{
	Delay_voidInit();
	GPIO_voidInit();
	
	
	while(1)
	{
		
			/* initialization of the led*/
			GPIO_voidSetPinValue(GPIOB ,GPIO_PIN_6 ,GPIO_SET);
			Led_Tog(100 ,1 ,GPIOC ,GPIO_PIN_13);
		
		
			if( GPIO_uint8GetPinValue(GPIOB ,GPIO_PIN_11) )
			{				
					Led_Tog(100 ,5 ,GPIOB ,GPIO_PIN_6);
					while( GPIO_uint8GetPinValue(GPIOB ,GPIO_PIN_11) );				
			}	
			
			
	}
	
	
}

