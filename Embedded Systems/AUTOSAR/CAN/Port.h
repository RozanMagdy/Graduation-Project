/**
  ******************************************************************************
  *
  * @Module: Port
  * @FileName: Port.h
  * @Description: Header file for  Port Module.
  * @version: 1.0.0
  * @date:    xx-xx-2020
  * @Authors: Ahmed Mohsen  && Ahmed Khamis && Ashraf Amgad
  *
  ******************************************************************************
  */

#ifndef __PORT_H
#define __PORT_H

/* Id for the company in the AUTOSAR */
#define PORT_VENDOR_ID      (1000U)

/* Port Module Id */
#define PORT_MODULE_ID      (120U)

/* Port Instance Id */
#define PORT_INSTANCE_ID     (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION           (4U)
#define PORT_AR_RELEASE_MINOR_VERSION           (0U)
#define PORT_AR_RELEASE_PATCH_VERSION           (3U)

#include "Dio_Regs.h"   // Our micro-controller #define (Register --> memory address)

/**< Standard AUTOSAR types */
#include "Std_Types.h"
/**<  */


/* AUTOSAR checking (comparison) between Std Types and Port Modules */
/* once any of the conditions is correct (mis-match), there is Error  */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
     ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
     ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Std_Types.h does not match the expected version"
#endif


/**< Dio Pre-Compile Configuration Header file */
#include "Port_Cfg.h"
/**<  */


/* AUTOSAR Version checking (comparison) between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
     ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
     ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking (comparison) between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
     ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
     ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
#error "The SW version of Port_Cfg.h does not match the expected version"
#endif


/**< Non AUTOSAR files */
#include "Common_Macros.h"
/**<  */

/* Macros for PORT Status */
#define PORT_INITIALIZED                ((uint8) 0x01)
#define PORT_NOT_INITIALIZED            ((uint8) 0x00)


/* Number of the configured port pins 3_ports */
#define PORT_CONFIGURED_PORTS            ((uint8) 0x03)

/* Number of the configured port pins 3_ports every port 16_pins */
#define PORT_CONFIGURED_PINS            ((uint8)32)

/* MAX SPEED on pins when configured as output */
#define  MAX_OUT_SPEED_2  	            ((uint8) 0x01)
#define  MAX_OUT_SPEED_10 	            ((uint8) 0x02)
#define  MAX_OUT_SPEED_50 	            ((uint8) 0x03)


/* Symbolic names (IDs) for Ports numbers ---> Hex equivalent */
// used in Port.c file, in Port_Init function
#define PORT_A_NUM                      ((Port_PortType) 0x00) // an element from the "Port_PortType" structure.
#define PORT_B_NUM                      ((Port_PortType) 0x01)
#define PORT_C_NUM                      ((Port_PortType) 0x02)
/**< Please note that the above Hex IDs refer to ........ defined in the "" file */

/* Symbolic names (IDs) for Pins numbers ---> Hex equivalent */
#define PORT_PIN_0_NUM                  ((Port_PinType) 0x00) // an element from the "Port_PinType" structure.
#define PORT_PIN_1_NUM                  ((Port_PinType) 0x01)
#define PORT_PIN_2_NUM                  ((Port_PinType) 0x02)
#define PORT_PIN_3_NUM                  ((Port_PinType) 0x03)
#define PORT_PIN_4_NUM                  ((Port_PinType) 0x04)
#define PORT_PIN_5_NUM                  ((Port_PinType) 0x05)
#define PORT_PIN_6_NUM                  ((Port_PinType) 0x06)
#define PORT_PIN_7_NUM                  ((Port_PinType) 0x07)
#define PORT_PIN_8_NUM                  ((Port_PinType) 0x08)
#define PORT_PIN_9_NUM                  ((Port_PinType) 0x09)
#define PORT_PIN_10_NUM                 ((Port_PinType) 0x0A)
#define PORT_PIN_11_NUM                 ((Port_PinType) 0x0B)
#define PORT_PIN_12_NUM                 ((Port_PinType) 0x0C)
#define PORT_PIN_13_NUM                 ((Port_PinType) 0x0D)
#define PORT_PIN_14_NUM                 ((Port_PinType) 0x0E)
#define PORT_PIN_15_NUM                 ((Port_PinType) 0x0F)
/**< Please note that the above Hex IDs refer to ........ defined in the "" file */




