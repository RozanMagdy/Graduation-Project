#include "Can.h"
#include "CanIf_Cbk.h"
#include "Det.h"


static uint8 CAN_HwStatus 	= CAN_UNINIT;
static uint8 CAN_SwStatus 	= CAN_CS_UNINIT;
const Can_ControllerBaudrateConfigType 	*CAN_BaudRate_Ptr = NULL_PTR;
const CanHardwareObjectType	 *CAN_HOH_Ptr    = NULL_PTR;
//const CanHwFilterType 			 *CAN_Filter_Ptr = NULL_PTR;



#if (CAN_DEV_ERROR_DETECT == STD_ON)
	/* AUTOSAR Version checking between Det and Dio Modules */
	#if ((DET_AR_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
	 || (DET_AR_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
	 || (DET_AR_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
		#error "The AR version of Det.h does not match the expected version"
	#endif
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
	/* SW Version checking between Det and Dio Modules */
	#if ((DET_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION)\
	 || (DET_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION)\
	 || (DET_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION))
		#error "The AR version of Det.h does not match the expected version"
	#endif
#endif


/************************************************************************************
* Service Name: CAN_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): Config: Pointer to driver configuration.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the module.
************************************************************************************/
void Can_Init( const Can_ConfigType* Config )
{
	boolean error = FALSE;
	uint8 Ph_Seg1 = 0;
	
	#if (CAN_DEV_ERROR_DETECT == STD_ON)
	
		if (CAN_SwStatus != CAN_CS_UNINIT)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_INIT_SID, CAN_E_TRANSITION);
			error = TRUE;
		}
		
		if (Config == NULL_PTR)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_INIT_SID, CAN_E_PARAM_POINTER);
			error = TRUE;
		}
		
		else 
		{
			/* Do no thing */
		}
		
	#endif
		if(error == FALSE)
		{
			CAN_HwStatus = CAN_READY;
			CAN_SwStatus = CAN_CS_STOPPED;
			

//			CAN1_MCR   = (uint32)(0x00000000);
//			CAN1_MSR   = (uint32)(0x00000000);
//			CAN1_TSR   = (uint32)(0x00000000);
//			CAN1_RF0R  = (uint32)(0x00000000);
//			CAN1_RF1R  = (uint32)(0x00000000);		
//			CAN1_IER   = (uint32)(0x00000000);
//			CAN1_ESR   = (uint32)(0x00000000);
//			CAN1_BTR   = (uint32)(0x00000000);
//			CAN1_FMR   = (uint32)(0x00000000);
//			CAN1_FM1R  = (uint32)(0x00000000);
//			CAN1_FS1R  = (uint32)(0x00000000);
//			CAN1_FFA1R = (uint32)(0x00000000);
//			CAN1_FA1R  = (uint32)(0x00000000);
//			
//			CAN1_TI0R   = (uint32)(0x00000000);
//			CAN1_TDT0R  = (uint32)(0x00000000);
//			CAN1_TDL0R  = (uint32)(0x00000000);
//			CAN1_TDH0R  = (uint32)(0x00000000);
//			
//			CAN1_TI1R   = (uint32)(0x00000000);
//			CAN1_TDT1R  = (uint32)(0x00000000);
//			CAN1_TDL1R  = (uint32)(0x00000000);
//			CAN1_TDH1R  = (uint32)(0x00000000);

//			CAN1_TI2R   = (uint32)(0x00000000);
//			CAN1_TDT2R  = (uint32)(0x00000000);
//			CAN1_TDL2R  = (uint32)(0x00000000);
//			CAN1_TDH2R  = (uint32)(0x00000000);

//			CAN1_RI0R   = (uint32)(0x00000000);
//			CAN1_RDT0R  = (uint32)(0x00000000);
//			CAN1_RDL0R  = (uint32)(0x00000000);
//			CAN1_RDH0R  = (uint32)(0x00000000);	
//			
//			CAN1_RI1R   = (uint32)(0x00000000);
//			CAN1_RDT1R  = (uint32)(0x00000000);
//			CAN1_RDL1R  = (uint32)(0x00000000);
//			CAN1_RDH1R  = (uint32)(0x00000000);	



//			CAN1_F0R1  = (uint32)(0x00000000);
//			CAN1_F0R2  = (uint32)(0x00000000);
//			CAN1_F1R1  = (uint32)(0x00000000);
//			CAN1_F1R2  = (uint32)(0x00000000);		
//			CAN1_F2R1  = (uint32)(0x00000000);
//			CAN1_F2R2  = (uint32)(0x00000000);
//			CAN1_F3R1  = (uint32)(0x00000000);
//			CAN1_F3R2  = (uint32)(0x00000000);
//			CAN1_F4R1  = (uint32)(0x00000000);
//			CAN1_F4R2  = (uint32)(0x00000000);
//			CAN1_F5R1  = (uint32)(0x00000000);
//			CAN1_F5R2  = (uint32)(0x00000000);
//			CAN1_F6R1  = (uint32)(0x00000000);
//			CAN1_F6R2  = (uint32)(0x00000000);
//			CAN1_F7R1  = (uint32)(0x00000000);
//			CAN1_F7R2  = (uint32)(0x00000000);		
//			CAN1_F8R1  = (uint32)(0x00000000);
//			CAN1_F8R2  = (uint32)(0x00000000);
//			CAN1_F9R1  = (uint32)(0x00000000);
//			CAN1_F9R2  = (uint32)(0x00000000);
//			CAN1_F10R1 = (uint32)(0x00000000);
//			CAN1_F10R2 = (uint32)(0x00000000);
//			CAN1_F11R1 = (uint32)(0x00000000);
//			CAN1_F11R2 = (uint32)(0x00000000);
//			CAN1_F12R1 = (uint32)(0x00000000);
//			CAN1_F12R2 = (uint32)(0x00000000);
//			CAN1_F13R1 = (uint32)(0x00000000);
//			CAN1_F13R2 = (uint32)(0x00000000);			
//			

			/* Exit from sleep mode */
			CAN1_MCR &= ~(CAN_MCR_SLEEP);

			/* Request initialisation */
			CAN1_MCR |= (CAN_MCR_INRQ);
				
			/* Wait the acknowledge */	
			while ((CAN1_MSR & CAN_MSR_INAK) != CAN_MSR_INAK);	
			
			
			
			if (CAN_TIME_TRIGGER == STD_ENABLE)
			{
				CAN1_MCR |= (CAN_MCR_TTCM);
			}
			else
			{
				CAN1_MCR &= ~(CAN_MCR_TTCM);
			}

			/* Set the automatic bus-off management */
			if (CAN_AUTO_BUS_OFF == STD_ENABLE)
			{
				CAN1_MCR |= (CAN_MCR_ABOM);
			}
			else
			{
				CAN1_MCR &= ~(CAN_MCR_ABOM);
			}

			/* Set the automatic wake-up mode */
			if (CAN_AUTO_WAKEUP == STD_ENABLE)
			{
				CAN1_MCR |= (CAN_MCR_AWUM);
			}
			else
			{
				CAN1_MCR &= ~(CAN_MCR_AWUM);
			}

			/* Set the no automatic retransmission */
			if (CAN_NON_AUTO_RETRANS == STD_ENABLE)
			{
				CAN1_MCR |= (CAN_MCR_NART);
			}
			else
			{
				CAN1_MCR &= ~(CAN_MCR_NART);
			}

			/* Set the receive FIFO locked mode */
			if (CAN_RECEIVE_FIFO_LOCKED_MODE == STD_ENABLE)
			{
				CAN1_MCR |= (CAN_MCR_RFLM);
			}
			else
			{
				CAN1_MCR &= ~(CAN_MCR_RFLM);
			}


			/* Set the transmit FIFO priority */
			if (CAN_TRANSMIT_FIFO_PRIORITY == STD_ENABLE)
			{
				CAN1_MCR |= (CAN_MCR_TXFP);
			}
			else
			{
				CAN1_MCR &= ~(CAN_MCR_TXFP);
			}
			
			
			uint8 CAN_BaudRate_Counter = 0;
			CAN_BaudRate_Ptr = Can_Configrations.Can_ControllerBaudrateConfigSet;
			
			
							/* Normal mode */
			CAN1_BTR &= ~(CAN_BTR_SILM | CAN_BTR_LBKM);
			
			
			/* Set the bit timing register */
			for(CAN_BaudRate_Counter = 0 ; CAN_BaudRate_Counter < MAX_NUMBER_OF_SUPORTED_BAUDRATE ; CAN_BaudRate_Counter++)
			{
			
				if(CAN_BaudRate_Ptr[CAN_BaudRate_Counter].CanControllerBaudRate == CAN_CONTROLLER_DEFAULT_BAUDRATE)
				{
					
					Ph_Seg1 = CAN_BaudRate_Ptr[CAN_BaudRate_Counter].CanControllerPropSeg + CAN_BaudRate_Ptr[CAN_BaudRate_Counter].CanControllerSeg1;
					CAN1_BTR = (uint32)(0x00000000);
					CAN1_BTR |= (uint32) ( ((uint32) ((Ph_Seg1) << 16)) |\
															   ((uint32) ((CAN_BaudRate_Ptr[CAN_BaudRate_Counter].CanControllerSeg2 ) << 20)) |\
															   ((uint32) ((CAN_BaudRate_Ptr[CAN_BaudRate_Counter].CanControllerSyncJumpWidth ) << 24)) |\
															   ((uint32) ((CAN_PRESCALER - 1) << 0)) );
					
					break;
				}
				
				else
				{
						/* No action needed */
				}
				
			}
			
			/* Exit from sleep mode */
			CAN1_MCR &= ~(CAN_MCR_SLEEP);
			/* Request leave initialisation */
			CAN1_MCR &= ~(CAN_MCR_INRQ);
			
			/* Wait the acknowledge */	
			while ( (CAN1_MSR & CAN_MSR_INAK) != CAN_MSR_INAK );
		
			
			
			/*CAN_HOH_Ptr = Can_Configrations.CanHardwareObjectSet;*/
			uint8 CAN_filter_Counter = 0;
			uint8 Temp_BufferNum = 0;
			uint32 filter_number_bit_pos = 0;
			
			
		
			/* Initialisation mode for the filter */
			CAN1_FMR |= (CAN_FMR_FINIT);
			
			
			for(CAN_filter_Counter = 0 ; CAN_filter_Counter < MAX_NUMBER_OF_FILTERS ; CAN_filter_Counter++)
			{
						
					//CAN_Filter_Ptr = &(Can_Configrations.CanHwFilterSet[CAN_filter_Counter]);
				
					Temp_BufferNum = Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterNumber;
				
					filter_number_bit_pos = (uint32)(0x01 << Temp_BufferNum);
					/* Filter Deactivation */
					CAN1_FA1R &= ~((uint32)filter_number_bit_pos);
				
					if(Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterScale == CAN_FilterScale_16bit)
					{
							/* 16-bit scale for the filter */
							CAN1_FS1R &= ~(uint32)filter_number_bit_pos;
						
							/* --> check stdlib function definition for more details <-- */
							/*---------------------------------------------------------------*/
							/* First 16-bit identifier and First 16-bit mask */
						/* Or First 16-bit identifier and Second 16-bit identifier */
						CAN1->sFilterRegister[Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterNumber].FR0 = (uint32)
						( ( ( (uint32) (0x0000FFFF) & (uint32)(Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterReg2 & 0x0000FFFF) ) << 16 ) |
							( (uint32) (0x0000FFFF) & (uint32)(Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterReg1 & 0x0000FFFF) ) );

						/* Second 16-bit identifier and Second 16-bit mask */
						/* Or Third 16-bit identifier and Fourth 16-bit identifier */
						CAN1->sFilterRegister[Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterNumber].FR1 = (uint32)
						( ( (uint32) (0x0000FFFF) & (uint32)(Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterReg2 << 16 ) ) |
							( (uint32) (0x0000FFFF) & (uint32)(Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterReg1 << 16 ) ) );
					
					}
					

					else if (Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterScale == CAN_FilterScale_32bit)
					{
						/* 32-bit scale for the filter */
						CAN1_FS1R |= (uint32)filter_number_bit_pos;
						
						/* 32-bit identifier or First 32-bit identifier */
						CAN1->sFilterRegister[Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterNumber].FR0 = (uint32)
						((uint32)(0xFFF00000) & ((uint32)(Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterReg1 ) << 21));
						
						/* 32-bit mask or Second 32-bit identifier */
						CAN1->sFilterRegister[Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterNumber].FR1 = (uint32)
						((uint32)(0xFFF00000) & ((uint32)(Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterReg2 ) << 21));
					}
					else 
					{
						/* No action needed */
					} 
								

				
					/* Filter Mode */
					if (Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterMode == CAN_FilterMode_IdMask)
					{
						/*Id/Mask mode for the filter*/
						CAN1_FM1R &= ~((uint32)filter_number_bit_pos);
					}
					else if(Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterMode == CAN_FilterMode_IdList)
					{
						/*Identifier list mode for the filter*/
						CAN1->FM1R |= ((uint32)filter_number_bit_pos);
					}
					else
					{
						/* No action needed */
					}

					/* Filter FIFO assignment */
					if (Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterFiFoAssignment == CAN_Filter_FIFO0)
					{
						/* FIFO 0 assignation for the filter */
						CAN1_FFA1R &= ~((uint32)filter_number_bit_pos);
					}

					else if (Can_Configrations.CanHwFilterSet[CAN_filter_Counter].CanFilterFiFoAssignment == CAN_Filter_FIFO1)
					{
						/* FIFO 1 assignation for the filter */
						CAN1_FFA1R |= (uint32)filter_number_bit_pos;
					}
					
					else 
					{
						/* No action needed */
					} 
					
					/* Filter activation */
				CAN1_FA1R |= filter_number_bit_pos;
					
			}
			
			/* Leave the initialisation mode for the filter */
			CAN1_FMR &= ~((uint32)CAN_FMR_FINIT);

	}
		
	CAN_SwStatus = CAN_CS_STARTED;		
}

