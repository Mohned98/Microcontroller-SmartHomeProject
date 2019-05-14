#include "Stepper_Motor.h"
#include "Systick.h"
void StepperMotor_ClkWise(float32 cycle)
{
	uint8 i=0;
	uint16 count=0;
	for (i=0; count<(1500*cycle); i++)
	{
		if(i==0)
		{
			DIO_WritePort(STEPPER_PORT,1<<STEPPER_BLUE, STD_HIGH);
			DIO_WritePort(STEPPER_PORT,(1<<STEPPER_PINK)|(1<<STEPPER_ORANGE)|(1<<STEPPER_YELLOW), STD_LOW);
		}
		else if(i==1)
		{
			DIO_WritePort(STEPPER_PORT,1<<STEPPER_PINK, STD_HIGH);
			DIO_WritePort(STEPPER_PORT,(1<<STEPPER_BLUE)|(1<<STEPPER_ORANGE)|(1<<STEPPER_YELLOW), STD_LOW);
		}
		else if(i==2)
		{
			DIO_WritePort(STEPPER_PORT,1<<STEPPER_ORANGE, STD_HIGH);
			DIO_WritePort(STEPPER_PORT,(1<<STEPPER_PINK)|(1<<STEPPER_BLUE)|(1<<STEPPER_YELLOW), STD_LOW);
		}
		else if(i==3)
		{
			DIO_WritePort(STEPPER_PORT,1<<STEPPER_YELLOW, STD_HIGH);
			DIO_WritePort(STEPPER_PORT,(1<<STEPPER_PINK)|(1<<STEPPER_ORANGE)|(1<<STEPPER_BLUE), STD_LOW);
			i=0;
		}
		count++; 
		SysTick_delay_ms(5);
	}
}



void StepperMotor_AntiClkWise(float32 cycle)
{
	uint8 i=0;
	uint16 count=0;
	for (i=0; count<(1500*cycle); i++)
	{
		if(i==0)
		{
			DIO_WritePort(STEPPER_PORT,1<<STEPPER_YELLOW, STD_HIGH);
			DIO_WritePort(STEPPER_PORT,(1<<STEPPER_PINK)|(1<<STEPPER_ORANGE)|(1<<STEPPER_BLUE), STD_LOW);
		}
		else if(i==1)
		{
			DIO_WritePort(STEPPER_PORT,1<<STEPPER_ORANGE, STD_HIGH);
			DIO_WritePort(STEPPER_PORT,(1<<STEPPER_BLUE)|(1<<STEPPER_PINK)|(1<<STEPPER_YELLOW), STD_LOW);
		}
		else if(i==2)
		{
			DIO_WritePort(STEPPER_PORT,1<<STEPPER_PINK, STD_HIGH);
			DIO_WritePort(STEPPER_PORT,(1<<STEPPER_ORANGE)|(1<<STEPPER_BLUE)|(1<<STEPPER_YELLOW), STD_LOW);
		}
		else if(i==3)
		{
			DIO_WritePort(STEPPER_PORT,1<<STEPPER_BLUE, STD_HIGH);
			DIO_WritePort(STEPPER_PORT,(1<<STEPPER_PINK)|(1<<STEPPER_ORANGE)|(1<<STEPPER_YELLOW), STD_LOW);
			i=0;
		}
		count++; 
		SysTick_delay_ms(20);
	}
}