///* Symbolic names for Port_A Pins */
//#define PORTA_PIN_0                     ((Port_PinType) 0x00)
//#define PORTA_PIN_1                     ((Port_PinType) 0x01)
//#define PORTA_PIN_2                     ((Port_PinType) 0x02)
//#define PORTA_PIN_3                     ((Port_PinType) 0x03)
//#define PORTA_PIN_4                     ((Port_PinType) 0x04)
//#define PORTA_PIN_5                     ((Port_PinType) 0x05)
//#define PORTA_PIN_6                     ((Port_PinType) 0x06)
//#define PORTA_PIN_7                     ((Port_PinType) 0x07)
//#define PORTA_PIN_8                     ((Port_PinType) 0x08)
//#define PORTA_PIN_9                     ((Port_PinType) 0x09)
//#define PORTA_PIN_10                    ((Port_PinType) 0x0A)
//#define PORTA_PIN_11                    ((Port_PinType) 0x0B)
//#define PORTA_PIN_12                    ((Port_PinType) 0x0C)
//#define PORTA_PIN_15                    ((Port_PinType) 0x0D)
//
///* Symbolic names for Port_B Pins */
//#define PORTB_PIN_0                     ((Port_PinType) 0x0E)
//#define PORTB_PIN_1                     ((Port_PinType) 0x0F)
//#define PORTB_PIN_3                     ((Port_PinType) 0x10)
//#define PORTB_PIN_4                     ((Port_PinType) 0x11)
//#define PORTB_PIN_5                     ((Port_PinType) 0x12)
//#define PORTB_PIN_6                     ((Port_PinType) 0x13)
//#define PORTB_PIN_7                     ((Port_PinType) 0x14)
//#define PORTB_PIN_8                     ((Port_PinType) 0x15)
//#define PORTB_PIN_9                     ((Port_PinType) 0x16)
//#define PORTB_PIN_10                    ((Port_PinType) 0x17)
//#define PORTB_PIN_11                    ((Port_PinType) 0x18)
//#define PORTB_PIN_12                    ((Port_PinType) 0x19)
//#define PORTB_PIN_13                    ((Port_PinType) 0x1A)
//#define PORTB_PIN_14                    ((Port_PinType) 0x1B)
//#define PORTB_PIN_15                    ((Port_PinType) 0x1C)
//
///* Symbolic names for Port_C Pins */
//#define PORTC_PIN_13                    ((Port_PinType)0x1D)
//#define PORTC_PIN_14                    ((Port_PinType)0x1E)
//#define PORTC_PIN_15                    ((Port_PinType)0x1F)



/*This Macro Function takes a pointer to the BSRR register, Pin Number, Pin initial value.
 it updates the BSRR bit corresponding with Pin X initial value */
#define MODIFY_BSRR_REG(Port_Ptr_BSRR , Pin_Num , Pin_initial_value)    if(Pin_initial_value == STD_HIGH) \
                                                                        { \
                                                                          Port_Ptr_BSRR |=  ( 1 << Pin_Num ); \
                                                                        } \
                                                                        else if (Pin_initial_value == STD_LOW) \
                                                                        { \
                                                                          Port_Ptr_BSRR |=  ( 1 << (Pin_Num + 16) ); \
                                                                        } \
                                                                        else \
                                                                        { \
                                                                            /**< error wrong Pin_initial_value */ \
                                                                        }\


/**< These macros are defined here and used by the "MODIFY_CR_REG" macro function Only */

/* Input Driven Mode  bit configuration  (no clk needed)*/
#define Analog_Config                   (0x00) // 0000
#define Floating_Config                 (0x04) // 0100
#define PullDown_Config                 (0x08) // 1000
#define PullUp_Config                   (0x08) // 1000

/* Output Driven Mode  bit configuration  (output with clk) */
#define GPIO_Push_Pull_Config      ( (0x00 << 2) | PORT_PIN_MAX_OUTSPEED ) // 4 bits
#define GPIO_Open_drain_Config     ( (0x01 << 2) | PORT_PIN_MAX_OUTSPEED )
#define AF_Push_Pull_Config        ( (0x02 << 2) | PORT_PIN_MAX_OUTSPEED )
#define AF_Open_drain_Config       ( (0x03 << 2) | PORT_PIN_MAX_OUTSPEED )


