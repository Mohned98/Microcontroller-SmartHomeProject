#include "button.h"

void Button_ActOnPressing( Dio_PortName port_name, uint8 pin_Number, void (*pAction)(void))
{
	if(!DIO_ReadPort(port_name,1<<pin_Number))
	{
		SysTick_delay_ms(50);
		if(!DIO_ReadPort(port_name,1<<pin_Number))
		{
			pAction();
			while(!DIO_ReadPort(port_name,1<<pin_Number))
			{}
		}
	}
	
}

void Button_ActOnReleasing( Dio_PortName port_name, uint8 pin_Number, void (*pAction)(void))
{
	if(!DIO_ReadPort(port_name,1<<pin_Number))
	{
		SysTick_delay_ms(50);
		if(!DIO_ReadPort(port_name,1<<pin_Number))
		{
			while(!DIO_ReadPort(port_name,1<<pin_Number))
			{}
			pAction();
		}
	}
	
	
}