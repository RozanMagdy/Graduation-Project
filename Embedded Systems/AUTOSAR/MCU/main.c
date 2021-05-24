
#include "Mcu.h"
#include "MCU_Regs.h"

void DelayMs(void)
{
	uint32 i = 0;
	for(i = 0; i < 100000; i++);
}

void SystemCoreClockUpdate (void);
extern uint32 SystemCoreClock;        /*!< System Clock Frequency (Core Clock) */

int main(void){
	Mcu_Init(&Mcu_Configuration);
	
	Mcu_InitClock(CLOCK_CONFIG_0);
	SystemCoreClockUpdate();

	PORTA_CRH &= ~(0x0F);
	PORTA_CRH |= 0x0B;
	
	PORTC_CRH &= ~(0x0F << 20);
	PORTC_CRH |= (0x03 << 20);
	
	//MCO SYSCLK output
	RCC_CFGR |= (0x04 << 24);
	
	while(1){
		
		PORTC_BSRR |= (1<<13);
		DelayMs();
		PORTC_BSRR |= (1<<(13+16));
		DelayMs();
		
		
		
		
	}
	return 0;
}
