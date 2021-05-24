
#include "USART.h"
 

void USART_voidInit(void)
{
    /* USART configuration structure for USART1 */
    USART_InitTypeDef usart1_init_struct;
     
    /* Enalbe clock for USART1, AFIO and GPIOA */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
 
    /* Enable USART1 */
    USART_Cmd(USART_USED, ENABLE);  
	
    /* Baud rate 9600, 8-bit data, One stop bit
     * No parity, Do both Rx and Tx, No HW flow control */
    usart1_init_struct.USART_BaudRate = USART_BAUDRATE;   
    usart1_init_struct.USART_WordLength = USART_WORDLENGTH;  
    usart1_init_struct.USART_StopBits = USART_STOPBITS;   
    usart1_init_struct.USART_Parity = USART_PARITY ;
    usart1_init_struct.USART_Mode =USART_MODE;
    usart1_init_struct.USART_HardwareFlowControl = USART_HARDWAREFLOWCONTROL;
	
    /* Configure USART1 */
    USART_Init(USART1, &usart1_init_struct);

}



void USART_PrintString(uint8_t* string){
	uint8_t i = 0;
	
	while(string[i] != '\0'){
		USART_SendData(USART_USED,string[i]);
		Delay(1);
		i++;
	}
	
}

void USART_voidPrintNumber(uint32_t number)
{
	uint32_t i = 0;
	uint8_t  j = 0;
	uint8_t str[255] = {0};
	uint32_t temp_number1 = 0;
	
	while( (number >> i) != 0)
	{
		temp_number1 = number;
		temp_number1 &= (0x0f << i);
		temp_number1 =(temp_number1 >> i);
		str[j] = temp_number1 + '0';
		i = i + 4;
		j++;
	}

	while(j > 0)
	{
		USART_SendData(USART1,str[j-1]);
		Delay(1);
		j--;
	}
}




void USART_PrintNumber(uint32_t number){
	uint8_t string[16] = {0};
	int8_t i = 0;



	while(number != 0){
		string[i] = (number%10) + '0';
		number = number / 10;
		i++;
	}


	while(i>=0)
	{
		USART_SendData(USART_USED,string[i]);
		Delay(1);
		i--;
	}
	USART_SendBreak(USART_USED);
}
