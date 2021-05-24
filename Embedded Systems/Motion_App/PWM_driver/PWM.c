/**
  ******************************************************************************
  * @file    pwm.h
  * @author  Ahmed_Khamis AUTOCAN_Embedded_team
  * @author  Ashraf_Amgad AUTOCAN_Embedded_team
	* @editor	 None
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all the functions prototypes for the PWM 
  *          firmware library.
  ******************************************************************************
	*/
	
/* Includes ------------------------------------------------------------------*/
/*============*/

#include "PWM.h"


/** @(PWM.h) 
  * @brief 			file that contains functions prototypes of PWM Driver 
  */
	




/* FUNCTION  DEFINITION ------------------------------------------------------*/
/*=========================*/

/**
  * @brief  this function configures pwm pins with the selected timer and channel ,
	*         from pwm_conf.h 
  * @param  None
  * @retval None
  */

/** 	
  * @attention 		we are using MODE 2 (low - false) PWM and center alignment mode
	*
	*								MODE 1 (high - false) PWM 		
	*																					PWM signal high while  (TIMx_CNT < TIMx_CCRy)
	*																					PWM signal low while (TIMx_CNT > TIMx_CCRy)
	*								MODE 2 (low - false) PWM 		
	*																					PWM signal low while  (TIMx_CNT < TIMx_CCRy)
	*																					PWM signal high while (TIMx_CNT > TIMx_CCRy)
	* 							you can control pwm modes using OCxM[0:2] bits in CCMRy
	*								pwm mode 1 -->  OCxM_0 = 0 , OCxM_1 = 1 and OCxM_2 = 1
	*								pwm mode 2 -->  OCxM_0 = 1 , OCxM_1 = 1 and OCxM_2 = 1
	*
	*								in center alignment mode counter counts up and down 
	*								you can control center alignment mode using CMS[0:1] in CR1
	*								00: Edge-aligned mode. The counter counts up or down depending on the direction bit(DIR in CR1).(DIR=0 counts_up)
	*								01: Center-aligned mode 1. Output compare interrupt flags are set when counter reaches 0; 
	*								10: Center-aligned mode 1. Output compare interrupt flags are set when counter reaches ARR;
	*								11: Center-aligned mode 1. Output compare interrupt flags are set when counter reaches 0 or ARR;
	*
	*	Fast_enable		OCxFE bit in CCMRy	to minimize the delayto active the output from 5 cycles to 3 cycles
	*								OCFE acts only if the channel is configured in PWM mode_1 or mode_2.
	*
	* prelaod_enable	   OCyPE bit in CCMRy	Read/Write operations access the preload register.
	*										TIMx_CCRy preload value is loaded in the active register at each update event
	*
	*	auto reload preload							ARPE bit in CR1	TIMx_ARR register is buffered.
  */
	
