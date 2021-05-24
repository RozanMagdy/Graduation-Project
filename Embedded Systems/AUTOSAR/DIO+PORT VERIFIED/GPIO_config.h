// its like a switch made for each pin, to turn on and off

#define INIT    1
#define UN_INIT 0

//speed of the output pins (all pins)
#define OUT_SPEED ((uint8) 0x03) // 50MHz
//
//PORTS FROM A-C ARE USED IN STM32F103C8 uc
//First, Choose PORTs you will use
#define GPIO_A INIT
#define GPIO_B INIT
#define GPIO_C INIT
#define AF   	 INIT
//
//Secondly, Use the desired Pins to be activated from these PORT
//
/*Remember That Mode Options are:
........In.....................Out .................. AF
INPUT_ANALOG 						  OUTPUT_PU_PU  			    OUTPUT_AF_PU_PU 
INPUT_FLOATING  					OUTTPUT_OPEN_DRAIN 		  OUTPUT_AF_OPEN_DRAIN
INPUT_PU_PD 																	  
..............................................
*/
//
//********
//PORTA
//********
#define GPIOA_PIN0		  UN_INIT
#define GPIOA_PIN0_MODE 		OUTPUT_PU_PU

#define GPIOA_PIN1		  UN_INIT
#define GPIOA_PIN1_MODE 		OUTPUT_PU_PU

#define GPIOA_PIN2		  UN_INIT
#define GPIOA_PIN2_MODE 		OUTPUT_PU_PU

#define GPIOA_PIN3		  UN_INIT
#define GPIOA_PIN3_MODE 		OUTPUT_PU_PU

#define GPIOA_PIN4		  UN_INIT
#define GPIOA_PIN4_MODE 		OUTPUT_PU_PU

#define GPIOA_PIN5		  UN_INIT
#define GPIOA_PIN5_MODE 		OUTPUT_PU_PU

#define GPIOA_PIN6			UN_INIT
#define GPIOA_PIN6_MODE 		OUTPUT_PU_PU

#define GPIOA_PIN7			UN_INIT
#define GPIOA_PIN7_MODE 		OUTPUT_PU_PU

#define GPIOA_PIN8			UN_INIT
#define GPIOA_PIN8_MODE 		OUTPUT_PU_PU

#define GPIOA_PIN9			INIT
#define GPIOA_PIN9_MODE 		OUTPUT_AF_PU_PU

#define GPIOA_PIN10			INIT
#define GPIOA_PIN10_MODE 		INPUT_FLOATING

#define GPIOA_PIN11			INIT
#define GPIOA_PIN11_MODE 		INPUT_PU_PD

#define GPIOA_PIN12			INIT
#define GPIOA_PIN12_MODE 		OUTPUT_AF_PU_PU

#define GPIOA_PIN13			UN_INIT
#define GPIOA_PIN13_MODE 		OUTPUT_PU_PU

#define GPIOA_PIN14			UN_INIT
#define GPIOA_PIN14_MODE 		OUTPUT_PU_PU

#define GPIOA_PIN15			UN_INIT
#define GPIOA_PIN15_MODE 		OUTPUT_PU_PU
//........................................
//........................................
//********
//PORTB
//********
//........................................
#define GPIOB_PIN0		UN_INIT
#define GPIOB_PIN0_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN1		UN_INIT
#define GPIOB_PIN1_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN2		UN_INIT
#define GPIOB_PIN2_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN3		UN_INIT
#define GPIOB_PIN3_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN4		UN_INIT
#define GPIOB_PIN4_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN5		UN_INIT
#define GPIOB_PIN5_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN6		UN_INIT
#define GPIOB_PIN6_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN7		UN_INIT
#define GPIOB_PIN7_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN8		UN_INIT
#define GPIOB_PIN8_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN9		UN_INIT
#define GPIOB_PIN9_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN10		UN_INIT
#define GPIOB_PIN10_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN11		UN_INIT
#define GPIOB_PIN11_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN12		INIT
#define GPIOB_PIN12_MODE 		INPUT_PU_PD 

#define GPIOB_PIN13		UN_INIT
#define GPIOB_PIN13_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN14		UN_INIT
#define GPIOB_PIN14_MODE 		OUTPUT_PU_PU

#define GPIOB_PIN15		UN_INIT
#define GPIOB_PIN15_MODE 		OUTPUT_PU_PU
//........................................
//........................................
//********
//PORTC
//********
//........................................
#define GPIOC_PIN0		UN_INIT
#define GPIOC_PIN0_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN1		UN_INIT
#define GPIOC_PIN1_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN2		UN_INIT
#define GPIOC_PIN2_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN3		UN_INIT
#define GPIOC_PIN3_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN4		UN_INIT
#define GPIOC_PIN4_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN5		UN_INIT
#define GPIOC_PIN5_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN6		UN_INIT
#define GPIOC_PIN6_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN7		UN_INIT
#define GPIOC_PIN7_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN8		UN_INIT
#define GPIOC_PIN8_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN9		UN_INIT
#define GPIOC_PIN9_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN10		UN_INIT
#define GPIOC_PIN10_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN11		UN_INIT
#define GPIOC_PIN11_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN12		UN_INIT
#define GPIOC_PIN12_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN13		INIT
#define GPIOC_PIN13_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN14		UN_INIT
#define GPIOC_PIN14_MODE 		OUTPUT_PU_PU

#define GPIOC_PIN15		UN_INIT
#define GPIOC_PIN15_MODE 		OUTPUT_PU_PU
//End 


