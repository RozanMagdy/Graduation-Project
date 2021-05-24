#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f10x.h"
static __IO uint32_t TimingDelay;
void TIMER_voidInit(void);
void Delay(__IO uint32_t nTime);



#endif
