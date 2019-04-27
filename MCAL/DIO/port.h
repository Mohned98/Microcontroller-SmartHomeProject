#ifndef PORT_H_
#define PORT_H_

#include "MACROS.h"
#include "STANDARD_TYPES.h"
#include "tm4c123gh6pm.h"

typedef enum
	{
		PORT_PIN_IN,
		PORT_PIN_OUT
	}Port_PinDirectionType;
	
	/*Functions prototypes*/
	void Port_Init( uint8 port_index );
	void Port_SetPinDirection( uint8 port_index, uint8 pins_mask, Port_PinDirectionType pins_direction );
	void Port_SetPinPullUp( uint8 port_index, uint8 pins_mask, uint8 enable );
	void Port_SetPinPullDown( uint8 port_index, uint8 pins_mask, uint8 enable );
	
#endif
