/**
  ******************************************************************************
  * @file    spi_prog.c
	* @editor	 Ahmed_Mohamed_Gamal AUTOCAN_Embedded_team_Leader
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file provides SPI firmware functions.
  ******************************************************************************
	*/

#include "GPIO.h"

/* Includes ------------------------------------------------------------------*/
/*============*/
#include "SPI.h"


/** @(SPI.h)
  * @@brief 	file that contains prototypes of SPI firmware functions
  */
	
	
/** 
	*		 global pointers to functions ,
	*		 point to the handler function of a spi peripheral 
	*/

/* pointer to function points to the handler function of SPI_1 */	
void (*SPI_1_RXNE_TEMP_HANDLER)(void);

/* pointer to function points to the handler function of SPI_2 */	
void (*SPI_2_RXNE_TEMP_HANDLER)(void);





/* FUNCTION  DEFINITION ------------------------------------------------------*/
/*=========================*/

/**
  * @brief  this function configures SPI according to configurations in " SPI_conf.h " 
	*					 
  * @param  None
  * @retval None
  */

void SPI_voidInit(void)
{

	#if (SPI_1_INIT  ==  SPI_INIT)
		/* enable clk of SPI_1 PORT , AFIO and SPI peripheral */
		RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_SPI1EN);
	
		/*clear pins configrations bits posistion */
		GPIOA->CRL &= ~( GPIO_CRL_CNF4 | GPIO_CRL_MODE4 \
									 | GPIO_CRL_CNF5 | GPIO_CRL_MODE5 	\
									 | GPIO_CRL_CNF6 | GPIO_CRL_MODE6 	\
									 | GPIO_CRL_CNF7 | GPIO_CRL_MODE7 );
		
		#if(SPI_1_MODE == SPI_MASTER)
				/* SPIx_NSS   --->   Alternate function push-pull */
				GPIOA->CRL |= ( GPIO_CRL_CNF4_1 | GPIO_CRL_MODE4 );
				
				/* SPIx_SCK   --->   Alternate function push-pull */
				GPIOA->CRL |= ( GPIO_CRL_CNF5_1 | GPIO_CRL_MODE5 );
				
				/* SPIx_MISO   --->   Input floating */
				GPIOA->CRL |= ( GPIO_CRL_CNF6_0 );
				
				/* SPIx_MOSI   --->   Alternate function push-pull */
				GPIOA->CRL |= ( GPIO_CRL_CNF7_1 | GPIO_CRL_MODE7 );
			
			
				SPI1->CR1 &= ~( 0x00000000 );
				/*  enable spi peripheral and prescaller = f/128 and enable software slave select */
				/* Master mode and drive an internal high level on slave select pin */
				SPI1->CR1 |= ( SPI_CR1_SPE | SPI_CR1_SSM | SPI_CR1_MSTR | SPI_CR1_SSI | SPI_CR1_BR_1 | SPI_CR1_BR_2 );
			
				
		// (SPI_1_MODE == SPI_SLAVE)
		#else	
				/* SPIx_NSS   --->   Input floating */
				GPIOA->CRL |= ( GPIO_CRL_CNF4_0 );
				
				/* SPIx_SCK   --->   Input floating */
				GPIOA->CRL |= ( GPIO_CRL_CNF5_0 );
				
				/* SPIx_MISO   --->   Alternate function push-pull */
				GPIOA->CRL |= ( GPIO_CRL_CNF6_1 | GPIO_CRL_MODE6 );
				
				/* SPIx_MOSI   --->   Input floating */
				GPIOA->CRL |= ( GPIO_CRL_CNF7_0 );

				SPI1->CR1 &= ~( 0x00000000 );
				/*  enable spi peripheral and enable software slave select */
				SPI1->CR1 |= ( SPI_CR1_SPE | SPI_CR1_SSM );
				/* slave mode and drive an internal low level on slave select pin */
				SPI1->CR1 &= ~( SPI_CR1_SSI );
		#endif
		
		
		#if(SPI_1_RXNE_INT == SPI_INT_ENABLE)
				/* enable recieving interrupt */	
				SPI1->CR2 |= (SPI_CR2_RXNEIE);
				/* enable global interrupt of SPI_1 in NVIC */
				NVIC_EnableIRQ(SPI1_IRQn);
		#endif
	
	#endif
	
	
	
	
	
	#if (SPI_2_INIT  ==  SPI_INIT)
		/* enable clk of SPI_2 PORT , AFIO and SPI peripheral */
		RCC->APB2ENR |= (RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN);
		RCC->APB1ENR |= (RCC_APB1ENR_SPI2EN);
	
		/*clear pins configrations bits position */
		GPIOB->CRH &= ~( GPIO_CRH_CNF12 | GPIO_CRH_MODE12 \
									 | GPIO_CRH_CNF13 | GPIO_CRH_MODE13 	\
									 | GPIO_CRH_CNF14 | GPIO_CRH_MODE14 	\
									 | GPIO_CRH_CNF15 | GPIO_CRH_MODE15 );
		
		
		#if(SPI_2_MODE == SPI_MASTER)
				/* SPIx_NSS   --->   Alternate function push-pull */
				GPIOB->CRH |= ( GPIO_CRH_CNF12_1 | GPIO_CRH_MODE12 );
				
				/* SPIx_SCK   --->   Alternate function push-pull */
				GPIOB->CRH |= ( GPIO_CRH_CNF13_1 | GPIO_CRH_MODE13 );
				
				/* SPIx_MISO   --->   Input floating */
				GPIOB->CRH |= ( GPIO_CRH_CNF14_0 );
				
				/* SPIx_MOSI   --->   Alternate function push-pull */
				GPIOB->CRH |= ( GPIO_CRH_CNF15_1 | GPIO_CRH_MODE15 );
			
			
				SPI2->CR1 &= ~( 0x00000000 );
				/*  enable spi peripheral and prescaller = f/128 and enable software slave select */
				/* Master mode and drive an internal high level on slave select pin */
				SPI2->CR1 |= ( SPI_CR1_SPE | SPI_CR1_SSM | SPI_CR1_MSTR | SPI_CR1_SSI | SPI_CR1_BR_1 | SPI_CR1_BR_2 );
			
			
		// (SPI_2_MODE == SPI_SLAVE)
		#else	
				/* SPIx_NSS   --->   Input floating */
				GPIOB->CRH |= ( GPIO_CRH_CNF12_0 );
				
				/* SPIx_SCK   --->   Input floating */
				GPIOB->CRH |= ( GPIO_CRH_CNF13_0 );
				
				/* SPIx_MISO   --->   Alternate function push-pull */
				GPIOB->CRH |= ( GPIO_CRH_CNF14_1 | GPIO_CRH_MODE14 );
				
				/* SPIx_MOSI   --->   Input floating */
				GPIOB->CRH |= ( GPIO_CRH_CNF15_0 );

				SPI2->CR1 &= ~( 0x00000000 );
				/*  enable spi peripheral and enable software slave select */
				SPI2->CR1 |= ( SPI_CR1_SPE | SPI_CR1_SSM );
				/* slave mode and drive an internal low level on slave select pin */
				SPI2->CR1 &= ~( SPI_CR1_MSTR | SPI_CR1_SSI);
		#endif
	
	
		#if(SPI_2_RXNE_INT == SPI_INT_ENABLE)
				/* enable recieving interrupt */	
				SPI2->CR2 |= (SPI_CR2_RXNEIE);
				/* enable global interrupt of SPI_2 in NVIC */	
				NVIC_EnableIRQ(SPI2_IRQn);
		#endif
	
	#endif

}



