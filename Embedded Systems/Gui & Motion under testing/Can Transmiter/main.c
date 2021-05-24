#include "Gpio/Gpio.h"
#include "Can/Can.h"



CanTxMsg myTxMsg;


int main()
{
	
	Delay_Init();
	Gpio_Init();
	Can_Init();
	
	
	
	
	uint8_t DCMotor_Direction = 0;
	uint8_t DCMotor_Speed = 0; 
	
	uint8_t Stepper_Direction = 0;
	uint8_t Stepper_Angle = 0;
	
	
	
	
	uint8_t* data = 0;
	uint8_t DLC = 4;
	uint8_t ID = 0x010;
	
	
	Can_SetTxMsg(&myTxMsg ,ID ,CAN_RTR_DATA ,DLC ,data);

	
	
	while(1)
	{
		
	
		myTxMsg.Data[0] = DCMotor_Direction;
		myTxMsg.Data[1] = DCMotor_Speed;
		
		
		myTxMsg.Data[2] = Stepper_Direction;
		myTxMsg.Data[3] = Stepper_Angle;
		
		
		CAN_Transmit(CAN1,&myTxMsg);
		Led_Tog(1000 ,1 ,GPIOC ,GPIO_PIN_13);
		
	}	
	

}

