#include "servo.h"

void Servo_Init(PWMModule module, PWMChannel channel, uint16 initial_angle)
{
	/*
		5%  duty_cycle ----> 0 degree
		10% duty_cycle ----> 180 degree
	*/
	PWM_Init(module, channel, PWM_PERIOD, (initial_angle*ANGLE180_DUTYCYCLE)/180);
	SysTick_delay_ms(50);
}

void Servo_SetDegree(PWMModule module, PWMChannel channel, uint16 angle)
{
	
	PWM_SetDuty(module, channel, (angle*ANGLE180_DUTYCYCLE)/180);
	SysTick_delay_ms(50);
	
}