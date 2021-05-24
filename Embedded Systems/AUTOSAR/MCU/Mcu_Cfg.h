#ifndef Mcu_Cfg_h
#define Mcu_Cfg_h


/*
 * Module Version 1.0.0
 */
#define MCU_CFG_SW_MAJOR_VERSION              (1U)
#define MCU_CFG_SW_MINOR_VERSION              (0U)
#define MCU_CFG_SW_PATCH_VERSION            	(0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define MCU_CFG_AR_RELEASE_MAJOR_VERSION     	(4U)
#define MCU_CFG_AR_RELEASE_MINOR_VERSION     	(0U)
#define MCU_CFG_AR_RELEASE_PATCH_VERSION     	(3U)


/* Pre-compile option for Version Info API */
#define MCU_VERSION_INFO_API          	(STD_OFF)

///////////////////////////////////////////////////////////
#define ENABLED 												(1U)
#define DISABLED 												(0U)

///////////////////////////////////////////////////////////

/* Pre-compile option for Development Error Detect */
#define MCU_DEV_ERROR_DETECT	        	(STD_OFF)

/* Enabling/Disabling getting the RAM state capability */
#define MCU_GET_RAM_STATE_API    	     	(STD_OFF)

/* Enabling/Disabling Initialising the clock by software intervention */
#define MCU_INIT_CLOCK                	(STD_ON)


/* PLL exists and it needs SW intervention */
#define MCU_NO_PLL                			(STD_OFF)

/* Enabling/Disabling performing software reset feature */
#define MCU_PERFORM_RESET_API						(STD_OFF)

//10.2.4 MCU Module Configuration

#define NUMBER_OF_CLOCK_CONGIFURATION 						(2U)
#define NUMBER_OF_RAM_CONGIFURATION								(2U)
#define NUMBER_OF_PERIPHERALS_CONGIFURATION				(2U)


/* Enabling/Disabling interrupts when the clock source fails */
#define MCU_CLOCK_SOURCE_FAILURE_NOTIFICATION (DISABLED)

/* Power Modes */
#define MCU_NUMBER_OF_MODES 							(3U) //Sleep - Standby - Stop
#define MCU_MODE_SLEEP_NOW								(0U)
#define MCU_MODE_STANDBY									(1U)
#define MCU_MODE_SLEEP_ON_EXIT						(2U)


/*******************************************************************************
 *                              Module Configuration                           *
 *******************************************************************************/
/* Clock Source */
#define CLK_SRC_HSI												(0U)
#define CLK_SRC_HSE												(1U)
//#define CLK_SRC_PLL											(2U) //Need to be considered in the .c file
//#define CLK_SRC_LSE											(2U)
//#define CLK_SRC_LSI											(3U)

/* PLL Multiplication */
#define PLL_MULT_2												(2U)
#define PLL_MULT_3												(3U)
#define PLL_MULT_4												(4U)
#define PLL_MULT_5												(5U)
#define PLL_MULT_6												(6U)
#define PLL_MULT_7												(7U)
#define PLL_MULT_8												(8U)
#define PLL_MULT_9												(9U)
#define PLL_MULT_10												(10U)
#define PLL_MULT_11												(11U)
#define PLL_MULT_12												(12U)
#define PLL_MULT_13												(13U)
#define PLL_MULT_14												(14U)
#define PLL_MULT_15												(15U)
#define PLL_MULT_16												(16U)
#define PLL_NONE													(0U)

/* HSE Divider */
#define HSE_DIV_1													(0U)
#define HSE_DIV_2													(1U)

/* Clock Switch */
#define CLK_SWITCH_HSI										(0U)
#define CLK_SWITCH_PLL										(1U)
#define CLK_SWITCH_HSE										(2U)

/* AHB Prescalar */
#define AHB_PR_1													(0U)
#define AHB_PR_2													(8U)
#define AHB_PR_4													(9U)
#define AHB_PR_8													(10U)
#define AHB_PR_16													(11U)
#define AHB_PR_64													(12U)
#define AHB_PR_128												(13U)
#define AHB_PR_256												(14U)
#define AHB_PR_512												(15U)

/* APB1 Prescalar */
#define APB1_PR_1													(0U)
#define APB1_PR_2													(4U)
#define APB1_PR_4													(5U)
#define APB1_PR_8													(6U)
#define APB1_PR_16												(7U)

/* APB2 Prescalar */
#define APB2_PR_1													(1U)
#define APB2_PR_2													(4U)
#define APB2_PR_4													(5U)
#define APB2_PR_8													(6U)
#define APB2_PR_16												(7U)

/* SYSCLK Frequency */
#define SYSCLK_FREQ_8MHZ									(8U)	//HSE_DIV_1, CLK_SWITCH_HSE, PLL_NONE
#define SYSCLK_FREQ_12MHZ									(12U)	//HSE_DIV_2, CLK_SWITCH_PLL, PLL_MULT_3
#define SYSCLK_FREQ_16MHZ									(16U)	//HSE_DIV_1, CLK_SWITCH_PLL, PLL_MULT_2
#define SYSCLK_FREQ_20MHZ									(20U)	//HSE_DIV_2, CLK_SWITCH_PLL, PLL_MULT_5
#define SYSCLK_FREQ_24MHZ									(24U)	//HSE_DIV_1, CLK_SWITCH_PLL, PLL_MULT_3
#define SYSCLK_FREQ_28MHZ									(28U)	//HSE_DIV_2, CLK_SWITCH_PLL, PLL_MULT_7
#define SYSCLK_FREQ_32MHZ									(32U)	//HSE_DIV_1, CLK_SWITCH_PLL, PLL_MULT_4
#define SYSCLK_FREQ_36MHZ									(36U)	//HSE_DIV_2, CLK_SWITCH_PLL, PLL_MULT_9
#define SYSCLK_FREQ_40MHZ									(40U)	//HSE_DIV_1, CLK_SWITCH_PLL, PLL_MULT_5
#define SYSCLK_FREQ_44MHZ									(44U)	//HSE_DIV_2, CLK_SWITCH_PLL, PLL_MULT_11
#define SYSCLK_FREQ_48MHZ									(48U)	//HSE_DIV_1, CLK_SWITCH_PLL, PLL_MULT_6
#define SYSCLK_FREQ_52MHZ									(52U)	//HSE_DIV_2, CLK_SWITCH_PLL, PLL_MULT_13
#define SYSCLK_FREQ_56MHZ									(56U)	//HSE_DIV_1, CLK_SWITCH_PLL, PLL_MULT_7
#define SYSCLK_FREQ_60MHZ									(60U)	//HSE_DIV_2, CLK_SWITCH_PLL, PLL_MULT_15
#define SYSCLK_FREQ_64MHZ									(64U)	//HSE_DIV_1, CLK_SWITCH_PLL, PLL_MULT_8
#define SYSCLK_FREQ_72MHZ									(72U)	//HSE_DIV_1, CLK_SWITCH_PLL, PLL_MULT_9

#define HSE_FREQ_VALUE										(8U)	//Need to be used in the logic in the .c code
#define HSI_FREQ_VALUE										(8U)

#define CLOCK_CONFIG_0										(0U)
#define CLOCK_CONFIG_1										(1U)


#endif

