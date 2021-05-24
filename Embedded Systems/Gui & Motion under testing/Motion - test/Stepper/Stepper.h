/**
  ******************************************************************************
  * @file    Stepper.h
  * @editor	 None
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all the functions prototypes for the stepper motor 
  *          firmware library.
  ******************************************************************************
	*/
  
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STEPPER_H
#define __STEPPER_H

/* Includes ------------------------------------------------------------------*/
/*============*/


#include "stm32f10x.h"                  // Device header
#include "stepper_cfg.h"
#include "../Timer/Timer.h"
#include "../GPIO/GPIO.h"
#include "../Timer/Timer.h"





#define Stepper_Clk					(1)
#define Stepper_Anti_Clk			(2)







void Stepper_SetAngle(uint8_t direction , float angle);
/*..............................................*/



void Stepper_Init(void);
/*..............................................*/



void Stepper_Timer2_Irq(void);
/*..............................................*/


#endif
