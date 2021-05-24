/**
  ******************************************************************************
  * @file    gpio_conf.h
  * @author  Ahmed_Mohsen AUTOCAN_Embedded_team
	* @editor	 Ashraf_Amgad AUTOCAN_Embedded_team
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all configrations for GPIO firmware driver.  
  ******************************************************************************
	*/
  
	
/** @attention 
	*							don't forget to include Delay driver ,
	*							because it's used in Led_Tog() function.
	*/
	
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_CFG_H
#define __GPIO_CFG_H


/* PORTS FROM A-C ARE USED IN STM32F103C8 uc */
/** @First 
	* Choose PORTs you will use
	*/
#define 	GPIO_A				 GPIO_INIT
#define 	GPIO_B 				 GPIO_INIT
#define 	GPIO_C 				 GPIO_INIT
#define 	AF   				 GPO_INIT


/** @Second
	* configure the desired max speed of the output pins
	*/
/** Remember :-
	*......MODE...................SPEED..*
	* ((uint8_t)0x01) 	 -->		  10 MHz	*
	*	((uint8_t)0x02) 	 -->		  2 MHz	*
	*	((uint8_t)0x03) 	 -->		  50 MHz	*
	*.....................................*
	*/
/* max speed of the output pins (50MHz) */
#define OUT_SPEED 			((uint8_t)0x03) 


/** @third 
	* choose the desired Pins to be activated from these PORTs
	* and choose theire modes
	*/
	
	
/** @attention
	* these are the provided pins in stm32f103c8
	*/
	
	
/*Remember That Modes Options are:
........In.....................Out .................. AF
INPUT_ANALOG 						  OUTPUT_PU_PU  			    OUTPUT_AF_PU_PU 
INPUT_FLOATING  					OUTTPUT_OPEN_DRAIN 		  OUTPUT_AF_OPEN_DRAIN
INPUT_PU_PD 																	  
..............................................*/


/* PORTA_PINS -------------------------------------*/
/* =============*/
#define GPIOA_PIN0		  GPIO_UNINIT
#define GPIOA_PIN0_MODE 		INPUT_FLOATING


#define GPIOA_PIN1		  GPIO_INIT
#define GPIOA_PIN1_MODE 		OUTPUT_PU_PU


#define GPIOA_PIN2		  GPIO_INIT
#define GPIOA_PIN2_MODE 		OUTPUT_PU_PU


#define GPIOA_PIN3		  GPIO_INIT
#define GPIOA_PIN3_MODE 		OUTPUT_PU_PU


#define GPIOA_PIN4		  GPIO_INIT
#define GPIOA_PIN4_MODE 		OUTPUT_PU_PU

#define GPIOA_PIN5		  GPIO_UNINIT
#define GPIOA_PIN5_MODE 		INPUT_FLOATING


#define GPIOA_PIN6			GPIO_UNINIT
#define GPIOA_PIN6_MODE 		INPUT_FLOATING


#define GPIOA_PIN7			GPIO_UNINIT
#define GPIOA_PIN7_MODE 		INPUT_FLOATING


#define GPIOA_PIN8			GPIO_UNINIT
#define GPIOA_PIN8_MODE 		INPUT_FLOATING


#define GPIOA_PIN9			GPIO_INIT
#define GPIOA_PIN9_MODE 		OUTPUT_PU_PU


#define GPIOA_PIN10			GPIO_INIT
#define GPIOA_PIN10_MODE 		OUTPUT_PU_PU


#define GPIOA_PIN11			GPIO_UNINIT
#define GPIOA_PIN11_MODE 		INPUT_FLOATING


#define GPIOA_PIN12			GPIO_UNINIT
#define GPIOA_PIN12_MODE 		INPUT_FLOATING


#define GPIOA_PIN15			GPIO_UNINIT
#define GPIOA_PIN15_MODE 		INPUT_FLOATING



/*-------------------------------------------------------------------------------*/
/* PORTB_PINS -------------------------------------*/
/* =============*/
#define GPIOB_PIN0		GPIO_INIT
#define GPIOB_PIN0_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN1		GPIO_UNINIT
#define GPIOB_PIN1_MODE 		OUTPUT_PU_PU


#define GPIOB_PIN3		GPIO_UNINIT
#define GPIOB_PIN3_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN4		GPIO_INIT
#define GPIOB_PIN4_MODE 		INPUT_FLOATING

#define GPIOB_PIN5		GPIO_INIT
#define GPIOB_PIN5_MODE 		INPUT_FLOATING

#define GPIOB_PIN6		GPIO_INIT
#define GPIOB_PIN6_MODE 		INPUT_FLOATING

#define GPIOB_PIN7		GPIO_INIT
#define GPIOB_PIN7_MODE 		INPUT_FLOATING

#define GPIOB_PIN8		GPIO_UNINIT
#define GPIOB_PIN8_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN9		GPIO_UNINIT
#define GPIOB_PIN9_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN10		GPIO_UNINIT
#define GPIOB_PIN10_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN11		GPIO_INIT
#define GPIOB_PIN11_MODE 		INPUT_FLOATING

#define GPIOB_PIN12		GPIO_UNINIT
#define GPIOB_PIN12_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN13		GPIO_INIT
#define GPIOB_PIN13_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN14		GPIO_UNINIT
#define GPIOB_PIN14_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN15		GPIO_UNINIT
#define GPIOB_PIN15_MODE 		OUTPUT_PU_PU



/*-------------------------------------------------------------------------------*/
/* PORTC_PINS -------------------------------------*/
/* =============*/

#define GPIOC_PIN13		GPIO_INIT
#define GPIOC_PIN13_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN14		GPIO_UNINIT
#define GPIOC_PIN14_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN15		GPIO_UNINIT
#define GPIOC_PIN15_MODE 		OUTPUT_PU_PU


/** AUTOCAN *****END OF FILE****/	
/*     __GPIO_CFG_H     */
#endif

