#include "SPI.h"
#include "GPIO.h"
#include "MCP.h"

void RCC_Init(void);

int main(void)
{
	
	RCC_Init();
	SystemCoreClockUpdate();
	
	GPIO_voidInit();
	SysTick_voidInit();
	SPI_voidInit();
	
	uint32_t i  = 0;
	
	MCP_Init();	
	
	for(i = 0; i < 10; i++);
	MCP_Config_CTRL();
	for(i = 0; i < 10; i++);
	MCP_Config_CFG();
	for(i = 0; i < 10; i++);
	MCP_Set_TXRTSCTRL();
	for(i = 0; i < 10; i++);
	MCP_SetNormalMode();
	
	for(i = 0; i < 1000000; i++);
	
	char x = 0;
	char ch = 'a';
	
	while(1)
	{
		MCP_LoadMsg(ch++);
		for(i = 0; i < 10; i++);
		
		MCP_RTS0();
		for(i = 0; i < 10; i++);
		
		//MCP_ReadReg(0x0F);
		if(ch == 'g') ch = 'a';
		
		GPIO_WriteBit(GPIOC,GPIO_Pin_13,x);
		x^=1;
		Delay(500);
		
	}
}


void RCC_Init(void){
	RCC_HCLKConfig(RCC_SYSCLK_Div1);
	RCC_PCLK1Config(RCC_HCLK_Div1); //For bxCAN, SPI2, ...
	RCC_PCLK2Config(RCC_HCLK_Div1); //For GPIO, SPI, ...
	//NOW, It should be 8MHz
	
	RCC_HSEConfig(RCC_HSE_ON);
	while(RCC_WaitForHSEStartUp() == ERROR);
	
	RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE);
}

