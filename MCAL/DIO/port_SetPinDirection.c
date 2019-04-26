#include "port.h"

	
	
void Port_SetPinDirection( uint8 port_index, uint8 pins_mask, Port_PinDirectionType pins_direction )
{
		switch (port_index)
		{
			case 0 :
				switch(pins_direction)
				{
					case PORT_PIN_IN:
							GPIO_PORTA_DIR_R &= ~pins_mask;
					break;
					case PORT_PIN_OUT:
							GPIO_PORTA_DIR_R |= pins_mask;
					break;
				}
				break;
			
			case 1 :
				switch(pins_direction)
				{
					case PORT_PIN_IN:
							GPIO_PORTB_DIR_R &= ~pins_mask;
					break;
					case PORT_PIN_OUT:
							GPIO_PORTB_DIR_R |= pins_mask;
					break;
				}
				break;
			
			case 2 :
				switch(pins_direction)
				{
					case PORT_PIN_IN:
							GPIO_PORTC_DIR_R &= ~pins_mask;
					break;
					case PORT_PIN_OUT:
							GPIO_PORTC_DIR_R |= pins_mask;
					break;
				}
				break;
			
			case 3 :
				switch(pins_direction)
				{
					case PORT_PIN_IN:
							GPIO_PORTD_DIR_R &= ~pins_mask;
					break;
					case PORT_PIN_OUT:
							GPIO_PORTD_DIR_R |= pins_mask;
					break;
				}
				break;
			
			case 4 :
				switch(pins_direction)
				{
					case PORT_PIN_IN:
							GPIO_PORTE_DIR_R &= ~pins_mask;
					break;
					case PORT_PIN_OUT:
							GPIO_PORTE_DIR_R |= pins_mask;
					break;
				}
				break;
			
			case 5 :
				switch(pins_direction)
				{
					case PORT_PIN_IN:
							GPIO_PORTF_DIR_R &= ~pins_mask;
					break;
					case PORT_PIN_OUT:
							GPIO_PORTF_DIR_R |= pins_mask;
					break;
				}
				break;
		}
}
