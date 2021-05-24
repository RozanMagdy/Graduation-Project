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
  
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PWM_H
#define __PWM_H

/* Includes ------------------------------------------------------------------*/
/*============*/

#include "stm32f10x.h"                  // Device header
#include "Pwm_Cfg.h"


/** @(STM32F10x.h)
  * @@brief 			StdPeriph_Driver
  */


/** @(PWM_conf.h) 
  * @brief 				this file that contains configrations of PWM Driver 
  */

// to choose which timer and channel you want to use
#define 	PWM_INIT						1
#define 	PWM_UNINIT					2


/* PWM_FREQUENCY   -------------------------------------------------*/
/*============================*/

/** check for CMS[0:1] bits in CR1	CMS_0 = 0 &&  CMS_1 = 0	,then it's edage alignment
	* frequency = ( f_clk/(ARR*PRE) )
	* if CMS_0 &&  CMS_1 any thing else then it's center alignment
	*	frequency = ( f_clk/(2*ARR*PRE) )
	*
	* f_clk = 72,000,000			DEFAULT 
	* f_clk = 8,000,000				HSI_clk
	* i.e PWM_frequency = 1,000
	*
	*	if you want to be sure that you are using HSI_clk ,write that command, 
	* RCC->CR |= RCC_CR_HSION;
	*
	*/
	
/**
	* @attention  choose PWM_AUTO_RELOAD_REGISTER with a simple number , 
	* 						to make it easy for you when you determine duty cycle
	*/
	
#define  PWM_PRESCALLER						720
#define  PWM_AUTO_RELOAD_REGISTER			100


/* GPIO PINS CONFIGRATION   -------------------------------------------------*/
/*============================*/

/** CLEAR CONFIGRATION BITS IN CRL & CRH THEN WRITE THE NEW CONFIGRATION
	* FOR ALL PWM PINS AS OUTPUT_PUSH_PULL
  */
	
/* set PWM_TIMER_2_CH_1 as OUTPUT_PUSH_PULL */ 	
#define 	PWM_TIMER_2_PORTA_PIN_0			((uint32_t)(0x0B) << 0)
/* CLEAR CONFIGRATION BITS IN CRL & CRH THEN WRITE THE NEW CONFIGRATION */
#define 	PWM_TIMER_2_RESET_PORTA_PIN_0_POSITION			((uint32_t)(0x0f) << 0)

/* set PWM_TIMER_2_CH_2 as OUTPUT_PUSH_PULL */
#define 	PWM_TIMER_2_PORTA_PIN_1			((uint32_t)(0x0B) << 4)
/* CLEAR CONFIGRATION BITS IN CRL & CRH THEN WRITE THE NEW CONFIGRATION */
#define 	PWM_TIMER_2_RESET_PORTA_PIN_1_POSITION			((uint32_t)(0x0f) << 4)

/* set PWM_TIMER_2_CH_3 as OUTPUT_PUSH_PULL */
#define 	PWM_TIMER_2_PORTA_PIN_2			((uint32_t)(0x0B) << 8)
/* CLEAR CONFIGRATION BITS IN CRL & CRH THEN WRITE THE NEW CONFIGRATION */
#define 	PWM_TIMER_2_RESET_PORTA_PIN_2_POSITION			((uint32_t)(0x0f) << 8)

/* set PWM_TIMER_2_CH_4 as OUTPUT_PUSH_PULL */
#define 	PWM_TIMER_2_PORTA_PIN_3			((uint32_t)(0x0B) << 12)
/* CLEAR CONFIGRATION BITS IN CRL & CRH THEN WRITE THE NEW CONFIGRATION */
#define 	PWM_TIMER_2_RESET_PORTA_PIN_3_POSITION		  ((uint32_t)(0x0f) << 12)



/* set PWM_TIMER_3_CH_1 as OUTPUT_PUSH_PULL */
#define 	PWM_TIMER_3_PORTA_PIN_6			((uint32_t)(0x0B) << 24)
/* CLEAR CONFIGRATION BITS IN CRL & CRH THEN WRITE THE NEW CONFIGRATION */
#define 	PWM_TIMER_3_RESET_PORTA_PIN_6_POSITION		  ((uint32_t)(0x0f) << 24)

/* set PWM_TIMER_3_CH_2 as OUTPUT_PUSH_PULL */
#define 	PWM_TIMER_3_PORTA_PIN_7			((uint32_t)(0x0B) << 28)
/* CLEAR CONFIGRATION BITS IN CRL & CRH THEN WRITE THE NEW CONFIGRATION */
#define 	PWM_TIMER_3_RESET_PORTA_PIN_7_POSITION		  ((uint32_t)(0x0f) << 28)

