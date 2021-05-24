/**
  ******************************************************************************
  * @file    Timer.c
  * @author  Ahmed_Khamis AUTOCAN_Embedded_team
  * @author  Ashraf_Amgad AUTOCAN_Embedded_team
  * @editor	 None
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all the functions definitions for the timer 
  *          firmware library.
  ******************************************************************************
	*/
	
/* Includes ------------------------------------------------------------------*/
/*============*/

#include "Timer.h"


/** @(Timer.h) 
  * @brief 			file that contains functions prototypes of Timer Driver 
  */
	



/** 
	*		 global pointers to functions ,
	*		 point to the handler function of a specific timer interrupt line 
	*/
	
	
/* pointer to function points to the handler function of Timer 2 */	
void(*TIMER_2_IRQ_TEMP_FUNCTION)(void) = 0;

/* pointer to function points to the handler function of Timer 3 */
void(*TIMER_3_IRQ_TEMP_FUNCTION)(void) = 0;

/* pointer to function points to the handler function of Timer 4 */
void(*TIMER_4_IRQ_TEMP_FUNCTION)(void) = 0;



/* FUNCTION  DEFINITION ------------------------------------------------------*/
/*=========================*/

/**
  * @brief  this function configures Timers peripheral with the selected timers' configurations  from Timer_conf.h 
  * @param  None
  * @retval None
  */

/** 	
  * @attention 		
	*
	* prelaod_enable	   OCyPE bit in CCMRy	Read/Write operations access the preload register.
	*										TIMx_CCRy preload value is loaded in the active register at each update event
	*
	*	auto reload preload							ARPE bit in CR1	TIMx_ARR register is buffered.
  */
	
void Timer_Init(void)
{
	
	#if(TIMER_2_INIT == TIMER_INIT)
		/* enable clk of timer_2*/
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; 
		
		/* set auto reload prelaod and choose center alignment mode 1 */
		TIM2->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_URS);				
			
		/* set ARR */
		TIM2->ARR  = (TIMER_AUTO_RELOAD_REGISTER);
		/* set PRESCALLER */
		TIM2->PSC  = (TIMER_PRESCALLER - 1);

		/* reintialize counter register */
		TIM2->EGR |= TIM_EGR_UG;
	#endif
	
	
	
	
	
		#if(TIMER_3_INIT == TIMER_INIT)
		/* enable clk of timer_2*/
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; 
		
		/* set auto reload prelaod and choose center alignment mode 1 */
		TIM3->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_URS);				
			
		/* set ARR */
		TIM3->ARR  = (TIMER_AUTO_RELOAD_REGISTER);
		/* set PRESCALLER */
		TIM3->PSC  = (TIMER_PRESCALLER - 1);

		/* reintialize counter register */
		TIM3->EGR |= TIM_EGR_UG;
	#endif
		
		
	#if(TIMER_4_INIT == TIMER_INIT)
		/* enable clk of timer_4*/
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; 
		
		/* set auto reload prelaod and choose center alignment mode 1 */
		TIM4->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_URS);				
			
		/* set ARR */
		TIM4->ARR  = (TIMER_AUTO_RELOAD_REGISTER);
		/* set PRESCALLER */
		TIM4->PSC  = (TIMER_PRESCALLER - 1);

		/* reintialize counter register */
		TIM4->EGR |= TIM_EGR_UG;
	#endif
		
	
}




void Timer_InterruptEnable(uint8_t TIMER_SELECTION)
{
	switch(TIMER_SELECTION)
	{
		
		#if(TIMER_2_INIT == TIMER_INIT)
			case (TIMER_2):
			{
				TIM2->DIER |= (TIM_DIER_UIE);	
				/* enable timer 2 interrupt line in NVIC */
				NVIC_EnableIRQ(TIM2_IRQn);
			break;
			}
		#endif
		
			
		#if(TIMER_3_INIT == TIMER_INIT)
			case (TIMER_3):
			{
				TIM3->DIER |= (TIM_DIER_UIE);	
				/* enable timer 3 interrupt line in NVIC */
				NVIC_EnableIRQ(TIM3_IRQn);	
			break;
			}
		#endif
			
		#if(TIMER_4_INIT == TIMER_INIT)
			case (TIMER_4):
			{
				TIM4->DIER |= (TIM_DIER_UIE);	
				/* enable timer 2 interrupt line in NVIC */
				NVIC_EnableIRQ(TIM4_IRQn);	
			break;
			}
		#endif
	}			
}



void Timer_InterruptDisable(uint8_t TIMER_SELECTION)
{
	switch(TIMER_SELECTION)
	{
		
		#if(TIMER_2_INIT == TIMER_INIT)
			case (TIMER_2):
			{
				TIM2->DIER &= ~(TIM_DIER_UIE);	
				/* Disable timer 2 interrupt line in NVIC */
				NVIC_DisableIRQ(TIM2_IRQn);
			break;
			}
		#endif
		
			
		#if(TIMER_3_INIT == TIMER_INIT)
			case (TIMER_3):
			{
				TIM3->DIER &= ~(TIM_DIER_UIE);	
				/* Disable timer 3 interrupt line in NVIC */
				NVIC_DisableIRQ(TIM3_IRQn);	
			break;
			}
		#endif
			
		#if(TIMER_4_INIT == TIMER_INIT)
			case (TIMER_4):
			{
				TIM4->DIER &= ~(TIM_DIER_UIE);	
				/* Disable timer 2 interrupt line in NVIC */
				NVIC_DisableIRQ(TIM4_IRQn);	
			break;
			}
		#endif
	}
}





