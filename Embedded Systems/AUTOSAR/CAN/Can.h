/**
  ******************************************************************************
  *
  * @Module: CAN
  * @FileName: CAN.h
  * @Description: Header file for  CAN Module.
  * @version: 1.0.0
  * @date:    xx-xx-2020
  * @Authors: Ahmed Khamis && Ashraf Amgad && Islam Elsnousy && Toka abdelhakim
  *
  ******************************************************************************
  */

#ifndef __CAN_H__
#define __CAN_H__



#define CAN_VENDOR_ID    (1000U)
#define CAN_MODULE_ID    (120U)
#define CAN_INSTANCE_ID  (0U)

#define CAN_SW_MAJOR_VERSION 		(1U)
#define CAN_SW_MINOR_VERSION 		(0U)
#define CAN_SW_PATCH_VERSION 		(0U)

/* AUTOSAR Version 4.0.3 */
#define CAN_AR_RELEASE_MAJOR_VERSION   (4U)
#define CAN_AR_RELEASE_MINOR_VERSION   (0U)
#define CAN_AR_RELEASE_PATCH_VERSION   (3U)


/*****************************************************************************************
*                                   Include Headres                                     *
*****************************************************************************************/

#include "Can_GeneralTypes.h"
/*---------------------------------------*/
/* AUTOSAR checking between Can_GeneralTypes.h and Can.h files */
#if ((CAN_AR_RELEASE_MAJOR_VERSION != CAN_GENERAL_TYPES_AR_RELEASE_MAJOR_VERSION)\
 ||  (CAN_AR_RELEASE_MINOR_VERSION != CAN_GENERAL_TYPES_AR_RELEASE_MINOR_VERSION)\
 ||  (CAN_AR_RELEASE_PATCH_VERSION != CAN_GENERAL_TYPES_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of CAN_GeneralTypes.h does not match the expected version"
#endif


/* Software Version checking between Can_GeneralTypes.h and Can.h files */
#if  ( (CAN_SW_MAJOR_VERSION != CAN_GENERAL_TYPES_SW_MAJOR_VERSION)\
    || (CAN_SW_MINOR_VERSION != CAN_GENERAL_TYPES_SW_MINOR_VERSION)\
    || (CAN_SW_PATCH_VERSION != CAN_GENERAL_TYPES_SW_PATCH_VERSION) )
#error "The SW version of CAN_GeneralTypes.h does not match the expected version"
#endif



#include "Can_Cfg.h"
/*---------------------------------------*/
/* AUTOSAR checking between Can_cfg.h and Can.h files */
#if ((CAN_AR_RELEASE_MAJOR_VERSION != CAN_CFG_AR_RELEASE_MAJOR_VERSION)\
 ||  (CAN_AR_RELEASE_MINOR_VERSION != CAN_CFG_AR_RELEASE_MINOR_VERSION)\
 ||  (CAN_AR_RELEASE_PATCH_VERSION != CAN_CFG_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Can_cfg.h does not match the expected version"
#endif


/* Software Version checking between Can_cfg.h and Can.h files */
#if  ( (CAN_SW_MAJOR_VERSION != CAN_CFG_SW_MAJOR_VERSION)\
    || (CAN_SW_MINOR_VERSION != CAN_CFG_SW_MINOR_VERSION)\
    || (CAN_SW_PATCH_VERSION != CAN_CFG_SW_PATCH_VERSION) )
#error "The SW version of Can_cfg.h does not match the expected version"
#endif


#include "ComStack_Types.h"
/*---------------------------------------*/
/* AUTOSAR checking between CAN_GeneralTypes.h and CAN.h files */
#if ((CAN_AR_RELEASE_MAJOR_VERSION != COMSTACK_TYPES_AR_RELEASE_MAJOR_VERSION)\
 ||  (CAN_AR_RELEASE_MINOR_VERSION != COMSTACK_TYPES_AR_RELEASE_MINOR_VERSION)\
 ||  (CAN_AR_RELEASE_PATCH_VERSION != COMSTACK_TYPES_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif


/* Software Version checking between CAN_GeneralTypes.h and CAN.h files */
#if  ( (CAN_SW_MAJOR_VERSION != COMSTACK_TYPES_SW_MAJOR_VERSION)\
    || (CAN_SW_MINOR_VERSION != COMSTACK_TYPES_SW_MINOR_VERSION)\
    || (CAN_SW_PATCH_VERSION != COMSTACK_TYPES_SW_PATCH_VERSION) )
