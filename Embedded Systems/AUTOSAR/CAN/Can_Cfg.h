#ifndef __CAN_CFG_H__
#define __CAN_CFG_H__


#define CAN_CFG_SW_MAJOR_VERSION 		(1U)
#define CAN_CFG_SW_MINOR_VERSION 		(0U)
#define CAN_CFG_SW_PATCH_VERSION 		(0U)

/* AUTOSAR Version 4.0.3 */
#define CAN_CFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define CAN_CFG_AR_RELEASE_MINOR_VERSION   (0U)
#define CAN_CFG_AR_RELEASE_PATCH_VERSION   (3U)


/**************************/


/* Pre-compile option for Development Error Detect */
#define CAN_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define CAN_VERSION_INFO_API                (STD_ON)


#define CAN_0_ID										(0U)


#define CAN_MAX_NUM_OF_CONTROLLER 	(1U)


#define CAN_CPU_CLOCK_REF						(0U)


/* CAN_TIME_TRIGGER can be set either to STD_DISABLE or STD_ENABLE */
#define	CAN_TIME_TRIGGER														STD_DISABLE

/* CAN_AUTO_BUS_OFF can be set either to STD_DISABLE or STD_ENABLE */
#define	CAN_AUTO_BUS_OFF															STD_DISABLE

/* CAN_AUTO_WAKEUP can be set either to STD_DISABLE or STD_ENABLE */
#define	CAN_AUTO_WAKEUP															STD_DISABLE

/* CAN_NON_AUTO_RETRANS can be set either to STD_DISABLE or STD_ENABLE */
#define	CAN_NON_AUTO_RETRANS												STD_ENABLE

/* CAN_RECEIVE_FIFO_LOCKED_MODE can be set either to STD_DISABLE or STD_ENABLE */
#define	CAN_RECEIVE_FIFO_LOCKED_MODE								STD_DISABLE

/* CAN_TRANSMIT_FIFO_PRIORITY can be set either to STD_DISABLE or STD_ENABLE */ 
#define	CAN_TRANSMIT_FIFO_PRIORITY									STD_DISABLE


/* CAN_PRESCALER ranges from 1 to 1024. */
#define CAN_PRESCALER											   					((uint16)(9U))

								
#define CAN_MAX_BAUDRATE														 ((uint16)(1000U))
#define CAN_CHANGE_BAUDRATE_SUPPORT									    (STD_ON)
#define MAX_NUMBER_OF_SUPORTED_BAUDRATE								    (4U)

#define CAN_CONTROLLER_DEFAULT_BAUDRATE								(CAN_CONTROLLER_BAUDRATE_500_Khz)



/********************************/



#define MAX_NUMBER_OF_HARDWARE_OBJECT	   (6U)


#define CAN_HRH_0		(0U)
#define CAN_HRH_1		(1U)
#define CAN_HRH_2		(2U)
#define CAN_HTH_0		(3U)
#define CAN_HTH_1		(4U)
#define CAN_HTH_2		(5U)

#define CAN_HOH_0_HandleType 			(CanHandleType_BASIC)
#define CAN_HOH_0_ObjectType 			(CanObjectType_RECEIVE)
#define CAN_HOH_0_Count 								  (1U)
#define CAN_HOH_0_IdType 					(CanIdType_STANDARD)
#define CAN_HOH_0_Buffer_Num 			(CAN_Filter_0_Num)


#define CAN_HOH_1_HandleType 			(CanHandleType_BASIC)
#define CAN_HOH_1_ObjectType 			(CanObjectType_RECEIVE)
#define CAN_HOH_1_Count 								   (1U)
#define CAN_HOH_1_IdType 					(CanIdType_STANDARD)
#define CAN_HOH_1_Buffer_Num 			(CAN_Filter_1_Num)


#define CAN_HOH_2_HandleType 			(CanHandleType_BASIC)
#define CAN_HOH_2_ObjectType 			(CanObjectType_RECEIVE)
#define CAN_HOH_2_Count 								   (1U)
#define CAN_HOH_2_IdType 					(CanIdType_STANDARD)
#define CAN_HOH_2_Buffer_Num 			(CAN_Filter_2_Num)


#define CAN_HOH_3_HandleType 			(CanHandleType_BASIC)
#define CAN_HOH_3_ObjectType 			(CanObjectType_TRANSMIT)
#define CAN_HOH_3_Count 								   (1U)
#define CAN_HOH_3_IdType 					(CanIdType_STANDARD)
#define CAN_HOH_3_Buffer_Num 			(CAN_MailBox_Any)


#define CAN_HOH_4_HandleType 			(CanHandleType_BASIC)
#define CAN_HOH_4_ObjectType 			(CanObjectType_TRANSMIT)
#define CAN_HOH_4_Count 								   (1U)
#define CAN_HOH_4_IdType 					(CanIdType_STANDARD)
#define CAN_HOH_4_Buffer_Num 			(CAN_MailBox_Any)

#define CAN_HOH_5_HandleType 			(CanHandleType_BASIC)
#define CAN_HOH_5_ObjectType 			(CanObjectType_TRANSMIT)
#define CAN_HOH_5_Count 								   (1U)
#define CAN_HOH_5_IdType 					(CanIdType_STANDARD)
#define CAN_HOH_5_Buffer_Num 			(CAN_MailBox_Any)




#define CAN_Filter_0_Mode						 (CAN_FilterMode_IdMask)
#define CAN_Filter_0_Scale					 (CAN_FilterScale_32bit)
#define CAN_Filter_0_FiFoAssignment	 (CAN_Filter_FIFO0)
#define CAN_Filter_0_Reg1	 					 			(0x050)
#define CAN_Filter_0_Reg2	 					 			(0x7ff)

#define CAN_Filter_1_Mode						 (CAN_FilterMode_IdList)
#define CAN_Filter_1_Scale					 (CAN_FilterScale_32bit)
#define CAN_Filter_1_FiFoAssignment	 (CAN_Filter_FIFO1)
#define CAN_Filter_1_Reg1	 					 			(0x100)
#define CAN_Filter_1_Reg2	 					 			(0x7ff)

#define CAN_Filter_2_Mode						 (CAN_FilterMode_IdMask)
#define CAN_Filter_2_Scale					 (CAN_FilterScale_32bit)
#define CAN_Filter_2_FiFoAssignment	 (CAN_Filter_FIFO0)
#define CAN_Filter_2_Reg1	 					 			(0x110)
#define CAN_Filter_2_Reg2	 					 			(0x7ff)


#define CAN_DISABLE_INTERUPTS         (uint32)(0X00000000)
#define CAN_ENABLE_INTERUPTS          (uint32)(0X00038F7F)


#define CAN_TxStatus_NoMailBox 				  	(50)

#define SLAK_TIMEOUT 							(uint32)(0x0000ffff)

/***********************************************/

#endif

