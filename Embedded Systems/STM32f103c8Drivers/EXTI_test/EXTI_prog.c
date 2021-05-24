/**
  ******************************************************************************
  * @file    exti_prog.c
	* @editor	 Ashraf_Amgad AUTOCAN_Embedded_team
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file provides EXTI firmware functions.
  ******************************************************************************
	*/



/* Includes ------------------------------------------------------------------*/
/*============*/
#include "EXTI.h"


/** @(EXTI.h)
  * @@brief 	file that contains prototypes of EXTI firmware functions
  */
	
	

/** 
	*		 global pointers to functions ,
	*		 point to the handler function of a specific external interrupt line 
	*/
	
	
/* pointer to function points to the handler function of line 0 */	
void(*EXTI0_IRQ_TEMP_FUNCTION)(void) = 0;

/* pointer to function points to the handler function of line 1 */
void(*EXTI1_IRQ_TEMP_FUNCTION)(void) = 0;

/* pointer to function points to the handler function of line 2 */
void(*EXTI2_IRQ_TEMP_FUNCTION)(void) = 0;

/* pointer to function points to the handler function of line 3 */
void(*EXTI3_IRQ_TEMP_FUNCTION)(void) = 0;

/* pointer to function points to the handler function of line 4 */
void(*EXTI4_IRQ_TEMP_FUNCTION)(void) = 0;




/* FUNCTION  DEFINITION ------------------------------------------------------*/
/*=========================*/

/**
  * @brief  this function configures EXTI pins according to configurations in " EXTI_conf.h " 
	*					 
  * @param  None
  * @retval None
  */
	