/************************************************************************************
* Service Name: Can_GetVersionInfo
* Service ID[hex]: 0x07
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo: Pointer to where to store the version information of this module.
* Return value: None
* Description: This function returns the version information of this module.
************************************************************************************/
#if (CAN_VERSION_INFO_API == STD_ON)
void Can_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
	
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
    /* Check if input pointer is not Null pointer */
    if(NULL_PTR == versioninfo)
    {
        /* Report to DET  */
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,
                        CAN_GET_VERSION_INFO_SID, CAN_E_PARAM_POINTER);
    }
    /* there is no errors */
    else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
    {
        /* Copy the vendor Id */
        versioninfo->vendorID = (uint16)CAN_VENDOR_ID;
        /* Copy the module Id */
        versioninfo->moduleID = (uint16)CAN_MODULE_ID;
        /* Copy Software Major Version */
        versioninfo->sw_major_version = (uint8)CAN_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version = (uint8)CAN_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version = (uint8)CAN_SW_PATCH_VERSION;
    }
}
#endif


/************************************************************************************
* Service Name: Can_CheckBaudrate
* Service ID[hex]: 0x0e
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Controller: CAN Controller to check for the support of a certain baudrate
					Baudrate: Baudrate to check in kbps
* Parameters (inout): None
* Parameters (out): None
* Return value: Std_ReturnType  E_OK: Baudrate supported by the CAN Controller  
								E_NOT_OK: Baudrate not supported / invalid CAN controller
* Description: This service shall check, if a certain CAN controller supports a requested baudrate.
************************************************************************************/
#if (CAN_CHANGE_BAUDRATE_SUPPORT == STD_ON)
Std_ReturnType Can_CheckBaudrate( uint8 Controller, const uint16 Baudrate )
{
	uint8 Check_BaudRate_counter = 0;
	uint8 Return_value  =0;
	boolean error; 
	//Error check
	#if (CAN_DEV_ERROR_DETECT == STD_ON)
	/* (1) check if CAN UNINIT */
		if (CAN_HwStatus == CAN_UNINIT)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_UNINIT);
			error = TRUE;
		}
		
		/* (2) check if Controller Param has invalid input */
		if (Controller > CAN_MAX_NUM_OF_CONTROLLER)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_PARAM_CONTROLLER);
			error = TRUE;
		}
		
		/* (3) check if Baudrate Param has invalid input */
		if (Baudrate > CAN_MAX_BAUDRATE)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_PARAM_BAUDRATE);
			error = TRUE;
		}	
		else 
		{
			/* Do no thing */
		}
	#endif
		
	/* check Baudrate itself */
	//ptr takes address of first element of the array of structs names Can_ControllerBaudrateConfigSet
	CAN_BaudRate_Ptr = Can_Configrations.Can_ControllerBaudrateConfigSet;  
		
	if(error == FALSE)
	{
	
		for(Check_BaudRate_counter=0;Check_BaudRate_counter<MAX_NUMBER_OF_SUPORTED_BAUDRATE;Check_BaudRate_counter++)
		{
			
			if(CAN_BaudRate_Ptr[Check_BaudRate_counter].CanControllerBaudRate == Baudrate)
			{
				Return_value= E_OK;
				break;
			}
			
			else
			{
				Return_value= E_NOT_OK;
			}
			
		}
	
	}
	else
	{
		/* No action needed */
	}
	return Return_value;
}
#endif
/************************************************************************************
* Service Name: Can_ChangeBaudrate
* Service ID[hex]: 0x0d
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Controller: CAN Controller, whose baudrate shall be changed
					Baudrate: Requested baudrate in kbps
* Parameters (inout): None
* Parameters (out): None
* Return value: Std_ReturnType  E_OK: Service request accepted, baudrate change started 
								E_NOT_OK: Service request not accepted
* Description: This service shall change the baudrate of the CAN controller.
************************************************************************************/
#if (CAN_CHANGE_BAUDRATE_SUPPORT == STD_ON)
Std_ReturnType Can_ChangeBaudrate( uint8 Controller, const uint16 Baudrate )
{
	boolean error;
	uint8 Check_BaudRate_counter = 0;
	Std_ReturnType Return_value= 0;
	
	//Error check
	#if (CAN_DEV_ERROR_DETECT == STD_ON)
	/* (1) check if CAN UNINIT */
		if (CAN_HwStatus == CAN_UNINIT)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHANGE_BAUDRATE_SID, CAN_E_UNINIT);
			error = TRUE;
		}
		
		/* (2) check if Controller Param has invalid input */
		if (Controller > CAN_MAX_NUM_OF_CONTROLLER)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHANGE_BAUDRATE_SID, CAN_E_PARAM_CONTROLLER);
			error = TRUE;
		}
		
		/* (3) check if Baudrate Param has invalid input */
		if (Baudrate > CAN_MAX_BAUDRATE)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHANGE_BAUDRATE_SID, CAN_E_PARAM_BAUDRATE);
			error = TRUE;
		}
		/* (4) check if in STOPPED state */
		if ( CAN_SwStatus != CAN_CS_STOPPED )
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHANGE_BAUDRATE_SID, CAN_E_TRANSITION);
			error = TRUE;
		}		
		else 
		{
			/* Do no thing */
		}
		
	#endif
	if (error == FALSE)
	{	
		for(Check_BaudRate_counter=0;Check_BaudRate_counter<MAX_NUMBER_OF_SUPORTED_BAUDRATE;Check_BaudRate_counter++)
		{		
			if(Can_Configrations.Can_ControllerBaudrateConfigSet[Check_BaudRate_counter].CanControllerBaudRate == Baudrate)
			{
					/* Set new Baudrate in CAN1_BTR Register
					and return E_OK			*/
					CAN1_BTR |= ( (Can_Configrations.Can_ControllerBaudrateConfigSet[Check_BaudRate_counter].CanControllerPropSeg) +
											(Can_Configrations.Can_ControllerBaudrateConfigSet[Check_BaudRate_counter].CanControllerSeg1 << 16) );
		
					CAN1_BTR |= ( (Can_Configrations.Can_ControllerBaudrateConfigSet[Check_BaudRate_counter].CanControllerSeg2 << 20) );
			
					CAN1_BTR |= ( (Can_Configrations.Can_ControllerBaudrateConfigSet[Check_BaudRate_counter].CanControllerSyncJumpWidth << 24) );
			
		  }
			
	   }
		Return_value= E_OK;				
  }
	
	else if(error == TRUE)
	{
			Return_value= E_NOT_OK;
	}
	
	return Return_value;
}
#endif
/************************************************************************************
* Service Name: Can_SetControllerMode
* Service ID[hex]: 0x03
* Sync/Async: Asynchronous
* Reentrancy: Non Reentrant
* Parameters (in): Controller: CAN controller for which the status shall be changed
					Transition: Transition value to request new CAN controller state
* Parameters (inout): None
* Parameters (out): None
* Return value: Can_ReturnType  CAN_OK: request accepted
							    CAN_NOT_OK: request not accepted, a development error occurred
* Description: This function performs software triggered state transitions of the CAN controller State machine.
************************************************************************************/
Can_ReturnType Can_SetControllerMode( uint8 Controller, Can_StateTransitionType Transition )
{
	boolean error = FALSE; 
	//Error check
	#if (CAN_DEV_ERROR_DETECT == STD_ON)
		if (CAN_HwStatus == CAN_UNINIT)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_UNINIT);
			error = TRUE;
		}
		
		if (Controller > CAN_MAX_NUM_OF_CONTROLLER)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_PARAM_CONTROLLER);
			error = TRUE;
		}
		
		else 
		{
			/* Do no thing */
		}
	#endif
		if(FALSE != error)
		{
				if((Transition == CAN_T_START) && (CAN_SwStatus != CAN_CS_STOPPED))
				{
					Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_UNINIT);
					error = TRUE;
				}
				else
				{
						/* normal mode */
						CAN1_MCR &= ~((uint32)(0x01 << 0));
					  CAN_SwStatus = CAN_CS_STARTED;
				}
				
				if((Transition == CAN_T_STOP) && ((CAN_SwStatus != CAN_CS_STOPPED) || (CAN_SwStatus != CAN_CS_STARTED)) )
				{
					Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_UNINIT);
					error = TRUE;
				}
				else
				{
						/* silent and loopback */
					 /* cancel pending massage */
					CAN1_BTR |= ((uint32)(0xC0000000));
					CAN1_TSR |= ((uint32)(0x00808080));
					 CAN_SwStatus = CAN_CS_STOPPED;
				}
				
				if((Transition == CAN_T_SLEEP) && ((CAN_SwStatus != CAN_CS_STOPPED) || (CAN_SwStatus != CAN_CS_SLEEP)) )
				{
					Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_UNINIT);
					error = TRUE;
				}
				else
				{
						/* sleep mode */
						CAN1_MCR &= ~((uint32)(0x01 << 1));
					  CAN_SwStatus = CAN_CS_SLEEP;
				}
				
				if((Transition == CAN_T_WAKEUP) && ((CAN_SwStatus != CAN_CS_STOPPED) || (CAN_SwStatus != CAN_CS_SLEEP)) )
				{
					Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_UNINIT);
					error = TRUE;
				}
				else
				{
						CAN_SwStatus = CAN_CS_STOPPED;
				}	
		
		}
		
		if(error == TRUE)
		{
			return CAN_NOT_OK;
		}
		else /*(error == FALSE)*/
		{
			return CAN_OK;
		}
			
}

