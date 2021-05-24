/**
  ******************************************************************************
  * @file    Can.h
  * @author  Ashraf_Amgad AutoCAN_Embedded_team_member
	* @editor	 Ashraf_Amgad
  * @version V2.0
  * @date    3-Dec-2019
  * @brief   This file contains functions definitions for CAN_peripheral.
  ****************************************************************************
	**/
	
	
	
/* Includes ------------------------------------------------------------------*/
#include "Can.h"	
#include "stm32f10x_can.h"              // Keil::Device:StdPeriph Drivers:CAN


/** @(CAN.h)
  * @@brief 	file that contains prototypes of CAN firmware functions
  */
	
/** @(stm32f10x_can.h) 
  * @brief 				CAN StdPeriph Driver 		
  */ 	



/** 
	*		 global pointers to functions ,
	*		 point to the handler function of a specific external interrupt line 
	*/
	



/* pointer to function points to the  massage pending handler function of FIFO 0 */	
void(*CAN_FIFO_0_FMP_IRQ_TEMP_FUNCTION)(void) = 0;

/* pointer to function points to the  massage pending handler function of FIFO 1 */	
void(*CAN_FIFO_1_FMP_IRQ_TEMP_FUNCTION)(void) = 0;


/* CAN CONFIGRATIONS ------------------------------------------------------*/
/*=====================*/

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


void Can_Init(void)
{
	
	/* CLK CONFIGRATIONS ------------------------------------------------------*/
	/*=====================*/
	
	/* enable clock of CAN_peripheral */
	RCC->APB1ENR |= RCC_APB1ENR_CAN1EN;
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1 ,ENABLE);
	
	/* enable clock of CAN_peripheral Pins*/
	RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN);
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA ,ENABLE);
	
	
	/* GPIO CONFIGRATIONS ------------------------------------------------------*/
	/*=====================*/
	
	/* set PORTA_PIN_11 (CAN_RX) to input pull up/down after clear the pin posistion configrations */
	GPIOA->CRH &= ~(GPIO_CRH_CNF11 | GPIO_CRH_MODE11);
	GPIOA->CRH |= GPIO_CRH_CNF11_1;
	
	
	/* set PORTA_PIN_12 (CAN_TX) to output push pull after clear the pin posistion configrations */
	GPIOA->CRH &= ~(GPIO_CRH_CNF12 | GPIO_CRH_MODE12);
	GPIOA->CRH |= (GPIO_CRH_CNF12_1 | GPIO_CRH_MODE12);
	
	
	
	/* CAN CONFIGRATIONS ------------------------------------------------------*/
	/*=====================*/
	
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




/* FILTER CONFIGURATIONS ------------------------------------------------------*/
/*=========================*/
/**
  * @brief  Initializes the CAN Filter
	*					
	*
	* @param 	CAN_FILTER_NUMBER: 							set the filter to be initialized.
	*
	*	@param	CAN_FILTER_MODE:	 							set the mode to be initialized
	*
	*	@param	CAN_Filter_Scale:	 							set the filter scale
	*
	*	@param	CAN_FILTER_ID_HIGH:							set the Filter Id High
	*
	*	@param	CAN_FILTER_ID_LOW:							set the Filter Id low
	*
	*	@param	CAN_FILTER_MASK_ID_HIGH:				set the Filter Mask Id High
	*
	*	@param	CAN_FILTER_MASK_ID_LOW:					set the Filter Mask Id low
	*
	*	@param	CAN_FILTER_FIFO_ASSIGNMENT:			select the FIFO
	*
	*	@param	CAN_FILTER_FIFO_ASSIGNMENT:			enables or disables the filter
	* 
	* @retval	None.
  */

