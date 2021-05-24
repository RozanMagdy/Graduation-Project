
#include "../Can/Can.h"
#include "../DC_Motor/DC_Motor.h"
#include "../Stepper/Stepper.h"





#define Motion_App_Motors_Can_Id			(0x123)
#define Motion_App_Motors_Can_Mask_Id		(0x00)






void Motion_App_Init(void);


void Motion_App_Can_Fifo_0_Receive_Interrupt(void);