#error "The SW version of PBcfg.c does not match the expected version"
#endif


#include "Common_Macros.h"
/*---------------------------------------*/
/* Software Version checking between CAN_GeneralTypes.h and CAN.h files */
#if  ( (CAN_SW_MAJOR_VERSION != COMMON_MACROS_SW_MAJOR_VERSION)\
    || (CAN_SW_MINOR_VERSION != COMMON_MACROS_SW_MINOR_VERSION)\
    || (CAN_SW_PATCH_VERSION != COMMON_MACROS_SW_PATCH_VERSION) )
#error "The SW version of PBcfg.c does not match the expected version"
#endif


#include "Can_reg.h"
#include "IRQ.h"
#include "Port.h"

/******************************************************************************
 *                      Post Build Macros                                 *
 ******************************************************************************/

/* prescaller = 1 && clk = 8 */
#define CAN_CONTROLLER_BAUDRATE_250_Khz				        ((uint16)(250))
#define CAN_CONTROLLER_BAUDRATE_250_Khz_PROPSEG				(CAN_BS1_11tq)
#define CAN_CONTROLLER_BAUDRATE_250_Khz_SEG1					(CAN_BS1_16tq)
#define CAN_CONTROLLER_BAUDRATE_250_Khz_SEG2					(CAN_BS2_4tq)
#define CAN_CONTROLLER_BAUDRATE_250_Khz_SJW						(CAN_SJW_1tq)

/* prescaller = 1 && clk = 8 */
#define CAN_CONTROLLER_BAUDRATE_500_Khz			        	((uint16)(500))
#define CAN_CONTROLLER_BAUDRATE_500_Khz_PROPSEG				(1U)
#define CAN_CONTROLLER_BAUDRATE_500_Khz_SEG1					(CAN_BS1_12tq)
#define CAN_CONTROLLER_BAUDRATE_500_Khz_SEG2					(CAN_BS2_2tq)
#define CAN_CONTROLLER_BAUDRATE_500_Khz_SJW						(CAN_SJW_1tq)

/* prescaller = 1 && clk = 8 */
#define CAN_CONTROLLER_BAUDRATE_800_Khz				        ((uint16)(800))
#define CAN_CONTROLLER_BAUDRATE_800_Khz_PROPSEG				(1U)
#define CAN_CONTROLLER_BAUDRATE_800_Khz_SEG1					(CAN_BS1_7tq)
#define CAN_CONTROLLER_BAUDRATE_800_Khz_SEG2					(CAN_BS2_1tq)
#define CAN_CONTROLLER_BAUDRATE_800_Khz_SJW						(CAN_SJW_1tq)

/* prescaller = 1 && clk = 8 */
#define CAN_CONTROLLER_BAUDRATE_1000_Khz				      ((uint16)(1000))
#define CAN_CONTROLLER_BAUDRATE_1000_Khz_PROPSEG		  (1U)
#define CAN_CONTROLLER_BAUDRATE_1000_Khz_SEG1					(CAN_BS1_5tq)
#define CAN_CONTROLLER_BAUDRATE_1000_Khz_SEG2					(CAN_BS2_1tq)
#define CAN_CONTROLLER_BAUDRATE_1000_Khz_SJW					(CAN_SJW_1tq)


#define CAN_SJW_1tq                 ((uint8)0x00)  /*!< 1 time quantum */
#define CAN_SJW_2tq                 ((uint8)0x01)  /*!< 2 time quantum */
#define CAN_SJW_3tq                 ((uint8)0x02)  /*!< 3 time quantum */
#define CAN_SJW_4tq                 ((uint8)0x03)  /*!< 4 time quantum */


