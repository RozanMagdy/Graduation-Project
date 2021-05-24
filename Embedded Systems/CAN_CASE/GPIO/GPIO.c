//------------------------------------------------------------HAL_GPIO.c
#include "stm32f10x.h"
#include "GPIO.h"
#include "GPIO_config.h"


void GPIO_void_Init(){
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
				GPIOA->CRL &= ~((1<<(0))|(1<<(1))| (1<<(2))|(1<<(3)));
				//setting it with the configration of Input Analog == 0 0
				GPIOA->CRL |=  (GPIOA_PIN0_MODE<<0);
	      #endif

	#if GPIOA_PIN1 == INIT
				GPIOA->CRL &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				GPIOA->CRL |=  (GPIOA_PIN1_MODE<<4);
				#endif

	#if GPIOA_PIN2 == INIT
				GPIOA->CRL &= ~((1<<8)|(1<<(9))| (1<<(10))|(1<<(11)));
				GPIOA->CRL |=  (GPIOA_PIN2_MODE<<8);
				#endif

	#if GPIOA_PIN3 == INIT
				GPIOA->CRL &= ~((1<<12)|(1<<(13))| (1<<(14))|(1<<(15)));
				GPIOA->CRL |=  (GPIOA_PIN3_MODE<<12);
				#endif

	#if GPIOA_PIN4 == INIT
				GPIOA->CRL &= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				GPIOA->CRL |=  (GPIOA_PIN4_MODE<<16);
				#endif

		#if GPIOA_PIN5 == INIT
				GPIOA->CRL &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				GPIOA->CRL |=  (GPIOA_PIN5_MODE<<20);
				#endif

	#if GPIOA_PIN6 == INIT
				GPIOA->CRL &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				GPIOA->CRL |=  (GPIOA_PIN6_MODE<<24);
				#endif

		#if GPIOA_PIN7 == INIT
				GPIOA->CRL &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				GPIOA->CRL |=  (GPIOA_PIN7_MODE<<28);
				#endif
	//
	//
	//.........B) HIGH PINs Config.
	//
	//
	#if  GPIOA_PIN8 == INIT
				//re-setting the 4 bits of the desired pin.
				GPIOA->CRH &= ~((1<<0)|(1<<(1))| (1<<(2))|(1<<(3)));
				//setting it with the configration of Input Analog == 0 0
				GPIOA->CRH |=  (GPIOA_PIN8_MODE<<0);
				#endif

	#if GPIOA_PIN9 == INIT
				GPIOA->CRH &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				GPIOA->CRH|=  (GPIOA_PIN9_MODE<<4);
	#endif

	#if GPIOA_PIN10 == INIT
				GPIOA->CRH &= ~((1<<8)|(1<<(9))| (1<<(10))|(1<<(11)));
				GPIOA->CRH |=  (GPIOA_PIN10_MODE<<8);
#endif

	#if GPIOA_PIN11 == INIT
				GPIOA->CRH &= ~((1<<12)|(1<<(13))| (1<<(14))|(1<<(15)));
				GPIOA->CRH |=  (GPIOA_PIN11_MODE<<12);
	#endif

	#if GPIOA_PIN12 == INIT
				GPIOA->CRH&= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				GPIOA->CRH |=  (GPIOA_PIN12_MODE<<16);
	#endif

		#if GPIOA_PIN13 == INIT
				GPIOA->CRH &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				GPIOA->CRH |=  (GPIOA_PIN13_MODE<<20);
	#endif

	#if GPIOA_PIN14 == INIT
				GPIOA->CRH &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				GPIOA->CRH |=  (GPIOA_PIN14_MODE<<24);
		#endif

		#if GPIOA_PIN15 == INIT
				GPIOA->CRH &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				GPIOA->CRH |=  (GPIOA_PIN15_MODE<<28);
	#endif
//
//
								//********
								//PORTB
								//********
	//.........A)LOW PINs Config.
	#if  GPIOB_PIN0 == INIT
				//re-setting the 4 bits of the desired pin.
				GPIOB->CRL &= ~((1<<0)|(1<<(1))| (1<<(2))|(1<<(3)));
				//setting it with the configration of Input Analog == 0 0
				GPIOB->CRL |=  (GPIOB_PIN0_MODE<<0);
				#endif

	#if GPIOB_PIN1 == INIT
				GPIOB->CRL &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				GPIOB->CRL |=  (GPIOB_PIN1_MODE<<4);
	#endif

	#if GPIOB_PIN2 == INIT
				GPIOB->CRL &= ~((1<<8)|(1<<(9))| (1<<(10))|(1<<(11)));
				GPIOB->CRL |=  (GPIOB_PIN2_MODE<<8);
#endif

	#if GPIOB_PIN3 == INIT
				GPIOB->CRL &= ~((1<<12)|(1<<(13))| (1<<(14))|(1<<(15)));
				GPIOB->CRL |=  (GPIOB_PIN3_MODE<<12);
	#endif

	#if GPIOB_PIN4 == INIT
				GPIOB->CRL &= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				GPIOB->CRL |=  (GPIOB_PIN4_MODE<<16);
	#endif

		#if GPIOB_PIN5 == INIT
				GPIOB->CRL &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				GPIOB->CRL |=  (GPIOB_PIN5_MODE<<20);
	#endif

	#if GPIOB_PIN6 == INIT
				GPIOB->CRL &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				GPIOB->CRL |=  (GPIOB_PIN6_MODE<<24);
		#endif

		#if GPIOB_PIN7 == INIT
				GPIOB->CRL &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				GPIOB->CRL |=  (GPIOB_PIN7_MODE<<28);
	#endif
	// 28---24---20---16---12---8---4---0 . these are the shifts for pins from 15 to 8 OR 7 to 0-7
	//they are 4 bits shited a number of times corresponding to the pin number
	//
	//
	//.........B) HIGH PINs Config.
	//
	//
	#if  GPIOB_PIN8 == INIT
				//re-setting the 4 bits of the desired pin.
				GPIOB->CRH &= ~((1<<0)|(1<<(1))| (1<<(2))|(1<<(3)));
				//setting it with the configration of Input Analog == 0 0
				GPIOB->CRH |=  (GPIOB_PIN8_MODE<<0);
				#endif

	#if GPIOB_PIN9 == INIT
				GPIOB->CRH &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				GPIOB->CRH|=  (GPIOB_PIN9_MODE<<4);
	#endif

	#if GPIOB_PIN10 == INIT
				GPIOB->CRH &= ~((1<<8)|(1<<(9))| (1<<(10))|(1<<(11)));
				GPIOB->CRH |=  (GPIOB_PIN10_MODE<<8);
#endif

	#if GPIOB_PIN11 == INIT
				GPIOB->CRH &= ~((1<<12)|(1<<(13))| (1<<(14))|(1<<(15)));
				GPIOB->CRH |=  (GPIOB_PIN11_MODE<<12);
	#endif

	#if GPIOB_PIN12 == INIT
				GPIOB->CRH&= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				GPIOB->CRH |=  (GPIOB_PIN12_MODE<<16);
	#endif

		#if GPIOB_PIN13 == INIT
				GPIOB->CRH &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				GPIOB->CRH |=  (GPIOB_PIN13_MODE<<20);
	#endif

	#if GPIOB_PIN14 == INIT
				GPIOB->CRH &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				GPIOB->CRH |=  (GPIOB_PIN14_MODE<<24);
		#endif

		#if GPIOB_PIN15 == INIT
				GPIOB->CRH &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				GPIOB->CRH |=  (GPIOB_PIN15_MODE<<28);
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
				GPIOC->CRL &= ~((1<<0)|(1<<(1))| (1<<(2))|(1<<(3)));
				//setting it with the configration of Input Analog == 0 0
				GPIOC->CRL |=  (GPIOC_PIN0_MODE<<0);
	#endif

	#if GPIOC_PIN1 == INIT
				GPIOC->CRL &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				GPIOC->CRL |=  (GPIOC_PIN1_MODE<<4);
	#endif

	#if GPIOC_PIN2 == INIT
				GPIOC->CRL &= ~((1<<8)|(1<<(9))| (1<<(10))|(1<<(11)));
				GPIOC->CRL |=  (GPIOC_PIN2_MODE<<8);
#endif

	#if GPIOC_PIN3 == INIT
				GPIOC->CRL &= ~((1<<12)|(1<<(13))| (1<<(14))|(1<<(15)));
				GPIOC->CRL |=  (GPIOC_PIN3_MODE<<12);
	#endif

	#if GPIOC_PIN4 == INIT
				GPIOC->CRL &= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				GPIOC->CRL |=  (GPIOC_PIN4_MODE<<16);
	#endif
		#if GPIOC_PIN5 == INIT
				GPIOC->CRL &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				GPIOC->CRL |=  (GPIOC_PIN5_MODE<<20);
	#endif
	#if GPIOC_PIN6 == INIT
				GPIOC->CRL &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				GPIOC->CRL |=  (GPIOC_PIN6_MODE<<24);
		#endif

		#if GPIOC_PIN7 == INIT
				GPIOC->CRL &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				GPIOC->CRL |=  (GPIOC_PIN7_MODE<<28);
	#endif
	//
	//
	//.........B) PORT C HIGH PINs Config.
	//
	//
	#if  GPIOC_PIN8 == INIT
				//re-setting the 4 bits of the desired pin.
				GPIOC->CRH &= ~((1<<0)|(1<<(1))| (1<<(2))|(1<<(3)));
				//setting it with the configration of Input Analog == 0 0
				GPIOC->CRH |=  (GPIOC_PIN8_MODE<<0);
				#endif
	#if GPIOC_PIN9 == INIT
				GPIOC->CRH &= ~((1<<4)|(1<<(5))| (1<<(6))|(1<<(7)));
				GPIOC->CRH|=  (GPIOC_PIN9_MODE<<4);
	#endif
	#if GPIOC_PIN10 == INIT
				GPIOC->CRH &= ~((1<<8)|(1<<(9))| (1<<(10))|(1<<(11)));
				GPIOC->CRH |=  (GPIOC_PIN10_MODE<<8);
#endif

	#if GPIOC_PIN11 == INIT
				GPIOC->CRH &= ~((1<<12)|(1<<(13))| (1<<(14))|(1<<(15)));
				GPIOC->CRH |=  (GPIOC_PIN11_MODE<<12);
	#endif

	#if GPIOC_PIN12 == INIT
				GPIOC->CRH&= ~((1<<16)|(1<<(17))| (1<<(18))|(1<<(19)));
				GPIOC->CRH |=  (GPIOC_PIN12_MODE<<16);
	#endif

	#if GPIOC_PIN13 == INIT
				GPIOC->CRH &= ~((1<<20)|(1<<(21))| (1<<(22))|(1<<(23)));
				GPIOC->CRH |=  (GPIOC_PIN13_MODE<<20);
	#endif

	#if GPIOC_PIN14 == INIT
				GPIOC->CRH &= ~((1<<24)|(1<<(25))| (1<<(26))|(1<<(27)));
				GPIOC->CRH |=  (GPIOC_PIN14_MODE<<24);
		#endif

	#if GPIOC_PIN15 == INIT
				GPIOC->CRH &= ~((1<<28)|(1<<(29))| (1<<(30))|(1<<(31)));
				GPIOC->CRH |=  (GPIOC_PIN15_MODE<<28);
	#endif
//
}


void GPIO_void_SetPinValue(GPIO_TypeDef *port, U8 pin, U8 state){
	//a function that can write on the whole port or on a specific pin
	// first, check for state.
	//state is a reference to whether u are working on:
	// pins (0-7) <--- LOW ..........pins (8-15) <--- HIGH
	if (state == 1){
		//shift 1 into that pinNumber
		port->BSRR = (1<<pin);
	}else{
		port->BSRR = (1<<(pin+16));
	}
}

U8 GPIO_uint8_GetPinValue( GPIO_TypeDef * port , U8 pin){
U8 state;
	state = port->ODR;
return state;
}