/**
  * @brief  this function sends data with a specific spi_x 
	*					 
  * @param  uint8_t SPI_x
	*					spi peripheral that you want to send data with 
	*	i.e					SPI_1			,				SPI_2
	*
	* @param  uint16_t DATA
	*					data you want to send
	*
  * @retval None
  */

void SPI_voidSendData(uint8_t SPI_x ,uint8_t DATA)
{
	switch (SPI_x)
	{
		case (SPI_1):
		{
			/* send data with SPI_1 */
			SPI1->DR  = DATA;
			/* wait for tarnsmit buffer to be empty */
			while( !(SPI2->SR & (SPI_SR_TXE) ));
			break;
		}
		
		default: // (SPI_2)
		{
			/* send data with SPI_2 */
			SPI2->DR  = DATA;
			/* wait for tarnsmit buffer to be empty */
			while( !(SPI2->SR & (SPI_SR_TXE) ));
			while( !(SPI2->SR & (SPI_SR_RXNE) ));
			break;
		}
	
	}
		
}

uint8_t SPI_Send_Byte(uint8_t SPI_x, uint8_t byte){
	switch (SPI_x)
	{
		case (SPI_1):
		{
			/* send data with SPI_1 */
			SPI1->DR  = byte;
			/* wait for tarnsmit buffer to be empty */
			while( (SPI1->SR | SPI_SR_RXNE) );
			return SPI1->DR;
			break;
		}
		
		default: // (SPI_2)
		{
			/* send data with SPI_2 */
			SPI2->DR  = byte;
			/* wait for tarnsmit buffer to be empty */
			while( !(SPI2->SR & (SPI_SR_TXE) ));
			while( !(SPI2->SR & (SPI_SR_RXNE) ));
			return SPI2->DR;
			break;
		}
	
	}
}

