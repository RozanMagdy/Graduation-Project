/**
  ******************************************************************************
  * @file    uart.c
  * @author  Omar_Hesham  AUTOCAN_Embedded_team
	* @editor	 Ashraf_Amgad AUTOCAN_Embedded_team
  * @version V0.1
  * @date    xx-xx-2020
  * @brief   This file provides UART firmware functions.
  ******************************************************************************
	*/



/* Includes ------------------------------------------------------------------*/
/*============*/
#include "UART.h"
#include "stm32f10x_usart.h"            // Keil::Device:StdPeriph Drivers:USART



/** @(UART.h)
  * @@brief 	file that contains prototypes of UART firmware functions
  */
	
/** @(stm32f10x_usart.h)
  * @@brief 			USART StdPeriph_Driver
  */


/* FUNCTION  DEFINITION ------------------------------------------------------*/
/*=========================*/


/**
  * @brief  this function configures UART with configrations 
						that user choosed in "UART_conf.h" 
  * @param  None
  * @retval None
  */
	
void UART_voidInit(void)
{
		/* Enalbe clock for AF */
		RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; 
		//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
    /* USART configuration structure for USART1 */
    USART_InitTypeDef usart1_init_struct;
     
    
		
	
	#if (USART_1_INIT == UART_INIT )
				/*			(TX/PA9, RX/PA10)					 */	
			/* Enalbe clock for USART1, and it's  pins*/
			RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN | RCC_APB2ENR_USART1EN);
			//RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);
	
			/*	TX --> Alternate function push-pull	*/
			GPIOA->CRH &= ~(GPIO_CRH_CNF9 | GPIO_CRH_MODE9);
			GPIOA->CRH |=  (GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9);
			
			/*	RX --> input floating	 */	
			GPIOA->CRH &= ~(GPIO_CRH_CNF10 | GPIO_CRH_MODE10);
			GPIOA->CRH |=  (GPIO_CRH_CNF10_0);

			/* Enable USART1 clk*/
			USART1->CR1 |= USART_CR1_UE;
			//USART_Cmd(USART1, ENABLE); 
	#endif
	
	
	#if (USART_2_INIT == UART_INIT )
				/*			(TX/PA2, RX/PA3)					 */
			/* Enalbe clock for USART2, and it's  pins*/
			RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
			RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
			
			//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
			//RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2 , ENABLE);
			
			/*	TX --> Alternate function push-pull	*/
			GPIOA->CRL &= ~(GPIO_CRL_CNF2 | GPIO_CRL_MODE2);
			GPIOA->CRL |=  (GPIO_CRL_CNF2_1 | GPIO_CRL_MODE2);
			
			/*	RX --> input floating	 */	
			GPIOA->CRL &= ~(GPIO_CRL_CNF3 | GPIO_CRL_MODE3);
			GPIOA->CRL |=  (GPIO_CRL_CNF3_0);

			/* Enable USART2 clk*/
			USART2->CR1 |= USART_CR1_UE;
			//USART_Cmd(USART2, ENABLE);
	#endif
	
	
	#if (USART_3_INIT == UART_INIT )
				/*			(TX/PB10, RX/PB11)					 */	
			/* Enalbe clock for USART3, and it's  pins*/
			RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
			RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
			
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3 , ENABLE);
				
			/*	TX --> Alternate function push-pull	*/
			GPIOB->CRH &= ~(GPIO_CRH_CNF10 | GPIO_CRH_MODE10);
			GPIOB->CRH |=  (GPIO_CRH_CNF10_1 | GPIO_CRH_MODE10);
			
			/*	RX --> input floating	 */	
			GPIOB->CRH &= ~(GPIO_CRH_CNF11 | GPIO_CRH_MODE11);
			GPIOB->CRH |=  (GPIO_CRH_CNF11_0);	
				
			/* Enable USART3 clk*/
			USART3->CR1 |= USART_CR1_UE;
			//USART_Cmd(USART3, ENABLE);	
	#endif
	
	
     
	
    /* set BaudRate */
    usart1_init_struct.USART_BaudRate = USART_BAUDRATE; 
		
		/* set WordLength */		
    usart1_init_struct.USART_WordLength = USART_WORDLENGTH;

		/* set number of Stop Bits */
    usart1_init_struct.USART_StopBits = USART_STOPBITS;

		/* set Parity */
    usart1_init_struct.USART_Parity = USART_PARITY ;
		
		/* set Mode (transmiter ,reciever or both) */
    usart1_init_struct.USART_Mode =USART_MODE;
		
		/* set HardwareFlowControl */
    usart1_init_struct.USART_HardwareFlowControl = USART_HARDWAREFLOWCONTROL;
	
	
    /* Configure USART1 using USART_Init() stdlib */
		#if (USART_1_INIT == UART_INIT )
				USART_Init(USART1, &usart1_init_struct);
		#endif
		
		/* Configure USART2 using USART_Init() stdlib */
		#if (USART_2_INIT == UART_INIT )
				USART_Init(USART2, &usart1_init_struct);
		#endif
		
		/* Configure USART3 using USART_Init() stdlib */
		#if (USART_3_INIT == UART_INIT )
				USART_Init(USART3, &usart1_init_struct);
		#endif
}




