
#include "std_types.h"

#define PERIPH_BASE           ((uint32)0x40000000) /*!< Peripheral base address in the alias region */

// Defining Base address for RCC
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)
#define RCC_BASE            	(AHBPERIPH_BASE + 0x1000)
#define APB2ENR (0x18)  //Input data reg

#define RCC_APB2ENR 					*((volatile uint32 *)(RCC_BASE+APB2ENR))


#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
/*Definig base addresses for GPIO Ports*/
#define GPIOA_BASE            (APB2PERIPH_BASE + 0x0800)
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)
#define GPIOC_BASE            (APB2PERIPH_BASE + 0x1000)
#define GPIOD_BASE            (APB2PERIPH_BASE + 0x1400)
#define GPIOE_BASE            (APB2PERIPH_BASE + 0x1800)
#define GPIOF_BASE            (APB2PERIPH_BASE + 0x1C00)
#define GPIOG_BASE            (APB2PERIPH_BASE + 0x2000)


 /* Defining offset values for DIO  regs*/
#define IDR (0x08)  //Input data reg
#define ODR (0x0C) // Output data reg
#define BSRR (0x10) // Bit setreset register
#define BRR (0x14) // Bit setreset register
#define CRL (0x00) // Bit reset register
#define CRH (0x04) // Bit reset register


 /* DefinitionS for PORTA Registers */
#define PORTA_CRH *((volatile uint32 *)(GPIOA_BASE+CRH))
#define PORTA_CRL *((volatile uint32 *)(GPIOA_BASE+CRL))
#define PORTA_IDR *((volatile uint32 *)(GPIOA_BASE+IDR))
#define PORTA_ODR *((volatile uint32 *)(GPIOA_BASE+ODR))
#define PORTA_BSRR *((volatile uint32 *)(GPIOA_BASE+BSRR))
#define PORTA_BRR *((volatile uint32 *)(GPIOA_BASE+BRR))
	

 /* DefinitionS for PORTB Registers */
#define PORTB_CRH *((volatile uint32 *)(GPIOB_BASE+CRH))
#define PORTB_CRL *((volatile uint32 *)(GPIOB_BASE+CRL))
#define PORTB_IDR *((volatile uint32 *)(GPIOB_BASE+IDR))
#define PORTB_ODR *((volatile uint32 *)(GPIOB_BASE+ODR))
#define PORTB_BSRR *((volatile uint32 *)(GPIOB_BASE+BSRR))
#define PORTB_BRR *((volatile uint32 *)(GPIOB_BASE+BRR))
 
	
 /* DefinitionS for PORTC Registers */
#define PORTC_CRH *((volatile uint32 *)(GPIOC_BASE+CRH))
#define PORTC_CRL *((volatile uint32 *)(GPIOC_BASE+CRL))
#define PORTC_IDR *((volatile uint32 *)(GPIOC_BASE+IDR))
#define PORTC_ODR *((volatile uint32 *)(GPIOC_BASE+ODR))
#define PORTC_BSRR *((volatile uint32 *)(GPIOC_BASE+BSRR))
#define PORTC_BRR *((volatile uint32 *)(GPIOC_BASE+BRR))

	
 /* DefinitionS for PORTD Registers */
#define PORTD_CRH *((volatile uint32 *)(GPIOD_BASE+CRH))
#define PORTD_CRL *((volatile uint32 *)(GPIOD_BASE+CRL))
#define PORTD_IDR *((volatile uint32 *)(GPIOD_BASE+IDR))
#define PORTD_ODR *((volatile uint32 *)(GPIOD_BASE+ODR))
#define PORTD_BSRR *((volatile uint32 *)(GPIOD_BASE+BSRR))
#define PORTD_BRR *((volatile uint32 *)(GPIOD_BASE+BRR))

	
 /* DefinitionS for PORTE Registers */
#define PORTE_CRH *((volatile uint32 *)(GPIOE_BASE+CRH))
#define PORTE_CRL *((volatile uint32 *)(GPIOE_BASE+CRL))
#define PORTE_IDR *((volatile uint32 *)(GPIOE_BASE+IDR))
#define PORTE_ODR *((volatile uint32 *)(GPIOE_BASE+ODR))
#define PORTE_BSRR *((volatile uint32 *)(GPIOE_BASE+BSRR))
#define PORTE_BRR *((volatile uint32 *)(GPIOE_BASE+BRR))

	
 /* DefinitionS for PORTF Registers */
#define PORTF_CRH *((volatile uint32 *)(GPIOF_BASE+CRH))
#define PORTF_CRL *((volatile uint32 *)(GPIOF_BASE+CRL))
#define PORTF_IDR *((volatile uint32 *)(GPIOF_BASE+IDR))
#define PORTF_ODR *((volatile uint32 *)(GPIOF_BASE+ODR))
#define PORTF_BSRR *((volatile uint32 *)(GPIOF_BASE+BSRR))
#define PORTF_BRR *((volatile uint32 *)(GPIOF_BASE+BRR))
 
	
 /* DefinitionS for PORTG Registers */
#define PORTG_CRH *((volatile uint32 *)(GPIOG_BASE+CRH))
#define PORTG_CRL *((volatile uint32 *)(GPIOG_BASE+CRL))
#define PORTG_IDR *((volatile uint32 *)(GPIOG_BASE+IDR))
#define PORTG_ODR *((volatile uint32 *)(GPIOG_BASE+ODR))
#define PORTG_BSRR *((volatile uint32 *)(GPIOG_BASE+BSRR))
#define PORTG_BRR *((volatile uint32 *)(GPIOG_BASE+BRR))

	
