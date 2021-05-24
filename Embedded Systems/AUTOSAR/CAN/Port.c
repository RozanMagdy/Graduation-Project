/**
  ******************************************************************************
  *
  * @Module: Port
  * @FileName: Port.c
  * @Description: Source file for Port Module
  * @version: 1.0.0
  * @date:    xx-xx-2020
  * @Author: Ahmed Mohsen  && Ahmed Khamis && Ashraf Amgad
  *
  ******************************************************************************
  */

#include "Port.h"


#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
    /* AUTOSAR Version checking between Det and Port Modules */
    #if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
         || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
         || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
    #error "The AR version of Det.h does not match the expected version"
    #endif
#endif

//Null pointer to point to the structure of configuration (pointer to structure)
STATIC const Port_PinConfigType *Port_Pins = NULL_PTR;	//Port_Pins is a pointer
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

/**
  ******************************************************************************
  *
  * @Service[Name]:      Port_Init
  * @Syntax:             void Port_Init( const Port_ConfigType* ConfigPtr )
  * @Service[ID]:        0x00
  * @Sync>Async:         Synchronous
  * @Reentrancy:         Non Reentrant
  * @Parameters[in]:     ConfigPtr Pointer to configuration set.
  * @Parameters[inout]:  None
  * @Parameters[out]:    None
  * @ReturnValue:        None
  * @Description:        Initializes the Port Driver module.
  *
  ******************************************************************************
  */
void Port_Init(const Port_ConfigType *ConfigPtr)
{
    /* counter we use to loop for all pins to configure them */
    uint8 PinId_Counter = 0;

    /* pointer to point to the specific BSRR register of a Specific port */
    Port_PortRegisterType   Port_Ptr_BSRR  = NULL_PTR;
    /* pointer to point to the specific CR register of a Specific port */
    Port_PortRegisterType   Port_Ptr_CR    = NULL_PTR;
                     // these typedefs are defined in Port.h file

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* check if the input configuration pointer is not a NULL_PTR */
    if ( IS_PORT_PARAM_NULL_POINTER(ConfigPtr) )// if a null pointer is sent (not correct) , so send error
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID ,PORT_E_PARAM_POINTER);// ch8 , // ch7
				//Port_init_SID is defined in Port.c
    }
    else