/**
  * @brief  this function sends single char using desired UART
	* @param  uint8_t UART_x :
	*
	*													the desired UART you want to send data through.
	*		i.e										UART_1	,		UART_2		,		UART_3.
	*
	* @param  uint16_t Data :
	*														char that you want to send. 
  * @retval None
  */


void UART_voidSendChar(uint8_t UART_x, uint16_t Data)
{
	
	switch (UART_x)
	{
		case UART_1:
		{
				//USART_SendData(USART1 ,Data);
				USART1->DR = (Data & (uint16_t)0x01FF);
				while(  ((USART1->SR) & USART_SR_TXE) == 0 );
			break;
		}
		
		case UART_2:
		{
				//USART_SendData(USART2 ,Data);
				USART2->DR = (Data & (uint16_t)0x01FF);
				while(  ((USART2->SR) & USART_SR_TXE) == 0 );
			break;
		}
		
		case UART_3:
		{
				//USART_SendData(USART3 ,Data);
				USART3->DR = (Data & (uint16_t)0x01FF);
				while(  ((USART3->SR) & USART_SR_TXE) == 0 );
			break;
		}
	
	}
		
}



/**
  * @brief  this function sends string using desired UART
	* @param  uint8_t UART_x :
	*
	*													the desired UART you want to send data through.
	*		i.e										UART_1	,		UART_2		,		UART_3.
	*
	* @param  uint8_t* string :
	*														address of string that you want to send. 
  * @retval None
  */

void UART_voidPrintString(uint8_t UART_x ,uint8_t* string)
{
	uint8_t i = 0;
	
	while(string[i] != '\0')
	{
		
			switch (UART_x)
			{
					case (UART_1):
					{
							/* stdlib function that Transmits single data */
							UART_voidSendChar(UART_1 ,string[i]);
							break;
					}
					
					
					case (UART_2):
					{
							/* stdlib function that Transmits single data */
							UART_voidSendChar(UART_2 ,string[i]);
							break;
					}
					
					default:	// (UART_3):
					{
							/* stdlib function that Transmits single data */
							UART_voidSendChar(UART_3 ,string[i]);
							break;
					}
					
			}				
				
		i++;
	}
	
}



/**
  * @brief  this function sends Hexadecimal numbers
	* @param  uint8_t UART_x :
	*
	*													the desired UART you want to send hex numbers through.
	*		i.e										UART_1	,		UART_2		,		UART_3.
	*
	* @param  uint16_t number :
	*														Hexadecimal number that you want to send. 
  * @retval None
  */
void UART_voidPrintHexNumber(uint8_t UART_x ,uint16_t Hex_number)
{
	/* counter variable */
	uint8_t i = 0;
	
	/* counter variable */
	uint8_t  j = 0;
	
	/* string that stores Hex_number after changing it's digit to characters  */
	uint8_t str[5] = {0};
	
	/* temp varaible */
	uint16_t temp_number1 = 0;
	
	while( (Hex_number >> i) != 0)
	{
		temp_number1 = Hex_number;
		
		/* get the needed digit of Hex_number */
		temp_number1 &= (0x0f << i);
		
		/* make that digit the first one on the right */
		temp_number1 =(temp_number1 >> i);
		
		/* change that digit with specified character in hexadecimal format*/
		if(temp_number1 <= 9)
		{
			str[j] = temp_number1 + '0';
		}
		
		else
		{
				switch (temp_number1)
				{
					case (10):
					{
						/* A represents 10 in hex */
						str[j] = 'A';
						break;
					}
					
					case (11):
					{
						/* B represents 11 in hex */
						str[j] = 'B';
						break;
					}
					
					case (12):
					{
						/* C represents 12 in hex */
						str[j] = 'C';
						break;
					}
					
					case (13):
					{
						/* D represents 13 in hex */
						str[j] = 'D';
						break;
					}
					
					case (14):
					{
						/* E represents 14 in hex */
						str[j] = 'E';
						break;
					}
					
					case (15):
					{
						/* F represents 15 in hex */
						str[j] = 'F';
						break;
					}
					
					default:
					{
						/* this is just indecator that wehave invalid hex number */
						str[j] = '!';
					}
				
					
				}

		}
		
		/* we add 4 because each digit in hex represents with 4 bits */
		i = i + 4;
		j++;
	}
	
	
	/*send all digits backwards one by one */
	while(j > 0)
	{
			switch (UART_x)
			{
					case (UART_1):
					{
							/* stdlib function that Transmits single data */
						  UART_voidSendChar(UART_1 ,str[j-1]);
							j--;
						break;
					}
					
					
					case (UART_2):
					{
							/* stdlib function that Transmits single data */
							UART_voidSendChar(UART_2 ,str[j-1]);
							j--;
						break;
					}
					
					default:	// (UART_3):
					{
							/* stdlib function that Transmits single data */
							UART_voidSendChar(UART_3 ,str[j-1]);
							j--;
						break;
					}
					
			}				
			
	}
	
}



/** AUTOCAN *****END OF FILE****/

