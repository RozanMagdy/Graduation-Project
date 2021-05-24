#include "GPIO.h"
#include "CAN.h"

CanTxMsg myTxMsg;

int main()
{
	Delay_voidInit();
	GPIO_voidInit();
	CAN_voidInit();
	
	uint8_t* data=0;
	CAN_voidSetTxMsg(&myTxMsg ,0x123 ,CAN_RTR_DATA ,1 ,data);
	
	uint8_t i='a'; 
	while(1)
	{
		
		GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_SET);
		Delay(600);
	
		myTxMsg.Data[0] = i;
		CAN_Transmit(CAN1,&myTxMsg);
		i++;
		
		Led_Tog(100 ,1 ,GPIOC ,GPIO_PIN_13);
		
	}		

}