void PWM_voidInit(void)
{
	/* enable clk of AF */
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	
		#if(PWM_TIM_2_INIT == PWM_INIT)
					/* enable clk of timer_2*/
					RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; 
					/* enable clk of timer_2 channels*/
					RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
			
						#if(PWM_CH_1_INIT == PWM_INIT)
									/* configure timer_2 channel_1 as output push_pull*/
									GPIOA->CRL  &= ~(PWM_TIMER_2_RESET_PORTA_PIN_0_POSITION);
									GPIOA->CRL  |=  (PWM_TIMER_2_PORTA_PIN_0);																		// PORTA---PIN0
									/* configure timer_2 channel_1 in pwm mode_2 ,set preload_enable and fast_enable*/
									TIM2->CCMR1 |=  (TIM_CCMR1_OC1M | TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE);
									/* enable channel_1*/
									TIM2->CCER  |=   TIM_CCER_CC1E;
						#endif
		
						#if(PWM_CH_2_INIT == PWM_INIT)
									/* configure timer_2 channel_2 as output push_pull*/
									GPIOA->CRL  &= ~(PWM_TIMER_2_RESET_PORTA_PIN_1_POSITION);
									GPIOA->CRL  |=  (PWM_TIMER_2_PORTA_PIN_1);																	// PORTA---PIN1
									/* configure timer_2 channel_2 in pwm mode_2 ,set preload_enable and fast_enable*/
									TIM2->CCMR1 |=  (TIM_CCMR1_OC2M | TIM_CCMR1_OC2PE | TIM_CCMR1_OC1FE);
									/* enable channel_2*/
									TIM2->CCER  |=   TIM_CCER_CC2E;
						#endif
							
						#if(PWM_CH_3_INIT == PWM_INIT)
									/* configure timer_2 channel_3 as output push_pull*/
									GPIOA->CRL  &= ~(PWM_TIMER_2_RESET_PORTA_PIN_2_POSITION);
									GPIOA->CRL  |=  (PWM_TIMER_2_PORTA_PIN_2);																	// PORTA---PIN2
									/* configure timer_2 channel_3 in pwm mode_2 ,set preload_enable and fast_enable*/
									TIM2->CCMR2 |=  (TIM_CCMR2_OC3M |  TIM_CCMR2_OC3PE | TIM_CCMR1_OC1FE);
									/* enable channel_3*/
									TIM2->CCER  |=   TIM_CCER_CC3E;
						#endif
						
						#if(PWM_CH_4_INIT == PWM_INIT)
									/* configure timer_2 channel_4 as output push_pull*/
									GPIOA->CRL  &= ~(PWM_TIMER_2_RESET_PORTA_PIN_3_POSITION);
									GPIOA->CRL  |=  (PWM_TIMER_2_PORTA_PIN_3);																	// PORTA---PIN3
									/* configure timer_2 channel_4 in pwm mode_2 ,set preload_enable and fast_enable*/
									TIM2->CCMR2 |=  (TIM_CCMR2_OC4M | TIM_CCMR2_OC4PE | TIM_CCMR1_OC1FE);
									/* enable channel_4*/
									TIM2->CCER  |=   TIM_CCER_CC4E;
						#endif	
			
				/* set auto reload prelaod and choose center alignment mode 1 */
				TIM2->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_CMS_0);
				/* set ARR */
				TIM2->ARR  = (PWM_AUTO_RELOAD_REGISTER);
				/* set PRESCALLER */
				TIM2->PSC  = (PWM_PRESCALLER - 1);
		#endif
	
	
		#if(PWM_TIM_3_INIT == PWM_INIT)
						/* enable clk of timer_3*/
						RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; 
					
						#if(PWM_CH_1_INIT == PWM_INIT)
									/* enable clk of timer_3 channel_1*/
									RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
									/* configure timer_3 channel_1 as output push_pull*/
									GPIOA->CRL   &= ~(PWM_TIMER_3_RESET_PORTA_PIN_6_POSITION);
									GPIOA->CRL   |=  (PWM_TIMER_3_PORTA_PIN_6);																			// PORTA---PIN6
									/* configure timer_3 channel_1 in pwm mode_2 ,set preload_enable and fast_enable*/
									TIM3->CCMR1  |=  (TIM_CCMR1_OC1M |  TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE);
									/* enable channel_1*/
									TIM3->CCER   |=   TIM_CCER_CC1E;
						#endif
						
						#if(PWM_CH_2_INIT == PWM_INIT)
									/* enable clk of timer_3 channel_2*/
									RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
									/* configure timer_3 channel_2 as output push_pull*/
									GPIOA->CRL   &= ~(PWM_TIMER_3_RESET_PORTA_PIN_7_POSITION);
									GPIOA->CRL   |=  (PWM_TIMER_3_PORTA_PIN_7);																				// PORTA---PIN7
									/* configure timer_3 channel_2 in pwm mode_2 ,set preload_enable and fast_enable*/
									TIM3->CCMR1  |=  (TIM_CCMR1_OC2M | TIM_CCMR1_OC2PE | TIM_CCMR1_OC1FE);
									/* enable channel_2*/
									TIM3->CCER   |=   TIM_CCER_CC2E;
						#endif

						#if(PWM_CH_3_INIT == PWM_INIT)
									/* enable clk of timer_3 channel_3*/
									RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
									/* configure timer_3 channel_3 as output push_pull*/
									GPIOB->CRL   &= ~(PWM_TIMER_3_RESET_PORTB_PIN_0_POSITION);	
									GPIOB->CRL   |=  (PWM_TIMER_3_PORTB_PIN_0);																				// PORTB---PIN0
									/* configure timer_3 channel_3 in pwm mode_2 ,set preload_enable and fast_enable*/
									TIM3->CCMR2  |=  (TIM_CCMR2_OC3M | TIM_CCMR2_OC3PE | TIM_CCMR1_OC1FE);
									/* enable channel_3*/
									TIM3->CCER   |=   TIM_CCER_CC3E;
						#endif

						#if(PWM_CH_4_INIT == PWM_INIT)
									/* enable clk of timer_3 channel_4*/
									RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
									/* configure timer_3 channel_4 as output push_pull*/
									GPIOB->CRL   &= ~(PWM_TIMER_3_RESET_PORTB_PIN_1_POSITION);
									GPIOB->CRL   |=  (PWM_TIMER_3_PORTB_PIN_1);																				// PORTB---PIN1
									/* configure timer_3 channel_3 in pwm mode_2 ,set preload_enable and fast_enable*/									
									TIM3->CCMR2  |=  (TIM_CCMR2_OC4M | TIM_CCMR2_OC4PE | TIM_CCMR1_OC1FE);
									/* enable channel_4*/
									TIM3->CCER   |=   TIM_CCER_CC4E;
						#endif	
				
				/* set auto reload prelaod and choose center alignment mode 1 */	
				TIM3->CR1 |= ( TIM_CR1_ARPE |  TIM_CR1_CMS_0);
				/* set ARR */
				TIM3->ARR  = (uint16_t)(PWM_AUTO_RELOAD_REGISTER);
				/* set PRESCALLER */
				TIM3->PSC  = (uint16_t)(PWM_PRESCALLER - 1);	
		#endif

		#if(PWM_TIM_4_INIT == PWM_INIT)	
					/* enable clk of timer_4*/
					RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
					/* enable clk of timer_4 channels*/
					RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

						#if(PWM_CH_1_INIT == PWM_INIT)
									/* configure timer_4 channel_1 as output push_pull*/
									GPIOB->CRL  &= ~(PWM_TIMER_4_RESET_PORTB_PIN_6_POSITION);
									GPIOB->CRL  |=  (PWM_TIMER_4_PORTB_PIN_6);																			// PORTB---PIN6
									/* configure timer_4 channel_1 in pwm mode_2 ,set preload_enable and fast_enable*/
									TIM4->CCMR1 |=  (TIM_CCMR1_OC2M | TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE);
									/* enable channel_1*/
									TIM4->CCER  |=   TIM_CCER_CC1E;
						#endif
							
						#if(PWM_CH_2_INIT == PWM_INIT)
									/* configure timer_4 channel_2 as output push_pull*/
									GPIOB->CRL  &= ~(PWM_TIMER_4_RESET_PORTB_PIN_7_POSITION);
									GPIOB->CRL  |=  (PWM_TIMER_4_PORTB_PIN_7);																			// PORTB---PIN7
									/* configure timer_4 channel_2 in pwm mode_2 ,set preload_enable and fast_enable*/
									TIM4->CCMR1 |=  (TIM_CCMR1_OC2M | TIM_CCMR1_OC2PE | TIM_CCMR1_OC1FE);
									/* enable channel_2*/
									TIM4->CCER  |=   TIM_CCER_CC2E;
						#endif
						
						#if(PWM_CH_3_INIT == PWM_INIT)
									/* configure timer_4 channel_3 as output push_pull*/
									GPIOB->CRH  &= ~(PWM_TIMER_4_RESET_PORTB_PIN_8_POSITION);
									GPIOB->CRH  |=  (PWM_TIMER_4_PORTB_PIN_8);																			// PORTB---PIN8
									/* configure timer_4 channel_3 in pwm mode_2 ,set preload_enable and fast_enable*/
									TIM4->CCMR2 |=  (TIM_CCMR2_OC3M | TIM_CCMR2_OC3PE | TIM_CCMR1_OC1FE);
									/* enable channel_3*/
									TIM4->CCER  |=   TIM_CCER_CC3E;
						#endif
						
						#if(PWM_CH_4_INIT == PWM_INIT)
									/* configure timer_4 channel_4 as output push_pull*/
									GPIOB->CRH  &= ~(PWM_TIMER_4_RESET_PORTB_PIN_9_POSITION);
									GPIOB->CRH  |=  (PWM_TIMER_4_PORTB_PIN_9);																			// PORTB---PIN9
									/* configure timer_4 channel_4 in pwm mode_2 ,set preload_enable and fast_enable*/
									TIM4->CCMR2 |=  (TIM_CCMR2_OC4M | TIM_CCMR2_OC4PE | TIM_CCMR1_OC1FE);
									/* enable channel_4*/
									TIM4->CCER  |=   TIM_CCER_CC4E;
						#endif	
				
				/* set auto reload prelaod and choose center alignment mode 1 */				
				TIM4->CR1 |= ( TIM_CR1_ARPE | TIM_CR1_CMS_0);
				/* set ARR */
				TIM4->ARR  = (PWM_AUTO_RELOAD_REGISTER);
				/* set PRESCALLER */
				TIM4->PSC  = (PWM_PRESCALLER - 1);
		#endif
	
}





