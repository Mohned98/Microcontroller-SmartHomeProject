#include "Stepper_Motor.h"
#include "Systick.h"
void StepperMotor_ClkWise(Dio_PortName port_name, uint8 pins_mask,float32 cycle)
{
	uint8 i=0;
for (float32 j=0; j<cycle; j++)
{
	DIO_WritePort( port_name,  pins_mask, 1<<i);
	 i++;             
  SysTick_delay_ms(100); 
  if (i==4)
      i=0;
}
}



void StepperMotor_AntiClkWise(Dio_PortName port_name, uint8 pins_mask,float32 cycle)
{
	uint8 i=0;
for (float32 j=0; j<cycle; j++)
{
	DIO_WritePort( port_name,  pins_mask, 8>>i);
	 i++;             
  SysTick_delay_ms(100); 
  if (i==4)
      i=0;
}
}