#define CAN_BS1_1tq                 ((uint8)0x00)  /*!< 1 time quantum */
#define CAN_BS1_2tq                 ((uint8)0x01)  /*!< 2 time quantum */
#define CAN_BS1_3tq                 ((uint8)0x02)  /*!< 3 time quantum */
#define CAN_BS1_4tq                 ((uint8)0x03)  /*!< 4 time quantum */
#define CAN_BS1_5tq                 ((uint8)0x04)  /*!< 5 time quantum */
#define CAN_BS1_6tq                 ((uint8)0x05)  /*!< 6 time quantum */
#define CAN_BS1_7tq                 ((uint8)0x06)  /*!< 7 time quantum */
#define CAN_BS1_8tq                 ((uint8)0x07)  /*!< 8 time quantum */
#define CAN_BS1_9tq                 ((uint8)0x08)  /*!< 9 time quantum */
#define CAN_BS1_10tq                ((uint8)0x09)  /*!< 10 time quantum */
#define CAN_BS1_11tq                ((uint8)0x0A)  /*!< 11 time quantum */
#define CAN_BS1_12tq                ((uint8)0x0B)  /*!< 12 time quantum */
#define CAN_BS1_13tq                ((uint8)0x0C)  /*!< 13 time quantum */
#define CAN_BS1_14tq                ((uint8)0x0D)  /*!< 14 time quantum */
#define CAN_BS1_15tq                ((uint8)0x0E)  /*!< 15 time quantum */
#define CAN_BS1_16tq                ((uint8)0x0F)  /*!< 16 time quantum */

#define CAN_BS2_1tq                 ((uint8)0x00)  /*!< 1 time quantum */
#define CAN_BS2_2tq                 ((uint8)0x01)  /*!< 2 time quantum */
#define CAN_BS2_3tq                 ((uint8)0x02)  /*!< 3 time quantum */
#define CAN_BS2_4tq                 ((uint8)0x03)  /*!< 4 time quantum */
#define CAN_BS2_5tq                 ((uint8)0x04)  /*!< 5 time quantum */
#define CAN_BS2_6tq                 ((uint8)0x05)  /*!< 6 time quantum */
#define CAN_BS2_7tq                 ((uint8)0x06)  /*!< 7 time quantum */
#define CAN_BS2_8tq                 ((uint8)0x07)  /*!< 8 time quantum */


#define CAN_UNINIT     						  (0x00U)
#define CAN_READY      					   	(0x01U)

#define MAX_DATA_LENGTH         		(8U)
#define MAX_NUMBER_OF_FILTERS				(3U)


#define CAN_FilterMode_IdMask       (0x00)  /*!< identifier/mask mode */
#define CAN_FilterMode_IdList       (0x01)  /*!< identifier list mode */


#define CAN_FilterScale_16bit       (0x00) /*!< Two 16-bit filters */
#define CAN_FilterScale_32bit       (0x01) /*!< One 32-bit filter */


#define CAN_Filter_FIFO0            (0x00)  /*!< Filter FIFO 0 assignment for filter x */
#define CAN_Filter_FIFO1            (0x01)  /*!< Filter FIFO 1 assignment for filter x */

#define CAN_MailBox_0							  (0x00)
#define CAN_MailBox_1							  (0x01)
#define CAN_MailBox_2							  (0x02)
#define CAN_MailBox_Any							(0x03)

#define CanHandleType_BASIC       	(0x00U)
#define CanHandleType_FULL        	(0x01U)


#define CanObjectType_RECEIVE   		(0x00U)
#define CanObjectType_TRANSMIT    	(0x01U)


#define CanIdType_EXTENDED   		    (0x00U)
#define CanIdType_MIXED      		    (0x01U) 
#define CanIdType_STANDARD    	    (0x02U)


#define CAN_Filter_0_Num						(0U)
#define CAN_Filter_1_Num						(1U)
#define CAN_Filter_2_Num						(2U)
#define CAN_Filter_3_Num						(3U)
#define CAN_Filter_4_Num						(4U)
#define CAN_Filter_5_Num						(5U)
#define CAN_Filter_6_Num						(6U)
#define CAN_Filter_7_Num						(7U)
#define CAN_Filter_8_Num						(8U)
#define CAN_Filter_9_Num						(9U)
#define CAN_Filter_10_Num						(10U)
#define CAN_Filter_11_Num						(11U)
#define CAN_Filter_12_Num						(12U)
#define CAN_Filter_13_Num						(13U)



