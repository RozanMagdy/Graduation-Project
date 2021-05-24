#ifndef __USART_Config_H
#define __USART_Config_H

#define USART_USED USART1  // the usart periheral you wish to use 
/*
Supported usart peripherals are:
USART1
USART2
USART3
UART4
UART5
*/

//Setup Configurations For USART
#define USART_BAUDRATE 9600    // Choose the communication baud rates as 9600 or 115200 or higher depeinding on the serial port defined baud rates 
#define USART_WORDLENGTH USART_WordLength_8b     // USART_WordLength indicates the number of data bits transmitted or received in a frame.
/*
supported values are:
for 8 bits Data : USART_WordLength_8b
for 9 bits Data : USART_WordLength_9b
*/
#define USART_STOPBITS USART_StopBits_1 //USART_StopBits defines the number of stop bits transmitted.
/*
supported values are:
USART_StopBits_1 : 1 stop bit is transmitted at the end of frame,
USART_StopBits_0_5 : 0.5 stop bit is transmitted at the end of frame,
USART_StopBits_2 : 2 stop bits are transmitted at the end of frame,
USART_StopBits_1_5 : 1.5 stop bit is transmitted at the end of frame.
*/
#define USART_PARITY USART_Parity_No  // USART_Parity defines the parity mode.
/*
supported values are:
USART_Parity_No : Parity Disable,
USART_Parity_Even : Even Parity,
USART_Parity_Odd : Odd Parity.
*/
#define USART_MODE USART_Mode_Rx | USART_Mode_Tx  // this value was selected to enable both transmission and recieving .
/*
supported values are:
USART_Mode_Tx : Transmit enabled,
USART_Mode_Rx : Receive enabled.
*/
#define USART_HARDWAREFLOWCONTROL   USART_HardwareFlowControl_None  //  USART_HardwareFlowControl specifies wether the hardware flow control mode is enabled or disabled.
/*
supported values are:
USART_HardwareFlowControl_None HFC Disabled,
USART_HardwareFlowControl_RTS RTS enabled,
USART_HardwareFlowControl_CTS CTS enabled,
USART_HardwareFlowControl_RTS_CTS RTS and CTS enabled.
*/
#endif /* __USART_Config */