#endif
    {
        /*
         * (1)--Set the module state to initialized.
		 * (2)--Port_Pins (global pointer) pointer points to the PB Port configuration structure.
         * This global pointer is global to be used by other functions to read the PB configuration structures
         */
        Port_Status  = PORT_INITIALIZED;
        Port_Pins = ConfigPtr->PORT_CONFIGURED_PIN; /* address of the first Channels structure --> Channels[0] */
                    //ConfigPtr is a pointer to a structure (input to the Init function)
                    //There is only one element in the AUTOSAR port, which is "PORT_CONFIGURED_PIN" ?!

        for (PinId_Counter = 0 ; PinId_Counter < PORT_CONFIGURED_PINS ; PinId_Counter++)
                // Counting from the first to last pin (0-31) in the AUTOSAR port.
        {
            /* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
            switch(Port_Pins[PinId_Counter].Port_Num)//setting bits for port to be activated
            {
            case 0:/*macro--PORT_A_NUM */

                Port_Ptr_BSRR = &PORTA_BSRR; /*SET INTIAL VALUE, going to BSRR address in memory */
                if(Port_Pins[PinId_Counter].Pin_Num <= 0x0F)
                 {
                    if(Port_Pins[PinId_Counter].Pin_Num <= 7)
                    {
                        Port_Ptr_CR = &PORTA_CRL ; //going to CRL address in memory
                    }
                    else
                    {
                        Port_Ptr_CR = &PORTA_CRH; //going to CRH address in memory
                    }
                }
                else
                {
                    /**< wrong Pin_Num */
                }

                break;

            case 1:/*macro--PORT_B_NUM*/
                Port_Ptr_BSRR=&PORTB_BSRR; /*SET INTIAL VALUE */
                if(Port_Pins[PinId_Counter].Pin_Num <= 0x0F)
                 {
                    if(Port_Pins[PinId_Counter].Pin_Num <= 7)
                    {
                        Port_Ptr_CR = &PORTB_CRL;
                    }
                    else
                    {
                        Port_Ptr_CR = &PORTB_CRH;
                    }
                }
                else
                {
                    /**< wrong Pin_Num */
                }
                break;

            case 2:/*macro--PORT_C_NUM*/
                Port_Ptr_BSRR=&PORTC_BSRR; /*SET INTIAL VALUE */
                if(Port_Pins[PinId_Counter].Pin_Num <= 0x0F)
                {
                    if(Port_Pins[PinId_Counter].Pin_Num <= 7)
                    {
                        Port_Ptr_CR = &PORTC_CRL;
                    }
                    else
                    {
                        Port_Ptr_CR = &PORTC_CRH;
                    }
                }
                else
                {
                    /**< wrong Pin_Num */
                }
                break;

            default:
                /**< error wrong port number */
							break;
            /* end of Port_Num switch case */
            }

            //After pointing to the BSRR, CRLx, CRHx; we modify these registers using the "MODIFY_BSRR_REG" function
            MODIFY_BSRR_REG(*Port_Ptr_BSRR , Port_Pins[PinId_Counter].Pin_Num , Port_Pins[PinId_Counter].Pin_initial_value);





            /**<
                Modifying CRx registers based on Pin_direction either (in/out)
                    with Configrations:
                            input :  Analog, Floating, Pull Down, Pull Up
                            output:  AF_Open Drain, AF_Push Pull, GP_Open Drain, GP_Push Pull

             */
            if(Port_Pins[PinId_Counter].Pin_direction == PORT_PIN_IN)
            {
                switch (Port_Pins[PinId_Counter].Pin_driven_mode)
                {
                case Analog:
                    /*make macro funs for both of the 2 macros*/
                    MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[PinId_Counter].Pin_Num , Analog_Config);
                    break;

                case Floating:
                    /*make macro funs for both of the 2 macros*/
                    MODIFY_CR_REG(*Port_Ptr_CR,Port_Pins[PinId_Counter].Pin_Num,Floating_Config);
                    break;

                case PullDown:
                    /*make macro funs for both of the 2 macros*/
                    MODIFY_CR_REG(*Port_Ptr_CR,Port_Pins[PinId_Counter].Pin_Num,PullDown_Config);
                    break;

                case PullUp:
                    /*make macro funs for both of the 2 macros*/
                    MODIFY_CR_REG(*Port_Ptr_CR,Port_Pins[PinId_Counter].Pin_Num,PullUp_Config);
                    break;

                default:
                    /**< error wrong Pin_driven_mode */
								 break;
                /* end of switch case Pin_driven_mode checking */
                }

            /* end of if condition Pin_direction checking */
            }
            else if (Port_Pins[PinId_Counter].Pin_direction == PORT_PIN_OUT)
            {
                switch (Port_Pins[PinId_Counter].Pin_driven_mode)
                {
                case AF_Open_drain :
                    /*make macro funs for both of the 2 macros*/
                    MODIFY_CR_REG(*Port_Ptr_CR,Port_Pins[PinId_Counter].Pin_Num,AF_Open_drain_Config);
                    break;

                case AF_Push_Pull :
                    /*make macro funs for both of the 2 macros*/
                    MODIFY_CR_REG(*Port_Ptr_CR,Port_Pins[PinId_Counter].Pin_Num,AF_Push_Pull_Config);
                    break;

                case GPIO_Open_drain :
                    /*make macro funs for both of the 2 macros*/
                    MODIFY_CR_REG(*Port_Ptr_CR,Port_Pins[PinId_Counter].Pin_Num,GPIO_Open_drain_Config);
                    break;

                case GPIO_Push_Pull :
                    /*make macro funs for both of the 2 macros*/
                    MODIFY_CR_REG(*Port_Ptr_CR,Port_Pins[PinId_Counter].Pin_Num,GPIO_Push_Pull_Config);
                    break;

                default:
                    /**< error wrong Pin_driven_mode */
										break;
                /* end of switch case Pin_driven_mode checking */
                }

            /* end of if condition Pin_direction checking */
            }

            /* else of Pin_direction checking */
            else
            {
                /**< error wrong Pin_direction */
            }

        /* end of for loop */
        }

    /* end of Det error checking */
    }

/* end of init function */
}


/**
  ******************************************************************************
  *
  * @Service[Name]:      Port_SetPinDirection
  * @Syntax:             void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
  * @Service[ID]:        0x01
  * @Sync>Async:         Synchronous
  * @Reentrancy:         Reentrant
  * @Parameters[in]: Pin :       Port Pin ID number
                     Direction:  Port Pin Direction
  * @Parameters[inout]:  None
  * @Parameters[out]:    None
  * @ReturnValue:        None
  * @Description:        Sets the port pin direction
  *
  ******************************************************************************
  */