/************************************************************************************
* Service Name: Can_DisableControllerInterrupts
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Controller CAN controller for which interrupts shall be disabled.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function disables all interrupts for this CAN controller.
************************************************************************************/
void Can_DisableControllerInterrupts( uint8 Controller )
{
	boolean error = FALSE;
	/*  Enable the specified CAN Controller Interrupts */
	//CANIntEnable(Global_Config->CanHardwareObjectRef[Controller].CanControllerRef->CanControllerBaseAddress,CAN_CTL_IE);
	#if (CAN_DEV_ERROR_DETECT == STD_ON)
		if (CAN_UNINIT == CAN_HwStatus)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_DISABLE_CONTROLLER_INTERRUPTS_SID, CAN_E_UNINIT);
			error = TRUE;
		}
		else 
		{
			/* Do no thing */
		}

		/*  [SWS_Can_00210] The function Can_EnableControllerInterrupts shall raise the error
		 *  CAN_E_PARAM_CONTROLLER if the parameter Controller is out of range
		 */
		if (Controller > CAN_MAX_NUM_OF_CONTROLLER)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_DISABLE_CONTROLLER_INTERRUPTS_SID, CAN_E_PARAM_CONTROLLER);
			error = TRUE;
		}
		else 
		{
			/* Do no thing */
		}
	#endif
	
		if(FALSE == error)
		{			
			switch (Controller)
			{
					case (CAN_0_ID):
						CAN1_IER = (uint32)(CAN_DISABLE_INTERUPTS);
					break;
				
					default:
					/* no action needed */
					break;
			}				
		}	
		else 
		{
			/* Do no thing */
		}
	
}


