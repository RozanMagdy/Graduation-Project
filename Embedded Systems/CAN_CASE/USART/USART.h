#ifndef __USART_H
#define __USART_H

#include "stm32f10x_usart.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

/* User defined function prototypes */
void USART_voidInit(void); 
void USART_PrintString(char* string);
void USART_PrintNumber(uint32_t number, uint8_t digit);

// Firmware use functions prototypes
/*
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState)
void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct)
void USART_SendData(USART_TypeDef* USARTx, u16 Data)
*/

// Firmware used functions description
/*
USART_Init : Initializes the USARTx peripheral according to the parameters specified
in the USART_InitStruct.
USART_Cmd : Enables or disables the specified USART peripheral.
USART_SendData : Transmits single data through the USARTx peripheral.
*/
#endif /* __USART */
