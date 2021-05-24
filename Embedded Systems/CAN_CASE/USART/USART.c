#include "USART.h"
#include "USART_Config.h"
#include "Delay.h"
 


void USART_voidInit(void)
{
    /* USART configuration structure for USART1 */
    USART_InitTypeDef usart1_init_struct;
    /* Bit configuration structure for GPIOA PIN9 and PIN10 */
    GPIO_InitTypeDef gpioa_init_struct;
     
    /* Enalbe clock for USART1, AFIO and GPIOA */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_AFIO | 
                           RCC_APB2Periph_GPIOA, ENABLE);
                            
    /* GPIOA PIN9 alternative function Tx */
    gpioa_init_struct.GPIO_Pin = GPIO_Pin_9;
    gpioa_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
    gpioa_init_struct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &gpioa_init_struct);
    /* GPIOA PIN9 alternative function Rx */
    gpioa_init_struct.GPIO_Pin = GPIO_Pin_10;
    gpioa_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
    gpioa_init_struct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &gpioa_init_struct);
 
    /* Enable USART1 */
    USART_Cmd(USART_USED, ENABLE);  
    /* Baud rate 9600, 8-bit data, One stop bit
     * No parity, Do both Rx and Tx, No HW flow control
     */
    usart1_init_struct.USART_BaudRate = USART_BAUDRATE;   
    usart1_init_struct.USART_WordLength = USART_WORDLENGTH;  
    usart1_init_struct.USART_StopBits = USART_STOPBITS;   
    usart1_init_struct.USART_Parity = USART_PARITY ;
    usart1_init_struct.USART_Mode =USART_MODE;
    usart1_init_struct.USART_HardwareFlowControl = USART_HARDWAREFLOWCONTROL;
    /* Configure USART1 */
    USART_Init(USART1, &usart1_init_struct);

}



void USART_PrintString(char* string){
	uint32_t i = 0;
	
	while(string[i] != '\0'){
		USART_SendData(USART_USED,string[i]);
 Delay(1);
		i++;
	}
	
}
void USART_PrintNumber(uint32_t number){
	char string[16] = {0};
	short int i = 0;



	while(number > 0){
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