/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

typedef  uint8  Can_ServiceId;


#define  CAN_INIT_SID                             ( (Can_ServiceId)0x00 )
#define  CAN_GET_VERSION_INFO_SID                 ( (Can_ServiceId)0x07 )
#define  CAN_CHECK_BAUDRATE_SID                   ( (Can_ServiceId)0x0e )
#define  CAN_CHANGE_BAUDRATE_SID                  ( (Can_ServiceId)0x0f )
#define  CAN_SET_CONTROLLER_MODE_SID              ( (Can_ServiceId)0x03 )
#define  CAN_DISABLE_CONTROLLER_INTERRUPTS_SID    ( (Can_ServiceId)0x04 )
#define  CAN_ENABLE_CONTROLLER_INTERRUPTS_SID     ( (Can_ServiceId)0x05 )
#define  CAN_CHECK_WAKEUP_SID                     ( (Can_ServiceId)0x0b )
#define  CAN_WRITE_SID                            ( (Can_ServiceId)0x06 )
#define  CAN_MAIN_FUNCTION_WRITE_SID              ( (Can_ServiceId)0x01 )
#define  CAN_MAIN_FUNCTION_READ_SID               ( (Can_ServiceId)0x08 )
#define  CAN_MAIN_FUNCTION_BUSOFF_SID             ( (Can_ServiceId)0x09 )
#define  CAN_MAIN_FUNCTION_WAKEUP_SID             ( (Can_ServiceId)0x0a )
#define  CAN_MAINFUNCTION_MODE_SID                ( (Can_ServiceId)0x0c )


/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/

typedef  uint8  Can_DetErrorType;


#define CAN_E_PARAM_POINTER              ( (Can_DetErrorType)0x01 )
#define CAN_E_PARAM_HANDLE               ( (Can_DetErrorType)0x02 )
#define CAN_E_PARAM_DLC                  ( (Can_DetErrorType)0x03 )
#define CAN_E_PARAM_CONTROLLER           ( (Can_DetErrorType)0x04 )
#define CAN_E_UNINIT                     ( (Can_DetErrorType)0x05 )
#define CAN_E_TRANSITION                 ( (Can_DetErrorType)0x06 )
#define CAN_E_DATALOST                   ( (Can_DetErrorType)0x07 )
/* this error is not in sws but we need it in function like Can_ChangeBaudrate() */
#define CAN_E_PARAM_BAUDRATE             ( (Can_DetErrorType)0x08 )


/*******************************************************************************
 *                      Module Data Types                                      *
 *******************************************************************************/
typedef volatile uint32*  Ptr2Reg;


typedef struct Can_Pdu
{
   PduIdType     swPduHandle ;  /* PDU ID */
   uint8         DLC;           /* DLC */
   Can_IdType    id ;           /* ID */
   uint8        sdu[8] ;          /* Data */
}Can_PduType; /*This type is used to provide ID, DLC and SDU from CAN interface to CAN driver.*/



typedef enum
{
    CAN_T_START, /*CAN controller transition value to request state STARTED.*/
    CAN_T_STOP,  /*CAN controller transition value to request state STOPPED.*/
    CAN_T_SLEEP, /*CAN controller transition value to request state SLEEP.*/
    CAN_T_WAKEUP /*CAN controller transition value to request state STOPPED from state SLEEP.*/
}Can_StateTransitionType;



typedef enum
{
    CAN_OK, 		/*success*/
    CAN_NOT_OK, /*error occurred or wakeup event occurred during sleep transition*/
    CAN_BUSY 		/*transmit request could not be processed because no transmit object was available*/
}Can_ReturnType;

/* we might need it later */
/* typedef float64 McuClockReferencePointType; */


