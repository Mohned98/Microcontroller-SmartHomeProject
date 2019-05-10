#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#include "DIO.h"

typedef enum
	{
		Stepper_Blue,
		Stepper_Pink,
		Stepper_Red,
		Stepper_Orange,
		Stepper_Yellow
	}Stepper_Pin_Color;
	

void StepperMotor_Init(Dio_PortName port_name,uint8 pins_mask);
void StepperMotor_ClkWise(float32 cycle);
void StepperMotor_AntiClkWise(float32 cycle);
void StepperMotor_Stop(Dio_PortName port_name, uint8 pins_mask);
#endif /* STEPPER_MOTOR_H_ */