/**
  * @brief  this function configures duty cycle of a specific timer and channel 
  * @param  uint8_t TIMER_SELECTION
	*																	timer that you want to change duty cycle of its channel
	*														i.e		PWM_TIMER_2 ,PWM_TIMER_3 and PWM_TIMER_4
	* @param  uint8_t CHANNEL_SELECTION
	*																	channel that you want to change its duty cycle
	*														i.e		PWM_CHANNEL_1 ,PWM_CHANNEL_2 and PWM_CHANNEL_3 and PWM_CHANNEL_4
  * @retval None
  */

/** 	
  * @attention 		don't forget to activate the desired timers and channels from pwm_confg.h.
	*								don't forget to enable the desired timers ,
	*								using PWM_TIM_ENABLE(uint8_t TIMER_SELECTION).
  */


void PWM_voidDuty_Cycle(uint8_t TIMER_SELECTION ,uint8_t CHANNEL_SELECTION ,uint16_t DUTY_CYCLE)
{
	
	/* Check the parameters */
	assert_param(IS_TIMER_SELECTION(TIMER_SELECTION));
	assert_param(IS_CHANNEL_SELECTION(CHANNEL_SELECTION));
	
	
	/* in mode 2 pwm (low - false) */
	/* check mode_2 pwm inthe beginning of this file */
	DUTY_CYCLE = PWM_AUTO_RELOAD_REGISTER - DUTY_CYCLE;

	
	switch (TIMER_SELECTION)
	{
		#if(PWM_TIM_2_INIT == PWM_INIT)
			case (PWM_TIMER_2):
			{
					switch (CHANNEL_SELECTION)
					{
						#if(PWM_CH_1_INIT == PWM_INIT)
							case (PWM_CHANNEL_1):
							{
									/* CCR1 determine duty cycle of channel_1 */
									TIM2->CCR1 = DUTY_CYCLE;
								break;
							}
						#endif
		
						#if(PWM_CH_2_INIT == PWM_INIT)
							case (PWM_CHANNEL_2):
							{
									/* CCR2 determine duty cycle of channel_2 */
									TIM2->CCR2 = DUTY_CYCLE;
								break;
							}
						#endif
							
						#if(PWM_CH_3_INIT == PWM_INIT)
							case (PWM_CHANNEL_3):
							{
									/* CCR3 determine duty cycle of channel_3 */
									TIM2->CCR3 = DUTY_CYCLE;
								break;
							}
						#endif
						
						#if(PWM_CH_4_INIT == PWM_INIT)
							default : 		// (PWM_CHANNEL_4):
							{
									/* CCR4 determine duty cycle of channel_4 */
									TIM2->CCR4 = DUTY_CYCLE;
								break;
							}
						#endif	
					}
				
				break;
			}
		#endif
	
		#if(PWM_TIM_3_INIT == PWM_INIT)
			case (PWM_TIMER_3):
			{
					switch (CHANNEL_SELECTION)
					{
						#if(PWM_CH_1_INIT == PWM_INIT)
							case (PWM_CHANNEL_1):
							{
									/* CCR1 determine duty cycle of channel_1 */
									TIM3->CCR1 = DUTY_CYCLE;
								break;
							}
						#endif
						
						#if(PWM_CH_2_INIT == PWM_INIT)
							case (PWM_CHANNEL_2):
							{
									/* CCR2 determine duty cycle of channel_2 */
									TIM3->CCR2 = DUTY_CYCLE;
									break;
							}
						#endif

						#if(PWM_CH_3_INIT == PWM_INIT)
							case (PWM_CHANNEL_3):
							{	
									/* CCR3 determine duty cycle of channel_3 */
									TIM3->CCR3 = DUTY_CYCLE;
								break;
							}
						#endif

						#if(PWM_CH_4_INIT == PWM_INIT)
							default: 			// case (PWM_CHANNEL_4):
							{
									/* CCR4 determine duty cycle of channel_4 */
									TIM3->CCR4 = DUTY_CYCLE;
								break;
							}
						#endif	
					}
					
				break;
			}
		#endif

		#if(PWM_TIM_4_INIT == PWM_INIT)	
		
			default: 		// case (PWM_TIMER_4):
			{
					switch (CHANNEL_SELECTION)
					{
						#if(PWM_CH_1_INIT == PWM_INIT)
							case (PWM_CHANNEL_1):
							{
									/* CCR1 determine duty cycle of channel_1 */
									TIM4->CCR1 = DUTY_CYCLE;
								break;
							}
						#endif
							
						#if(PWM_CH_2_INIT == PWM_INIT)
							case (PWM_CHANNEL_2):
							{
									/* CCR2 determine duty cycle of channel_2 */
									TIM4->CCR2 = DUTY_CYCLE;
								break;
							}
						#endif
						
						#if(PWM_CH_3_INIT == PWM_INIT)
							case (PWM_CHANNEL_3):
							{
									/* CCR3 determine duty cycle of channel_3 */
									TIM4->CCR3 = DUTY_CYCLE;
								break;
							}
						#endif
						
						#if(PWM_CH_4_INIT == PWM_INIT)
							default: 				// (PWM_CHANNEL_4):
							{	
									/* CCR4 determine duty cycle of channel_4 */
									TIM4->CCR4 = DUTY_CYCLE;
								break;
							}
						#endif	
					}
				
				break;
			}
		#endif
	}
	
}