void EXTI_voidInit(void)
{
	
	/* enable AF clk (don't delete it) */
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; 
	
	
	/* CHECK FOR EDAGE DETECTOR ------------------------------------------------------*/
	/*=============================*/
	
	#if ( EXTI_LINE_0_TRIGER	== EXTI_RISING_EDAGE )
			EXTI->RTSR |= EXTI_RTSR_TR0; 
			EXTI->FTSR &= ~(EXTI_FTSR_TR0); 
	#elif ( EXTI_LINE_0_TRIGER	== EXTI_FALLING_EDAGE )
			EXTI->RTSR &= ~(EXTI_RTSR_TR0); 
			EXTI->FTSR |= EXTI_FTSR_TR0;
	#else // ( (EXTI_LINE_0_TRIGER	== EXTI_FALLING_EDAGE)  || (EXTI_LINE_0_TRIGER	== EXTI_RISING_EDAGE))
			EXTI->RTSR |= EXTI_RTSR_TR0; 
			EXTI->FTSR |= EXTI_FTSR_TR0;
	#endif
	
	
	#if ( EXTI_LINE_1_TRIGER	== EXTI_RISING_EDAGE )
			EXTI->RTSR |= EXTI_RTSR_TR1; 
			EXTI->FTSR &= ~(EXTI_FTSR_TR1);  
	#elif ( EXTI_LINE_1_TRIGER	== EXTI_FALLING_EDAGE )
			EXTI->RTSR &= ~(EXTI_RTSR_TR1); 
			EXTI->FTSR |= EXTI_FTSR_TR1;
	#else // ( (EXTI_LINE_0_TRIGER	== EXTI_FALLING_EDAGE)  || (EXTI_LINE_0_TRIGER	== EXTI_RISING_EDAGE))
			EXTI->RTSR |= EXTI_RTSR_TR1; 
			EXTI->FTSR |= EXTI_FTSR_TR1;
	#endif
	
	#if ( EXTI_LINE_2_TRIGER	== EXTI_RISING_EDAGE )
			EXTI->RTSR |= EXTI_RTSR_TR2; 
			EXTI->FTSR &= ~(EXTI_FTSR_TR2);  
	#elif ( EXTI_LINE_2_TRIGER	== EXTI_FALLING_EDAGE )
			EXTI->RTSR &= ~(EXTI_RTSR_TR2); 
			EXTI->FTSR |= EXTI_FTSR_TR2;
	#else // ( (EXTI_LINE_2_TRIGER	== EXTI_FALLING_EDAGE)  || (EXTI_LINE_2_TRIGER	== EXTI_RISING_EDAGE))
			EXTI->RTSR |= EXTI_RTSR_TR2; 
			EXTI->FTSR |= EXTI_FTSR_TR2;
	#endif
	
	#if ( EXTI_LINE_3_TRIGER	== EXTI_RISING_EDAGE )
			EXTI->RTSR |= EXTI_RTSR_TR3; 
			EXTI->FTSR &= ~(EXTI_FTSR_TR3); 
	#elif ( EXTI_LINE_3_TRIGER	== EXTI_FALLING_EDAGE )
			EXTI->RTSR &= ~(EXTI_RTSR_TR3); 
			EXTI->FTSR |= EXTI_FTSR_TR3;
	#else // ( (EXTI_LINE_3_TRIGER	== EXTI_FALLING_EDAGE)  || (EXTI_LINE_3_TRIGER	== EXTI_RISING_EDAGE))
			EXTI->RTSR |= EXTI_RTSR_TR3; 
			EXTI->FTSR |= EXTI_FTSR_TR3;
	#endif
	
	#if ( EXTI_LINE_4_TRIGER	== EXTI_RISING_EDAGE )
			EXTI->RTSR |= EXTI_RTSR_TR4; 
			EXTI->FTSR &= ~(EXTI_FTSR_TR4); 
	#elif ( EXTI_LINE_4_TRIGER	== EXTI_FALLING_EDAGE )
			EXTI->RTSR &= ~(EXTI_RTSR_TR4); 
			EXTI->FTSR |= EXTI_FTSR_TR4;
	#else // ( (EXTI_LINE_4_TRIGER	== EXTI_FALLING_EDAGE)  || (EXTI_LINE_4_TRIGER	== EXTI_RISING_EDAGE))
			EXTI->RTSR |= EXTI_RTSR_TR4; 
			EXTI->FTSR |= EXTI_FTSR_TR4;
	#endif
	

	/** CONFIGURATION OF  LINES AND PINS ------------------------------------------------------*
		*=======================================
		* ------------	PORTA	-----------------	
		*=======================================
		*/	
	#if (EXTI_PORTA_PIN_0	== EXTI_INIT)
			/*clear pin configrations position to ensure you write specified configrations */
			GPIOA->CRL &= ~(GPIO_CRL_CNF0 | GPIO_CRL_MODE0);
			/* gpio pin config input floating*/
			GPIOA->CRL |= GPIO_CRL_CNF0_0;
			/* line 0 ( pin 0 of all ports )*/ 
			EXTI->IMR |= EXTI_IMR_MR0;
			/* choose the specific pin and port */
			AFIO->EXTICR[0] &= ~(0x000f << 0);
			/* enable line_interrupt in NVIC */
			NVIC_EnableIRQ(EXTI0_IRQn);
	#endif
	
	#if (EXTI_PORTA_PIN_1	== EXTI_INIT)
			/*clear pin configrations position to ensure you write specified configrations */
			GPIOA->CRL &= ~(GPIO_CRL_CNF1 | GPIO_CRL_MODE1);
			/* gpio pin config input floating*/
			GPIOA->CRL |= GPIO_CRL_CNF1_0;
			/* line 1 ( pin 1 of all ports )*/ 
			EXTI->IMR |= EXTI_IMR_MR1;
			/* choose the specific pin and port */
			AFIO->EXTICR[0] &= ~((uint16_t)0x000f << 4);
			/* enable line_interrupt in NVIC */
			NVIC_EnableIRQ(EXTI1_IRQn);
	#endif
	
	#if (EXTI_PORTA_PIN_2	== EXTI_INIT)
			/*clear pin configrations position to ensure you write specified configrations */
			GPIOA->CRL &= ~(GPIO_CRL_CNF2 | GPIO_CRL_MODE2);
			/* gpio pin config input floating*/
			GPIOA->CRL |= GPIO_CRL_CNF2_0;
			/* line 2 ( pin 2 of all ports )*/ 
			EXTI->IMR |= EXTI_IMR_MR2;
			/* choose the specific pin and port */
			AFIO->EXTICR[0] &= ~((uint16_t)0x000f << 8);
			/* enable line_interrupt in NVIC */
			NVIC_EnableIRQ(EXTI2_IRQn);
	#endif
	
	#if (EXTI_PORTA_PIN_3	== EXTI_INIT)
			/*clear pin configrations position to ensure you write specified configrations */
			GPIOA->CRL &= ~(GPIO_CRL_CNF3 | GPIO_CRL_MODE3);
			/* gpio pin config input floating*/
			GPIOA->CRL |= GPIO_CRL_CNF3_0;
			/* line 3 ( pin 3 of all ports )*/ 
			EXTI->IMR |= EXTI_IMR_MR3;
			/* choose the specific pin and port */
			AFIO->EXTICR[0] &= ~((uint16_t)0x000f << 12); 
			/* enable line_interrupt in NVIC */
			NVIC_EnableIRQ(EXTI3_IRQn);
	#endif
	
	#if (EXTI_PORTA_PIN_4	== EXTI_INIT)
			/*clear pin configrations position to ensure you write specified configrations */
			GPIOA->CRL &= ~(GPIO_CRL_CNF4 | GPIO_CRL_MODE4);
			/* gpio pin config input floating*/
			GPIOA->CRL |= GPIO_CRL_CNF4_0;
			/* line 4 ( pin 4 of all ports )*/ 
			EXTI->IMR |= EXTI_IMR_MR4;
			/* choose the specific pin and port */
			AFIO->EXTICR[1] &= ~((uint16_t)0x000f << 0);
			/* enable line_interrupt in NVIC */
			NVIC_EnableIRQ(EXTI4_IRQn);
	#endif


	/** CONFIGURATION OF  LINES AND PINS ------------------------------------------------------*
		*=======================================
		* ------------	PORTB	-----------------	
		*=======================================
		*/
		
	#if (EXTI_PORTB_PIN_0	== EXTI_INIT)
			/*clear pin configrations position to ensure you write specified configrations */
			GPIOB->CRL &= ~(GPIO_CRL_CNF0 | GPIO_CRL_MODE0);
			/* gpio pin config input floating*/
			GPIOB->CRL |= GPIO_CRL_CNF0_0;
			/* line 0 ( pin 0 of all ports )*/ 
			EXTI->IMR |= EXTI_IMR_MR0;
			/* choose the specific pin and port */
			AFIO->EXTICR[0] |= AFIO_EXTICR1_EXTI0_PB;
			/* enable line_interrupt in NVIC */
			NVIC_EnableIRQ(EXTI0_IRQn);
	#endif
	
	#if (EXTI_PORTB_PIN_1	== EXTI_INIT)
			/*clear pin configrations position to ensure you write specified configrations */
			GPIOB->CRL &= ~(GPIO_CRL_CNF1 | GPIO_CRL_MODE1);
			/* gpio pin config input floating*/
			GPIOB->CRL |= GPIO_CRL_CNF1_0;
			/* line 1 ( pin 1 of all ports )*/ 
			EXTI->IMR |= EXTI_IMR_MR1;
			/* choose the specific pin and port */
			AFIO->EXTICR[0] |= AFIO_EXTICR1_EXTI1_PB;
			/* enable line_interrupt in NVIC */
			NVIC_EnableIRQ(EXTI1_IRQn);
	#endif
	
	#if (EXTI_PORTB_PIN_2	== EXTI_INIT)
			/*clear pin configrations position to ensure you write specified configrations */
			GPIOB->CRL &= ~(GPIO_CRL_CNF2 | GPIO_CRL_MODE2);
			/* gpio pin config input floating*/
			GPIOB->CRL |= GPIO_CRL_CNF2_0;
			/* line 2 ( pin 2 of all ports )*/ 
			EXTI->IMR |= EXTI_IMR_MR2;
			/* choose the specific pin and port */
			AFIO->EXTICR[0] |= AFIO_EXTICR1_EXTI2_PB; 
			/* enable line_interrupt in NVIC */
			NVIC_EnableIRQ(EXTI2_IRQn);			
	#endif
	
	#if (EXTI_PORTB_PIN_3	== EXTI_INIT)
			/*clear pin configrations position to ensure you write specified configrations */
			GPIOB->CRL &= ~(GPIO_CRL_CNF3 | GPIO_CRL_MODE3);
			/* gpio pin config input floating*/
			GPIOB->CRL |= GPIO_CRL_CNF3_0;
			/* line 3 ( pin 3 of all ports )*/ 
			EXTI->IMR |= EXTI_IMR_MR3;
			/* choose the specific pin and port */
			AFIO->EXTICR[0] |= AFIO_EXTICR1_EXTI3_PB;
			/* enable line_interrupt in NVIC */
			NVIC_EnableIRQ(EXTI3_IRQn);
	#endif

			
	#if (EXTI_PORTB_PIN_4	== EXTI_INIT)
			/*clear pin configrations position to ensure you write specified configrations */
			GPIOB->CRL &= ~(GPIO_CRL_CNF4 | GPIO_CRL_MODE4);
			/* gpio pin config input floating*/
			GPIOB->CRL |= GPIO_CRL_CNF4_0;
			/* line 4 ( pin 4 of all ports )*/ 
			EXTI->IMR |= EXTI_IMR_MR4;
			/* choose the specific pin and port */
			AFIO->EXTICR[1] |= AFIO_EXTICR2_EXTI4_PB;
			/* enable line_interrupt in NVIC */
			NVIC_EnableIRQ(EXTI4_IRQn);
	#endif
	

}




