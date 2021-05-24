/**
  ******************************************************************************
  * @file    stepper_cfg.h
  * @editor	 None
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all the configurations of the stepper motor 
  *          firmware library.
  ******************************************************************************
	*/
  
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STEPPER_CFG_H
#define __STEPPER_CFG_H

/* Includes ------------------------------------------------------------------*/
/*============*/



#define STEPPER_GPIO_PORT		(GPIOA)


#define STEPPER_GPIO_PIN_1		(GPIO_PIN_1)
#define STEPPER_GPIO_PIN_2		(GPIO_PIN_2)
#define STEPPER_GPIO_PIN_3		(GPIO_PIN_3)
#define STEPPER_GPIO_PIN_4		(GPIO_PIN_4)


/**@attention 
 *
 * make sure that timer you choose is initialized in timer driver.
 *
 ********************************************************************/
#define STEPPER_TIMER			(TIMER_2)




#endif

