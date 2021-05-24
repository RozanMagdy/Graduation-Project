/**
  ******************************************************************************
  * @file    CAN_int.h
  * @author  Ashraf_Amgad_AutoCAN_Embedded_team_member
	* @editor	 None
  * @version V1.0
  * @date    3-Dec-2019
  * @brief   This file contains functions prototypes for CAN_driver.
  ****************************************************************************
	**/
	
/* Define to prevent recursive inclusion */
#ifndef __CAN_INT_H_
#define	__CAN_INT_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"                  // Device header
#include "stm32f10x_can.h"              // CAN_StdPeriph_driver header 
#include "CAN_confg.h"									// CAN_driver configuration header 
#include "stm32f10x_can.h"              // Keil::Device:StdPeriph Drivers:CAN


/* Prototypes ------------------------------------------------------------------*/
/* prototype of function which configure CAN_peripheral in "CAN_confg.h" */
void CAN_voidInit(void);

/* prototype of function which configure CAN_filter in "CAN_confg.h" */
void CAN_voidConfigFilter(void);

/* prototype of function which configure CAN_filter in "CAN_confg.h" */
void CAN_voidSetTxMsg(CanTxMsg* TxMessage ,uint32_t StdId ,uint8_t RTR ,uint8_t DLC);




/** AUTOCAN *****END OF FILE****/	
#endif
