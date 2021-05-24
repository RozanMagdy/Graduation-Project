#include "SPI.h"
#include "MCP.h"

GPIO_TypeDef* CS_PORT;

void MCP_Init(void){
	volatile int i = 0;
	switch(MCP_CS_PORT){
		case GPIO_PORT_A:
			CS_PORT = GPIOA;
			break;
		case GPIO_PORT_B:
			CS_PORT = GPIOB;
			break;
		case GPIO_PORT_C:
			CS_PORT = GPIOC;
			break;
	}
	
	GPIO_ResetBits(CS_PORT, MCP_CS_PIN); // slave select (low)
	SPI_voidSendData(SPI_2,MCP_RESET);
	for(i = 0; i < 80; i++);
	GPIO_SetBits(CS_PORT, MCP_CS_PIN); // slave select (low)
}

void MCP_Config_CFG(void){
	volatile int i = 0;
	//Configuration Mode is entered by defalt after Reset
	GPIO_ResetBits(CS_PORT, MCP_CS_PIN); 	// slave select (low)
	SPI_voidSendData(SPI_2,MCP_WRITE);
	SPI_voidSendData(SPI_2,0x28);
	//CFG3
	SPI_voidSendData(SPI_2,0x81); 						//SOF , PS2 = 2T
	// CFG2
	SPI_voidSendData(SPI_2,0x91); 						//PS2 , ONE_SAMPLE , PS1 = 6 , PROPAGATION = 7
	// CFG1
	SPI_voidSendData(SPI_2,0x00); 						//BRP = 2 , SJW = 1T	
	for(i = 0; i < 80; i++);
	GPIO_SetBits(CS_PORT, MCP_CS_PIN); // slave select (low)
}

void MCP_Config_CTRL(void){
	volatile int i = 0;
	//Configuration Mode is entered by defalt after Reset
	GPIO_ResetBits(CS_PORT, MCP_CS_PIN); 	// slave select (low)
	SPI_voidSendData(SPI_2,MCP_WRITE);
	SPI_voidSendData(SPI_2,0x0F);
	SPI_voidSendData(SPI_2,0x8C); 						//Config_Mode , ABORT , ONE_SHOT , EN_CLKOUT , F_CLKOUT = CLK/1
	for(i = 0; i < 80; i++);
	GPIO_SetBits(CS_PORT, MCP_CS_PIN); // slave select (low)
}

void MCP_Set_TXRTSCTRL(void){
	volatile int i = 0;
	GPIO_ResetBits(CS_PORT, MCP_CS_PIN); 	// slave select (low)
	SPI_voidSendData(SPI_2,MCP_WRITE);
	SPI_voidSendData(SPI_2,0x0D);
	SPI_voidSendData(SPI_2,0x01); 						
	for(i = 0; i < 80; i++);
	GPIO_SetBits(CS_PORT, MCP_CS_PIN); // slave select (low)
}

void MCP_SetNormalMode(void){
	volatile int i = 0;
	GPIO_ResetBits(CS_PORT, MCP_CS_PIN); 	// slave select (low)
	SPI_voidSendData(SPI_2,MCP_WRITE);
	SPI_voidSendData(SPI_2,0x0F);
	SPI_voidSendData(SPI_2,0x0C); 						//Normal_Mode , ABORT , ONE_SHOT , EN_CLKOUT , F_CLKOUT = CLK/1
	for(i = 0; i < 80; i++);
	GPIO_SetBits(CS_PORT, MCP_CS_PIN); // slave select (low)
}

void MCP_LoadMsg(char ch){
	volatile int i = 0;
	GPIO_ResetBits(CS_PORT, MCP_CS_PIN); 	// slave select (low)
	SPI_voidSendData(SPI_2,MCP_LOAD_TX_B0SIDH);
	//0x31
	SPI_voidSendData(SPI_2,(uint8_t)(0x123 >> 3));			//Standard ID 
	SPI_voidSendData(SPI_2,(uint8_t)(0x123 << 5));			//Standard ID , IDE = 0
	SPI_voidSendData(SPI_2,0x00);											//Extended ID
	SPI_voidSendData(SPI_2,0x00);											//Extended ID
	//0x35
	SPI_voidSendData(SPI_2,0x01);											//RTR = 0 , DLC = 1
	SPI_voidSendData(SPI_2,ch);												//Data
	for(i = 0; i < 80; i++);
	GPIO_SetBits(CS_PORT, MCP_CS_PIN); // slave select (low)		
}

void MCP_RTS0(void){
	volatile int i = 0;
	GPIO_ResetBits(CS_PORT, MCP_CS_PIN); 	// slave select (low)
	SPI_voidSendData(SPI_2,MCP_RTS_TX_B0);
	for(i = 0; i < 80; i++);
	GPIO_SetBits(CS_PORT, MCP_CS_PIN); // slave select (low)		
}

uint8_t MCP_TX_ReadStatus(void){
	volatile int i = 0;
	uint8_t data = 0;
	GPIO_ResetBits(CS_PORT, MCP_CS_PIN); 	// slave select (low)
	data = SPI_Send_Byte(SPI_2, MCP_READ_STATUS);
	for(i = 0; i < 80; i++);
	GPIO_SetBits(CS_PORT, MCP_CS_PIN); // slave select (high)		
	return ( (data & (1<<2)) >> 2);
	
}

uint8_t MCP_ReadReg(uint8_t address){
	volatile int i = 0;
	uint8_t data = 0;
	GPIO_ResetBits(CS_PORT, MCP_CS_PIN); 	// slave select (low)
	SPI_voidSendData(SPI_2,MCP_READ);
	data = SPI_Send_Byte(SPI_2, address);
	data = SPI_Send_Byte(SPI_2, 0);				//Revise this
	for(i = 0; i < 80; i++);
	GPIO_SetBits(CS_PORT, MCP_CS_PIN); 		// slave select (high)		
	return data;
}

