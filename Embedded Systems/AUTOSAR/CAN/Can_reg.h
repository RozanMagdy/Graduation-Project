#ifndef __CAN_REG_H__
#define __CAN_REG_H__

#include "Platform_Types.h"


/* comment this line if you don't want to use RCC Registers */
#define CAN_RCC_DEFINE

/* comment this line if you don't want to use GPIO Registers */
#define CAN_GPIO_DEFINE




typedef struct
{
volatile uint32 TIR;
volatile uint32 TDTR;
volatile uint32 TDLR;
volatile uint32 TDHR;
} CAN_TxMailBox_TypeDef;


typedef struct
{
volatile uint32 RIR;
volatile uint32 RDTR;
volatile uint32 RDLR;
volatile uint32 RDHR;
} CAN_FIFOMailBox_TypeDef;



typedef struct
{
volatile uint32 FR0;
volatile uint32 FR1;
} CAN_FilterRegister_TypeDef;


typedef struct
{
volatile uint32 MCR;
volatile uint32 MSR;
volatile uint32 TSR;
volatile uint32 RF0R;
volatile uint32 RF1R;
volatile uint32 IER;
volatile uint32 ESR;
volatile uint32 BTR;
volatile uint32 RESERVED0[88];
CAN_TxMailBox_TypeDef sTxMailBox[3];
CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
volatile uint32 RESERVED1[12];
volatile uint32 FMR;
volatile uint32 FM1R;
volatile uint32 RESERVED2[1];
volatile uint32 FS1R;
volatile uint32 RESERVED3[1];
volatile uint32 FFA1R;
volatile uint32 RESERVED4[1];
volatile uint32 FA1R;
volatile uint32 RESERVED5[8];
CAN_FilterRegister_TypeDef sFilterRegister[14];
} CAN_TypeDef;


#ifdef CAN_GPIO_DEFINE
typedef struct
{
  volatile uint32 CRL;
  volatile uint32 CRH;
  volatile uint32 IDR;
  volatile uint32 ODR;
  volatile uint32 BSRR;
  volatile uint32 BRR;
  volatile uint32 LCKR;
} GPIO_TypeDef;
#endif


#ifdef CAN_RCC_DEFINE
typedef struct
{
  volatile uint32 CR;
  volatile uint32 CFGR;
  volatile uint32 CIR;
  volatile uint32 APB2RSTR;
  volatile uint32 APB1RSTR;
  volatile uint32 AHBENR;
  volatile uint32 APB2ENR;
  volatile uint32 APB1ENR;
  volatile uint32 BDCR;
  volatile uint32 CSR;

} RCC_TypeDef;
#endif


#define PERIPH_BASE					 ((uint32)0x40000000)
#define APB1PERIPH_BASE					 (PERIPH_BASE)
#define APB2PERIPH_BASE 		((uint32)(PERIPH_BASE + 0x10000))
#define AHBPERIPH_BASE 			((uint32)(PERIPH_BASE + 0x20000))


#ifdef CAN_RCC_DEFINE
/******************  RCC BASE ADDRESS *****************/
#define RCC_BASE               ((uint32)(AHBPERIPH_BASE + 0x1000))
#define RCC                    ((RCC_TypeDef*) RCC_BASE)

/********************  Bit definition for RCC_CR register  ********************/
#define  RCC_CR_HSION                        ((uint32)0x00000001)        /*!< Internal High Speed clock enable */

/******************  Bit definition for RCC_APB2ENR register  *****************/
#define  RCC_APB2ENR_AFIOEN                  ((uint32)0x00000001)         /*!< Alternate Function I/O clock enable */
#define  RCC_APB2ENR_IOPAEN                  ((uint32)0x00000004)         /*!< I/O port A clock enable */

/*****************  Bit definition for RCC_APB1ENR register  ******************/
#define  RCC_APB1ENR_CAN1EN                  ((uint32)0x02000000)        /*!< CAN1 clock enable */


#endif

