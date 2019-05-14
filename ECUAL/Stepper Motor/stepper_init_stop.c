#include "Stepper_Motor.h"


void StepperMotor_Init()
{
	DIO_Init(STEPPER_PORT, STEPPER_MASK);
	DIO_SetPinDirection( STEPPER_PORT, STEPPER_MASK, DIO_PIN_OUT );
	DIO_WritePort(STEPPER_PORT,1<<STEPPER_RED, STD_HIGH);
}

void StepperMotor_Stop()
{
	 DIO_WritePort(STEPPER_PORT, STEPPER_MASK, STD_LOW);
}
