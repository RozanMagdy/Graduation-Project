/**
  ******************************************************************************
  * @file    gpio.c
  * @author  Ahmed_Mohsen AUTOCAN_Embedded_team
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file provides GPIO firmware functions.
  ******************************************************************************
	*/



/* Includes ------------------------------------------------------------------*/
/*============*/
#include "GPIO.h"


/** @(GPIO.h)
  * @@brief 	file that contains prototypes of gpio firmware functions
  */
	


/* FUNCTION  DEFINITION ------------------------------------------------------*/
/*=========================*/

/**
  * @brief  this function configures each pin to be ready to use. it reads directly 
	*					from "GPIO_conf.h".
	*					if the pin 
  * @param  None
  * @retval None
  */
	
void GPIO_voidInit(void)
{ 
	
	/** we check if we want to use PORTA or not to enable its clock 
	  * if we want to use this port we can choose it from GPIO_config.h */
	#if (GPIO_A == GPIO_INIT)
		GPIO_CLK_ENABLE_PORTA;
  #endif
	
	
	/** we check if we want to use PORTB or not to enable its clock 
	  * if we want to use this port we can choose it from GPIO_config.h */
	#if (GPIO_B == GPIO_INIT)
		GPIO_CLK_ENABLE_PORTB;
	#endif
	
	
	/** we check if we want to use PORTC or not to enable its clock 
	  * if we want to use this port we can choose it from GPIO_config.h */
  #if (GPIO_C == GPIO_INIT)
		GPIO_CLK_ENABLE_PORTC;
  #endif

	
	/** we check if we want to use GPIO pins to any other prepheral (i.e UART) or not to enable its clock 
	  * if we want to use this port we can choose it from GPIO_config.h */
	#if (AF == GPIO_INIT)
	  GPIO_CLK_ENABLE_AF;
	#endif
	
	/**
		*	EACH PIN HAS 4 BITS TO CONFIGURE THE MODE (i.e OUTPUT_PP) AND MAX SPEED (i.e 50MHZ)
		* so we have 2 registers (CRL for 8_low_pins (0:7) and CLH for 8_high_pins (8:15)) 32_bits long for 16_pin of stm32f103c8
		*/
		
		
/* PORTA ......................................A) LOW PINs Config. ( CRL )*/
/* =======*/

	#if  GPIOA_PIN0 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOA->CRL &= ~((1<<0)|(1<<(1))| (1<<(2))|(1<<(3)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOA->CRL |=  (GPIOA_PIN0_MODE<<0);
	#endif
				
	#if GPIOA_PIN1 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOA->CRL &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOA->CRL |=  (GPIOA_PIN1_MODE<<4);
	#endif
				
	#if GPIOA_PIN2 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOA->CRL &= ~((1<<8)|(1<<(9))| (1<<(10))|(1<<(11)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOA->CRL |=  (GPIOA_PIN2_MODE<<8);
	#endif
				
	#if GPIOA_PIN3 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOA->CRL &= ~((1<<12)|(1<<(13))| (1<<(14))|(1<<(15)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOA->CRL |=  (GPIOA_PIN3_MODE<<12);
	#endif
				
	#if GPIOA_PIN4 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOA->CRL &= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOA->CRL |=  (GPIOA_PIN4_MODE<<16);
	#endif
				
	#if GPIOA_PIN5 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOA->CRL &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOA->CRL |=  (GPIOA_PIN5_MODE<<20);
	#endif
				
	#if GPIOA_PIN6 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOA->CRL &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOA->CRL |=  (GPIOA_PIN6_MODE<<24);
	#endif
				
	#if GPIOA_PIN7 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOA->CRL &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOA->CRL |=  (GPIOA_PIN7_MODE<<28);	
	#endif
	
	
	
/* PORTA................................B) HIGH PINs Config. ( CRH )*/
/* =======*/

	#if  GPIOA_PIN8 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOA->CRH &= ~((1<<0)|(1<<(1))| (1<<(2))|(1<<(3)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOA->CRH |=  (GPIOA_PIN8_MODE<<0);
	#endif
				
	#if GPIOA_PIN9 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOA->CRH &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOA->CRH|=  (GPIOA_PIN9_MODE<<4);
	#endif
	
	#if GPIOA_PIN10 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOA->CRH &= ~((1<<8)|(1<<(9))| (1<<(10))|(1<<(11)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOA->CRH |=  (GPIOA_PIN10_MODE<<8);
	#endif

	#if GPIOA_PIN11 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOA->CRH &= ~((1<<12)|(1<<(13))| (1<<(14))|(1<<(15)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOA->CRH |=  (GPIOA_PIN11_MODE<<12);
	#endif
	
	#if GPIOA_PIN12 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOA->CRH&= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOA->CRH |=  (GPIOA_PIN12_MODE<<16);
	#endif
	
		
	#if GPIOA_PIN15 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOA->CRH &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOA->CRH |=  (GPIOA_PIN15_MODE<<28);	
	#endif



/* PORTB ................................A) LOW PINs Config. ( CRL )*/
/* =======*/

	#if  GPIOB_PIN0 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOB->CRL &= ~((1<<0)|(1<<(1))| (1<<(2))|(1<<(3)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOB->CRL |=  (GPIOB_PIN0_MODE<<0);
	#endif
				
	#if GPIOB_PIN1 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOB->CRL &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOB->CRL |=  (GPIOB_PIN1_MODE<<4);
	#endif

	#if GPIOB_PIN3 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOB->CRL &= ~((1<<12)|(1<<(13))|(1<<(14))|(1<<(15)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOB->CRL |=  (GPIOB_PIN3_MODE<<12);
	#endif
	
	#if GPIOB_PIN4 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOB->CRL &= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOB->CRL |=  (GPIOB_PIN4_MODE<<16);
	#endif
	
	#if GPIOB_PIN5 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOB->CRL &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOB->CRL |=  (GPIOB_PIN5_MODE<<20);
	#endif
	
	#if GPIOB_PIN6 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOB->CRL &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOB->CRL |=  (GPIOB_PIN6_MODE<<24);
	#endif
		
	#if GPIOB_PIN7 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOB->CRL &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOB->CRL |=  (GPIOB_PIN7_MODE<<28);	
	#endif



/* PORTB ................................B) HIGH PINs Config. ( CRH )*/
/* =======*/

	#if  GPIOB_PIN8 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOB->CRH &= ~((1<<0)|(1<<(1))| (1<<(2))|(1<<(3)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOB->CRH |=  (GPIOB_PIN8_MODE<<0);
	#endif
				
	#if GPIOB_PIN9 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOB->CRH &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOB->CRH |=  (GPIOB_PIN9_MODE<<4);
	#endif
	
	#if GPIOB_PIN10 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOB->CRH &= ~((1<<8)|(1<<(9))| (1<<(10))|(1<<(11)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOB->CRH |=  (GPIOB_PIN10_MODE<<8);
	#endif

	#if GPIOB_PIN11 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOB->CRH &= ~((1<<12)|(1<<(13))| (1<<(14))|(1<<(15)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOB->CRH |=  (GPIOB_PIN11_MODE<<12);
	#endif
	
	#if GPIOB_PIN12 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOB->CRH&= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOB->CRH |=  (GPIOB_PIN12_MODE<<16);
	#endif
	
	#if GPIOB_PIN13 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOB->CRH &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOB->CRH |=  (GPIOB_PIN13_MODE<<20);
	#endif
	
	#if GPIOB_PIN14 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOB->CRH &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOB->CRH |=  (GPIOB_PIN14_MODE<<24);
	#endif
		
	#if GPIOB_PIN15 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOB->CRH &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOB->CRH |=  (GPIOB_PIN15_MODE<<28);	
	#endif
	
	
	
	/* PORTC................................B) HIGH PINs Config. ( CRH )*/
/* =======*/

	#if GPIOC_PIN13 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOC->CRH &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOC->CRH |=  (GPIOC_PIN13_MODE<<20);
	#endif
	
	#if GPIOC_PIN14 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOC->CRH &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOC->CRH |=  (GPIOC_PIN14_MODE<<24);
	#endif
		
	#if GPIOC_PIN15 == GPIO_INIT
				/* re-setting the 4 bits of the desired pin. */
				GPIOC->CRH &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				/* setting it with the configration that user enter in gpio_config.h */
				GPIOC->CRH |=  (GPIOC_PIN15_MODE<<28);	
	#endif		
}




