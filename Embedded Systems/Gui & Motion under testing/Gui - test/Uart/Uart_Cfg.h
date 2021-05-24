/**
  ******************************************************************************
  * @file    Uart_Cfg.h
  * @author  Omar_Hesham AUTOCAN_Embedded_team
	* @editor	 Ashraf_Amgad AUTOCAN_Embedded_team
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all configrations for UART firmware driver.  
  ******************************************************************************
	*/
  

/**@attention
	*							clk and gpio configrations for UART_x pins are without any remaping ,
	*							if you want to use remaping pins ,
	*							change clk and gpio configrations in Init function.
	*
	*/
	
	
/**					  ||----------------||----------------||----------------||
	*				  ||    UART_1		||		 UART_2	  ||	UART_3		||
	*	|-------------||----------------||----------------||----------------||
	*	|	  TX	  ||	PORTA_9	    ||		 PORTA_2  ||	PORTB_10	||
	*	|-------------||----------------||----------------||----------------||
	*	|	  RX	  ||	PORTA_10	||		 PORTA_3  ||	PORTB_11    ||
	*	|-------------||----------------||----------------||----------------||
	*	
	*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __UART_Conf_H
#define __UART_Conf_H


/** @first  			 
	*	choose the usart periheral you wish to use
	*										
	*	you can use to configure desired UART 
	*
	*										UART_INIT			,			UART_UNINIT		
	*/


#define USART_1_INIT				UART_INIT	

#define USART_2_INIT				UART_INIT

#define USART_3_INIT				UART_INIT	


  

/** @Second
	* configure the desired UART
	*/


/**	 Choose the communication baud rates 
	*	
	*	i.e				9600 , 	19200 ,	115200
	*
	*/	
#define 		USART_BAUDRATE 								9600 



/**		Choose the USART_WordLength
	*	
	*	i.e				USART_WordLength_8b			,		USART_WordLength_9b
	*
	*/
#define 		USART_WORDLENGTH 				USART_WordLength_8b     



/**		Choose the number of stop bits
	*	
	*	i.e				USART_StopBits_1			,		USART_StopBits_2
	*
	*/
#define	 		USART_STOPBITS 					USART_StopBits_1 



/**		Choose the parity mode
	*	
	*	i.e				USART_Parity_No				,			USART_Parity_Even			or			USART_Parity_Odd
	*
	*/
#define			 USART_PARITY 					USART_Parity_No





/**		Choose if you want to enable transmiter ,reciever or both
	*	
	*	i.e				to enable tansmiter						( USART_Mode_Tx )
	*						to enable reciever						( USART_Mode_Rx )
	*						to enable both of them				(USART_Mode_Rx | USART_Mode_Tx)	
	*
	*/
#define			 USART_MODE 						(USART_Mode_Rx | USART_Mode_Tx)  



/**		Choose the flow control mode
	*	
	*	supported values are:
	*													USART_HardwareFlowControl_None			 		HFC 	Disabled  (hardawre flow control disable), 
	*													USART_HardwareFlowControl_RTS 					RTS 	enabled ,
	*													USART_HardwareFlowControl_CTS					 	CTS 	enabled ,
	*													USART_HardwareFlowControl_RTS_CTS 			RTS	 and	 CTS	 enabled.
	*
	*/
#define 		USART_HARDWAREFLOWCONTROL  			 USART_HardwareFlowControl_None  



#endif /* __UART_Cfg */