#ifdef CAN_GPIO_DEFINE
/******************  GPIOA BASE ADDRESS *****************/
#define GPIOA_BASE            ((uint32)(APB2PERIPH_BASE + 0x0800))
#define GPIOA                 ((GPIO_TypeDef *) GPIOA_BASE)


/*******************  Bit definition for GPIO_CRH register  *******************/

#define  GPIO_CRH_MODE11                     ((uint32)0x00003000)        /*!< MODE11[1:0] bits (Port x mode bits, pin 11) */
#define  GPIO_CRH_MODE11_0                   ((uint32)0x00001000)        /*!< Bit 0 */
#define  GPIO_CRH_MODE11_1                   ((uint32)0x00002000)        /*!< Bit 1 */

#define  GPIO_CRH_CNF11                      ((uint32)0x0000C000)        /*!< CNF11[1:0] bits (Port x configuration bits, pin 11) */
#define  GPIO_CRH_CNF11_0                    ((uint32)0x00004000)        /*!< Bit 0 */
#define  GPIO_CRH_CNF11_1                    ((uint32)0x00008000)        /*!< Bit 1 */


#define  GPIO_CRH_MODE12                     ((uint32)0x00030000)        /*!< MODE12[1:0] bits (Port x mode bits, pin 12) */
#define  GPIO_CRH_MODE12_0                   ((uint32)0x00010000)        /*!< Bit 0 */
#define  GPIO_CRH_MODE12_1                   ((uint32)0x00020000)        /*!< Bit 1 */


#define  GPIO_CRH_CNF12                      ((uint32)0x000C0000)        /*!< CNF12[1:0] bits (Port x configuration bits, pin 12) */
#define  GPIO_CRH_CNF12_0                    ((uint32)0x00040000)        /*!< Bit 0 */
#define  GPIO_CRH_CNF12_1                    ((uint32)0x00080000)        /*!< Bit 1 */



#endif
/******************  CAN BASE ADDRESS *****************/

#define CAN1_BASE      (APB1PERIPH_BASE + 0x6400)
#define CAN1           ((CAN_TypeDef *) CAN1_BASE)


/******************  CAN REGISTERS MACROS *****************/

#define CAN1_MCR			*((volatile uint32*)CAN1_BASE)
#define CAN1_MSR			(CAN1->MSR)
#define CAN1_TSR			(CAN1->TSR)
#define CAN1_RF0R			(CAN1->RF0R)
#define CAN1_RF1R			(CAN1->RF1R)
#define CAN1_IER			(CAN1->IER)
#define CAN1_ESR			(CAN1->ESR)	
#define CAN1_BTR			(CAN1->BTR)
#define CAN1_FMR			(CAN1->FMR)
#define CAN1_FM1R			(CAN1->FM1R)
#define CAN1_FS1R			(CAN1->FS1R)
#define CAN1_FFA1R		(CAN1->FFA1R)
#define CAN1_FA1R			(CAN1->FA1R)


#define CAN1_TI0R			(CAN1->sTxMailBox[0].TIR)
#define CAN1_TDT0R		(CAN1->sTxMailBox[0].TDTR)	
#define CAN1_TDL0R		(CAN1->sTxMailBox[0].TDLR)	
#define CAN1_TDH0R		(CAN1->sTxMailBox[0].TDHR)


#define CAN1_TI1R			(CAN1->sTxMailBox[1].TIR)
#define CAN1_TDT1R		(CAN1->sTxMailBox[1].TDTR)	
#define CAN1_TDL1R		(CAN1->sTxMailBox[1].TDLR)	
#define CAN1_TDH1R		(CAN1->sTxMailBox[1].TDHR)

#define CAN1_TI2R			(CAN1->sTxMailBox[2].TIR)
#define CAN1_TDT2R		(CAN1->sTxMailBox[2].TDTR)	
#define CAN1_TDL2R		(CAN1->sTxMailBox[2].TDLR)	
#define CAN1_TDH2R		(CAN1->sTxMailBox[2].TDHR)


