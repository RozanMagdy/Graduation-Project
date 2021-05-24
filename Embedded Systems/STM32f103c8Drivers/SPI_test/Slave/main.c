#include "SPI.h"
#include "UART.h"




void SPI_RX_test(void)
{
	uint8_t ch = 0;	
		ch = SPI_voidRecieveData(SPI_2);
		UART_voidPrintString(UART_1 ," ---->  ");
		UART_voidSendChar(UART_1 ,ch);
		UART_voidSendChar(UART_1 ,'\n');

}	


int main()
{
	
	UART_voidInit();
	SPI_voidInit();
	
	SPI_2_voidRXNE_Handler(SPI_RX_test);
	
	
	
	while(1);

}
