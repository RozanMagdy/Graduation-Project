//Libraries should be included :
//RCC(stm32f10x_rcc.h) - GPIO(stm32f10x_gpio.h) - TIMER(stm32f10x_tim.h)

#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
GPIO_InitTypeDef GPIO_InitStructure;
TIM_TimeBaseInitTypeDef my_timer_setup_struct;

void InitGPIO(void)
{
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
}

int main(void){
	
	InitGPIO();
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	// Get the clock frequencies
	RCC_ClocksTypeDef RCC_Clocks;
	RCC_GetClocksFreq(&RCC_Clocks);
	
	my_timer_setup_struct.TIM_Prescaler = 1000;
	my_timer_setup_struct.TIM_CounterMode = TIM_CounterMode_Up;
	my_timer_setup_struct.TIM_ClockDivision = TIM_CKD_DIV1;
	my_timer_setup_struct.TIM_Period = 0xFFFF;
	
	TIM_TimeBaseInit(TIM2,&my_timer_setup_struct);
	
	TIM_Cmd(TIM2, ENABLE); // start counting by enabling CEN in CR1 */
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); // enable so we can track each period
	
	while(1){
		
		if(TIM_GetCounter(TIM2) >= 0x7FFF){
			GPIOC->BRR = GPIO_Pin_13;
		}else{
			GPIOC->BSRR = GPIO_Pin_13;
		}
	}		
	
	return 0;
}
