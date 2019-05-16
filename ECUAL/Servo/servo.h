#ifndef SERVO_H_
#define SERVO_H_

#include "PWM.h"
#include "SysTick.h"

/*
 -------------------------------------------------------PWM PINS----------------------------------------------
	PWMModule0 PWM0 ---> PB6 
	PWMModule0 PWM1 ---> PB7 
	PWMModule0 PWM2 ---> PB4 
	PWMModule0 PWM3 ---> PB5 
	PWMModule0 PWM4 ---> PE4 
	PWMModule0 PWM5 ---> PE5
	PWMModule0 PWM6 ---> PC4
	PWMModule0 PWM7 ---> PC5
	PWMModule1 PWM0 ---> PD0 
	PWMModule1 PWM1 ---> PD1
	PWMModule1 PWM2 ---> PA6
	PWMModule1 PWM3 ---> PA7
	PWMModule1 PWM4 ---> PF0 
	PWMModule1 PWM5 ---> PF1 
	PWMModule1 PWM6 ---> PF2 
	PWMModule1 PWM7 ---> PF3 
	-------------------------------------------------------------------------------------------------------------
*/

#define PWM_CLK 1250000
#define SERVO_FREQENCY 50
#define PWM_PERIOD (PWM_CLK/SERVO_FREQENCY)
#define ANGLE0_DUTYCYCLE 5
#define ANGLE180_DUTYCYCLE 14

/*-------------------------------------------function prototypes------------------------------------------------*/

void Servo_Init(PWMModule module, PWMChannel channel, uint16 initial_angle);

void Servo_SetDegree(PWMModule module, PWMChannel channel, uint16 angle);

#endif /*SERVO_H_*/