void Can_ConfigFilter(uint8_t CAN_FILTER_NUMBER ,uint8_t CAN_FILTER_MODE ,uint8_t CAN_Filter_Scale 
	,uint16_t CAN_FILTER_ID ,uint16_t CAN_FILTER_MASK_ID ,uint16_t CAN_FILTER_FIFO_ASSIGNMENT)
{	
	
	/* CAN_FilterInitStructure pointer to a CAN_FilterInitTypeDef structure 
		 containing the configuration information of filter */
	CAN_FilterInitTypeDef CAN_FilterInitStructure;
		
	
	//  CAN_FILTER_NUMBER ranges from 0 to 13.	
	CAN_FilterInitStructure.CAN_FilterNumber = CAN_FILTER_NUMBER;
	
	
	// CAN_FILTER_MODE can be set either to CAN_FilterMode_IdMask or CAN_FilterMode_IdList.
	CAN_FilterInitStructure.CAN_FilterMode = CAN_FILTER_MODE;
	
	
	// CAN_FILTER_SCALE can be set either to CAN_FilterScale_16bit or CAN_FilterScale_32bit.
	CAN_FilterInitStructure.CAN_FilterScale = CAN_Filter_Scale;;
	
	
	/** CAN_FILTER_ID_HIGH select the filter identification number, 
      (MSBs for a 32-bit configuration, first one for a 16-bit configuration). 
      It ranges from 0x0000 to 0xFFFF.
		*/
	CAN_FilterInitStructure.CAN_FilterIdHigh = (CAN_FILTER_ID << 5);
	
	
	/** CAN_FILTER_ID_LOW is used to select the filter identification number, 
      (LSBs for a 32-bit configuration, second one for a 16-bit configuration). 
      It ranges from 0x0000 to 0xFFFF. 
	  */
	CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
	
	
	/** CAN_FILTER_MASK_ID_HIGH is used to select the filter mask number or identification number,
		  according to the mode (MSBs for a 32-bit configuration, first one for a 16-bit configuration).
		  It ranges from 0x0000 to 0xFFFF.
	  */
	CAN_FilterInitStructure.CAN_FilterMaskIdHigh = (CAN_FILTER_MASK_ID << 5);
	
	
	/** CAN_FILTER_MASK_ID_LOW is used to select the filter mask number or identification number,
		  according to the mode (LSBs for a 32-bit configuration, second one for a 16-bit configuration).
		  It ranges from 0x0000 to 0xFFFF
	  */
	CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
	
	 
	// CAN_FILTER_FIFO_ASSIGNMENT can be set either to CAN_FilterFIFO0 or CAN_FilterFIFO1.
	CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FILTER_FIFO_ASSIGNMENT;
	
	
	// CAN_FILTER_ACTIVATION can be set either to ENABLE or DISABLE.
	CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
	
	
	// Initializes the CAN peripheral according to the specified parameters in the CAN_FilterInitStruct
	CAN_FilterInit(&CAN_FilterInitStructure);	
	
}


/* Transmited Massage configurations ------------------------------------------------------*/
/*======================================*/

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

void Can_SetTxMsg(CanTxMsg* TxMessage ,uint32_t StdId ,uint8_t RTR ,uint8_t DLC ,uint8_t* Data)
{
	
	/* Set the the standard identifier */
	TxMessage->StdId = StdId;
	
	/* Set the type of identifier for the message */
	TxMessage->IDE = CAN_ID_STD;
	
	/* Set the type of frame */
	TxMessage->RTR = RTR;
	
	/* Set the length of data */
	TxMessage->DLC = DLC;
	
	
	/* variable we use as a counter to set data */
	uint8_t i=0;
	/* Set the data according to DLC */
	while(i < DLC)
	{
		TxMessage->Data[i] = Data[i];
		i++;
	}
	
}




/**
  * @brief  the index of the filter the message stored in the mailbox passed through
	*
  * @param  CAN_FilterFIFO :  FIFO that massage passed through
	*
	* @retval	uint8_t Filter Index.
	*/

/**
	*	@attention this function needs a test.
	*	
  */

