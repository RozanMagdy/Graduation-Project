#include "UART.h"


int main()
{
		
	UART_voidInit();
		
	
	
	uint8_t num = 0x1A;
	uint32_t i = 0;
	uint32_t delay = 10000000;

		while(1)
		{
			
			UART_voidPrintString(UART_1 ," * UART_1 :--->  ");
			UART_voidPrintString(UART_1 ," * HEX_NUMBERS :--->  ");
			
			UART_voidPrintString(UART_2 ," * UART_2 :--->  ");
			UART_voidPrintString(UART_2 ," * HEX_NUMBERS :--->  ");
			
			UART_voidPrintString(UART_3 ," * UART_3 :--->  ");
			UART_voidPrintString(UART_3 ," * HEX_NUMBERS :--->  ");
				for(i=0 ;i<delay ;i++);
			
			
			UART_voidPrintHexNumber(UART_1 ,num);
			UART_voidPrintHexNumber(UART_2 ,num);
			UART_voidPrintHexNumber(UART_3 ,num);
				for(i=0 ;i<delay ;i++);
			
				
			UART_voidPrintString(UART_1 ,"\n");
			UART_voidPrintString(UART_2 ,"\n");
			UART_voidPrintString(UART_3 ,"\n");
			num++;
		
		}
	
	
	


}
