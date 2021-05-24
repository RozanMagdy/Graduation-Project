#ifndef Dio_Cfg_h
#define Dio_Cfg_h


/*
 * Module Version 1.0.0
 */
#define DIO_CFG_SW_MAJOR_VERSION              (1U)
#define DIO_CFG_SW_MINOR_VERSION              (0U)
#define DIO_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                (STD_OFF)

/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                (STD_OFF)

/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API                (STD_ON)

/* Number of the configured Dio Channels */
#define DIO_CONFIGURED_CHANNLES             (1U)

/* Channel Index in the array of structures in Dio_PBcfg.c */
#define DioConf_LED_CHANNEL_ID_INDEX        (uint8)0x00

/* DIO Configured Port ID's  */
#define DioConf_LED_PORT_NUM                (Dio_PortType)2 /* PORTC */

/* DIO Configured Channel ID's */
#define DioConf_LED_CHANNEL_NUM             (Dio_ChannelType)13/* Pin 5 in PORTC */

#endif

/*Configuring LED group*/
/*configure num of bits mask*/
#define DioconfigGroup_LED_Mask 					(uint32)3 // 3 pins 
#define DioConfigGroup_LED_Offset                    (uint8)1  /*Pin1*/
#define DioConfGroup_LED_Port  						(Dio_PortType)0 /* PORTA */

/*Configuring BUTTONS group*/
/*configure num of bits mask*/
#define DioconfigGroup_BUTTON_Mask 					(uint32)3 // 3 pins 
#define DioConfigGroup_BUTTON_Offset                    (uint8)0  /*Pin0*/
#define DioConfGroup_BUTTON_Port  						(Dio_PortType)1 /* PORTB */