#if(IS_PORT_DIRECTION_CHANGEABLE_DURING_RUNTIME == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
    /* pointer to point to the specific CR register of a Specific port */
    Port_PortRegisterType Port_Ptr_CR = NULL_PTR;
    boolean error = FALSE;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Driver is initialized before using this function */
    if ( !IS_PORT_MODULE_INITIALIZED(Port_Status) )
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }


    /* Check if the used channel is within the valid range */
    if ( !(IS_PORT_PARAM_PIN(Pin)) )
    {

        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
        error = TRUE;
    }
    else
    {
        /* No action Required */
    }

#endif

    /* In-case there are no errors */
    if(FALSE == error)
    {
        switch( Port_Pins[Pin].Port_Num )
        {
        case 0:
            if(Port_Pins[Pin].Pin_Num <= 7)
            {
                Port_Ptr_CR = &PORTA_CRL;
            }
            else
            {
                Port_Ptr_CR = &PORTA_CRH;
            }
            break;

        case 1:
            if(Port_Pins[Pin].Pin_Num <= 7)
            {
                Port_Ptr_CR = &PORTB_CRL;
            }
            else
            {
                Port_Ptr_CR = &PORTB_CRH;
            }
            break;

        case 2:
            if(Port_Pins[Pin].Pin_Num <= 7)
            {
                Port_Ptr_CR = &PORTC_CRL;
            }
            else
            {
                Port_Ptr_CR = &PORTC_CRH;
            }
            break;

        default:
            /* No action Required */
				break;
        }

        if(Direction == PORT_PIN_IN)
        {
            MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Floating_Config);
        }

        else if(Direction == PORT_PIN_OUT)
        {
            MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , GPIO_Push_Pull_Config);
        }

        else
        {
            /* error wrong direction */
        }
    }

    else
    {
        /* No action Required */
    }

}
#endif
/**
  ******************************************************************************
  *
  * @Service[Name]:      Port_RefreshPortDirection
  * @Syntax:             void Port_RefreshPortDirection( void )
  * @Service[ID]:        0x02
  * @Sync>Async:         Synchronous
  * @Reentrancy:         Non Reentrant
  * @Parameters[in]:     None
  * @Parameters[inout]:  None
  * @Parameters[out]:    None
  * @ReturnValue:        None
  * @Description:        Refreshes port direction
  *
  ******************************************************************************
  */
#if (IS_PORT_DIRECTION_CHANGEABLE_DURING_RUNTIME == STD_ON)
void Port_RefreshPortDirection(void)
{
    /* pointer to point to the specific CR register of a Specific port */
    Port_PortRegisterType *Port_Ptr_CR = NULL_PTR;
    boolean error = FALSE;
	
#if (DIO_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Driver is initialized before using this function */
    if (PORT_NOT_INITIALIZED == Port_Status)
    {
        Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                        PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
        error = TRUE;
    }

    /* there is no errors */
    else
#endif
    {
        /* Refresh port direction */
    }

}
#endif
/**
  ******************************************************************************
  *
  * @Service[Name]:      Port_GetVersionInfo
  * @Syntax:             void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
  * @Service[ID]:        0x03
  * @Sync>Async:         Synchronous
  * @Reentrancy:         Non Reentrant
  * @Parameters[in]:     None
  * @Parameters[inout]:  None
  * @Parameters[out]:    versioninfo Pointer to where to store the version information of this module.
  * @ReturnValue:        None
  * @Description:        Returns the version information of this module.
  *
  ******************************************************************************
  */
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if input pointer is not Null pointer */
    if(IS_PORT_PARAM_NULL_POINTER(versioninfo))
    {
        /* Report to DET  */
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
    }
    /* there is no errors */
    else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
    {
        /* Copy the vendor Id */
        versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
        /* Copy the module Id */
        versioninfo->moduleID = (uint16)PORT_MODULE_ID;
        /* Copy Software Major Version */
        versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
    }
}
#endif

/**
  ******************************************************************************
  *
  * @Service[Name]:      Port_SetPinMode
  * @Syntax:             void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
  * @Service[ID]:        0x04
  * @Sync>Async:         Synchronous
  * @Reentrancy:         Reentrant
  * @Parameters[in]: Pin Port:  Pin ID number
                                Mode New Port Pin mode to be set on port pin.
  * @Parameters[inout]:  None
  * @Parameters[out]:    None
  * @ReturnValue:        None
  * @Description:        Sets the port pin mode.
  *
  ******************************************************************************
  */
