#include "PWM.h"

int main()
{
	
	PWM_voidInit();
	
	PWM_voidDuty_Cycle(PWM_TIMER_2 ,PWM_CHANNEL_1 ,0);
	PWM_voidDuty_Cycle(PWM_TIMER_2 ,PWM_CHANNEL_2 ,10);
	PWM_voidDuty_Cycle(PWM_TIMER_2 ,PWM_CHANNEL_3 ,50);
	PWM_voidDuty_Cycle(PWM_TIMER_2 ,PWM_CHANNEL_4 ,100);
	PWM_voidTIM_ENABLE(PWM_TIMER_2);

	PWM_voidDuty_Cycle(PWM_TIMER_3 ,PWM_CHANNEL_1 ,0);
	PWM_voidDuty_Cycle(PWM_TIMER_3 ,PWM_CHANNEL_2 ,10);
	PWM_voidDuty_Cycle(PWM_TIMER_3 ,PWM_CHANNEL_3 ,50);
	PWM_voidDuty_Cycle(PWM_TIMER_3 ,PWM_CHANNEL_4 ,100);
	PWM_voidTIM_ENABLE(PWM_TIMER_3);

	PWM_voidDuty_Cycle(PWM_TIMER_4 ,PWM_CHANNEL_1 ,0);
	PWM_voidDuty_Cycle(PWM_TIMER_4 ,PWM_CHANNEL_2 ,10);
	PWM_voidDuty_Cycle(PWM_TIMER_4 ,PWM_CHANNEL_3 ,50);
	PWM_voidDuty_Cycle(PWM_TIMER_4 ,PWM_CHANNEL_4 ,100);
	PWM_voidTIM_ENABLE(PWM_TIMER_4);
	
	
	while(1)
	{
	}
}

