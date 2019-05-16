#ifndef BUTTON_H_
#define BUTTON_H_

#include "DIO.h"
#include "SysTick.h"

typedef enum
{
	PULL_DOWN,
	PULL_UP
}InputMode;

void Button_Init( Dio_PortName port_name, uint8 pins_mask, InputMode mode );
void Button_ActOnPressing( Dio_PortName port_name, uint8 pin_Number, void (*pAction)(void) );
void Button_ActOnReleasing( Dio_PortName port_name, uint8 pin_Number, void (*pAction)(void) );	
void Button_ActOnHighLevel( Dio_PortName port_name, uint8 pin_Number, void (*pAction)(void) );
void Button_ActOnLowLevel( Dio_PortName port_name, uint8 pin_Number, void (*pAction)(void) );


#endif /*BUTTON_H_*/