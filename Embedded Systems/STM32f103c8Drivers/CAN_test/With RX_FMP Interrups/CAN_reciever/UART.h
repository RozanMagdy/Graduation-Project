/**
  ******************************************************************************
  * @file    uart.h
  * @author  Omar_Hesham AUTOCAN_Embedded_team
	* @editor	 Ashraf_Amgad AUTOCAN_Embedded_team
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all the functions prototypes for the UART 
  *          firmware library.
  ******************************************************************************
	*/



/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H
#define __USART_H


/* Includes ------------------------------------------------------------------*/
/*============*/
#include "stm32f10x.h"                  // Device header
#include "UART_conf.h"

/** @attention
	*							initialization of Delay driver is in the top of UART_voidInit() function. 
	*
	*/

/** @(STM32F10x.h)
  * @@brief 			StdPeriph_Driver
  */
	
	
	
/** @(UART_conf.h) 
  * @brief 				configration file of UART driver 		
  */ 

	
	
/* we use them to choose which UART we want to configure */	
#define UART_INIT						1
#define UART_UNINIT					0


/* available UART prephirals in stm32f103c8  */	
#define UART_1							2
#define UART_2							3
#define UART_3							4



/* FUNCTION PROTOTYPES   ------------------------------------------------------*/
/*=========================*/

// this function set configrations for UART_1.
void UART_voidInit(void);
/*............................................*/


// this function sends a single char using desired UART.
void UART_voidSendChar(uint8_t UART_x, uint16_t Data);
/*............................................*/


// this functions send string using UART_1.
void UART_voidPrintString(uint8_t UART_x ,uint8_t* string);
/*..............................................*/


//this function send Hex numbers using UART_1.
void UART_voidPrintHexNumber(uint8_t UART_x ,uint16_t Hex_number);
/*..............................................*/


/** AUTOCAN *****END OF FILE****/	
/* 		__UART_	   */
#endif	