/**
  * @brief  this function clears a line interrupt flag 
	*					 
  * @param  LINE_NUMBER  	it's the line you want to clear its flag
	*						i.e					EXTI_LINE_0 ,EXTI_LINE_1 ,EXTI_LINE_2 ......EXTI_LINE_4
	*
  * @retval None
  */


/**	@attention
	*							you have to clear the interrupt flag by yourself ,
	*							by writing 1 to the desired line flag.
	*
	*/
void EXTI_voidClearIntFlag(uint16_t LINE_NUMBER)
{
	/* clear line flag*/
	EXTI->PR |= ( (uint16_t)0x01 << LINE_NUMBER );
	
}



/**
  * @brief  this function stores your handler function address of line 0 
	*					 
  * @param  EXTI0_IRQ_FUNCTION   address of a function ,
	*															 handler function address of line 0 
	*
  * @retval None
  */


void EXTI0_voidIRQ( void(*EXTI0_IRQ_FUNCTION)(void) )
{
	/* store handler function address of line 0 in pointer to function */
	EXTI0_IRQ_TEMP_FUNCTION = EXTI0_IRQ_FUNCTION; 
}


/**
  * @brief  this function stores your handler function address of line 1 
	*					 
  * @param  EXTI1_IRQ_FUNCTION   address of a function ,
	*															 handler function address of line 1
	*
  * @retval None
  */

