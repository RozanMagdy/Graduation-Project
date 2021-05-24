/**
  ******************************************************************************
  * @file    CAN_prog.h
  * @author  Ashraf_Amgad_AutoCAN_Embedded_team_member
	* @editor	 None
  * @version V1.0
  * @date    3-Dec-2019
  * @brief   This file contains functions definitions for CAN_peripheral.
  ****************************************************************************
	**/
	
/* Includes ------------------------------------------------------------------*/
#include "CAN_int.h"				// CAN_driver functions prototypes header 



/**
  * @brief  Initializes the CAN peripheral according to the specified in "CAN_confg.h",
	*					with the help of std_pripheral_liberary_function:
	*					
	*					->	CAN_Init(param_1 ,param_2)
	*							  *
	*								* @brief  Initializes the CAN peripheral according to the specified
	*								*         parameters in the CAN_InitStruct.
	*								* @param_1  CANx:           where x can be 1 or 2 to to select the CAN 
	*								*                         peripheral.
	*								* @param_2  CAN_InitStruct: pointer to a CAN_InitTypeDef structure that
	*								*                         contains the configuration information for the 
	*								*                         CAN peripheral.
	*								* @retval Constant indicates initialization succeed which will be 
	*								*         CAN_InitStatus_Failed or CAN_InitStatus_Success.
	*								*
	*					
  * @param  None:  If you want to change anything you can do it in "CAN_confg.h".
	* 
	* @retval	None.
  */

#if (CAN_CONFIGURATION == CAN_INITIALIZED)

void CAN_voidInit(void)
{
	/* CAN_InitStructure pointer to a CAN_InitTypeDef structure 
	   that contains the configuration information for the CAN peripheral */
	CAN_InitTypeDef CAN_InitStructure;
	
	/* Set the time triggered communication mode */
	CAN_InitStructure.CAN_TTCM = CAN_TIME_TRIGGER;
	
	/* Set the automatic bus-off management */
	CAN_InitStructure.CAN_ABOM = CAN_ABORT_MODE;
	
	/* Set the automatic wake-up mode */
	CAN_InitStructure.CAN_AWUM = CAN_AUTO_WAKEUP;
	
	/* Set the no automatic retransmission */
	CAN_InitStructure.CAN_NART = CAN_NON_AUTO_RETRANS;
	
	/* Set the receive FIFO locked mode */
	CAN_InitStructure.CAN_RFLM = CAN_RECEIVE_FIFO_LOCKED_MODE;
	
	/* Set the transmit FIFO priority */
	CAN_InitStructure.CAN_TXFP = CAN_TRANSMIT_FIFO_PRIORITY;
	
	/* Set the operating mode */
	CAN_InitStructure.CAN_Mode = CAN_MODE;
	
	/* Set the Resynchronization Jump Width */
	CAN_InitStructure.CAN_SJW = CAN_RESYNCHRONIZATION_JUMP_WIDTH;
	
	/* Set the number of time quanta in Bit Segment 1 */
	CAN_InitStructure.CAN_BS1 = CAN_BIT_SEGMENT_1;
	
	/* Set the number of time quanta in Bit Segment 2 */
	CAN_InitStructure.CAN_BS2 = CAN_BIT_SEGMENT_2;
	
	/* Set the Prescaler */
	CAN_InitStructure.CAN_Prescaler = CAN_PRESCALER;
	
	/* pass all configurations in CAN_InitStructure structure to CAN_Init std_periph_liberary 
		to set CAN_peripheral registers value*/
	CAN_Init(CAN1 ,&CAN_InitStructure);
}


/**
  * @brief  Initializes the CAN Filter
	*					
	*
  * @param  None: If you want to change anything you can do it in "CAN_confg.h".
	* 
	* @retval	None.
  */

void CAN_voidConfigFilter(void)
{	
	// CAN_FilterInitStructure pointer to a CAN_FilterInitTypeDef structure containing the configuration information.
	CAN_FilterInitTypeDef CAN_FilterInitStructure;
		
	// set the filter to be initialized.
	CAN_FilterInitStructure.CAN_FilterNumber = 2;
	
	// set the mode to be initialized
	CAN_FilterInitStructure.CAN_FilterMode = CAN_FILTER_MODE;
	
	// set the filter scale
	CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;;
	
	// set the Filter Id High
	CAN_FilterInitStructure.CAN_FilterIdHigh = CAN_FILTER_ID_HIGH;
	
	// set the Filter Id low
	CAN_FilterInitStructure.CAN_FilterIdLow = CAN_FILTER_ID_LOW;
	
	// set the Filter Mask Id High
	CAN_FilterInitStructure.CAN_FilterMaskIdHigh = CAN_FILTER_MASK_ID_HIGH;
	
	// set the Filter Mask Id low
	CAN_FilterInitStructure.CAN_FilterMaskIdLow = CAN_FILTER_MASK_ID_LOW;
	
	// select the FIFO
	CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FILTER_FIFO_ASSIGNMENT;
	
	// enables or disables the filter
	CAN_FilterInitStructure.CAN_FilterActivation = CAN_FILTER_ACTIVATION;
	
	// Initializes the CAN peripheral according to the specified parameters in the CAN_FilterInitStruct
	CAN_FilterInit(&CAN_FilterInitStructure);	
}


/**
  * @brief  initiates the transmission of a message.
	*
  * @param  TxMessage:  pointer to a structure which contains CAN Id, CAN DLC and CAN data.
	*
	* @param  StdId: 			IDE is used to configure the type of identifier for the message that will be transmitted.
	*
	* @param  RTR: 				is used to select the type of frame for the message that will be transmitted. It can be set
	*							 				either to data frame or remote frame.
	*
	* @param	DLC: 				is used to configure the length of the frame that will be transmitted. It ranges from 0 to 0x8.
	* 
	* @retval	None.
  */

void CAN_voidSetTxMsg(CanTxMsg* TxMessage ,uint32_t StdId ,uint8_t RTR ,uint8_t DLC)
{
	/* Set the the standard identifier */
	TxMessage->StdId = StdId;
	
	/* Set the type of identifier for the message */
	TxMessage->IDE = CAN_ID_STD;
	
	/* Set the type of frame */
	TxMessage->RTR = RTR;
	
	/* Set the length of data */
	TxMessage->DLC = DLC;
}



/** AUTOCAN *****END OF FILE****/	
#endif

int main()
{
	return 0;
}
