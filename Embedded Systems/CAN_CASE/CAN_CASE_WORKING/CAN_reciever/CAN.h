/**
  ******************************************************************************
  * @file    CAN_int.h
  * @author  Ashraf_Amgad_AutoCAN_Embedded_team_member
	* @editor	 ashraf
  * @version V2.0
  * @date    3-Dec-2019
  * @brief   This file contains functions prototypes for CAN_driver.
  ****************************************************************************
	**/
	
/* Define to prevent recursive inclusion */
#ifndef __CAN_INT_H_
#define	__CAN_INT_H_



/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"                  // Device header
#include "CAN_config.h"									// CAN_driver configuration header 
#include "stm32f10x_can.h"              // Keil::Device:StdPeriph Drivers:CAN
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC




/* Prototypes ------------------------------------------------------------------*/
/* prototype of function which configure CAN_peripheral in "CAN_confg.h" */
void CAN_voidInit(void);


/* prototype of function which configure CAN_filter in "CAN_confg.h" */
void CAN_voidConfigFilter(uint8_t CAN_FILTER_NUMBER ,uint8_t CAN_FILTER_MODE ,uint8_t CAN_Filter_Scale 
	,uint16_t CAN_FILTER_ID ,uint16_t CAN_FILTER_MASK_ID ,uint16_t CAN_FILTER_FIFO_ASSIGNMENT);


/* prototype of function which configure CAN_filter in "CAN_confg.h" */
void CAN_voidSetTxMsg(CanTxMsg* TxMessage ,uint32_t StdId ,uint8_t RTR ,uint8_t DLC ,uint8_t* Data);


uint8_t CAN_voidGetFilterIndex(uint8_t CAN_FilterFIFO);

/** AUTOCAN *****END OF FILE****/	
#endif
