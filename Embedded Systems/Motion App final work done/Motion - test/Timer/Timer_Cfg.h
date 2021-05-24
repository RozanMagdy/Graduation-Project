/**
  ******************************************************************************
  * @file    Timer_Cfg.h
  * @author  Ahmed_Khamis AUTOCAN_Embedded_team
  * @author  Ashraf_Amgad AUTOCAN_Embedded_team
  * @editor	 None
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all configrations FOR Timer firmware library.
  ******************************************************************************
  */
  
	
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIMER_CFG_H
#define __TIMER_CFG_H



#define TIMER_2_INIT  (TIMER_UNINIT)
#define TIMER_3_INIT  (TIMER_INIT)
#define TIMER_4_INIT  (TIMER_UNINIT)




/* Timer interrupt timing   -------------------------------------------------*/
/*============================*/

/** * frequency = ( f_clk/(ARR*PRE) )
	*	frequency = ( f_clk/(ARR*PRE) )
	*
	* f_clk = 72,000,000			DEFAULT 
	* f_clk = 8,000,000				HSI_clk
	* i.e Timer interrupt timing = 0.000 001 (1u)
	* frequency = 1M
	* 
	*	if you want to be sure that you are using HSI_clk ,write that command, 
	* RCC->CR |= RCC_CR_HSION;
	*
	*/
	
	
/* frequency (1M) = f_clk (72,000,000) / (24,000*3,000) */

#define  TIMER_PRESCALLER					2400
#define  TIMER_AUTO_RELOAD_REGISTER			50





/*****END OF FILE****/
/*     __TIMER_CFG_H     */
#endif	