uint8_t Can_GetFilterIndex(uint8_t CAN_FilterFIFO)
{
	//uint32_t CAN_RDTR = 0;
	uint32_t temp = 0;
	switch (CAN_FilterFIFO)
	{
		case CAN_FilterFIFO0:
		{
			
			 temp = (CAN1->sFIFOMailBox[0].RDTR >> 8);
			 //CAN_RDTR = (*((volatile uint32_t *)( CAN1_BASE + 0x1b4 ))) ;
			 //temp = ((CAN_RDTR & 0x000000ff) >> 8);
			return ( temp  & 0x000000ff );
		}
		
		case CAN_FilterFIFO1:
		{
			temp = (CAN1->sFIFOMailBox[1].RDTR >> 8);
			  //CAN_RDTR = (*((volatile uint32_t *)( CAN1_BASE + 0x1c4 )));
			  //temp = ((CAN_RDTR & 0x000000ff) >> 8);
			return ( temp & 0x000000ff );
		}
		
		default :
		{
				/* do some thing */
				return 255;
		}
	
	}	
	
}


/*************************************************************/
/*************************/

/**
  * @brief  enable CAN1 interrupts accoding to the data in "CAN_conf.h"
	*
  * @param  None
	*
	* @retval	None
	*/


void Can_InterruptEnable(void)
{
	#if (CAN_FIFO_0_PENDING_MASSAGE_INTERRUPT_ENABLE	==	CAN_INTERRUPT_ENABLE)
			/* enable FIFO_0 massage pending interrupt */
			CAN1->IER |= CAN_IER_FMPIE0;
	/* enable FIFO_0 NVIC global interrupt */
	NVIC_EnableIRQ(USB_LP_CAN1_RX0_IRQn);
	#endif
	
	
	#if (CAN_FIFO_1_PENDING_MASSAGE_INTERRUPT_ENABLE	==	CAN_INTERRUPT_ENABLE)	
			/* enable FIFO_1 massage pending interrupt */
			CAN1->IER |= CAN_IER_FMPIE1;
	/* enable FIFO_1 NVIC global interrupt */
	NVIC_EnableIRQ(CAN1_RX1_IRQn);
	#endif

}



/**
  * @brief  handler function of FIFO_0 massage pending for the user 
	*
  * @param  handler function address of FIFO_0 massage pending 
	*
	* @retval	None
	*/

void Can_FIFO_0_FMP_IRQ(void(*CAN_FIFO_0_FMP_IRQ_FUNCTION)(void))
{
	/* make global pointer to function point to handler function of FIFO_0 massage pending */
	CAN_FIFO_0_FMP_IRQ_TEMP_FUNCTION = CAN_FIFO_0_FMP_IRQ_FUNCTION;

}



/**
  * @brief  handler function of FIFO_1 massage pending for the user 
	*
  * @param  handler function address of FIFO_1 massage pending 
	*
	* @retval	None
	*/

void Can_FIFO_1_FMP_IRQ(void(*CAN_FIFO_1_FMP_IRQ_FUNCTION)(void))
{
	/* make global pointer to function point to handler function of FIFO_1 massage pending */
	CAN_FIFO_1_FMP_IRQ_TEMP_FUNCTION = CAN_FIFO_1_FMP_IRQ_FUNCTION;

}



/**
  * @brief  handler function of FIFO_0
	*
  * @param  None
	*
	* @retval	None
	*/ 

void USB_LP_CAN1_RX0_IRQHandler()
{
	
		/* callback FIFO_0 pending massage */
		CAN_FIFO_0_FMP_IRQ_TEMP_FUNCTION();
		
}



/**
  * @brief  handler function of FIFO_1
	*
  * @param  None
	*
	* @retval	None
	*/

void CAN1_RX1_IRQHandler()
{
	
		/* callback FIFO_1 pending massage */
		CAN_FIFO_1_FMP_IRQ_TEMP_FUNCTION();

}




/** AUTOCAN *****END OF FILE****/	