void EXTI1_voidIRQ( void(*EXTI1_IRQ_FUNCTION)(void) )
{
	/* store handler function address of line 1 in pointer to function */
	EXTI1_IRQ_TEMP_FUNCTION = EXTI1_IRQ_FUNCTION; 
}


/**
  * @brief  this function stores your handler function address of line 2 
	*					 
  * @param  EXTI2_IRQ_FUNCTION   address of a function ,
	*															 handler function address of line 2
	*
  * @retval None
  */

void EXTI2_voidIRQ( void(*EXTI2_IRQ_FUNCTION)(void) )
{
	/* store handler function address of line 2 in pointer to function */
	EXTI2_IRQ_TEMP_FUNCTION = EXTI2_IRQ_FUNCTION; 
}


/**
  * @brief  this function stores your handler function address of line 3 
	*					 
  * @param  EXTI3_IRQ_FUNCTION   address of a function ,
	*															 handler function address of line 3
	*
  * @retval None
  */

void EXTI3_voidIRQ( void(*EXTI3_IRQ_FUNCTION)(void) )
{
	/* store handler function address of line 3 in pointer to function */
	EXTI3_IRQ_TEMP_FUNCTION = EXTI3_IRQ_FUNCTION; 
}


/**
  * @brief  this function stores your handler function address of line 4 
	*					 
  * @param  EXTI4_IRQ_FUNCTION   address of a function ,
	*															 handler function address of line 4
	*
  * @retval None
  */


void EXTI4_voidIRQ( void(*EXTI4_IRQ_FUNCTION)(void) )
{
	/* store handler function address of line 4 in pointer to function */
	EXTI4_IRQ_TEMP_FUNCTION = EXTI4_IRQ_FUNCTION; 
}



/**
  * @brief  IRQHandler of line 0 
	*					 
  * @param  None
	*
  * @retval None
  */


void EXTI0_IRQHandler()
{
		/* call back you handler function of line 0 */
		EXTI0_IRQ_TEMP_FUNCTION();
	/* clear interrupt falg of line 0 (you should do it by software) */
	EXTI_voidClearIntFlag(EXTI_LINE_0);
}



/**
  * @brief  IRQHandler of line 1
	*					 
  * @param  None
	*
  * @retval None
  */

void EXTI1_IRQHandler()
{
		/* call back you handler function of line 1 */
		EXTI1_IRQ_TEMP_FUNCTION();
	/* clear interrupt falg of line 1 (you should do it by software) */
	EXTI_voidClearIntFlag(EXTI_LINE_1);
}



/**
  * @brief  IRQHandler of line 2
	*					 
  * @param  None
	*
  * @retval None
  */

void EXTI2_IRQHandler()
{
		/* call back you handler function of line 2 */
		EXTI2_IRQ_TEMP_FUNCTION();
	/* clear interrupt falg of line 2 (you should do it by software) */
	EXTI_voidClearIntFlag(EXTI_LINE_2);

}



/**
  * @brief  IRQHandler of line 3 
	*					 
  * @param  None
	*
  * @retval None
  */

void EXTI3_IRQHandler()
{
		/* call back you handler function of line 3 */
		EXTI3_IRQ_TEMP_FUNCTION();
	/* clear interrupt falg of line 3 (you should do it by software) */
	EXTI_voidClearIntFlag(EXTI_LINE_3);

}



/**
  * @brief  IRQHandler of line 4 
	*					 
  * @param  None
	*
  * @retval None
  */

void EXTI4_IRQHandler()
{
		/* call back you handler function of line 4 */
		EXTI4_IRQ_TEMP_FUNCTION();
	/* clear interrupt falg of line 4 (you should do it by software) */
	EXTI_voidClearIntFlag(EXTI_LINE_4);

}


/*****END OF FILE****/