#define MODIFY_CR_REG(Port_Ptr_CR , Pin_Num , driven_mode_Config)       if(Pin_Num < 8)\
                                                                        {\
																																						Port_Ptr_CR &= ~( (0xFF) << (Pin_Num << 2) );\
                                                                            Port_Ptr_CR |= ( driven_mode_Config << (Pin_Num << 2) );\
                                                                        }\
                                                                        else if( (Pin_Num < 16) && (Pin_Num >= 8) )\
                                                                        {\
																																						Port_Ptr_CR &= ~( (0xFF) << ((Pin_Num-8) << 2) );\
                                                                            Port_Ptr_CR |= ( driven_mode_Config << ((Pin_Num-8) << 2) );\
                                                                        }\
                                                                        else\
                                                                        {\
                                                                            /**< error wrong driven_mode */\
                                                                        }\

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

/* Service ID for Port Init */
#define PORT_INIT_SID      			    	((uint8) 0x00)

/* Service ID for Port Set Pin Direction */
#define PORT_SET_PIN_DIRECTION_SID          ((uint8) 0x01)

/* Service ID for PORT refresh port direction */
#define PORT_REFRESH_PORT_DIRECTION_SID     ((uint8) 0x02)

/* Service ID for PORT Port Get Version Info */
#define PORT_GET_VERSION_INFO_SID           ((uint8) 0x03)

/* Service ID for PORT Set Pin Mode */
#define PORT_SET_PIN_MODE_SID    			((uint8) 0x04)


/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/

/* Invalid Port Pin ID requested  */
#define PORT_E_PARAM_PIN        (0x0A)
#define IS_PORT_A_PARAM_PIN(Pin)     ( (Pin <= PORTA_PIN_15) && (Pin != 0x0D) && (Pin != 0x0E) )
#define IS_PORT_B_PARAM_PIN(Pin)     ( (Pin > PORTA_PIN_15) && (Pin <= PORTB_PIN_15) && (Pin != 0x12) )
#define IS_PORT_C_PARAM_PIN(Pin)     ( ( (Pin > PORTB_PIN_15) && (Pin < PORT_CONFIGURED_PINS) ) \
                                    && ( (pin == PORTC_PIN_13) || (pin == PORTC_PIN_14) || (pin == PORTC_PIN_15) ) )

#define IS_PORT_PARAM_PIN(Pin)   (IS_PORT_A_PARAM_PIN(Pin) || IS_PORT_B_PARAM_PIN(Pin) || IS_PORT_C_PARAM_PIN(Pin))

/* Port Pin not configured as changeable in direction */
#define PORT_E_DIRECTION_UNCHANGEABLE                                       (0x0B)
/* check for DIRECTION CHANGEABLE in "Port_cfg.h" */
#define IS_PORT_DIRECTION_CHANGEABLE_DURING_RUNTIME          (PORT_DIRECTION_CHANGEABLE_DURING_RUNTIME)

/* API Port_Init service called with wrong parameter. */
#define PORT_E_INIT_FAILED               (0x0C)


/* invalid port mode */
#define PORT_E_PARAM_INVALID_MODE        (0x0D)
#define IS_PORT_PARAM_MODE(param_mode)        (   (param_mode ==  PORT_PIN_MODE_ADC) \
                                               || (param_mode ==  PORT_PIN_MODE_CAN) \
                                               || (param_mode ==  PORT_PIN_MODE_DIO) \
                                               || (param_mode ==  PORT_PIN_MODE_DIO_GPT) \
                                               || (param_mode ==  PORT_PIN_MODE_DIO_WDG) \
                                               || (param_mode ==  PORT_PIN_MODE_ICU) \
                                               || (param_mode ==  PORT_PIN_MODE_LIN) \
                                               || (param_mode ==  PORT_PIN_MODE_MEM) \
                                               || (param_mode ==  PORT_PIN_MODE_PWM) \
                                               || (param_mode ==  PORT_PIN_MODE_SPI) \ )


/* Port Pin not configured as changeable in mode */
#define PORT_E_MODE_UNCHANGEABLE   	                                 (0x0E)
/* check for MODE CHANGEABLE in "Port_cfg.h" */
#define IS_PORT_MODE_CHANGEABLE_DURING_RUNTIME          (PORT_MODE_CHANGEABLE_DURING_RUNTIME)

