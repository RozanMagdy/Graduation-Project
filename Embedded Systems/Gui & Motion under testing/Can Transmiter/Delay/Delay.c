/**
  ******************************************************************************
  * @file    delay.h
  * @author  Ahmed_Gamal AUTOCAN_Embedded_team_leader
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains functions definitions for the delay (systick) (system timer)
  *          firmware library.
  ******************************************************************************
	*/


/* Includes ------------------------------------------------------------------*/
/*============*/

#include "Delay.h"

/** @(Delay.h)
  * @@brief 			file contains functions prototypes of Delay driver
  */
	
	
/* FUNCTION  DEFINITION ------------------------------------------------------*/
/*=========================*/

/**
  * @brief  this function initialize System timer to give an interrupt every (1ms)
	*					desired_frequency = (SystemCoreClock / system_timer_load_value (number of ticks) )
  * @param  None
  * @retval None
  */
	
void Delay_Init(void)
{
				/* load SysTick->LOAD register with value that gives us f = 1000 HZ (1ms)*/
        SysTick_Config(SystemCoreClock / 1000);
}


/**
  * @brief  Handler routine of System timer interrupt
	*					decrease TimingDelay (delay time)
	*					when TimingDelay reaches zero that means time delay is finished
  * @param  None
  * @retval None
  */

void SysTick_Handler(void)
{
			if (TimingDelay != 0x00)
			{
							TimingDelay--;
			}
				
}



/**
  * @brief  this is the delay function that processor waits here untill the system timer (TimingDelay)
	*					reaches to zero.
  * @param  __IO uint32_t nTime
	*					__IO								 means volatile ( allows read and write operation) 
	*					uint32_t nTime 			 delay period
  * @retval None
  */

void Delay(__IO uint32_t nTime)
{
			 TimingDelay = nTime;
			 while(TimingDelay != 0);
}



/** AUTOCAN *****END OF FILE****/	