/************************************************************************************
* Service Name: Can_EnableControllerInterrupts
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Controller: CAN controller for which interrupts shall be re-enabled.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function enables all allowed interrupts.
************************************************************************************/
void Can_EnableControllerInterrupts( uint8 Controller )
{
	boolean error = FALSE;
	
	//PROTECTION MUST BE HANDLES 
		/*  Enable the specified CAN Controller Interrupts */
		//CANIntEnable(Global_Config->CanHardwareObjectRef[Controller].CanControllerRef->CanControllerBaseAddress,CAN_CTL_IE);
	#if (CAN_DEV_ERROR_DETECT == STD_ON)
		if (CAN_UNINIT == CAN_HwStatus)
		{
			 Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_ENABLE_CONTROLLER_INTERRUPTS_SID, CAN_E_UNINIT);
			 error = TRUE;
		}
		else 
		{
			/* Do no thing */
		}

		/*  [SWS_Can_00210] The function Can_EnableControllerInterrupts shall raise the error
		 *  CAN_E_PARAM_CONTROLLER if the parameter Controller is out of range
		 */
		if (Controller > CAN_MAX_NUM_OF_CONTROLLER)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_ENABLE_CONTROLLER_INTERRUPTS_SID, CAN_E_PARAM_CONTROLLER);
			error = TRUE;
		}
		else 
		{
			/* Do no thing */
		}
	#endif 
	
	if(FALSE == error)
	{
		
		switch (Controller)
		{
			case CAN_0_ID:
				CAN1_IER = (uint32)(CAN_IER_FMPIE0 | CAN_IER_FMPIE1 | CAN_IER_TMEIE);
				//NVIC_EnableIRQ(USB_LP_CAN1_RX0_IRQn | CAN1_RX1_IRQn | USB_HP_CAN1_TX_IRQn);
			break;
			
			default:
					/* no action needed */
			break;
			
		}
	
	}
	
}

