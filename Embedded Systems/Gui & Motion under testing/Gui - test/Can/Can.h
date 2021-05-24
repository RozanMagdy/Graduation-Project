/**
  ******************************************************************************
  * @file    Can.h
  * @author  Ashraf_Amgad AutoCAN_Embedded_team
	* @editor	 Ashraf_Amgad
  * @version V2.0
  * @date    3-Dec-2019
  * @brief   This file contains functions prototypes for CAN_driver.
  ****************************************************************************
	**/
	
/* Define to prevent recursive inclusion */
#ifndef __CAN_H_
#define	__CAN_H_



/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"                  // Device header 
#include "Can_Cfg.h"									// CAN_driver configuration header
#include "stm32f10x_can.h"              // Keil::Device:StdPeriph Drivers:CAN



/** @(STM32F10x.h)
  * @@brief 			StdPeriph_Driver
  */
	
	
/** @(Can_Cfg.h) 
  * @brief 				configrations of CAN driver  
  */



/* macros to enable or disable can interrupts */
#define	CAN_INTERRUPT_ENABLE		1

#define	CAN_INTERRUPT_DISABLE		0


/* FUNCTION PROTOTYPES   ------------------------------------------------------*/
/*=========================*/

/* configurations of  CAN driver */
void Can_Init(void);
/*............................................*/



/* prototype of function which configure CAN_filter */
void Can_ConfigFilter(uint8_t CAN_FILTER_NUMBER ,uint8_t CAN_FILTER_MODE ,uint8_t CAN_Filter_Scale 
	,uint16_t CAN_FILTER_ID ,uint16_t CAN_FILTER_MASK_ID ,uint16_t CAN_FILTER_FIFO_ASSIGNMENT);
/*............................................*/



/* prototype of function that configures CAN transmited massage */
void Can_SetTxMsg(CanTxMsg* TxMessage ,uint32_t StdId ,uint8_t RTR ,uint8_t DLC ,uint8_t* Data);
/*............................................*/



/**
	*	@attention  CAN_voidGetFilterIndex() function needs a test.
	*	
  */
/* prototype of function that return filter index */
uint8_t Can_GetFilterIndex(uint8_t CAN_FilterFIFO);
/*............................................*/



/* enable CAN interrupts */
void Can_InterruptEnable(void);
/*............................................*/


/* handler function of FIFO_0 massage pending for the user  */
void Can_FIFO_0_FMP_IRQ(void(*CAN_FIFO_0_FMP_IRQ_FUNCTION)(void));
/*............................................*/

	
/* handler function of FIFO_1 massage pending for the user */
void Can_FIFO_1_FMP_IRQ(void(*CAN_FIFO_1_FMP_IRQ_FUNCTION)(void));
/*............................................*/	

/** AUTOCAN *****END OF FILE****/	
/*     __CAN_H_     */
#endif