/**
  * @brief  function that can write on the whole port or on a specific pin
  * @param  GPIO_TypeDef *port		which port you want to set or reset its pin
	*					i.e										GPIOA ,GPIOB and GPIOC. 							
	* @param  uint8_t pin						which pin of the port you want to set or reset 
	*					i.e										GPIO_Pin_0 ,GPIO_Pin_1 ...GPIO_Pin_15
	* @param  uint8_t state					choose if you want to write 1 or 0 tp the pin
	*					i.e										GPIO_SET and GPIO_RESET
  * @retval None
  */


void GPIO_voidSetPinValue(GPIO_TypeDef *PORT, uint16_t PIN_NUMBER, uint8_t STATE){
	
	if (STATE == GPIO_SET)
	{
		/* set the pin */ 
		PORT->BSRR |= PIN_NUMBER;
	}
	
	else	// (STATE == GPIO_RESET)
	{
		/* reset the pin */ 
		PORT->BRR |= PIN_NUMBER;
		//PORT->BSRR = (1<<(PIN_NUMBER+16));
	}
	
}


/**
  * @brief  function to read a specific pin
  * @param  GPIO_TypeDef *port		which port you want to read its pin
	*					i.e										GPIOA ,GPIOB and GPIOC. 							
	* @param  uint8_t pin						which pin of the port you want to read 
	*					i.e										GPIO_Pin_0 ,GPIO_Pin_1 ...GPIO_Pin_15
  * @retval None
  */

uint8_t GPIO_uint8GetPinValue( GPIO_TypeDef * PORT ,uint16_t PIN_NUMBER)
{
	uint16_t state;
		
	/* read port data from input data register and read your pin */
	state = ( (PORT->IDR) & PIN_NUMBER);	
	
	if(state == 0)
	{
		return 0;
	}
	
	else
	{
			return 1;
	}
	
	
}



/**
  * @brief  function to togle the led on PIN_13 of PORTC of stm32f103c8 (blue pill)
  * @param  uint16_t Delay_Time						delay time to togle the led 							
	* @param  uint8_t counter								how many times you want to togle the led 
  * @retval None
  */

/** @attention 
	*							don't forget to include Delay driver
	*/

void Led_Tog(uint16_t Delay_Time ,uint8_t counter)
{
	
	uint8_t j=0;
	 
 		for(j=0 ;j<counter ;j++)
		{
			/* SET the led on PIN_13 of PORTC*/ 
			GPIO_voidSetPinValue(GPIOC ,GPIO_Pin_13 ,GPIO_SET);
			
			/* wait for the delay time */
			Delay(Delay_Time);
			
			/* RESET the led on PIN_13 of PORTC*/ 
			GPIO_voidSetPinValue(GPIOC ,GPIO_Pin_13 ,GPIO_RESET);
			
			/* wait for the delay time */
			Delay(Delay_Time);
			
		}
		
}


/** AUTOCAN *****END OF FILE****/	
