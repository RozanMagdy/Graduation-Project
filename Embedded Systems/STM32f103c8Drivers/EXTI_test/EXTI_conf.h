/**
  ******************************************************************************
  * @file    exti_conf.h
  * @author  Ashraf_Amgad AUTOCAN_Embedded_team
	* @editor	 None
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all configrations FOR EXTI firmware library.
  ******************************************************************************
	*/
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EXTI_CONF_H
#define __EXTI_CONF_H



/** CHOOSE WHICH PIN you want to use as External interrupt
	*	
	*
	* @attention  
	*						
	*						each line has an edage detector , 
	*						all pins of that line have same edage detector.
	*
	*						you can't use 2 pins in the same line ,  
	*	i.e				you can't use EXTI_PORTA_PIN_0 and EXTI_PORTB_PIN_0. 
	*/
	

/* PORTA ------------------------------------------------------------------*/
/*============*/

#define EXTI_PORTA_PIN_0						EXTI_UNINIT
#define EXTI_PORTA_PIN_1						EXTI_UNINIT
#define EXTI_PORTA_PIN_2						EXTI_UNINIT
#define EXTI_PORTA_PIN_3						EXTI_UNINIT
#define EXTI_PORTA_PIN_4						EXTI_UNINIT


/* PORTB ------------------------------------------------------------------*/
/*============*/
#define EXTI_PORTB_PIN_0						EXTI_UNINIT
#define EXTI_PORTB_PIN_1						EXTI_UNINIT
#define EXTI_PORTB_PIN_2						EXTI_UNINIT
#define EXTI_PORTB_PIN_3						EXTI_UNINIT
#define EXTI_PORTB_PIN_4						EXTI_INIT



/** CHOOSE the edge detector for desired line
	*
	*
	* @attention 
	*						 when you use rising and falling edage ,
	*						 the interrupt will be handled with the first rising edage.  
	*/
	
	
#define EXTI_LINE_0_TRIGER					EXTI_RISING_EDAGE
#define EXTI_LINE_1_TRIGER					EXTI_RISING_EDAGE
#define EXTI_LINE_2_TRIGER					EXTI_RISING_EDAGE
#define EXTI_LINE_3_TRIGER					EXTI_RISING_EDAGE
#define EXTI_LINE_4_TRIGER					EXTI_FALLING_EDAGE




/*****END OF FILE****/
/*     __EXTI_CONF_H     */
#endif	

