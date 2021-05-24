
#ifndef __MCP_H_
#define __MCP_H_

#include "stm32f10x.h"
#define MCP_CS_PORT									GPIO_PORT_B
#define MCP_CS_PIN									GPIO_Pin_5

#define GPIO_PORT_A 0
#define GPIO_PORT_B 1
#define GPIO_PORT_C 2

#define MCP_RESET 0xC0

#define MCP_READ 0x03

#define MCP_READ_RX_B0SIDH 0x90 	//Address: 0x61
#define MCP_READ_RX_B0D0 0x92			//Address: 0x66
#define MCP_READ_RX_B1SIDH 0x94		//Address: 0x71
#define MCP_READ_RX_B1D0 0x96			//Address: 0x76

#define MCP_WRITE 0x02

#define MCP_LOAD_TX_B0SIDH 0x40			//Address: 0x31
#define MCP_LOAD_TX_B0D0 0x41				//Address: 0x36
#define MCP_LOAD_TX_B1SIDH 0x42			//Address: 0x41
#define MCP_LOAD_TX_B1D0 0x43				//Address: 0x46
#define MCP_LOAD_TX_B2SIDH 0x44			//Address: 0x51
#define MCP_LOAD_TX_B2D0 0x45				//Address: 0x56

#define MCP_RTS_TX_B0 0x81
#define MCP_RTS_TX_B1 0x82
#define MCP_RTS_TX_B2 0x84

#define MCP_READ_STATUS 0xA0

#define MCP_RX_STATUS 0xB0

#define MCP_BIT_MODIFY 0x05

void MCP_Init(void);
void MCP_Config_CFG(void);
void MCP_Config_CTRL(void);
void MCP_SetNormalMode(void);
void MCP_LoadMsg(char ch);
void MCP_RTS0(void);
uint8_t MCP_TX_ReadStatus(void);
uint8_t MCP_ReadReg(uint8_t address);
void MCP_Set_TXRTSCTRL(void);
//void MCP_RX_ReadStatus(void);

#endif