/**
  * @brief  this function clears a line interrupt flag 
	*					 
  * @param  LINE_NUMBER  	it's the line you want to clear its flag
	*						i.e					EXTI_LINE_0 ,EXTI_LINE_1 ,EXTI_LINE_2 ......EXTI_LINE_4
	*
  * @retval None
  */



void Timer_ClearIntFlag(uint8_t TIMER_SELECTION)
{
	switch(TIMER_SELECTION)
	{
		
		#if(TIMER_2_INIT == TIMER_INIT)
			case (TIMER_2):
			{
				TIM2->SR &= ~(TIM_SR_UIF);	
			break;
			}
		#endif
		
			
		#if(TIMER_3_INIT == TIMER_INIT)
			case (TIMER_3):
			{
				TIM3->SR &= ~(TIM_SR_UIF);
			break;
			}
		#endif
			
		#if(TIMER_4_INIT == TIMER_INIT)
			case (TIMER_4):
			{
				TIM4->SR &= ~(TIM_SR_UIF);
			break;
			}
		#endif
	}
}




/**
  * @brief  this function enables timer 
  * @param  uint8_t TIMER_SELECTION
	*																timer that you want to enable
	*														i.e		TIMER_2 ,TIMER_3 and TIMER_4
  * @retval None
  */

/** 	
  * @attention 		don't forget to activate the desired timers and channels from pwm_confg.h.
	*					
  */

void Timer_Enable(uint8_t TIMER_SELECTION)
{
	
	switch(TIMER_SELECTION)
	{
		
			#if(TIMER_2_INIT == TIMER_INIT)
				case (TIMER_2):
				{
					/* enable the counter of timer 2*/
					TIM2->CR1 |= TIM_CR1_CEN;	
					break;
				}
			#endif
			
			#if(TIMER_3_INIT == TIMER_INIT)
				case (TIMER_3):
				{
					/* enable the counter of timer 3*/
					TIM3->CR1 |= TIM_CR1_CEN;
					break;
				}
			#endif
			
			#if(TIMER_4_INIT == TIMER_INIT)
				default: 				//		case (TIMER_4):
				{
					/* enable the counter of timer 4*/
					TIM4->CR1 |= TIM_CR1_CEN;	
					break;
				}
			#endif
	}
}




/**
  * @brief  this function disables timer 
  * @param  uint8_t TIMER_SELECTION
	*																timer that you want to disable
	*														i.e		TIMER_2 ,TIMER_3 and TIMER_4
  * @retval None
  */

/** 	
  * @attention 		don't forget to activate the desired timers and channels from pwm_confg.h.
	*					
  */

void Timer_Disable(uint8_t TIMER_SELECTION)
{
	
	switch(TIMER_SELECTION)
	{
		
			#if(TIMER_2_INIT == TIMER_INIT)
				case (TIMER_2):
				{
					/* enable the counter of timer 2*/
					TIM2->CR1 &= ~TIM_CR1_CEN;	
					break;
				}
			#endif
			
			#if(TIMER_3_INIT == TIMER_INIT)
				case (TIMER_3):
				{

					/* enable the counter of timer 3*/
					TIM3->CR1 &= ~TIM_CR1_CEN;
					break;
				}
			#endif
			
			#if(TIMER_4_INIT == TIMER_INIT)
				default: 				//		case (TIMER_4):
				{
					/* enable the counter of timer 4*/
					TIM4->CR1 &= ~TIM_CR1_CEN;	
					break;
				}
			#endif
	}
}




void Timer2_IRQ( void(*TIMER_2_IRQ_FUNCTION)(void) )
{
	/* store handler function address of line 0 in pointer to function */
	TIMER_2_IRQ_TEMP_FUNCTION = TIMER_2_IRQ_FUNCTION; 
}



void TIM2_IRQHandler()
{
	TIMER_2_IRQ_TEMP_FUNCTION();
	Timer_ClearIntFlag(TIMER_2);
}



void Timer3_IRQ( void(*TIMER_3_IRQ_FUNCTION)(void) )
{
	/* store handler function address of line 0 in pointer to function */
	TIMER_3_IRQ_TEMP_FUNCTION = TIMER_3_IRQ_FUNCTION; 
}



void TIM3_IRQHandler()
{
	TIMER_3_IRQ_TEMP_FUNCTION();
	Timer_ClearIntFlag(TIMER_3);
}



void Timer4_IRQ( void(*TIMER_4_IRQ_FUNCTION)(void) )
{
	/* store handler function address of line 0 in pointer to function */
	TIMER_4_IRQ_TEMP_FUNCTION = TIMER_4_IRQ_FUNCTION; 
}



void TIM4_IRQHandler()
{
	TIMER_4_IRQ_TEMP_FUNCTION();
	Timer_ClearIntFlag(TIMER_4);
}





/*****END OF FILE****/

