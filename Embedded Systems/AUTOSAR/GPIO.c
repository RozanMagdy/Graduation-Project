//------------------------------------------------------------HAL_GPIO.c
#include "GPIO.h"

void GPIO_voidInit(void){ 
	//this function configures each pin to be ready to use. it reads directly 
	//																											from "GPIO_config.h".
	//**************************************************
	//First, the PORT selection
	// 													Here, we enable either GPIO ports or Alternate Function I/O
	//**************************************************
	#if GPIO_A == INIT
		GPIO_CLK_ENABLE_PORTA;
  	#endif
	
	 #if GPIO_B == INIT
		GPIO_CLK_ENABLE_PORTB;
	  #endif
	
   #if GPIO_C == INIT
		GPIO_CLK_ENABLE_PORTC;
	  #endif
	
	 #if AF == UN_INIT
	  GPIO_CLK_ENABLE_AF;
	  #endif
	//
	//**************************************************
	//Second, Pins and Pin Mode Selection
  //																		Here, Mode and Speed commands/Settings are made 
	//																		to the pins for each port																						
	//**************************************************
				
								//********
								//PORTA
								//********
	//.........A)LOW PINs Config.
	#if  GPIOA_PIN0 == INIT
				//re-setting the 4 bits of the desired pin.
				PORTA_CRL &= ~((1<<0)|(1<<(1))| (1<<(2))|(1<<(3)));
				//setting it with the configration of Input Analog == 0 0
				PORTA_CRL |=  (GPIOA_PIN0_MODE<<0);
	      #endif
				
	#if GPIOA_PIN1 == INIT
				PORTA_CRL &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				PORTA_CRL |=  (GPIOA_PIN1_MODE<<4);
				#endif
				
	#if GPIOA_PIN2 == INIT
				PORTA_CRL &= ~((1<<8)|(1<<(9))|(1<<(10))|(1<<(11)));
				PORTA_CRL |=  (GPIOA_PIN2_MODE<<8);
				#endif
				
	#if GPIOA_PIN3 == INIT
				PORTA_CRL &= ~((1<<12)|(1<<(13))| (1<<(14))|(1<<(15)));
				PORTA_CRL |=  (GPIOA_PIN3_MODE<<12);
				#endif
				
	#if GPIOA_PIN4 == INIT
				PORTA_CRL &= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				PORTA_CRL |=  (GPIOA_PIN4_MODE<<16);
				#endif
				
		#if GPIOA_PIN5 == INIT
				PORTA_CRL &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				PORTA_CRL |=  (GPIOA_PIN5_MODE<<20);
				#endif
				
	#if GPIOA_PIN6 == INIT
				PORTA_CRL &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				PORTA_CRL |=  (GPIOA_PIN6_MODE<<24);
				#endif
				
		#if GPIOA_PIN7 == INIT
				PORTA_CRL &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				PORTA_CRL |=  (GPIOA_PIN7_MODE<<28);	
				#endif
	//
	//
	//.........B) HIGH PINs Config.
	//
	//
	#if  GPIOA_PIN8 == INIT
				//re-setting the 4 bits of the desired pin.
				PORTA_CRH &= ~((1<<0)|(1<<(1))| (1<<(2))|(1<<(3)));
				//setting it with the configration of Input Analog == 0 0
				PORTA_CRH |=  (GPIOA_PIN8_MODE<<0);
				#endif
				
	#if GPIOA_PIN9 == INIT
				PORTA_CRH &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				PORTA_CRH|=  (GPIOA_PIN9_MODE<<4);
	#endif
	
	#if GPIOA_PIN10 == INIT
				PORTA_CRH &= ~((1<<8)|(1<<(9))| (1<<(10))|(1<<(11)));
				PORTA_CRH |=  (GPIOA_PIN10_MODE<<8);
#endif

	#if GPIOA_PIN11 == INIT
				PORTA_CRH &= ~((1<<12)|(1<<(13))| (1<<(14))|(1<<(15)));
				PORTA_CRH |=  (GPIOA_PIN11_MODE<<12);
	#endif
	
	#if GPIOA_PIN12 == INIT
				PORTA_CRH &= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				PORTA_CRH |=  (GPIOA_PIN12_MODE<<16);
	#endif
	
		#if GPIOA_PIN13 == INIT
				PORTA_CRH &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				PORTA_CRH |=  (GPIOA_PIN13_MODE<<20);
	#endif
	
	#if GPIOA_PIN14 == INIT
				PORTA_CRH &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				PORTA_CRH |=  (GPIOA_PIN14_MODE<<24);
		#endif
		
		#if GPIOA_PIN15 == INIT
				PORTA_CRH &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				PORTA_CRH |=  (GPIOA_PIN15_MODE<<28);	
	#endif
//
//			
								//********
								//PORTB
								//********
	//.........A)LOW PINs Config.
	#if  GPIOB_PIN0 == INIT
				//re-setting the 4 bits of the desired pin.
				PORTB_CRL &= ~((1<<0)|(1<<(1))| (1<<(2))|(1<<(3)));
				//setting it with the configration of Input Analog == 0 0
				PORTB_CRL |=  (GPIOB_PIN0_MODE<<0);
				#endif
				
	#if GPIOB_PIN1 == INIT
				PORTB_CRL &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				PORTB_CRL |=  (GPIOB_PIN1_MODE<<4);
	#endif
	
	#if GPIOB_PIN2 == INIT
				PORTB_CRL &= ~((1<<8)|(1<<(9))| (1<<(10))|(1<<(11)));
				PORTB_CRL |=  (GPIOB_PIN2_MODE<<8);
#endif

	#if GPIOB_PIN3 == INIT
				PORTB_CRL &= ~((1<<12)|(1<<(13))| (1<<(14))|(1<<(15)));
				PORTB_CRL |=  (GPIOB_PIN3_MODE<<12);
	#endif
	
	#if GPIOB_PIN4 == INIT
				PORTB_CRL &= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				PORTB_CRL |=  (GPIOB_PIN4_MODE<<16);
	#endif
	
		#if GPIOB_PIN5 == INIT
				PORTB_CRL &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				PORTB_CRL |=  (GPIOB_PIN5_MODE<<20);
	#endif
	
	#if GPIOB_PIN6 == INIT
				PORTB_CRL &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				PORTB_CRL |=  (GPIOB_PIN6_MODE<<24);
		#endif
		
		#if GPIOB_PIN7 == INIT
				PORTB_CRL &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				PORTB_CRL |=  (GPIOB_PIN7_MODE<<28);	
	#endif
	//
	//
	//.........B) HIGH PINs Config.
	//
	//
	#if  GPIOB_PIN8 == INIT
				//re-setting the 4 bits of the desired pin.
				PORTB_CRH &= ~((1<<0)|(1<<(1))| (1<<(2))|(1<<(3)));
				//setting it with the configration of Input Analog == 0 0
				PORTB_CRH |=  (GPIOB_PIN8_MODE<<0);
				#endif
				
	#if GPIOB_PIN9 == INIT
				PORTB_CRH &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				PORTB_CRH|=  (GPIOB_PIN9_MODE<<4);
	#endif
	
	#if GPIOB_PIN10 == INIT
				PORTB_CRH &= ~((1<<8)|(1<<(9))| (1<<(10))|(1<<(11)));
				PORTB_CRH |=  (GPIOB_PIN10_MODE<<8);
#endif

	#if GPIOB_PIN11 == INIT
				PORTB_CRH &= ~((1<<12)|(1<<(13))| (1<<(14))|(1<<(15)));
				PORTB_CRH |=  (GPIOB_PIN11_MODE<<12);
	#endif
	
	#if GPIOB_PIN12 == INIT
				PORTB_CRH&= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				PORTB_CRH |=  (GPIOB_PIN12_MODE<<16);
	#endif
	
		#if GPIOB_PIN13 == INIT
				PORTB_CRH &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				PORTB_CRH |=  (GPIOB_PIN13_MODE<<20);
	#endif
	
	#if GPIOB_PIN14 == INIT
				PORTB_CRH &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				PORTB_CRH |=  (GPIOB_PIN14_MODE<<24);
		#endif
		
		#if GPIOB_PIN15 == INIT
				PORTB_CRH &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				PORTB_CRH |=  (GPIOB_PIN15_MODE<<28);	
	#endif
//
//
//
								//********
								//PORTC
								//********
	//.........A) PORT C LOW PINs Config.
	#if  GPIOC_PIN0 == INIT
				//re-setting the 4 bits of the desired pin.
				PORTC_CRL &= ~((1<<0)|(1<<(1))| (1<<(2))|(1<<(3)));
				//setting it with the configration of Input Analog == 0 0
				PORTC_CRL |=  (GPIOC_PIN0_MODE<<0);
	#endif			
	
	#if GPIOC_PIN1 == INIT
				PORTC_CRL &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				PORTC_CRL |=  (GPIOC_PIN1_MODE<<4);
	#endif
	
	#if GPIOC_PIN2 == INIT
				PORTC_CRL &= ~((1<<8)|(1<<(9))| (1<<(10))|(1<<(11)));
				PORTC_CRL |=  (GPIOC_PIN2_MODE<<8);
#endif

	#if GPIOC_PIN3 == INIT
				PORTC_CRL &= ~((1<<12)|(1<<(13))| (1<<(14))|(1<<(15)));
				PORTC_CRL |=  (GPIOC_PIN3_MODE<<12);
	#endif
	
	#if GPIOC_PIN4 == INIT
				PORTC_CRL &= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				PORTC_CRL |=  (GPIOC_PIN4_MODE<<16);
	#endif
		#if GPIOC_PIN5 == INIT
				PORTC_CRL &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				PORTC_CRL |=  (GPIOC_PIN5_MODE<<20);
	#endif
	#if GPIOC_PIN6 == INIT
				PORTC_CRL &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				PORTC_CRL |=  (GPIOC_PIN6_MODE<<24);
		#endif
		
		#if GPIOC_PIN7 == INIT
				PORTC_CRL &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				PORTC_CRL |=  (GPIOC_PIN7_MODE<<28);	
	#endif
	//
	//
	//.........B) PORT C HIGH PINs Config.
	//
	//
	#if  GPIOC_PIN8 == INIT
				//re-setting the 4 bits of the desired pin.
				PORTC_CRH &= ~((1<<0)|(1<<(1))| (1<<(2))|(1<<(3)));
				//setting it with the configration of Input Analog == 0 0
				PORTC_CRH |=  (GPIOC_PIN8_MODE<<0);
				#endif
	#if GPIOC_PIN9 == INIT
				PORTC_CRH &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				PORTC_CRH|=  (GPIOC_PIN9_MODE<<4);
	#endif
	#if GPIOC_PIN10 == INIT
				PORTC_CRH &= ~((1<<8)|(1<<(9))| (1<<(10))|(1<<(11)));
				PORTC_CRH |=  (GPIOC_PIN10_MODE<<8);
#endif

	#if GPIOC_PIN11 == INIT
				PORTC_CRH &= ~((1<<12)|(1<<(13))| (1<<(14))|(1<<(15)));
				PORTC_CRH |=  (GPIOC_PIN11_MODE<<12);
	#endif
	
	#if GPIOC_PIN12 == INIT
				PORTC_CRH&= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				PORTC_CRH |=  (GPIOC_PIN12_MODE<<16);
	#endif
	
	#if GPIOC_PIN13 == INIT
				
				PORTC_CRH &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				PORTC_CRH |=  (GPIOC_PIN13_MODE<<20);
	#endif
	
	#if GPIOC_PIN14 == INIT
				PORTC_CRH &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				PORTC_CRH |=  (GPIOC_PIN14_MODE<<24);
		#endif
		
	#if GPIOC_PIN15 == INIT
				PORTC_CRH &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				PORTC_CRH |=  (GPIOC_PIN15_MODE<<28);	
	#endif
//		
}