#define CAN1_RI0R			(CAN1->sFIFOMailBox[0].RIR)
#define CAN1_RDT0R		(CAN1->sFIFOMailBox[0].RDTR)	
#define CAN1_RDL0R		(CAN1->sFIFOMailBox[0].RDLR)	
#define CAN1_RDH0R		(CAN1->sFIFOMailBox[0].RDHR)


#define CAN1_RI1R			(CAN1->sFIFOMailBox[1].RIR)
#define CAN1_RDT1R		(CAN1->sFIFOMailBox[1].RDTR)	
#define CAN1_RDL1R		(CAN1->sFIFOMailBox[1].RDLR)	
#define CAN1_RDH1R		(CAN1->sFIFOMailBox[1].RDHR)


#define CAN1_F0R1			(CAN1->sFilterRegister[0].FR0)
#define CAN1_F0R2			(CAN1->sFilterRegister[0].FR1)
#define CAN1_F1R1			(CAN1->sFilterRegister[1].FR0)
#define CAN1_F1R2			(CAN1->sFilterRegister[1].FR1)
#define CAN1_F2R1			(CAN1->sFilterRegister[2].FR0)
#define CAN1_F2R2			(CAN1->sFilterRegister[2].FR1)
#define CAN1_F3R1			(CAN1->sFilterRegister[3].FR0)
#define CAN1_F3R2			(CAN1->sFilterRegister[3].FR1)


#define CAN1_F4R1			(CAN1->sFilterRegister[4].FR0)
#define CAN1_F4R2			(CAN1->sFilterRegister[4].FR1)
#define CAN1_F5R1			(CAN1->sFilterRegister[5].FR0)
#define CAN1_F5R2			(CAN1->sFilterRegister[5].FR1)
#define CAN1_F6R1			(CAN1->sFilterRegister[6].FR0)
#define CAN1_F6R2			(CAN1->sFilterRegister[6].FR1)
#define CAN1_F7R1			(CAN1->sFilterRegister[7].FR0)
#define CAN1_F7R2			(CAN1->sFilterRegister[7].FR1)


#define CAN1_F8R1			(CAN1->sFilterRegister[8].FR0)
#define CAN1_F8R2			(CAN1->sFilterRegister[8].FR1)
#define CAN1_F9R1			(CAN1->sFilterRegister[9].FR0)
#define CAN1_F9R2			(CAN1->sFilterRegister[9].FR1)
#define CAN1_F10R1		(CAN1->sFilterRegister[10].FR0)
#define CAN1_F10R2		(CAN1->sFilterRegister[10].FR1)
#define CAN1_F11R1		(CAN1->sFilterRegister[11].FR0)
#define CAN1_F11R2		(CAN1->sFilterRegister[11].FR1)


#define CAN1_F12R1		(CAN1->sFilterRegister[12].FR0)
#define CAN1_F12R2		(CAN1->sFilterRegister[12].FR1)
#define CAN1_F13R1		(CAN1->sFilterRegister[13].FR0)
#define CAN1_F13R2		(CAN1->sFilterRegister[13].FR1)


/*!< CAN control and status registers */
/*******************  Bit definition for CAN_MCR register  ********************/
#define  CAN_MCR_INRQ                        ((uint16)0x0001)            /*!< Initialization Request */
#define  CAN_MCR_SLEEP                       ((uint16)0x0002)            /*!< Sleep Mode Request */
#define  CAN_MCR_TXFP                        ((uint16)0x0004)            /*!< Transmit FIFO Priority */
#define  CAN_MCR_RFLM                        ((uint16)0x0008)            /*!< Receive FIFO Locked Mode */
#define  CAN_MCR_NART                        ((uint16)0x0010)            /*!< No Automatic Retransmission */
#define  CAN_MCR_AWUM                        ((uint16)0x0020)            /*!< Automatic Wakeup Mode */
#define  CAN_MCR_ABOM                        ((uint16)0x0040)            /*!< Automatic Bus-Off Management */
#define  CAN_MCR_TTCM                        ((uint16)0x0080)            /*!< Time Triggered Communication Mode */

