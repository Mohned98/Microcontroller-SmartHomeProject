

#include "Stepper_Motor.h"


void StepperMotor_Init(Dio_PortName port_name,uint8 pins_mask){
	
	DIO_Init(  port_name, pins_mask );
	DIO_SetPinDirection(  port_name,  pins_mask, DIO_PIN_OUT );
	
}

void StepperMotor_Stop(Dio_PortName port_name, uint8 pins_mask){
	
	void DIO_WritePort( port_name,  pins_mask, STD_LOW);
	
}
