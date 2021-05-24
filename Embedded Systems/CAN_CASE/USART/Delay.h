#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f10x.h"
static __IO uint32_t TimingDelay;
void InitTimer(void);
void Delay(__IO uint32_t nTime);


#endif
