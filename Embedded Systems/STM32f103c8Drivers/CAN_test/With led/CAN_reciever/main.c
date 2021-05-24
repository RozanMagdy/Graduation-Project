#include "GPIO.h"
#include "CAN.h"


CanRxMsg	myRxMsg;

int main()
{
	
	Delay_voidInit();
	GPIO_voidInit();
	CAN_voidInit();
	
	CAN_voidConfigFilter(0 ,CAN_FilterMode_IdList ,CAN_FilterScale_16bit ,0x103 ,0x123 ,CAN_FilterFIFO0);
	
	
	while(1)
	{	
		
		GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);
		Delay(550);
		
		CAN_Receive(CAN1,CAN_FIFO0,&myRxMsg);
		CAN_FIFORelease(CAN1 ,CAN_FIFO0);
		
		
		if(myRxMsg.StdId == 0x123)
		{
				Led_Tog(1000 ,1 ,GPIOC ,GPIO_PIN_13);
		}
		
		else
		{
				Led_Tog(100 ,1 ,GPIOC ,GPIO_PIN_13);
		}
		
	}		

}
