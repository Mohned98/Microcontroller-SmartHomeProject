#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#include "DIO.h"
#include "Systick.h"

#define STEPPER_PORT PORTA
#define STEPPER_BLUE 0
#define STEPPER_PINK 1
#define STEPPER_RED 2
#define STEPPER_ORANGE 3
#define STEPPER_YELLOW 4
#define STEPPER_MASK ((1<<STEPPER_BLUE)|(1<<STEPPER_PINK)|(1<<STEPPER_RED)|(1<<STEPPER_ORANGE)|(1<<STEPPER_YELLOW))

void StepperMotor_Init();
void StepperMotor_ClkWise(float32 cycle);
void StepperMotor_AntiClkWise(float32 cycle);
void StepperMotor_Stop();
#endif /* STEPPER_MOTOR_H_ */
