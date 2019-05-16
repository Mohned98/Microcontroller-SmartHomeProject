#include "button.h"

void Button_Init( Dio_PortName port_name, uint8 pins_mask, InputMode mode )
{
	DIO_Init(port_name,pins_mask);
	DIO_SetPinDirection(port_name, pins_mask, DIO_PIN_IN);
	if(mode == PULL_DOWN)
		DIO_SetPinPullDown(port_name, pins_mask);
	else
		DIO_SetPinPullUp(port_name, pins_mask);
}

void Button_ActOnHighLevel( Dio_PortName port_name, uint8 pin_Number, void (*pAction)(void) )
{
	if (DIO_ReadPort(port_name, 1<<pin_Number))
	{
		SysTick_delay_ms(30);
		if(DIO_ReadPort(port_name, 1<<pin_Number))
		{
			while(DIO_ReadPort(port_name, 1<<pin_Number))
			{
				pAction();
				SysTick_delay_ms(200);
			}
		}
	}
}

void Button_ActOnLowLevel( Dio_PortName port_name, uint8 pin_Number, void (*pAction)(void) )
{
	if (!DIO_ReadPort(port_name, 1<<pin_Number))
	{
		SysTick_delay_ms(30);
		if(!DIO_ReadPort(port_name, 1<<pin_Number))
		{
			while(!DIO_ReadPort(port_name, 1<<pin_Number))
			{
				pAction();
				SysTick_delay_ms(200);
			}
		}
	}
}