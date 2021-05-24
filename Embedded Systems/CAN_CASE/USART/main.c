#include "stm32f10x.h"
#include "USART.h"
#include "Delay.h"
  
int main(void)
{
     /* Initialize USART1 */
    USART_voidInit();
	InitTimer();
 
    while(1)
    {	
        USART_PrintString("Helloo World");
			 Delay(500);
     } 
	 }

 

 



