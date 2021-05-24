/**
  ******************************************************************************
  * @file    DC_Motor_Cfg.h
  * @editor	 None
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all configrations For DC_Motor firmware library.
  ******************************************************************************
  */
  
  
  	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DC_MOTOR_H
#define __DC_MOTOR_H

/* Includes ------------------------------------------------------------------*/
/*============*/


#include "stm32f10x.h"                  // Device header
#include "DC_Motor_Cfg.h"
#include "../Pwm/Pwm.h"
#include "../Gpio/Gpio.h"





#define DCMotor_Forward					(1U)
#define DCMotor_Backward				(2U)






void DCMotor_Init(void);
/*..............................................*/



void DCMotor_SetSpeed(uint8_t 	Direction , uint8_t	Speed);
/*..............................................*/






#endif