void GPIO_void_SetPinValue(PORT port, uint8 pin, uint8 state){
	//a function that can write on the whole port or on a specific pin
	// first, check for state. 
	//state is a reference to whether u are working on:
	// pins (0-7) <--- LOW ..........pins (8-15) <--- HIGH
	
		//shift 1 into that pinNumber
		switch(port){
		case PORTA:
			if (state == 1){
				PORTA_BSRR = (1<<pin);
			}else{
				PORTA_BSRR = (1<<(pin+16));
			}
		break;
		case PORTB:
			if (state == 1){
				PORTB_BSRR = (1<<pin);
			}else{
				PORTB_BSRR = (1<<(pin+16));
			}
		break;
		case PORTC:
			if (state == 1){
				PORTC_BSRR = (1<<pin);
			}else{
				PORTC_BSRR = (1<<(pin+16));
			}
		break;
		case PORTD:
			if (state == 1){
				PORTD_BSRR = (1<<pin);
			}else{
				PORTD_BSRR = (1<<(pin+16));
			}
		break;
		case PORTE:
			if (state == 1){
				PORTE_BSRR = (1<<pin);
			}else{
				PORTE_BSRR = (1<<(pin+16));
			}
		break;
		case PORTF:
			if (state == 1){
				PORTF_BSRR = (1<<pin);
			}else{
				PORTF_BSRR = (1<<(pin+16));
			}
		break;
		case PORTG:
			if (state == 1){
				PORTG_BSRR = (1<<pin);
			}else{
				PORTG_BSRR = (1<<(pin+16));
			}
		break;		
	}
	
	
}

uint8 GPIO_uint8_GetPinValue( PORT port , uint8 pin){
	uint8 state;
	switch(port){
		case PORTA:
			state = PORTA_ODR;
		break;
		case PORTB:
			state = PORTB_ODR;
		break;
		case PORTC:
			state = PORTC_ODR;
		break;
		case PORTD:
			state = PORTD_ODR;
		break;
		case PORTE:
			state = PORTE_ODR;
		break;
		case PORTF:
			state = PORTF_ODR;
		break;
		case PORTG:
			state = PORTG_ODR;
		break;		
	}
	
	return state;
}

void Led_Tog(uint16 ms ,uint8 i)
{
	uint8 j=0;
	
 		for(j=0 ;j<i ;j++)
		{
			GPIO_void_SetPinValue(PORTC,13,1);
			Delay(ms);
			GPIO_void_SetPinValue(PORTC,13,0);
			Delay(ms);
		}

}

