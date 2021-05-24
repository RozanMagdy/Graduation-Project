/**
  ******************************************************************************
  * @file    Timer.h
  * @author  Ahmed_Khamis AUTOCAN_Embedded_team
  * @author  Ashraf_Amgad AUTOCAN_Embedded_team
	* @editor	 None
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all the functions prototypes for the Timer 
  *          firmware library.
  ******************************************************************************
	*/
  
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIMER_H
#define __TIMER_H

/* Includes ------------------------------------------------------------------*/
/*============*/

#include "stm32f10x.h"                  // Device header
#include "Timer_Cfg.h"


/** @(STM32F10x.h)
  * @@brief 			StdPeriph_Driver
  */


/** @(Timer_conf.h) 
  * @brief 				this file that contains configrations of Timer Driver 
  */

// to choose which timer and channel you want to use
#define 	TIMER_INIT					1
#define 	TIMER_UNINIT				2


/* definitions we use to enable timers in Timer_Enable(uint8_t TIMER_SELECTION) function*/
#define TIMER_2		3
#define TIMER_3		4
#define TIMER_4		5





/* FUNCTION PROTOTYPES   ------------------------------------------------------*/
/*=========================*/

// this function set configration of the selected timer and channel
/* you can select the desired timer configrations from Timer_conf.h */ 
void Timer_Init(void);
/*............................................*/



/* To enable the desired intterupt fthat you have chosen from "Timer_conf.h" */ 
void Timer_InterruptEnable(uint8_t TIMER_SELECTION);
/*............................................*/


/* To disable all of timers  interrupt */ 
void Timer_InterruptDisable(uint8_t TIMER_SELECTION);
/*............................................*/


//this function enables a specific timer.
void Timer_Enable(uint8_t TIMER_SELECTION);
/*..............................................*/


//this function disables a specific timer.
void Timer_Disable(uint8_t TIMER_SELECTION);
/*..............................................*/

//this function clears a specific timer interrupt flag.
void Timer_ClearIntFlag(uint8_t TIMER_SELECTION);
/*..............................................*/



void Timer2_IRQ( void(*TIMER_2_IRQ_FUNCTION)(void) );
/*..............................................*/
	


void Timer3_IRQ( void(*TIMER_3_IRQ_FUNCTION)(void) );
/*..............................................*/
	

void Timer4_IRQ( void(*TIMER_4_IRQ_FUNCTION)(void) );
/*..............................................*/



/*****END OF FILE****/
/*     __TIMER_H     */
#endif	


