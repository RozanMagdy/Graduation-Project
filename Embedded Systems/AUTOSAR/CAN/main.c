#include "Can.h"

Can_PduType test_massage;


int main()
{
	
			
//	/* enable clock of CAN_peripheral */

	RCC->APB1ENR |= RCC_APB1ENR_CAN1EN;
//	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1 ,ENABLE);
//	
//	/* enable clock of CAN_peripheral Pins*/
//	RCC_APB2ENR |= (RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN);
//	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA ,ENABLE);
//	
	RCC_APB2ENR |= ((1 << 1) | (1 << 2) | (1 << 3) | (1 << 4)) ;
	Port_Init(&Port_Configuration);
	Can_Init(&Can_Configrations);
	
	test_massage.id = 0x123;
	test_massage.DLC = 1;
	test_massage.sdu[0] = 'a';
	
	uint32 i = 0;
	uint32 delay = 0x00ffffff;
	
	while(1)
	{
			
			Can_Write( CAN_HOH_0_HandleType , &test_massage);
			test_massage.sdu[0]++;
			for(i=0 ;i<delay ;i++);
	
	}
	

}

