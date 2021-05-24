#include "stm32f10x.h"
#include "Delay.h"
#include "GPIO.h"

static volatile uint32 TimingDelay;

void TIMER_voidInit(void)
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
void Delay(volatile uint32 nTime)
{
         TimingDelay = nTime;
         while(TimingDelay != 0);
}