/*******************  Bit definition for CAN_MSR register  ********************/
#define  CAN_MSR_INAK                        ((uint16)0x0001)            /*!< Initialization Acknowledge */
#define  CAN_MSR_SLAK                        ((uint16)0x0002)            /*!< Sleep Acknowledge */
#define  CAN_MSR_WKUI                        ((uint16)0x0008)            /*!< Wakeup Interrupt */
#define  CAN_MSR_SLAKI                       ((uint16)0x0010)            /*!< Sleep Acknowledge Interrupt */
#define  CAN_MSR_TXM                         ((uint16)0x0100)            /*!< Transmit Mode */
#define  CAN_MSR_RXM                         ((uint16)0x0200)            /*!< Receive Mode */
#define  CAN_MSR_RX                          ((uint16)0x0800)            /*!< CAN Rx Signal */

/*******************  Bit definition for CAN_TSR register  ********************/
#define  CAN_TSR_RQCP0                       ((uint32)0x00000001)        /*!< Request Completed Mailbox0 */
#define  CAN_TSR_TXOK0                       ((uint32)0x00000002)        /*!< Transmission OK of Mailbox0 */
#define  CAN_TSR_ALST0                       ((uint32)0x00000004)        /*!< Arbitration Lost for Mailbox0 */
#define  CAN_TSR_TERR0                       ((uint32)0x00000008)        /*!< Transmission Error of Mailbox0 */
#define  CAN_TSR_ABRQ0                       ((uint32)0x00000080)        /*!< Abort Request for Mailbox0 */
#define  CAN_TSR_RQCP1                       ((uint32)0x00000100)        /*!< Request Completed Mailbox1 */
#define  CAN_TSR_TXOK1                       ((uint32)0x00000200)        /*!< Transmission OK of Mailbox1 */
#define  CAN_TSR_ALST1                       ((uint32)0x00000400)        /*!< Arbitration Lost for Mailbox1 */
#define  CAN_TSR_TERR1                       ((uint32)0x00000800)        /*!< Transmission Error of Mailbox1 */
#define  CAN_TSR_ABRQ1                       ((uint32)0x00008000)        /*!< Abort Request for Mailbox 1 */
#define  CAN_TSR_RQCP2                       ((uint32)0x00010000)        /*!< Request Completed Mailbox2 */
#define  CAN_TSR_TXOK2                       ((uint32)0x00020000)        /*!< Transmission OK of Mailbox 2 */
#define  CAN_TSR_ALST2                       ((uint32)0x00040000)        /*!< Arbitration Lost for mailbox 2 */
#define  CAN_TSR_TERR2                       ((uint32)0x00080000)        /*!< Transmission Error of Mailbox 2 */
#define  CAN_TSR_ABRQ2                       ((uint32)0x00800000)        /*!< Abort Request for Mailbox 2 */
#define  CAN_TSR_CODE                        ((uint32)0x03000000)        /*!< Mailbox Code */

#define  CAN_TSR_TME                         ((uint32)0x1C000000)        /*!< TME[2:0] bits */
#define  CAN_TSR_TME0                        ((uint32)0x04000000)        /*!< Transmit Mailbox 0 Empty */
#define  CAN_TSR_TME1                        ((uint32)0x08000000)        /*!< Transmit Mailbox 1 Empty */
#define  CAN_TSR_TME2                        ((uint32)0x10000000)        /*!< Transmit Mailbox 2 Empty */


/*******************  Bit definition for CAN_RFxR register  *******************/
#define  CAN_RFR_FMP                       ((uint8)0x03)               /*!< FIFO Message Pending */
#define  CAN_RFR_FULL                      ((uint8)0x08)               /*!< FIFO Full */
#define  CAN_RFR_FOVR                      ((uint8)0x10)               /*!< FIFO Overrun */
#define  CAN_RFR_RFOM                      ((uint8)0x20)               /*!< Release FIFO Output Mailbox */

