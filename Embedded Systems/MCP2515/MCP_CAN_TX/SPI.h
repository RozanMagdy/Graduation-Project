/**
  ******************************************************************************
  * @file    spi.h
  * @author  Ahmed_Mohamed_Gamal AUTOCAN_Embedded_team_Leader
	* @editor	 None
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all the functions prototypes for the spi 
  *          firmware library.
  ******************************************************************************
	*/
  
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPI_H
#define __SPI_H

/* Includes ------------------------------------------------------------------*/
/*============*/

#include "stm32f10x.h"                  // Device header
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "stm32f10x_spi.h"              // Keil::Device:StdPeriph Drivers:SPI
#include "SPI_conf.h"


/** @(STM32F10x.h)
  * @@brief 			StdPeriph_Driver
  */

/** @(stm32f10x_gpio.h) 
  * @brief 				this file that contains GPIO StdPeriph_Driver 
  */
	
/** @(stm32f10x_rcc.h) 
  * @brief 				this file that contains RCC StdPeriph_Driver 
  */

/** @(stm32f10x_spi.h) 
  * @brief 				this file that contains spi StdPeriph_Driver 
  */

/** @(SPI_conf.h) 
  * @brief 				this file that contains configrations of SPI Driver 
  */
	
	
	
	
/* to choose which SPI peripheral that user want to use */
#define SPI_INIT						0
#define SPI_UNINIT					1

/* to choose which SPI mode that user want to use */
#define SPI_SLAVE						2
#define SPI_MASTER					3

/* to choose if user want to use interrupts or not */
#define	SPI_INT_ENABLE			4
#define	SPI_INT_DISABLE			5

/* to choose between SPIs peripheral  */
#define SPI_1								6
#define SPI_2								7








/* FUNCTION PROTOTYPES   ------------------------------------------------------*/
/*=========================*/

// this function set configration of the selected SPI peripheral from EXTI_conf.h */ 
void SPI_voidInit(void);
/*............................................*/


// this function sends data
void SPI_voidSendData(uint8_t SPI_x ,uint8_t DATA);
/*..............................................*/


// this function recieves data
uint8_t SPI_voidRecieveData(uint8_t SPI_x);
/*..............................................*/


// callback interrupt handler routine of SPI_1 for user
void SPI_1_voidRXNE_Handler( void(*SPI_1_RXNE_HANDLER)(void) );
/*..............................................*/


// callback interrupt handler routine of SPI_2 for user
void SPI_2_voidRXNE_Handler( void(*SPI_2_RXNE_HANDLER)(void) );
/*..............................................*/

uint8_t SPI_Send_Byte(uint8_t SPI_x, uint8_t byte);

/*****END OF FILE****/
/*     __SPI_H     */
#endif	



