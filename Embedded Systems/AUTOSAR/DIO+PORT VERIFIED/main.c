

#include "Port.h"
#include "Dio.h"


int main(void)
{
	RCC_APB2ENR |= ((1 << 2) | (1 << 3) | (1 << 4)) ;
	
	Port_Init(&Port_Configuration);
	Dio_Init(&Dio_Configuration);
	
	
	while(1);
}