/************************************************************************************
* Service Name: Can_CheckWakeup
* Service ID[hex]: 0x0b
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Controller: Controller to be checked for a wakeup.
* Parameters (inout): None
* Parameters (out): None
* Return value: Can_ReturnType CAN_OK: A wakeup was detected for the given controller. 
							   CAN_NOT_OK: No wakeup was detected for the given controller.
* Description: This function checks if a wakeup has occurred for the given controller.
************************************************************************************/
Can_ReturnType Can_CheckWakeup( uint8 Controller )
{
	boolean error = FALSE;
	Can_ReturnType CH_Wakeup = CAN_NOT_OK;
	uint32 WAIT_SLAK = SLAK_TIMEOUT;
	
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Driver is initialized before using this function */
    if (CAN_UNINIT == CAN_HwStatus)
    {
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_WAKEUP_SID, CAN_E_UNINIT);
				error = TRUE;
    }
		else 
		{
			/* Do no thing */
		}
		
		if (Controller > CAN_MAX_NUM_OF_CONTROLLER)
		{
			Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_WAKEUP_SID, CAN_E_PARAM_CONTROLLER);
			error = TRUE;
		}
		else 
		{
			/* Do no thing */
		}
#endif		
    if(error == FALSE)
    {
        switch (Controller)
				{
					case(CAN_0_ID):
						while(((CAN1_MSR & CAN_MSR_SLAK) == CAN_MSR_SLAK) && (WAIT_SLAK != 0X00))
						{
						 WAIT_SLAK--;
						}
						
						if((CAN1_MSR & CAN_MSR_SLAK) != CAN_MSR_SLAK)
						{
						 /* WAKE UP DONE : SLEEP MODE EXITED */
							CH_Wakeup = CAN_OK;
						}
			
						else
						{   
							/*wt are u doing here my man ??*/
							CH_Wakeup = CAN_NOT_OK;
						}
					break;
						
					default:
						/* Do no thing */
					break;
				}
				
			}
		
