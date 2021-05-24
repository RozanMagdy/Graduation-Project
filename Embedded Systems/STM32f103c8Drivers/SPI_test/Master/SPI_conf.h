/**
  ******************************************************************************
  * @file    spi_conf.h
  * @author  Ahmed_Mohamed_Gamal AUTOCAN_Embedded_team_Leader
	* @editor	 None
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file contains all configrations FOR EXTI firmware library.
  ******************************************************************************
	*/
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPI_CONF_H
#define __SPI_CONF_H




/**@attention
	*						all configrations in init function are as follow :-
	*	CR1
	*					default					 full duplex	
	*					default					 CRC calculation disabled
	*					default					 8-bit data frame
	*													 Software slave select management enabled
	*					default					 MSB transmitted first
	*										 			 BR[2:0] ---> 110: 	fPCLK/128
	*					default					 ClK to 0 when idle (CPOL = 0)
	*					default					 The first clock transition is the first data capture edge (CPHA = 0)
	*
	*/

/**@attention
	*						all configrations of rcc and gpoi pins in SPI_voidinit() function are without any remaping
	*						if you want to use remap pins then reconfigure rcc gpio pins in Init function.
	*/
		
/**@attention
	*						Software slave select management enabled that means NSS is freely to use as GPIO
	*/
	
/**										 |=================|=================|=================|=================|
											 |		SPIx_NSS  	 |		SPIx_SCK 		 |		SPIx_MISO	   |		SPIx_MOSI	   |  
	|====================|=================|=================|=================|=================|		
	| 			SPI_1 			 |	PORTA---PIN4   |	PORTA---PIN5	 |	PORTA---PIN6	 |	PORTA---PIN7   |
	|====================|=================|=================|=================|=================|
	|	 			SPI_2 			 |	PORTB---PIN12  |	PORTB---PIN13	 |	PORTB---PIN14	 |	PORTB---PIN15  |
	|====================|=================|=================|=================|=================|
*/
	







/** 
	*	choose which peripheral you want to use
	*	i.e			SPI_INIT		,		SPI_UNINIT
	*
	*/
#define	SPI_1_INIT			SPI_INIT 	
#define	SPI_2_INIT			SPI_INIT 	



/** 
	*	choose which mode you want your peripheral to work on 
	*	i.e			SPI_MASTER		,		SPI_SLAVE
	*
	*/
#define SPI_1_MODE			SPI_MASTER
#define	SPI_2_MODE			SPI_SLAVE



/** 
	*	choose if you want to enable RXNE interrupt or not 
	*	i.e			SPI_INT_ENABLE		,		SPI_INT_DISABLE
	*
	*/
#define SPI_1_RXNE_INT				SPI_INT_DISABLE
#define SPI_2_RXNE_INT				SPI_INT_DISABLE




/*****END OF FILE****/
/*     __SPI_CONF_H     */
#endif	

