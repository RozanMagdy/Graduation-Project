#include "SPI.h"



int main()
{
	
	SPI_voidInit();

	uint32_t i  = 0;
	uint8_t  ch = 'a';
	while(1)
	{
		SPI_voidSendData(SPI_1 ,ch);
		ch++;
		
		/* delay */
		for(i=0 ; i<10000000 ; i++);
		
		
	}

}