/********************  Bit definition for CAN_IER register  *******************/
#define  CAN_IER_TMEIE                       ((uint32)0x00000001)        /*!< Transmit Mailbox Empty Interrupt Enable */
#define  CAN_IER_FMPIE0                      ((uint32)0x00000002)        /*!< FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE0                       ((uint32)0x00000004)        /*!< FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE0                      ((uint32)0x00000008)        /*!< FIFO Overrun Interrupt Enable */
#define  CAN_IER_FMPIE1                      ((uint32)0x00000010)        /*!< FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE1                       ((uint32)0x00000020)        /*!< FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE1                      ((uint32)0x00000040)        /*!< FIFO Overrun Interrupt Enable */
#define  CAN_IER_EWGIE                       ((uint32)0x00000100)        /*!< Error Warning Interrupt Enable */
#define  CAN_IER_EPVIE                       ((uint32)0x00000200)        /*!< Error Passive Interrupt Enable */
#define  CAN_IER_BOFIE                       ((uint32)0x00000400)        /*!< Bus-Off Interrupt Enable */
#define  CAN_IER_LECIE                       ((uint32)0x00000800)        /*!< Last Error Code Interrupt Enable */
#define  CAN_IER_ERRIE                       ((uint32)0x00008000)        /*!< Error Interrupt Enable */
#define  CAN_IER_WKUIE                       ((uint32)0x00010000)        /*!< Wakeup Interrupt Enable */
#define  CAN_IER_SLKIE                       ((uint32)0x00020000)        /*!< Sleep Interrupt Enable */

/*******************  Bit definition for CAN_BTR register  ********************/
#define  CAN_BTR_BRP                         ((uint32)0x000003FF)        /*!< Baud Rate Prescaler */
#define  CAN_BTR_TS1                         ((uint32)0x000F0000)        /*!< Time Segment 1 */
#define  CAN_BTR_TS2                         ((uint32)0x00700000)        /*!< Time Segment 2 */
#define  CAN_BTR_SJW                         ((uint32)0x03000000)        /*!< Resynchronization Jump Width */
#define  CAN_BTR_LBKM                        ((uint32)0x40000000)        /*!< Loop Back Mode (Debug) */
#define  CAN_BTR_SILM                        ((uint32)0x80000000)        /*!< Silent Mode */

/*!< CAN mailbox registers */
/*******************  Bit definition for CAN_TIxR register  *******************/
#define  CAN_TIR_TXRQ                       ((uint32)0x00000001)        /*!< Transmit Mailbox Request */
#define  CAN_TIR_RTR                        ((uint32)0x00000002)        /*!< Remote Transmission Request */
#define  CAN_TIR_IDE                        ((uint32)0x00000004)        /*!< Identifier Extension */
#define  CAN_TIR_STID                       ((uint32)0xFFE00000)        /*!< Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDTxR register  ******************/
#define  CAN_TDTR_DLC                       ((uint32)0x0000000F)        /*!< Data Length Code */

/*******************  Bit definition for CAN_RIxR register  *******************/
#define  CAN_RIR_RTR                        ((uint32)0x00000002)        /*!< Remote Transmission Request */
#define  CAN_RIR_IDE                        ((uint32)0x00000004)        /*!< Identifier Extension */
#define  CAN_RIR_EXID                       ((uint32)0x001FFFF8)        /*!< Extended Identifier */
#define  CAN_RIR_STID                       ((uint32)0xFFE00000)        /*!< Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDTxR register  ******************/
#define  CAN_RDTR_DLC                       ((uint32)0x0000000F)        /*!< Data Length Code */
#define  CAN_RDTR_FMI                       ((uint32)0x0000FF00)        /*!< Filter Match Index */


/*!< CAN filter registers */
/*******************  Bit definition for CAN_FMR register  ********************/
#define  CAN_FMR_FINIT                       ((uint8)0x01)               /*!< Filter Init Mode */


/*********************************************************************************************************/

#endif