/* set PWM_TIMER_3_CH_3 as OUTPUT_PUSH_PULL */
#define 	PWM_TIMER_3_PORTB_PIN_0			((uint32_t)(0x0B) << 0)
/* CLEAR CONFIGRATION BITS IN CRL & CRH THEN WRITE THE NEW CONFIGRATION */
#define 	PWM_TIMER_3_RESET_PORTB_PIN_0_POSITION		  ((uint32_t)(0x0f) << 0)

/* set PWM_TIMER_3_CH_4 as OUTPUT_PUSH_PULL */
#define 	PWM_TIMER_3_PORTB_PIN_1			((uint32_t)(0x0B) << 4)
/* CLEAR CONFIGRATION BITS IN CRL & CRH THEN WRITE THE NEW CONFIGRATION */
#define 	PWM_TIMER_3_RESET_PORTB_PIN_1_POSITION		  ((uint32_t)(0x0f) << 4)



/* set PWM_TIMER_4_CH_1 as OUTPUT_PUSH_PULL */
#define 	PWM_TIMER_4_PORTB_PIN_6			((uint32_t)(0x0B) << 24)
/* CLEAR CONFIGRATION BITS IN CRL & CRH THEN WRITE THE NEW CONFIGRATION */
#define 	PWM_TIMER_4_RESET_PORTB_PIN_6_POSITION		  ((uint32_t)(0x0f) << 24)

/* set PWM_TIMER_4_CH_2 as OUTPUT_PUSH_PULL */
#define 	PWM_TIMER_4_PORTB_PIN_7			((uint32_t)(0x0B) << 28)
/* CLEAR CONFIGRATION BITS IN CRL & CRH THEN WRITE THE NEW CONFIGRATION */
#define 	PWM_TIMER_4_RESET_PORTB_PIN_7_POSITION		  ((uint32_t)(0x0f) << 28)

/* set PWM_TIMER_4_CH_3 as OUTPUT_PUSH_PULL */
#define 	PWM_TIMER_4_PORTB_PIN_8			((uint32_t)(0x0B) << 0)
/* CLEAR CONFIGRATION BITS IN CRL & CRH THEN WRITE THE NEW CONFIGRATION */
#define 	PWM_TIMER_4_RESET_PORTB_PIN_8_POSITION		  ((uint32_t)(0x0f) << 0)

/* set PWM_TIMER_4_CH_4 as OUTPUT_PUSH_PULL */
#define 	PWM_TIMER_4_PORTB_PIN_9			((uint32_t)(0x0B) << 4)
/* CLEAR CONFIGRATION BITS IN CRL & CRH THEN WRITE THE NEW CONFIGRATION */
#define 	PWM_TIMER_4_RESET_PORTB_PIN_9_POSITION		  ((uint32_t)(0x0f) << 4)



/* AVAILABLE TIMERS AND CHANNELS   ----------------------------------------------*/
/*====================================*/

/* available timers in stm32f03c8 */
#define		PWM_TIMER_2					3
#define		PWM_TIMER_3					4
#define		PWM_TIMER_4					5

			
/* Check the parameters */																		
#define IS_TIMER_SELECTION(TIMER_SELECTION)		( ( (TIMER_SELECTION) == PWM_TIMER_2 ) || \
																								( (TIMER_SELECTION) == PWM_TIMER_3 ) || \
																								( (TIMER_SELECTION) == PWM_TIMER_4 ) )


/* available channels in stm32f03c8 */
#define	PWM_CHANNEL_1					11
#define	PWM_CHANNEL_2					12
#define	PWM_CHANNEL_3					13
#define	PWM_CHANNEL_4					14


/* Check the parameters */
#define IS_CHANNEL_SELECTION(CHANNEL_SELECTION)		( ( (CHANNEL_SELECTION) == PWM_CHANNEL_1 ) || \
																										( (CHANNEL_SELECTION) == PWM_CHANNEL_2 ) || \
																										( (CHANNEL_SELECTION) == PWM_CHANNEL_3 ) || \
																										( (CHANNEL_SELECTION) == PWM_CHANNEL_4 ) )




/* FUNCTION PROTOTYPES   ------------------------------------------------------*/
/*=========================*/

// this function set configration of the selected timer and channel
/* you can select the desired timer and channel from pwm_conf.h */ 
void Pwm_Init(void);
/*............................................*/


// this functions sets duty cycle of specific channel of a specific timer
void Pwm_SetDutyCycle(uint8_t TIMER_SELECTION ,uint8_t CHANNEL_SELECTION ,uint16_t DUTY_CYCLE);
/*..............................................*/


//this function enables a specific timer.
void Pwm_Timer_Enable(uint8_t TIMER_SELECTION);
/*..............................................*/


/*****END OF FILE****/
/*     __PWM_CFG_H     */
#endif	


