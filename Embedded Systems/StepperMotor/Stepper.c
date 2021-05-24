#include "Stepper.h"




uint8_t Stepper_Steps_Dir_Clk[4] = {STEPPER_STEP_1_DIR_CLK, STEPPER_STEP_2_DIR_CLK, STEPPER_STEP_3_DIR_CLK, STEPPER_STEP_4_DIR_CLK};
uint8_t Stepper_Steps_Dir_AntiClk[4] = {STEPPER_STEP_1_DIR_ANTI_CLK, STEPPER_STEP_2_DIR_ANTI_CLK, STEPPER_STEP_3_DIR_ANTI_CLK, STEPPER_STEP_4_DIR_ANTI_CLK};







void Stepper_Set_Angle(uint8_t direction , float angle)
{
	
	
	uint8_t counter = 0;
	uint8_t stepNumber = (uint8_t)(angle/STEPPER_STEP_ANGLE);  
	
	
	switch (direction)
	{
		
		case STEPPER_DIR_CLK:  
			for(counter=0; counter < stepNumber ;counter++)
			{
				
				STEPPER_PORT->BSRR &= ~(STEPPER_PINS << 16);
				STEPPER_PORT->BSRR |= Stepper_Steps_Dir_Clk[0]; 
				Delay(100000);
				
				STEPPER_PORT->BSRR &= ~(STEPPER_PINS << 16);
				STEPPER_PORT->BSRR |= Stepper_Steps_Dir_Clk[1];
				Delay(100000);	

				STEPPER_PORT->BSRR &= ~(STEPPER_PINS << 16);
				STEPPER_PORT->BSRR |= Stepper_Steps_Dir_Clk[2];
				Delay(100000);
				
				STEPPER_PORT->BSRR &= ~(STEPPER_PINS << 16);
				STEPPER_PORT->BSRR |= Stepper_Steps_Dir_Clk[3]; 
				Delay(100000);
				
			}
		break;
		
		
		case STEPPER_DIR_ANTI_CLK:  
			for(counter=0; counter < stepNumber ;counter++)
			{
				
				STEPPER_PORT->BSRR &= ~(STEPPER_PINS << 16);
				STEPPER_PORT->BSRR |= Stepper_Steps_Dir_AntiClk[0]; 
				Delay(100000);
				
				STEPPER_PORT->BSRR &= ~(STEPPER_PINS << 16);
				STEPPER_PORT->BSRR |= Stepper_Steps_Dir_AntiClk[1];
				Delay(100000);	

				STEPPER_PORT->BSRR &= ~(STEPPER_PINS << 16);
				STEPPER_PORT->BSRR |= Stepper_Steps_Dir_AntiClk[2];
				Delay(100000);
				
				STEPPER_PORT->BSRR &= ~(STEPPER_PINS << 16);
				STEPPER_PORT->BSRR |= Stepper_Steps_Dir_AntiClk[3]; 
				Delay(100000);
				
			}
		break;
		
	}
	
}


void Delay(uint32_t delay)
{

	uint32_t i = 0;
	
	for(i = 0 ;i < delay ;i++);
	
	

}