/**
  * @brief  this function recieves data with a specific spi_x 
	*					 
  * @param  uint8_t SPI_x
	*					spi peripheral that you want to recieve data with 
	*	i.e					SPI_1			,				SPI_2
	*
	* @param  uint16_t DATA
	*					data you want to recieve
	*
  * @retval None
  */

uint8_t SPI_voidRecieveData(uint8_t SPI_x)
{
	switch (SPI_x)
	{
		case (SPI_1):
		{
			/* recieve data with SPI_1 */
			return ( SPI1->DR );
		}
		
		default: // (SPI_2)
		{
			/* recieve data with SPI_2 */
			return ( SPI2->DR );
		}
	
	}
		
}



/**
  * @brief  callback interrupt handler routine of SPI_1 for user
	*					 
  * @param  SPI_1_RXNE_HANDLER
	*					address of handler function of SPI_1 
	*
  * @retval None
  */

void SPI_1_voidRXNE_Handler( void(*SPI_1_RXNE_HANDLER)(void) )
{
	/* store SPI_1 handler function address in pointer to function */
	SPI_1_RXNE_TEMP_HANDLER = SPI_1_RXNE_HANDLER;

}



/**
  * @brief  callback interrupt handler routine of SPI_2 for user
	*					 
  * @param  SPI_2_RXNE_HANDLER
	*					address of handler function of SPI_2 
	*
  * @retval None
  */

void SPI_2_voidRXNE_Handler( void(*SPI_2_RXNE_HANDLER)(void) )
{
	/* store SPI_2 handler function address in pointer to function */
	SPI_2_RXNE_TEMP_HANDLER = SPI_2_RXNE_HANDLER;

}



/**
  * @brief  interrupt handler routine of SPI_1
	*					 
  * @param  None
	*
  * @retval None
  */

void SPI1_IRQHandler()
{
	/* call back your handler function spi_1 */
	SPI_1_RXNE_TEMP_HANDLER();

}



/**
  * @brief  interrupt handler routine of SPI_2
	*					 
  * @param  None
	*
  * @retval None
  */
void SPI2_IRQHandler()
{
	/* call back your handler function SPI_2 */
	SPI_2_RXNE_TEMP_HANDLER();
}



