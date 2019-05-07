#ifndef BUTTON_H_
#define BUTTON_H_

#include "port.h"
#include "DIO.h"
#include "SysTick.h"

typedef enum
{
	PULL_DOWN,
	PULL_UP
}InputMode;

void Button_Init( uint8 port_index, uint8 pins_mask, InputMode mode );
void Button_ActOnRisingEdge( uint8 port_index, uint8 pin_Number, void (*pAction)(void) );
void Button_ActOnFallingEdge( uint8 port_index, uint8 pin_Number, void (*pAction)(void) );	
void Button_ActOnHighLevel( uint8 port_index, uint8 pin_Number, void (*pAction)(void) );
void Button_ActOnLowLevel( uint8 port_index, uint8 pin_Number, void (*pAction)(void) );


#endif /*BUTTON_H_*/