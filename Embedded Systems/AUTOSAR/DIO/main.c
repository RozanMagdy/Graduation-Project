
#include "Dio_Regs.h"
#include "GPIO.h"
#include "Delay.h"
#include "Dio.h"
int main(void)
{
	TIMER_voidInit();
	GPIO_voidInit();
	Dio_Init(&Dio_Configuration);
  Dio_LevelType level;
	while(1){
//Dio_WriteChannelGroup(&Dio_LEDGroupConfiguration,STD_LOW);
//		Delay(100);
//Dio_WriteChannelGroup(&Dio_LEDGroupConfiguration,STD_HIGH);
//		Delay(100);
		
		if(Dio_ReadChannelGroup(&Dio_BUTTONGroupConfiguration)==0x06)
		{
			Dio_WriteChannelGroup(&Dio_LEDGroupConfiguration,STD_LOW);
		}
		else
		{
			Dio_WriteChannelGroup(&Dio_LEDGroupConfiguration,STD_HIGH);
		}
	

		
	
			}
}
