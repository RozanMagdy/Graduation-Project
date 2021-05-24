/**
  ******************************************************************************
  * @file    delay.h
  * @author  Ahmed_Gamal AUTOCAN_Embedded_team_leader
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains functions prototypes for the delay (systick) (system timer)
  *          firmware library.
  ******************************************************************************
	*/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DELAY_H
#define __DELAY_H

/* Includes ------------------------------------------------------------------*/
/*============*/

#include "stm32f10x.h"                  // Device header

/** @(STM32F10x.h)
  * @@brief 			StdPeriph_Driver
  */
	
	
	
/* FUNCTION PROTOTYPES   ------------------------------------------------------*/
/*=========================*/

/**	__IO means volatile ( allows read and write operation) 
	* static variable that contains delay period.
	*/
static __IO uint32_t TimingDelay;
/*............................................*/


// this function initialize system timer.
void SysTick_voidInit(void);
/*..............................................*/


//this is the delay function.
void Delay(__IO uint32_t nTime);
/*..............................................*/



/** AUTOCAN *****END OF FILE****/	
/*     __DELAY_H     */
#endif
