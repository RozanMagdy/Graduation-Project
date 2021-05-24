/**
  ******************************************************************************
  *
  * @Module: Port
  * @FileName: Port_Cfg.h
  * @Description: Header file contains Pre-Compile Configuration for Port Module.
  * @version: 1.0.0
  * @date:    xx-xx-2020
  * @Authors: Ahmed Mohsen  && Ahmed Khamis && Ashraf Amgad
  *
  * @Brief: this file contains:
  *                             (1) Module version and AUTOSAR version
  *                             (2) Initialization for Error Detection functions (to be ON/OFF)
  *                             (3) PORT parameters main initialization:
  *                                                            is the Direction changeable during runtime or not.
  *                                                            is the Mode changeable during runtime or not.
  *                                                            PORT clk speed (if output pin)
  *                                                            Pin initial parameters.
  ******************************************************************************
  */

#ifndef __PORT_CFG_H
#define __PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)
/**<  */
/**<  */
/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_ON)
/**<  */
/**<  */
/* Pre-compile option for PIN_DIRECTION_CHANGEABLE during runtime */
#define	PORT_DIRECTION_CHANGEABLE_DURING_RUNTIME    (STD_ON)

/* Pre-compile option for PORT_MODE_CHANGEABLE during runtime */
#define		PORT_MODE_CHANGEABLE_DURING_RUNTIME		    (STD_ON)
/**<  */
/**<  */
/* Max speed that pin can handle in output mode */
/* MAX_OUT_SPEED_2  ,   MAX_OUT_SPEED_10    ,   MAX_OUT_SPEED_50 */
#define   PORT_PIN_MAX_OUTSPEED         (MAX_OUT_SPEED_50)

/**< Initial; making an initial value for: Direction, Level, Mode, Driven Mode */
#define	PORT_PIN_DIRECTION_INITIAL_VALUE		(Port_PinDirectionType)(PORT_PIN_OUT)
                                        // "PORT_PIN_IN" is an element from the "Port_PinDirectionType" enum
#define	PORT_PINLEVEL_INITIAL_VALUE				(Port_PinType)(STD_LOW)
#define PORT_PIN_MODE_INITIAL_VALUE				(Port_PinModeType)(PORT_PIN_MODE_DIO)
#define PORT_PIN_DRIVEN_MODE_INITIAL_VALUE		(Port_PinDrivenModeType)(Floating)

#endif // __PORT_CFG_H
