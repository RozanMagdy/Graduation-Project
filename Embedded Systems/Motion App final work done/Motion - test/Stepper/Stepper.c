/**
  ******************************************************************************
  * @file    Stepper.c
  * @editor	 None
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all the functions definitions for the stepper motor 
  *          firmware library.
  ******************************************************************************
	*/
	
/* Includes ------------------------------------------------------------------*/
/*============*/

#include "Stepper.h"




#define Stepper_Angle_State_1			1
#define Stepper_Angle_State_2			2
#define Stepper_Angle_State_3			3
#define Stepper_Angle_State_4			4



volatile uint32_t Stepper_Angle_counter = 0;
volatile uint32_t Stepper_Angle_counts_Value = 0;
volatile uint8_t Stepper_Angle_Status = Stepper_Angle_State_1;
volatile uint8_t Stepper_Direction = 0;







void Stepper_Init(void)
{

	Gpio_Init();
	
	Timer_Init();
	Timer_InterruptEnable(STEPPER_TIMER);
//	Timer_Enable(STEPPER_TIMER);
	
//	Timer2_IRQ(Stepper_Timer_Irq);
  Timer3_IRQ(Stepper_Timer_Irq);
}








void Stepper_SetAngle(uint8_t direction , float angle)
{
//	static int8_t Stepper_Angle = 0;
	
//	if(!Gpio_GetPinValue(GPIOB,GPIO_PIN_6))
//	{
//		if(direction == Stepper_Anti_Clk)
//			Stepper_Angle +=  angle;
//		
//		else //(direction == Stepper_Anti_Clk)
//			Stepper_Angle -=  angle;
//	}
	
//	if (Stepper_Angle < 25 && Stepper_Angle > -25)
//	{
		Stepper_Angle_counts_Value = (uint32_t)( (angle * 9000 ) / 360 );
		Stepper_Direction = direction;
	
		Stepper_Angle_counter = 0;
		Timer_Enable(STEPPER_TIMER);
//	}

}








void Stepper_Timer_Irq(void)
{

		if(Stepper_Angle_counter != Stepper_Angle_counts_Value)
		{
			switch(Stepper_Direction)
			{
					case (Stepper_Anti_Clk):	
							switch(Stepper_Angle_Status)
							{
									case (Stepper_Angle_State_1):
										/* call function to do angle state 1 */
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_1 ,GPIO_SET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_2 ,GPIO_RESET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_3 ,GPIO_RESET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_4 ,GPIO_RESET);
										Stepper_Angle_Status = Stepper_Angle_State_2;
										
									break;
									
									
									case (Stepper_Angle_State_2):
										/* call function to do angle state 2 */
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_1 ,GPIO_RESET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_2 ,GPIO_RESET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_3 ,GPIO_SET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_4 ,GPIO_RESET);
										Stepper_Angle_Status = Stepper_Angle_State_3;
									break;
									
									
									case (Stepper_Angle_State_3):
										/* call function to do angle state 3 */
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_1 ,GPIO_RESET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_2 ,GPIO_SET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_3 ,GPIO_RESET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_4 ,GPIO_RESET);
										Stepper_Angle_Status = Stepper_Angle_State_4;
									break;
									
									
									case (Stepper_Angle_State_4):
										/* call function to do angle state 4 */
												Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_1 ,GPIO_RESET);
												Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_2 ,GPIO_RESET);
												Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_3 ,GPIO_RESET);
												Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_4 ,GPIO_SET);
										Stepper_Angle_Status = Stepper_Angle_State_1;
										Stepper_Angle_counter++;
									break;
							}
					break;
							
						
							
					case (Stepper_Clk):
							switch(Stepper_Angle_Status)
							{
									case (Stepper_Angle_State_1):
										/* call function to do angle state 1 */
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_1 ,GPIO_RESET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_2 ,GPIO_RESET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_3 ,GPIO_RESET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_4 ,GPIO_SET);
										Stepper_Angle_Status = Stepper_Angle_State_2;
										
									break;
									
									
									case (Stepper_Angle_State_2):
										/* call function to do angle state 2 */
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_1 ,GPIO_RESET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_2 ,GPIO_SET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_3 ,GPIO_RESET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_4 ,GPIO_RESET);
										Stepper_Angle_Status = Stepper_Angle_State_3;
									break;
									
									
									case (Stepper_Angle_State_3):
										/* call function to do angle state 3 */
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_1 ,GPIO_RESET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_2 ,GPIO_RESET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_3 ,GPIO_SET);
											Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_4 ,GPIO_RESET);
										Stepper_Angle_Status = Stepper_Angle_State_4;
									break;
									
									
									case (Stepper_Angle_State_4):
										/* call function to do angle state 4 */
												Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_1 ,GPIO_SET);
												Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_2 ,GPIO_RESET);
												Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_3 ,GPIO_RESET);
												Gpio_SetPinValue(STEPPER_GPIO_PORT ,STEPPER_GPIO_PIN_4 ,GPIO_RESET);
										Stepper_Angle_Status = Stepper_Angle_State_1;
										Stepper_Angle_counter++;
									break;
							}
					break;
		
			}	
		
		}
		
		else
		{
			Timer_Disable(STEPPER_TIMER);
			/* Do nothing you have reached your angle keep it there */
		}		
		
			
		
	
	
}