/**
  * @brief  this function enables timer 
  * @param  uint8_t TIMER_SELECTION
	*																	timer that you want to enable
	*														i.e		PWM_TIMER_2 ,PWM_TIMER_3 and PWM_TIMER_4
  * @retval None
  */

/** 	
  * @attention 		don't forget to activate the desired timers and channels from pwm_confg.h.
	*					
  */

void PWM_voidTIM_ENABLE(uint8_t TIMER_SELECTION)
{
	/* Check the parameters */
	assert_param(IS_TIMER_SELECTION(TIMER_SELECTION));
	
		switch(TIMER_SELECTION)
		{
			
				#if(PWM_TIM_2_INIT == PWM_INIT)
					case (PWM_TIMER_2):
					{
						  /* Re-initialize the counter of timer 2*/
							TIM2->EGR |= TIM_EGR_UG;
							/* enable the counter of timer 2*/
							TIM2->CR1 |= TIM_CR1_CEN;	
							break;
					}
				#endif
				
				#if(PWM_TIM_3_INIT == PWM_INIT)
					case (PWM_TIMER_3):
					{
							/* Re-initialize the counter of timer 3*/
							TIM3->EGR |= TIM_EGR_UG;
							/* enable the counter of timer 3*/
							TIM3->CR1 |= TIM_CR1_CEN;
							break;
					}
				#endif
				
				#if(PWM_TIM_4_INIT == PWM_INIT)
					default: 				//		case (PWM_TIMER_4):
					{
							/* Re-initialize the counter of timer 4*/
							TIM4->EGR |= TIM_EGR_UG;
							/* enable the counter of timer 4*/
							TIM4->CR1 |= TIM_CR1_CEN;	
							break;
					}
				#endif
		}
}




/*****END OF FILE****/

