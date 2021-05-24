#include "stm32f10x.h"                  // Device header
#include "Motion_app_conf.h"


#define	Default_Command_Id		(0x000)


typedef struct 
{
	
	uint16_t 	Command_Id;
	uint8_t 	Command_Type;

}Motion_Command_Type;


typedef struct 
{
	
	Motion_Command_Type  Motion_Command[Number_Of_Commands];
	
}Motion_Commands_Type;




extern const Motion_Commands_Type 	Motion_App_Configrations;
void Motor_Speed(uint8_t 	Command_Type , uint8_t	Data);