typedef struct
{
	/* Specifies the baudrate of the controller in kbps */
	uint16 CanControllerBaudRate; /* Range min=0 to max=2000 */

	/* Specifies propagation delay in time quantas */
	uint8 CanControllerPropSeg; /* Range min=0 to max=255 */

	/* Specifies phase segment 1 in time quantas*/
	uint8 CanControllerSeg1; /* Range min=0 to max=255 */

	/* Specifies phase segment 2 in time quantas*/
	uint8 CanControllerSeg2; /* Range min=0 to max=255 */

	/* Specifies the synchronization jump width for the controller in time quantas*/
	uint8 CanControllerSyncJumpWidth; /* Range min=0 to max=255 */

}Can_ControllerBaudrateConfigType;



typedef struct
{
	uint8  CanFilterNumber;             /* the id of the filter */

	uint8  CanFilterMode;               /* list or mask */

	uint8  CanFilterScale;              /* 16 or 32 */

	uint8  CanFilterFiFoAssignment;     /* the filter is either assignment to FIFO1 or FIFO2 */

	uint32  CanFilterReg1;              /* reg1 */

	uint32  CanFilterReg2;              /* reg2 */


} CanHwFilterType;



typedef struct
{
    uint8 CanHandleType;    /* Specifies the type (Full-CAN or Basic-CAN) of a hardware object. */

	
    uint8   CanObjectType; /* Specifies if the HardwareObject is used as Transmit or as Receive object */

	
    uint16 CanHwObjectCount; /*   Number of hardware objects used to implement one HOH. In case of a
                              *   HRH this parameter defines the number of elements in the hardware FIFO
                              *   or the number of shadow buffers, in case of a HTH it defines the number of
                              *   hardware objects used for multiplexed transmission or for a hardware FIFO
                              *   used by a FullCAN HTH.*/

	
    uint16 CanObjectId;/* Holds the handle ID of HRH or HTH. The value of this parameter is unique
                        *   in a given CAN Driver, and it should start with 0 and continue without any gaps.
                        *   The HRH and HTH Ids share a common ID range.
                        *   Example: HRH0-0, HRH1-1, HTH0-2, HTH1-3 */


    uint8 CanIdType; /* Specifies the IdValuetype (EXTENDED , STANDARD or MIXED ) */


		uint16 CanBufferNum; /*it represents the number of either the filter or mailbox its assigned to in the objecttype */

} CanHardwareObjectType;



typedef struct
{
							/* array of the configured BRS */
	Can_ControllerBaudrateConfigType    Can_ControllerBaudrateConfigSet[MAX_NUMBER_OF_SUPORTED_BAUDRATE];
							/* array of the configured HOH */
	CanHardwareObjectType  							CanHardwareObjectSet[MAX_NUMBER_OF_HARDWARE_OBJECT];  
						  /* array of the configured filters */	
	CanHwFilterType  										CanHwFilterSet[MAX_NUMBER_OF_FILTERS];                             

}Can_ConfigType;



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
extern const Can_ConfigType Can_Configrations;

void Can_Init(const Can_ConfigType* Config);


void Can_GetVersionInfo(Std_VersionInfoType* versioninfo);

#if (CAN_CHANGE_BAUDRATE_SUPPORT == STD_ON)
	Std_ReturnType Can_CheckBaudrate(uint8 Controller , const uint16 Baudrate);

	Std_ReturnType Can_ChangeBaudrate(uint8 Controller , const uint16 Baudrate);
#endif

Can_ReturnType Can_SetControllerMode(uint8 Controller , Can_StateTransitionType Transition);


void Can_DisableControllerInterrupts(uint8 Controller);


void Can_EnableControllerInterrupts(uint8 Controller);


Can_ReturnType Can_CheckWakeup(uint8 Controller);


Can_ReturnType Can_Write(Can_HwHandleType Hth , const Can_PduType* PduInfo);

/*
void Can_MainFunction_Write(void);


void Can_MainFunction_Read(void);


void Can_MainFunction_BusOff(void);


void Can_MainFunction_Wakeup(void);


void Can_MainFunction_Mode(void);
*/


#endif /* CAN_H_ */



