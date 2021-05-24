/*************************
 * stm32 uart main.c
 *************************/
 
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_usart.h"
#include<String.h> 
/* User defined function prototypes */
void GPIOA_Init(void);

void led_toggle(void);
void InitTIM2(void);
void USART1_Init(void);
void USART_PrintString(char* string);
 void USART_PrintNumber(u32 number, u8 digit);
 static __IO uint32_t TimingDelay;
 
 void InitTimer()
{
        SysTick_Config(SystemCoreClock / 1000);
}
void SysTick_Handler(void)
{
        if (TimingDelay != 0x00)
        {
                TimingDelay--;
        }
}
void Delay(__IO uint32_t nTime)
{
         TimingDelay = nTime;
         while(TimingDelay != 0);
}

int main(void)
{
    /* Initialize GPIOA PIN8 */
    GPIOA_Init();
	
	//	InitTIM2();
	  InitTimer();
    /* Initialize USART1 */
    USART1_Init();
 
    while(1)
    {	
//			USART_SendData(USART1,'O');
//			Delay(500);
//			USART_SendData(USART1,'K');
//			Delay(500);
			
		
//			if(TIM_GetCounter(TIM2) == 0x7FFF){
				USART_PrintString("Helloo");
			Delay(500);
//				//USART_PrintNumber(10,0);
//				USART_SendData(USART1,'O');
//				//led_toggle();
//		}
//			if(TIM_GetCounter(TIM2) == 0x7FFF){
//				//USART_PrintString("Helloo");
//				//USART_PrintNumber(10,0);
//				
//				
//				USART_SendData(USART1,'k');
//				//led_toggle();
//		}
  }
}   
 
/***********************************************
 * Initialize GPIOA PIN8 as push-pull output
 ***********************************************/
void GPIOA_Init(void)
{
    /* Bit configuration structure for GPIOA PIN8 */
    GPIO_InitTypeDef gpioa_init_struct = { GPIO_Pin_8, GPIO_Speed_50MHz, 
                                           GPIO_Mode_Out_PP };
                                             
    /* Enable PORT A clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    /* Initialize GPIOA: 50MHz, PIN8, Push-pull Output */
    GPIO_Init(GPIOA, &gpioa_init_struct);   
     
    /* Turn off LED to start with */
    GPIO_SetBits(GPIOA, GPIO_Pin_8);
}
 
/*****************************************************
 * Initialize USART1: enable interrupt on reception
 * of a character
 *****************************************************/
void USART1_Init(void)
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
    USART_Cmd(USART1, ENABLE);  
    /* Baud rate 9600, 8-bit data, One stop bit
     * No parity, Do both Rx and Tx, No HW flow control
     */
    usart1_init_struct.USART_BaudRate = 9600;   
    usart1_init_struct.USART_WordLength = USART_WordLength_8b;  
    usart1_init_struct.USART_StopBits = USART_StopBits_1;   
    usart1_init_struct.USART_Parity = USART_Parity_No ;
    usart1_init_struct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    usart1_init_struct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    /* Configure USART1 */
    USART_Init(USART1, &usart1_init_struct);
    /* Enable RXNE interrupt */
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
    /* Enable USART1 global interrupt */
    NVIC_EnableIRQ(USART1_IRQn);
}
 
/*******************************************
 * Toggle LED 
 *******************************************/
void led_toggle(void)
{
    /* Read LED output (GPIOA PIN8) status */
    uint8_t led_bit = GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_8);
     
    /* If LED output set, clear it */
    if(led_bit == (uint8_t)Bit_SET)
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_8);
    }
    /* If LED output clear, set it */
    else
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_8);
    }
}
void USART_PrintString(char* string){
	int i = 0;
	while(string[i] != '\0'){
		USART_SendData(USART1,string[i]);
		Delay(10);
		i++;
	}
}
void USART_PrintNumber(u32 number, u8 digit){
	char string[16] = {0};
	short int i = 0;
	char flag = 0;
	if(number == 0){
		while(digit > 0){
			USART_SendData(USART1,'0');
			digit--;
		}
		return;
	}
	else if(number < 0){
		number = number * -1;
		flag = 1;
	}

	while(number > 0){
		string[i] = (number%10) + '0';
		number = number / 10;
		i++;
	}

	while(i < digit){
		USART_SendData(USART1,'0');
		digit--;
	}

	i--;
	if(flag == 1) USART_SendData(USART1,'-');
	while(i >= 0){
		USART_SendData(USART1,string[i]);
		i--;
	}
}
void InitTIM2(void)
{
	TIM_TimeBaseInitTypeDef TIM_InitStructure2;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	// Get the clock frequencies
	RCC_ClocksTypeDef RCC_Clocks;
	RCC_GetClocksFreq(&RCC_Clocks);
	
	TIM_InitStructure2.TIM_Prescaler = 1000;
	TIM_InitStructure2.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStructure2.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_InitStructure2.TIM_Period = 0xFFFF;
	
	TIM_TimeBaseInit(TIM2,&TIM_InitStructure2);

	TIM_Cmd(TIM2, ENABLE); // start counting by enabling CEN in CR1 */
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); // enable so we can track each period
}

//void USART1_IRQHandler(void)
//{
//    /* RXNE handler */
//    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
//    {
//        /* If received 't', toggle LED and transmit 'T' */
//        if((char)USART_ReceiveData(USART1) == 't')
//        {
//            led_toggle();
//            USART_SendData(USART1, 'T');
//            /* Wait until Tx data register is empty, not really 
//             * required for this example but put in here anyway.
//             */
//            /*
//            while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
//            {
//            }*/
//        }
//    }
//     
//    /* ------------------------------------------------------------ */
//    /* Other USART1 interrupts handler can go here ...             */
//} 

