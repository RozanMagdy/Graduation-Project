#include "EXTI.h"


void EXTI4_test()
{
		
		int32_t delay = 10000000;
		uint32_t i = 0;
		uint8_t j = 0;
	
	/* don't use delay function because it uses a systick interrupt*/
	while( j < 3 )
	{
		GPIOC->BSRR |= GPIO_BSRR_BS13;
		for(i=0 ;i<delay ;i++){}
			
		GPIOC->BSRR |= GPIO_BSRR_BR13;
		for(i=0 ;i<delay ;i++){}
		j++;	
	}
	
}



//void EXTI0_test()
//{
//		
//		int32_t delay = 10000000;
//		uint32_t i = 0;
//		uint8_t j = 0;
//	
//	/* don't use delay function because it uses a systick interrupt*/
//	while( j < 2 )
//	{
//		GPIOC->BSRR |= GPIO_BSRR_BS13;
//		for(i=0 ;i<delay ;i++){}
//			
//		GPIOC->BSRR |= GPIO_BSRR_BR13;
//		for(i=0 ;i<delay ;i++){}
//		j++;	
//	}
//	
//}

int main()
{	
	
	EXTI_voidInit();
//	EXTI0_voidIRQ(EXTI0_test);
	EXTI4_voidIRQ(EXTI4_test);
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	GPIOC->CRH   &= ~( (0x0f) << 20 );
	GPIOC->CRH   |=  ( (0x03) << 20 );
	
	
	
	while(1)
	{
		GPIOC->BSRR |= GPIO_BSRR_BR13;
	}
		
}
