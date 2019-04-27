#include "port.h"

void Port_SetPinPullUp( uint8 port_index, uint8 pins_mask, uint8 enable )
{
	switch(port_index){
		case 0: 
			(enable)?(GPIO_PORTA_PUR_R|=pins_mask):(GPIO_PORTA_PUR_R&=(~pins_mask)); 
			 break;
		case 1: 
			(enable)?(GPIO_PORTB_PUR_R|=pins_mask):(GPIO_PORTB_PUR_R&=(~pins_mask)); 
			 break;
		case 2: 
			(enable)?(GPIO_PORTC_PUR_R|=pins_mask):(GPIO_PORTC_PUR_R&=(~pins_mask)); 
				break;
		case 3: 
			(enable)?(GPIO_PORTD_PUR_R|=pins_mask):(GPIO_PORTD_PUR_R&=(~pins_mask)); 
				break;
		case 4: 
			(enable)?(GPIO_PORTE_PUR_R|=pins_mask):(GPIO_PORTE_PUR_R&=(~pins_mask)); 
				break;
		case 5: 
			(enable)?(GPIO_PORTF_PUR_R|=pins_mask):(GPIO_PORTF_PUR_R&=(~pins_mask)); 
				break;
	
	}
}
