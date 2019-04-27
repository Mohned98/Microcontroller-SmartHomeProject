#include "port.h"


void Port_Init( uint8 port_index )
{
		SYSCTL_RCGCGPIO_R|=1<<port_index;                  //enable the clock for required port
		while(!IS_BIT_SET(SYSCTL_PRGPIO_R,port_index));    //wait until clock is configured
		switch(port_index)                                 //unlock and digital enable all the pins of required port 
		{
			case 0:
				GPIO_PORTA_LOCK_R=GPIO_LOCK_KEY;
				GPIO_PORTA_CR_R=0xFF;
			  	GPIO_PORTA_DEN_R=0xFF;
				GPIO_PORTA_AFSEL_R=0x00;
				GPIO_PORTA_PCTL_R=0x00;
				GPIO_PORTA_AMSEL_R=0x00;
				break;
			case 1:
				GPIO_PORTB_LOCK_R=GPIO_LOCK_KEY;
				GPIO_PORTB_CR_R=0xFF;
			 	GPIO_PORTB_DEN_R=0xFF;
				GPIO_PORTB_AFSEL_R=0x00;
				GPIO_PORTB_PCTL_R=0x00;
				GPIO_PORTB_AMSEL_R=0x00;
				break;
			case 2:
				GPIO_PORTC_LOCK_R=GPIO_LOCK_KEY;
				GPIO_PORTC_CR_R=0xFF;
			  	GPIO_PORTC_DEN_R=0xFF;
				GPIO_PORTC_AFSEL_R=0x00;
				GPIO_PORTC_PCTL_R=0x00;
				GPIO_PORTC_AMSEL_R=0x00;
				break;
			case 3:
				GPIO_PORTD_LOCK_R=GPIO_LOCK_KEY;
				GPIO_PORTD_CR_R=0xFF;
			  	GPIO_PORTD_DEN_R=0xFF;
				GPIO_PORTD_AFSEL_R=0x00;
				GPIO_PORTD_PCTL_R=0x00;
				GPIO_PORTD_AMSEL_R=0x00;
				break;
			case 4:
				GPIO_PORTE_LOCK_R=GPIO_LOCK_KEY;
			  GPIO_PORTE_CR_R=0xFF;
			  GPIO_PORTE_DEN_R=0xFF;
				GPIO_PORTE_AFSEL_R=0x00;
				GPIO_PORTE_PCTL_R=0x00;
				GPIO_PORTE_AMSEL_R=0x00;
				break;
			case 5:
				GPIO_PORTF_LOCK_R=GPIO_LOCK_KEY;
			  	GPIO_PORTF_CR_R=0xFF;
			  	GPIO_PORTF_DEN_R=0xFF;
				GPIO_PORTF_AFSEL_R=0x00;
				GPIO_PORTF_PCTL_R=0x00;
				GPIO_PORTF_AMSEL_R=0x00;
				break;
		}
}

	
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

void Port_SetPinPullDown( uint8 port_index, uint8 pins_mask, uint8 enable )
{
	switch(port_index){
		case 0: 
			(enable)?(GPIO_PORTA_PDR_R|=pins_mask):(GPIO_PORTA_PDR_R&=(~pins_mask)); 
				break;
		case 1: 
			(enable)?(GPIO_PORTB_PDR_R|=pins_mask):(GPIO_PORTB_PDR_R&=(~pins_mask)); 
				break;
		case 2: 
			(enable)?(GPIO_PORTC_PDR_R|=pins_mask):(GPIO_PORTC_PDR_R&=(~pins_mask)); 
				break;
		case 3: 
			(enable)?(GPIO_PORTD_PDR_R|=pins_mask):(GPIO_PORTD_PDR_R&=(~pins_mask)); 
				break;
		case 4: 
			(enable)?(GPIO_PORTE_PDR_R|=pins_mask):(GPIO_PORTE_PDR_R&=(~pins_mask)); 
				break;
		case 5: 
			(enable)?(GPIO_PORTF_PDR_R|=pins_mask):(GPIO_PORTF_PDR_R&=(~pins_mask)); 
				break;
	
	}
}