/*
 * API service used without module initialization is reported using following
 * error code (Not exist in AUTOSAR 4.0.3 Port SWS Document.
 */
#define PORT_E_UNINIT      				                 (0x0F)
#define IS_PORT_MODULE_INITIALIZED(Port_Status)        (Port_Status)

/*
 * The API service shall return immediately without any further action,
 * beside reporting this development error.
 */
#define PORT_E_PARAM_POINTER   		            (0x10)
#define IS_PORT_PARAM_NULL_POINTER(param)    (param == NULL_PTR)

/*******************************************************************************
 *                              Module Data Types                              *
 *   enums.:
            Port_PinModeType (ADC, CAN, DIO, DIO_GPT, ...
            Port_PinDrivenModeType
            Port_PinDirectionType (in/out)
            Port_PinLevelType (low/high)
 *
 *
 *   Structs:
            Port_PinConfigType (portNum,pinNum, direction, initial value, mode, drive mode)
            Port_ConfigType
 *
 *   Typedefs:
            Port_PortType (8)
            Port_PinType (8)
            Port_PortRegisterType (32)
 *
 *   Functions in this file:
            Port_Init
            Port_SetPinDirection
            Port_RefreshPortDirection
            Port_SetPinMode
            Port_GetVersionInfo
 *
 *   externs in this file:
        A const var. of the type "Port_ConfigType"
 *
 *
 *******************************************************************************/

/* Type definition for Port_Pin_Mode used by the pin APIs */
/**< @note: Pin_Driven_Mode is (i/p) and (o/p) configured set. However, Pin_Mode is All possible AF of the pin */
typedef enum
{
    PORT_PIN_MODE_ADC,
    PORT_PIN_MODE_CAN,
    PORT_PIN_MODE_DIO,
    PORT_PIN_MODE_DIO_GPT,
    PORT_PIN_MODE_DIO_WDG,
    PORT_PIN_MODE_FLEXRAY,
    PORT_PIN_MODE_ICU,
    PORT_PIN_MODE_LIN,
    PORT_PIN_MODE_MEM,
    PORT_PIN_MODE_PWM,
    PORT_PIN_MODE_SPI
} Port_PinModeType; //Port number


typedef enum
{
    // These elements differ from the ones defined by #defines at the beginning of the file.
    //This structure used to set pins configration
    AF_Open_drain,
    AF_Push_Pull,
    GPIO_Open_drain,
    GPIO_Push_Pull,
    Analog,
    Floating,
    PullDown,
    PullUp
} Port_PinDrivenModeType;


/* Type definition for Symbolic names of Ports */
typedef uint8 Port_PortType;
/* Type definition for Symbolic names of Port's Pins */
typedef uint8 Port_PinType;

typedef volatile uint32*  Port_PortRegisterType;


/* Type definition for Pin Direction */
typedef enum
{
    PORT_PIN_IN ,
    PORT_PIN_OUT
} Port_PinDirectionType;


/* Type definition for Pin Level */
typedef enum
{
    PORT_Pin_Level_low , PORT_Pin_Level_High
} Port_PinLevelType;


//This struct contains info about the pin settings
typedef struct
{
    Port_PortType 	        Port_Num;
    Port_PinType            Pin_Num;
    Port_PinDirectionType   Pin_direction;
    Port_PinLevelType       Pin_initial_value;
    Port_PinModeType 	      Pin_mode;
    Port_PinDrivenModeType  Pin_driven_mode;
} Port_PinConfigType;



//This is an array of the previous structure, used as an element-
// of the "Port_ConfigType" struct.
// this structure used to include each pins into their port.
// this structure deals with All the pins as if they are in one port !
// And is modified from the "Port_PBcfg.c" file.
typedef struct
{
    Port_PinConfigType PORT_CONFIGURED_PIN[PORT_CONFIGURED_PINS] ;
} Port_ConfigType;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void Port_Init(const Port_ConfigType* ConfigPtr);

#if(IS_PORT_DIRECTION_CHANGEABLE_DURING_RUNTIME == STD_ON)
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction);
void Port_RefreshPortDirection(void);
#endif

#if(IS_PORT_MODE_CHANGEABLE_DURING_RUNTIME == STD_ON) // mode, not driven mode
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode);
#endif

#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif
/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Dio and other modules */
extern const Port_ConfigType Port_Configuration;

#endif // __PORT_H
