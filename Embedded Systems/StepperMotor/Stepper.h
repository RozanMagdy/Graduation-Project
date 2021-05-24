#include "GPIO.h"
#include "StepperConf.h"


#define STEPPER_DIR_CLK 0


#define STEPPER_DIR_ANTI_CLK 1



#define STEPPER_STEP_1_DIR_CLK	(1)
#define STEPPER_STEP_2_DIR_CLK	(2)
#define STEPPER_STEP_3_DIR_CLK	(4)
#define STEPPER_STEP_4_DIR_CLK	(8)





#define STEPPER_STEP_1_DIR_ANTI_CLK	(8)
#define STEPPER_STEP_2_DIR_ANTI_CLK	(4)
#define STEPPER_STEP_3_DIR_ANTI_CLK	(2)
#define STEPPER_STEP_4_DIR_ANTI_CLK	(1)






void Stepper_Set_Angle(uint8_t direction , float angle);


void Delay(uint32_t delay);

