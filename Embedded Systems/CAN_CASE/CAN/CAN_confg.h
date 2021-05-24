/**
  ******************************************************************************
  * @file    CAN_confg.h
  * @author  Ashraf_Amgad_AutoCAN_Embedded_team_member
	* @editor	 None
  * @version V1.0
  * @date    3-Dec-2019
  * @brief   This file provides Configuration settings for CAN_peripheral.
  ****************************************************************************
	**/
	
	
/* Define to prevent recursive inclusion */
#ifndef __CAN_CONFG_H_
#define	__CAN_CONFG_H_


/** Defines to activate CAN_peripheral configration,
	  when you choose CAN_CONFIGURATION as CAN_INITIALIZED 
	**/
#define CAN_UNINITIALIZED										  0
#define CAN_INITIALIZED			   							  1
#define CAN_CONFIGURATION							CAN_INITIALIZED



// CAN_TIME_TRIGGER can be set either to DISABLE or ENABLE
#define	CAN_TIME_TRIGGER														DISABLE

// CAN_ABORT_MODE can be set either to DISABLE or ENABLE
#define	CAN_ABORT_MODE															DISABLE

// CAN_AUTO_WAKEUP can be set either to DISABLE or ENABLE
#define	CAN_AUTO_WAKEUP															DISABLE

// CAN_NON_AUTO_RETRANS can be set either to DISABLE or ENABLE
#define	CAN_NON_AUTO_RETRANS												DISABLE

// CAN_RECEIVE_FIFO_LOCKED_MODE can be set either to DISABLE or ENABLE
#define	CAN_RECEIVE_FIFO_LOCKED_MODE								DISABLE

// CAN_TRANSMIT_FIFO_PRIORITY can be set either to DISABLE or ENABLE
#define	CAN_TRANSMIT_FIFO_PRIORITY									DISABLE

// CAN_MODE can be a value of CAN_Mode_Normal ,CAN_Mode_Silent ,CAN_Mode_LoopBack or CAN_Mode_Silent_LoopBac
#define	CAN_MODE																		CAN_Mode_Normal

// CAN_RESYNCHRONIZATION_JUMP_WIDTH can be a value from CAN_SJW_1tq to CAN_SJW_4tq
#define CAN_RESYNCHRONIZATION_JUMP_WIDTH 						CAN_SJW_3tq

// CAN_BIT_SEGMENT_1 can be a value from CAN_BS1_1tq to CAN_BS1_16tq
#define CAN_BIT_SEGMENT_1														CAN_BS1_5tq

// CAN_BIT_SEGMENT_2 can be a value form CAN_BS2_1tq to CAN_BS2_8tq.
#define CAN_BIT_SEGMENT_2														CAN_BS2_5tq

// CAN_PRESCALER ranges from 1 to 1024.
#define CAN_PRESCALER																		5

/** 
	* @note 
	*	it's prefered to keep the sum of CAN_BIT_SEGMENT_1 and CAN_BIT_SEGMENT_2 equal 10,
	* to facilitate the calculations.
	*/
	


	/**			----------------------------------			
		*****        Filter configurations       ********
	 *			----------------------------------
	 */
	
//  CAN_FILTER_NUMBER ranges from 0 to 13.	
#define CAN_FILTER_NUMBER																	0

// CAN_FILTER_MODE can be set either to CAN_FilterMode_IdMask or CAN_FilterMode_IdList.
#define CAN_FILTER_MODE 														CAN_FilterMode_IdMask

// CAN_FILTER_SCALE can be set either to CAN_FilterScale_16bit or CAN_FilterScale_32bit.
#define CAN_FILTER_SCALE 												   CAN_FilterScale_32bit

/** CAN_FILTER_ID_HIGH select the filter identification number, 
   (MSBs for a 32-bit configuration, first one for a 16-bit configuration). 
   It ranges from 0x0000 to 0xFFFF.
	*/
#define CAN_FILTER_ID_HIGH 																(0x20)	

/** CAN_FILTER_ID_LOW is used to select the filter identification number, 
   (LSBs for a 32-bit configuration, second one for a 16-bit configuration). 
   It ranges from 0x0000 to 0xFFFF. 
	*/
#define CAN_FILTER_ID_LOW 																(0x00)

/** CAN_FILTER_MASK_ID_HIGH is used to select the filter mask number or identification number,
		according to the mode (MSBs for a 32-bit configuration, first one for a 16-bit configuration).
		It ranges from 0x0000 to 0xFFFF.
	*/
#define CAN_FILTER_MASK_ID_HIGH 													(0xff)

/** CAN_FILTER_MASK_ID_LOW is used to select the filter mask number or identification number,
		according to the mode (LSBs for a 32-bit configuration, second one for a 16-bit configuration).
		It ranges from 0x0000 to 0xFFFF
	*/
#define CAN_FILTER_MASK_ID_LOW 														(0x00)


// CAN_FILTER_FIFO_ASSIGNMENT can be set either to CAN_FilterFIFO0 or CAN_FilterFIFO1.
#define CAN_FILTER_FIFO_ASSIGNMENT 									CAN_FilterFIFO0

// CAN_FILTER_ACTIVATION can be set either to ENABLE or DISABLE.
#define CAN_FILTER_ACTIVATION 											ENABLE
	
	
	
/** AUTOCAN *****END OF FILE****/	
#endif


