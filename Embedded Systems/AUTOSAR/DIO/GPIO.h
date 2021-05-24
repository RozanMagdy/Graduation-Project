//-----------Writing HAL_GPIO.h
#ifndef GPIO_H
#define GPIO_H

#include "std_types.h"
#include "Dio_Regs.h"
#include "GPIO_config.h"
#include "Delay.h"

typedef enum{
	PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG
}PORT;


#define LOW 0
#define HIGH 1

//
//Input Modes Types
#define INPUT_ANALOG   ((uint8) 0x00) //Analog mode
#define INPUT_FLOATING ((uint8) 0x01)//Floating input (reset state)
#define INPUT_PU_PD    ((uint8) 0x08)//Input with pull-up / pull-down (0b1000 = 0x08)

//Outout Modes Types
#define OUTPUT_PU_PU         ((uint8) ((0x00<<2) | OUT_SPEED) ) //General purpose output push-pull
#define OUTPUT_OPEN_DRAIN    ((uint8) ((0x01<<2) | OUT_SPEED) ) //General purpose output Open-drain
#define OUTPUT_AF_PU_PU      ((uint8) ((0x02<<2) | OUT_SPEED) ) //Alternate function output Push-pull
#define OUTPUT_AF_OPEN_DRAIN ((uint8) ((0x03<<2) | OUT_SPEED) ) //Alternate function output Open-drain (0x03 = 0b11)


//CLK enabling; because we need to enable the clock each time 
//								we want a specific register to work.
#define GPIO_CLK_ENABLE_AF (RCC_APB2ENR |= (1<<0))//bit 0
//alternate function is used when we handle the interrupts
//
#define GPIO_CLK_ENABLE_PORTA (RCC_APB2ENR |= (1<<2))//bit 2
#define GPIO_CLK_ENABLE_PORTB (RCC_APB2ENR |= (1<<3))//bit 3
#define GPIO_CLK_ENABLE_PORTC (RCC_APB2ENR |= (1<<4))//bit 4
#define GPIO_CLK_ENABLE_PORTD (RCC_APB2ENR |= (1<<5))//bit 5
#define GPIO_CLK_ENABLE_PORTE (RCC_APB2ENR |= (1<<6))//bit 6
//***********************************************************

//Function Prototypes : 
void GPIO_voidInit(void);
//this function set configration for all pins on the Blue Pill
//setting the "configration" part in CRH or CRL 
//and also: //setting Mode (input OR output with speed)
//............................................................................
void GPIO_void_SetPinValue(PORT port, uint8 pin, uint8 state);
//this functions writes either 1 or 0 on a specific pin.
// it takes 3 parameters.
//GPIO_TypeDef * GPIOx is either GPIOA, GPIOB, GPIOC, AF
// uint pin number
//the U8 state is either 1 or 0 == ON or OFF
//............................................................................
uint8 GPIO_uint8_GetPinValue( PORT port , uint8 pin);
//this function gets value on specific pin. it takes 2  parameters.
//............................................................................


void Led_Tog(uint16 ms ,uint8 i);

#endif

