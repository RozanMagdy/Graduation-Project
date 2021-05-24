/**
  ******************************************************************************
  * @file    gpio.h
  * @author  Ahmed_Mohsen AUTOCAN_Embedded_team
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all the functions prototypes for the GPIO 
  *          firmware library.
  ******************************************************************************
	*/
  
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H
#define __GPIO_H

/* Includes ------------------------------------------------------------------*/
/*============*/
#include "stm32f10x.h"
#include "GPIO_conf.h"
#include "Delay.h"

/** @(STM32F10x.h)
  * @@brief 			StdPeriph_Driver
  */

/** @(GPIO_conf.h) 
  * @brief 				it's a file for the user to configure port 
	*        				and pins he wants to use and the mode of each pin  		
  */ 

/** @(Delay.h) 
  * @brief 				this is a file that contain a delay function using systick timer
  * @attention 		don't forget to initialize the timer ( SysTick_voidInit() )
	*								in your main project before using delay function.  
  */


// to choose which port or pin you want to use
#define GPIO_INIT    		1
#define GPIO_UNINIT		 	0



// to choose if you want to write 1 or 0
#define GPIO_SET    		1
#define GPIO_RESET		 	0


/** its like a switch made for each pin, to turn on and off
	*	GPIO_LOW 	means output 0 
	* GPIO_HIGH means output 1 
	*/
#define GPIO_LOW 				0
#define GPIO_HIGH 			1


/* PORT NAMES   --------------------------------------------------------------*/
/*================*/
//---Also called "GPIO_TypeDef"
#define GPIO_PORTA 					GPIOA
#define GPIO_PORTB 					GPIOB
#define GPIO_PORTC 					GPIOC

//***********************************************************



/* INPUT MODES TYPES   --------------------------------------------------------*/
/*======================*/
//Analog mode
#define INPUT_ANALOG  			 					( (uint8_t) 0x00 ) 
//Floating input (reset state)
#define INPUT_FLOATING 			 					( (uint8_t) 0x01 )
//Input with pull-up / pull-down 
#define INPUT_PU_PD    			 					( (uint8_t) 0x08 )

//***********************************************************


/* OUTOUT MODES TYPES   -------------------------------------------------------*/
/*========================*/
//General purpose output push-pull
#define OUTPUT_PU_PU        						 ( (uint8_t)((0x00<<2) | OUT_SPEED) ) 
//General purpose output Open-drain
#define OUTPUT_OPEN_DRAIN    						 ( (uint8_t)((0x01<<2) | OUT_SPEED) ) 
//Alternate function output Push-pull
#define OUTPUT_AF_PU_PU      						 ( (uint8_t)((0x02<<2) | OUT_SPEED) ) 
//Alternate function output Open-drain
#define OUTPUT_AF_OPEN_DRAIN 						 ( (uint8_t)((0x03<<2) | OUT_SPEED) ) 

//***********************************************************


/* CLK ENABLING    -----------------------------------------------------------*/
/*===================*/
//bit 0 in APB2ENR register
#define GPIO_CLK_ENABLE_AF 				(RCC->APB2ENR |= (1<<0))
//bit 2 in APB2ENR register
#define GPIO_CLK_ENABLE_PORTA 		(RCC->APB2ENR |= (1<<2))
//bit 3 in APB2ENR register
#define GPIO_CLK_ENABLE_PORTB 		(RCC->APB2ENR |= (1<<3))
//bit 4 in APB2ENR register
#define GPIO_CLK_ENABLE_PORTC 		(RCC->APB2ENR |= (1<<4))

//***********************************************************


/* FUNCTION PROTOTYPES   ------------------------------------------------------*/
/*=========================*/

// this function set configrations for all pins.
void GPIO_voidInit(void);
/*............................................*/


// this functions writes either 1 or 0 on a specific pin.
	 void GPIO_voidSetPinValue( GPIO_TypeDef * GPIOx ,uint16_t PIN_NUMBER ,uint8_t state);
/*..............................................*/


//this function gets value on specific pin.
uint8_t GPIO_uint8GetPinValue( GPIO_TypeDef * GPIOx ,uint16_t PIN_NUMBER);
/*..............................................*/


// this function togle pin 13 of portc. 
void Led_Tog(uint16_t ms ,uint8_t i);
//............................................................................


/** AUTOCAN *****END OF FILE****/	
/*     __GPIO_H     */
#endif	

