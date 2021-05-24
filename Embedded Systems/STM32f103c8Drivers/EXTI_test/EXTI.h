/**
  ******************************************************************************
  * @file    exti.h
  * @author  Ashraf_Amgad AUTOCAN_Embedded_team
	* @editor	 None
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all the functions prototypes for the EXTI 
  *          firmware library.
  ******************************************************************************
	*/
  
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EXTI_H
#define __EXTI_H

/* Includes ------------------------------------------------------------------*/
/*============*/

#include "stm32f10x.h"                  // Device header
#include "EXTI_conf.h"


/** @(STM32F10x.h)
  * @@brief 			StdPeriph_Driver
  */


/** @(PWM_conf.h) 
  * @brief 				this file that contains configrations of PWM Driver 
  */
	
	
	
	
/* to choose which PIN you want to use as EXTI */
#define EXTI_INIT				1
#define EXTI_UNINIT			0


/* to choose Edage Detector */
#define EXTI_RISING_EDAGE							2
#define EXTI_FALLING_EDAGE						3
#define EXTI_RISING_FALLING_EDAGE			4



/* AVAILABLE LINES TO BE USED AS EXTI   ----------------------------------------------*/
/*========================================*/

/**
	* @attention
	*						don't change EXTI_LINE_x numbers ,
							because it's used in[ EXTI_voidClearInt(uint16_t LINE_NUMBER) ]
	*
	*/

/* EXTI_LINE_0 is connected to pin_0 of all ports */
#define EXTI_LINE_0						0

/* EXTI_LINE_1 is connected to pin_1 of all ports */
#define EXTI_LINE_1						1

/* EXTI_LINE_2 is connected to pin_2 of all ports */
#define EXTI_LINE_2						2

/* EXTI_LINE_3 is connected to pin_3 of all ports */
#define EXTI_LINE_3						3

/* EXTI_LINE_4 is connected to pin_4 of all ports */
#define EXTI_LINE_4						4




/* FUNCTION PROTOTYPES   ------------------------------------------------------*/
/*=========================*/

// this function set configration of the selected pin to be used as external interrupt
/* you can select the desired configration from EXTI_conf.h */ 
void EXTI_voidInit(void);
/*............................................*/


// this functions clear interrupt falg
void EXTI_voidClearIntFlag(uint16_t LINE_NUMBER);
/*..............................................*/


// interrupt handler routine of line 0
void EXTI0_voidIRQ( void(*EXTI0_IRQ_FUNCTION)(void) );
/*..............................................*/


// interrupt handler routine of line 1
void EXTI1_voidIRQ( void(*EXTI1_IRQ_FUNCTION)(void) );
/*..............................................*/


// interrupt handler routine of line 3
void EXTI2_voidIRQ( void(*EXTI2_IRQ_FUNCTION)(void) );
/*..............................................*/


// interrupt handler routine of line 3
void EXTI3_voidIRQ( void(*EXTI3_IRQ_FUNCTION)(void) );
/*..............................................*/


// interrupt handler routine of line 4
void EXTI4_voidIRQ( void(*EXTI4_IRQ_FUNCTION)(void) );
/*..............................................*/


/*****END OF FILE****/
/*     __EXTI_H     */
#endif	
