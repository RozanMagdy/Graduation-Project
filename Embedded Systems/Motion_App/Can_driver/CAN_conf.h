/**
  ******************************************************************************
  * @file    CAN_confg.h
  * @author  Ashraf_Amgad AutoCAN_Embedded_team_member
	* @editor	 Ashraf_Amgad
  * @version V2.0
  * @date    3-Dec-2019
  * @brief   This file provides Configuration settings for CAN_peripheral.
  ****************************************************************************
	*/

/**@attention
	*							clk and gpio configrations for UART_x pins are without any remaping ,
	*							if you want to use remaping pins ,
	*							change clk and gpio configrations in Init function.
	*
	*/
	
	
/* Define to prevent recursive inclusion */
#ifndef __CAN_CONF_H_
#define	__CAN_CONF_H_


/* Enable or disable CAN_INTERRUPTs it can be CAN_INTERRUPT_ENABLE or CAN_INTERRUPT_DISABLE*/
#define CAN_FIFO_0_PENDING_MASSAGE_INTERRUPT_ENABLE						CAN_INTERRUPT_ENABLE

#define CAN_FIFO_1_PENDING_MASSAGE_INTERRUPT_ENABLE						CAN_INTERRUPT_DISABLE


// CAN_TIME_TRIGGER can be set either to DISABLE or ENABLE
#define	CAN_TIME_TRIGGER														DISABLE

// CAN_ABORT_MODE can be set either to DISABLE or ENABLE
#define	CAN_ABORT_MODE															DISABLE

// CAN_AUTO_WAKEUP can be set either to DISABLE or ENABLE
#define	CAN_AUTO_WAKEUP															DISABLE

// CAN_NON_AUTO_RETRANS can be set either to DISABLE or ENABLE
#define	CAN_NON_AUTO_RETRANS												ENABLE

// CAN_RECEIVE_FIFO_LOCKED_MODE can be set either to DISABLE or ENABLE
#define	CAN_RECEIVE_FIFO_LOCKED_MODE								DISABLE

// CAN_TRANSMIT_FIFO_PRIORITY can be set either to DISABLE or ENABLE
#define	CAN_TRANSMIT_FIFO_PRIORITY									DISABLE

// CAN_MODE can be a value of CAN_Mode_Normal ,CAN_Mode_Silent ,CAN_Mode_LoopBack or CAN_Mode_Silent_LoopBac
#define	CAN_MODE																		CAN_Mode_Normal

// CAN_RESYNCHRONIZATION_JUMP_WIDTH can be a value from CAN_SJW_1tq to CAN_SJW_4tq
#define CAN_RESYNCHRONIZATION_JUMP_WIDTH 						CAN_SJW_1tq

// CAN_BIT_SEGMENT_1 can be a value from CAN_BS1_1tq to CAN_BS1_16tq
#define CAN_BIT_SEGMENT_1														CAN_BS1_13tq

// CAN_BIT_SEGMENT_2 can be a value form CAN_BS2_1tq to CAN_BS2_8tq.
#define CAN_BIT_SEGMENT_2														CAN_BS2_2tq

// CAN_PRESCALER ranges from 1 to 1024.
#define CAN_PRESCALER																		9

/**
	* baudrate =  72,000,000 / (CAN_PRESCALER * (ts1 + ts2 + 1))
	*	baudrate =  72,000,000 / (9*(6+1+1))
	*	baudrate = 1 MHz
	*/
/** 
	* @note 
	*	it's prefered to keep the sum of CAN_BIT_SEGMENT_1 and CAN_BIT_SEGMENT_2 equal 10,
	* to facilitate the calculations.
	*/
	
	
	
/** AUTOCAN *****END OF FILE****/	
/*     __CAN_CONF_H_     */
#endif


