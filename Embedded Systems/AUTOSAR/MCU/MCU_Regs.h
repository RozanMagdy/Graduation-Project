#ifndef Mcu_Regs_h
#define Mcu_Regs_h

#include "Std_types.h"

#define PERIPH_BASE           ((uint32)0x40000000) /*!< Peripheral base address in the alias region */
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define RCC_BASE            	(AHBPERIPH_BASE + 0x1000)

#define CR (0x00)
#define CFGR (0x04)
#define CIR (0x08)
#define AHBENR (0x14)
#define APB2ENR (0x18)
#define APB1ENR (0x1C)
#define CSR (0x24)


#define RCC_CR 								*((volatile uint32 *)(RCC_BASE+CR))
#define RCC_CFGR 							*((volatile uint32 *)(RCC_BASE+CFGR))
#define RCC_CIR 							*((volatile uint32 *)(RCC_BASE+CIR))
#define RCC_AHBENR 						*((volatile uint32 *)(RCC_BASE+AHBENR))
#define RCC_APB2ENR 					*((volatile uint32 *)(RCC_BASE+APB2ENR))
#define RCC_APB1ENR 					*((volatile uint32 *)(RCC_BASE+APB1ENR))
#define RCC_CSR 							*((volatile uint32 *)(RCC_BASE+CSR))
#define APP_INT_AND_RST_CTRL  *((volatile uint32 *)(0xE000ED0C))
//Application Interrupt/Reset Control Register
/*Causes a signal to be asserted to the outer system that indicates a reset is requested.
Intended to force a large system reset of all major components except for debug. Setting
this bit does not prevent Halting Debug from running*/

///////////////////////////////////////////////////////////////////////////////////////////////////

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
	

 /* DefinitionS for PORTC Registers */
#define PORTC_CRH *((volatile uint32 *)(GPIOC_BASE+CRH))
#define PORTC_CRL *((volatile uint32 *)(GPIOC_BASE+CRL))
#define PORTC_IDR *((volatile uint32 *)(GPIOC_BASE+IDR))
#define PORTC_ODR *((volatile uint32 *)(GPIOC_BASE+ODR))
#define PORTC_BSRR *((volatile uint32 *)(GPIOC_BASE+BSRR))
#define PORTC_BRR *((volatile uint32 *)(GPIOC_BASE+BRR))



#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)
#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x2000) /*!< Flash registers base address */
#define FLASH_BASE               	(FLASH_R_BASE)
#define ACR 											(0x00)
#define FLASH_ACR									*((volatile uint32 *)FLASH_BASE+ACR)
#define FLASH_ACR_LATENCY                   ((uint8)0x03)               /*!< LATENCY[2:0] bits (Latency) */
#define FLASH_ACR_LATENCY_2                 ((uint8)0x02)               /*!< Bit 1 */
#define FLASH_ACR_PRFTBE                    ((uint8)0x10)               /*!< Prefetch Buffer Enable */

#define SCS_BASE            	(0xE000E000UL)                            /*!< System Control Space Base Address */
#define SCB_BASE            	(SCS_BASE +  0x0D00UL)                    /*!< System Control Block Base Address */
#define VTOR									(0x08)
#define SCB_VTOR 							*((volatile uint32 *)(SCB_BASE+VTOR))

#endif
