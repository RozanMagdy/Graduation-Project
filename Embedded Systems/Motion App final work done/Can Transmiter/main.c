#include "Gpio/Gpio.h"
#include "Can/Can.h"



CanTxMsg myTxMsg;


int main()
{
	
	Delay_Init();
	Gpio_Init();
	Can_Init();
	
	
	
	
	uint8_t DCMotor_Direction = 2;
	uint8_t DCMotor_Speed = 10; 
	
	uint8_t Stepper_Direction = 2;
	uint8_t Stepper_Angle = 10;
	
	
	
	
	uint8_t* data = 0;
	uint8_t DLC = 4;
	uint32_t ID = 0x123;
	
	
	Can_SetTxMsg(&myTxMsg ,ID ,CAN_RTR_DATA ,DLC ,data);
	
	
	
	while(1)
	{
		
	
		myTxMsg.Data[0] = DCMotor_Direction;
		myTxMsg.Data[1] = DCMotor_Speed;
		
		
		myTxMsg.Data[2] = Stepper_Direction;
		myTxMsg.Data[3] = Stepper_Angle;
		
		
		CAN_Transmit(CAN1,&myTxMsg);
		Led_Tog(100 ,1 ,GPIOC ,GPIO_PIN_13);
		Delay(100);
		
	}	
	

}