#if (IS_PORT_MODE_CHANGEABLE_DURING_RUNTIME == STD_ON)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
    /* pointer to point to the specific CR register of a Specific port */
    Port_PortRegisterType Port_Ptr_CR = NULL_PTR;
    boolean error = FALSE;
#if (DIO_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Driver is initialized before using this function */
    if (PORT_NOT_INITIALIZED == Port_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
        error = TRUE;
    }
    else
    {
        /* No action Required */
    }

    if ( !(IS_PORT_PARAM_PIN(Pin)) )
    {

        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
        error = TRUE;
    }
    else
    {
        /**< No action Required */
    }
#endif

    /* In-case there are no errors */
    if(FALSE == error)
    {

        switch( Port_Pins[Pin].Port_Num )
        {
        case 0:
            if(Port_Pins[Pin].Pin_Num <= 7)
            {
                Port_Ptr_CR = &PORTA_CRL;
            }
            else
            {
                Port_Ptr_CR = &PORTA_CRH;
            }
            break;

        case 1:
            if(Port_Pins[Pin].Pin_Num <= 7)
            {
                Port_Ptr_CR = &PORTB_CRL;
            }
            else
            {
                Port_Ptr_CR = &PORTB_CRH;
            }
            break;

        case 2:
            if(Port_Pins[Pin].Pin_Num <= 7)
            {
                Port_Ptr_CR = &PORTC_CRL;
            }
            else
            {
                Port_Ptr_CR = &PORTC_CRH;
            }
            break;

        default:
            /* No action Required */
						 break;
        }

        switch(Pin)
        {
        case (0):
        case (1):
        case (2):
        case (3):
            switch(Mode)
            {
            case(PORT_PIN_MODE_ADC):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Analog_Config);
                break;

            /* USART not supported in AUTOSAR */
//            case():
//
//                break;

            /**< there are 2 modes of timer's channels input capture and output compare */
            case(PORT_PIN_MODE_ICU):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Floating_Config);
                break;

            case(PORT_PIN_MODE_PWM):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , AF_Push_Pull_Config);
                break;

            default:
                /* error wrong Mode */
								 break;
            }
            break;

        case (4):
            switch(Mode)
            {

            /* USART not supported in AUTOSAR */
//            case():
//
//                break;
            case(PORT_PIN_MODE_ADC):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Analog_Config);
                break;

            /**< SPI has many modes check reference manual */
            case(PORT_PIN_MODE_SPI):
                /* i chose SPIx_NSS as Software */
               /* No action Required */
                break;

            default:
                /* error wrong Port_A_PIN_4 Mode */
								 break;
            }
            break;

        case (5):
           switch(Mode)
            {
            case(PORT_PIN_MODE_ADC):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Analog_Config);
                break;

            /**< SPI has many modes check reference manual */
            case(PORT_PIN_MODE_SPI):
                /* i chose SPIx_SCK as slave */
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Floating_Config);
                break;

            default:
                /* error wrong Port_A_PIN_5 Mode */
								 break;
            }
            break;

        case (6):
            switch(Mode)
            {
            case(PORT_PIN_MODE_ADC):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Analog_Config);
                break;

             /* i chose SPIx_SCK as slave */
            case(PORT_PIN_MODE_SPI):
                /* i chose SPIx_SCK as slave (Point to Point) */
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , AF_Push_Pull_Config);
                break;

            case(PORT_PIN_MODE_ICU):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Floating_Config);
                break;

            case(PORT_PIN_MODE_PWM):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , AF_Push_Pull_Config);
                break;

            default:
                /* error wrong Port_A_PIN_6 Mode */
								 break;
            }
            break;

        case (7):
            switch(Mode)
            {
            case(PORT_PIN_MODE_ADC):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Analog_Config);
                break;

            case(PORT_PIN_MODE_SPI):
                /* i chose SPIx_SCK as full duplex slave */
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Floating_Config);
                break;

            case(PORT_PIN_MODE_ICU):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Floating_Config);
                break;

            case(PORT_PIN_MODE_PWM):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , AF_Push_Pull_Config);
                break;

            default:
                /* error wrong Port_A_PIN_7 Mode */
								 break;
            }
            break;

        case (8):
        case (9):
        case (10):
            switch(Mode)
            {
            /* USART not supported in AUTOSAR */
//            case():
//
//                break;
            case(PORT_PIN_MODE_ICU):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Floating_Config);
                break;

            case(PORT_PIN_MODE_PWM):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , AF_Push_Pull_Config);
                break;

            default:
                /* error wrong Port_A_PIN_7 Mode */
								 break;
            }
            break;

        case (11):
            switch(Mode)
            {
            /* USART not supported in AUTOSAR */
//            case():
//
//                break;
            case(PORT_PIN_MODE_ICU):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Floating_Config);
                break;

            case(PORT_PIN_MODE_PWM):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , AF_Push_Pull_Config);
                break;

            case(PORT_PIN_MODE_CAN):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Floating_Config);
                break;

            default:
                /* error wrong Port_A_PIN_7 Mode */
								 break;
            }
            break;

        case (12):
            switch(Mode)
            {
            /* USART not supported in AUTOSAR */
//            case():
//
//                break;

            case(PORT_PIN_MODE_CAN):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , AF_Push_Pull_Config);
                break;

            default:
                /* error wrong Port_A_PIN_7 Mode */
								 break;
            }
            break;

        case (13):
            /* No thing to map */
            break;

        case (14):
        case (15):
            switch(Mode)
            {

            case(PORT_PIN_MODE_ADC):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Analog_Config);
                break;

            case(PORT_PIN_MODE_ICU):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Floating_Config);
                break;

            case(PORT_PIN_MODE_PWM):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , AF_Push_Pull_Config);
                break;

            default:
                /* error wrong Port_A_PIN_7 Mode */
								 break;
            }
            break;

        case (16):
        case (17):
        case (18):
           /**< there is no thing to map */
            break;

        case (19):
        case (20):
            switch(Mode)
            {
            /* USART not supported in AUTOSAR */
//            case():
//
//                break;

            case(PORT_PIN_MODE_ICU):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Floating_Config);
                break;

            case(PORT_PIN_MODE_PWM):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , AF_Push_Pull_Config);
                break;

            default:
                /* error wrong Port_A_PIN_7 Mode */
								 break;
            }
            break;

        case (21):
        case (22):
            switch(Mode)
            {
            case(PORT_PIN_MODE_ICU):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Floating_Config);
                break;

            case(PORT_PIN_MODE_PWM):
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , AF_Push_Pull_Config);
                break;

            default:
                /* error wrong Port_A_PIN_7 Mode */
								 break;
            }
            break;

        case (23):
        case (24):
            switch(Mode)
            {
            /* USART not supported in AUTOSAR */
//            case():
//
//                break;

            default:
                /* error wrong Port_A_PIN_7 Mode */
								 break;
            }
            break;

        case (25):
            switch(Mode)
            {
            /* USART not supported in AUTOSAR */
//            case():
//
//                break;

              case(PORT_PIN_MODE_SPI):
                /* i chose SPIx_NSS as Software */
               /* No action Required */
                break;

              default:
                /* error wrong Port_A_PIN_7 Mode */
								 break;
            }
            break;

        case (26):
            switch(Mode)
            {
            /* USART not supported in AUTOSAR */
//            case():
//
//                break;

              case(PORT_PIN_MODE_SPI):
                /* i chose SPIx_SCK as full duplex slave */
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Floating_Config);
                break;

              default:
                /* error wrong Port_A_PIN_7 Mode */
								 break;
            }
            break;

        case (27):
            switch(Mode)
            {
            /* USART not supported in AUTOSAR */
//            case():
//
//                break;

              case(PORT_PIN_MODE_SPI):
                /* i chose SPIx_MISO  */
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , AF_Push_Pull_Config);
                break;

              default:
                /* error wrong Port_A_PIN_7 Mode */
								 break;
            }
            break;

        case (28):
            switch(Mode)
            {
              case(PORT_PIN_MODE_SPI):
                /* i chose SPIx_MISO  */
                MODIFY_CR_REG(*Port_Ptr_CR , Port_Pins[Pin].Pin_Num , Floating_Config);
                break;

              default:
                /* error wrong Port_A_PIN_7 Mode */
								 break;
            }
            break;

        case (29):
        case (30):
        case (31):
            /**< Do nothing */
            break;

        }

    }
    else
    {
        /**< No action Required */
    }

}
#endif
