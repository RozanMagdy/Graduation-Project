/**
  ******************************************************************************
  * @file    Pwm_Cfg.h
  * @author  Ahmed_Khamis AUTOCAN_Embedded_team
  * @author  Ashraf_Amgad AUTOCAN_Embedded_team
	* @editor	 None
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all configrations FOR PWM firmware library.
  ******************************************************************************
	*/
  

/**@attention
	*							clk and gpio configrations for UART_x pins are without any remaping ,
	*							if you want to use remaping pins ,
	*							change clk and gpio configrations in Init function.
	*
	*/
	

/**						 |=================|=================|=================|=================|
						 |  PWM_CHANNEL_1  |	PWM_CHANNEL_2|	PWM_CHANNEL_3  |	PWM_CHANNEL_4|  
	|====================|=================|=================|=================|=================|		
	| 	PWM_TIMER_2 	 |	PORTA---PIN0   |    PORTA---PIN1 |	PORTA---PIN2   |	PORTA---PIN3 |
	|====================|=================|=================|=================|=================|
	|	PWM_TIMER_3 	 |	PORTA---PIN6   |	PORTA---PIN7 |	PORTB---PIN0   |	PORTB---PIN1 |
	|====================|=================|=================|=================|=================|
	|	PWM_TIMER_4 	 |	PORTB---PIN6   |	PORTB---PIN7 |	PORTB---PIN8   |	PORTB---PIN9 |
	|====================|=================|=================|=================|=================|
*/
	
	
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PWM_CFG_H
#define __PWM_CFG_H


	
/* CHOOSE WHICH TIMER YOU WANT TO BE ACTIVATED  */
#define 	PWM_TIM_2_INIT			PWM_INIT
#define 	PWM_TIM_3_INIT			PWM_UNINIT
#define 	PWM_TIM_4_INIT			PWM_UNINIT



/* CHOOSE WHICH CHANNEL YOU WANT TO BE ACTIVATED */
#define 	PWM_CH_1_INIT			PWM_INIT
#define 	PWM_CH_2_INIT			PWM_UNINIT
#define 	PWM_CH_3_INIT			PWM_UNINIT
#define 	PWM_CH_4_INIT			PWM_UNINIT



/*****END OF FILE****/
/*     __PWM_CFG_H     */
#endif	