return CH_Wakeup;

}

/************************************************************************************
* Service Name: Can_Write
* Service ID[hex]: 0x06
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Hth  information which HW-transmit handle shall be used for transmit. Implicitly this is also the information about the controller to use because the Hth numbers are unique inside one hardware unit.
				   PduInfo Pointer to SDU user memory, DLC and Identifier.
* Parameters (inout): None
* Parameters (out): None
* Return value: Can_ReturnType
								CAN_OK: Write command has been accepted 
								CAN_NOT_OK: development error occurred 
								CAN_BUSY: No TX hardware buffer available or pre-emptive call of Can_Write that can't be implemented re-entrant
* Description: --
************************************************************************************/
Can_ReturnType Can_Write( Can_HwHandleType Hth, const Can_PduType* PduInfo )
{
	
	/* check errors acording to sws */
	
	
	uint8 Temp_PduInfo_DLC = 0;
	uint8 transmit_mailbox = 0;
	Can_ReturnType return_value = CAN_NOT_OK;
	
	/* Select one empty transmit mailbox */	
  if ( (CAN1_TSR & CAN_TSR_TME0) == CAN_TSR_TME0)
  {
    transmit_mailbox = 0;
  }
  else if ( (CAN1_TSR & CAN_TSR_TME1) == CAN_TSR_TME1)
  {
    transmit_mailbox = 1;
  }
  else if ( (CAN1_TSR & CAN_TSR_TME2) == CAN_TSR_TME2)
  {
    transmit_mailbox = 2;
  }
  else
  {
    transmit_mailbox = CAN_TxStatus_NoMailBox;
		return_value = CAN_BUSY;
  }

  if (transmit_mailbox != CAN_TxStatus_NoMailBox)
  {
			
		  /* this line to make sure that the massage is standard id and data frame */
			CAN1->sTxMailBox[transmit_mailbox].TIR = (uint32)(0x00000000);
		 
			CAN1->sTxMailBox[transmit_mailbox].TIR &= CAN_TIR_TXRQ;
     /* Set up the Id */
      CAN1->sTxMailBox[transmit_mailbox].TIR |= (PduInfo->id << 21);
																								

			/* Set up the DLC */
			Temp_PduInfo_DLC =( PduInfo->DLC) & (uint8)0x0000000F;
		
			CAN1->sTxMailBox[transmit_mailbox].TDTR &= ~((uint32)(Temp_PduInfo_DLC));
			CAN1->sTxMailBox[transmit_mailbox].TDTR |= Temp_PduInfo_DLC;

			/* Set up the data field */
			CAN1->sTxMailBox[transmit_mailbox].TDLR = ( ( (uint32) PduInfo->sdu[3] << 24) |
																							    ( (uint32) PduInfo->sdu[2] << 16) |
																							    ( (uint32) PduInfo->sdu[1] << 8) |
																							    ( (uint32) PduInfo->sdu[0]) );
		
			CAN1->sTxMailBox[transmit_mailbox].TDHR = ( ( (uint32) PduInfo->sdu[7] << 24) |
																							    ( (uint32) PduInfo->sdu[6] << 16) |
                                                  ( (uint32) PduInfo->sdu[5] << 8) |
                                                  ( (uint32) PduInfo->sdu[4]) );
    /* Request transmission */
    CAN1->sTxMailBox[transmit_mailbox].TIR |= CAN_TIR_TXRQ;
		return_value = CAN_OK;
  }
	
	
  return return_value;
	
}



