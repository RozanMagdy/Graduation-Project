/* Module Version 1.0.0 */
#define CAN_PBCFG_SW_MAJOR_VERSION              (1U)
#define CAN_PBCFG_SW_MINOR_VERSION              (0U)
#define CAN_PBCFG_SW_PATCH_VERSION              (0U)



/* AUTOSAR Version 4.0.3 */
#define CAN_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define CAN_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define CAN_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)


#include "Can.h"

/* AUTOSAR Version checking between CAN_PBcfg.c and CAN.h files */
#if  ( (CAN_PBCFG_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_PBCFG_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
    || (CAN_PBCFG_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION) )
#error "The AR version of Can_PBcfg.h does not match the expected version"
#endif



/* Software Version checking between CAN_PBcfg.c and CAN.h files */
#if  ( (CAN_PBCFG_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION)\
    || (CAN_PBCFG_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION)\
    || (CAN_PBCFG_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION) )
#error "The SW version of Can_PBcfg.h does not match the expected version"
#endif





/* PB structure used with CAN_Init API */
const Can_ConfigType Can_Configrations =
{
	CAN_CONTROLLER_BAUDRATE_250_Khz  , CAN_CONTROLLER_BAUDRATE_250_Khz_PROPSEG  , CAN_CONTROLLER_BAUDRATE_250_Khz_SEG1  , CAN_CONTROLLER_BAUDRATE_250_Khz_SEG2  , CAN_CONTROLLER_BAUDRATE_250_Khz_SJW  , 
	CAN_CONTROLLER_BAUDRATE_500_Khz  , CAN_CONTROLLER_BAUDRATE_500_Khz_PROPSEG  , CAN_CONTROLLER_BAUDRATE_500_Khz_SEG1  , CAN_CONTROLLER_BAUDRATE_500_Khz_SEG2  , CAN_CONTROLLER_BAUDRATE_500_Khz_SJW  , 
	CAN_CONTROLLER_BAUDRATE_800_Khz  , CAN_CONTROLLER_BAUDRATE_800_Khz_PROPSEG  , CAN_CONTROLLER_BAUDRATE_800_Khz_SEG1  , CAN_CONTROLLER_BAUDRATE_800_Khz_SEG2  , CAN_CONTROLLER_BAUDRATE_800_Khz_SJW  , 
	CAN_CONTROLLER_BAUDRATE_1000_Khz , CAN_CONTROLLER_BAUDRATE_1000_Khz_PROPSEG , CAN_CONTROLLER_BAUDRATE_1000_Khz_SEG1 , CAN_CONTROLLER_BAUDRATE_1000_Khz_SEG2 , CAN_CONTROLLER_BAUDRATE_1000_Khz_SJW , 

	CAN_HOH_0_HandleType , CAN_HOH_0_ObjectType  , CAN_HOH_0_Count , CAN_HRH_0 , CAN_HOH_0_IdType , CAN_HOH_0_Buffer_Num ,
	CAN_HOH_1_HandleType , CAN_HOH_1_ObjectType  , CAN_HOH_1_Count , CAN_HRH_1 , CAN_HOH_1_IdType , CAN_HOH_1_Buffer_Num ,
	CAN_HOH_2_HandleType , CAN_HOH_2_ObjectType  , CAN_HOH_2_Count , CAN_HRH_2 , CAN_HOH_2_IdType , CAN_HOH_2_Buffer_Num ,
	CAN_HOH_3_HandleType , CAN_HOH_3_ObjectType  , CAN_HOH_3_Count , CAN_HTH_0 , CAN_HOH_3_IdType , CAN_HOH_3_Buffer_Num ,
	CAN_HOH_4_HandleType , CAN_HOH_4_ObjectType  , CAN_HOH_4_Count , CAN_HTH_1 , CAN_HOH_4_IdType , CAN_HOH_4_Buffer_Num ,
	CAN_HOH_5_HandleType , CAN_HOH_5_ObjectType  , CAN_HOH_5_Count , CAN_HTH_2 , CAN_HOH_5_IdType , CAN_HOH_5_Buffer_Num ,

	
	CAN_Filter_0_Num , CAN_Filter_0_Mode , CAN_Filter_0_Scale , CAN_Filter_0_FiFoAssignment , CAN_Filter_0_Reg1 , CAN_Filter_0_Reg2 , 
	CAN_Filter_1_Num , CAN_Filter_1_Mode , CAN_Filter_1_Scale , CAN_Filter_1_FiFoAssignment , CAN_Filter_1_Reg1 , CAN_Filter_1_Reg2 , 
	CAN_Filter_2_Num , CAN_Filter_2_Mode , CAN_Filter_2_Scale , CAN_Filter_2_FiFoAssignment , CAN_Filter_2_Reg1 , CAN_Filter_2_Reg2 


};

