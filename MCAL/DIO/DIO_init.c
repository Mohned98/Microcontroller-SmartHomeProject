#include "DIO.h"


void DIO_Init( Dio_PortName port_name,uint8 pins_mask )
{
		SYSCTL_RCGCGPIO_R|=1<<port_name;                  //enable the clock for required port
		while(!IS_BIT_SET(SYSCTL_PRGPIO_R,port_name));    //wait until clock is configured
		switch(port_name)                                 //unlock and digital enable all the pins of required port 
		{
			case PORTA:
				GPIO_PORTA_LOCK_R=GPIO_LOCK_KEY;
				GPIO_PORTA_CR_R|=pins_mask;
			  GPIO_PORTA_DEN_R|=pins_mask;
				GPIO_PORTA_AFSEL_R&=~pins_mask;
				GPIO_PORTA_AMSEL_R&=~pins_mask;
				break;
			case PORTB:
				GPIO_PORTB_LOCK_R=GPIO_LOCK_KEY;
				GPIO_PORTB_CR_R|=pins_mask;
			 	GPIO_PORTB_DEN_R|=pins_mask;
				GPIO_PORTB_AFSEL_R&=~pins_mask;
				GPIO_PORTB_AMSEL_R&=~pins_mask;
				break;
			case PORTC:
			  GPIO_PORTC_DEN_R|=pins_mask;
				GPIO_PORTC_AFSEL_R&=~pins_mask;
				GPIO_PORTC_AMSEL_R&=~pins_mask;
				break;
			case PORTD:
			  GPIO_PORTD_DEN_R|=pins_mask;
				GPIO_PORTD_AFSEL_R&=~pins_mask;
				GPIO_PORTD_AMSEL_R&=~pins_mask;
				break;
			case PORTE:
				GPIO_PORTE_LOCK_R=GPIO_LOCK_KEY;
			  GPIO_PORTE_CR_R|=pins_mask;
			  GPIO_PORTE_DEN_R|=pins_mask;
				GPIO_PORTE_AFSEL_R&=~pins_mask;
				GPIO_PORTE_AMSEL_R&=~pins_mask;
				break;
			case PORTF:
				GPIO_PORTF_LOCK_R=GPIO_LOCK_KEY;
			  GPIO_PORTF_CR_R|=pins_mask;
			  GPIO_PORTF_DEN_R|=pins_mask;
				GPIO_PORTF_AFSEL_R&=~pins_mask;
				GPIO_PORTF_AMSEL_R&=~pins_mask;
				break;
		}
}

	
void DIO_SetPinDirection( Dio_PortName port_name, uint8 pins_mask, Dio_PinDirectionType pins_direction )
{
		switch (port_name)
		{
			case PORTA :
				switch(pins_direction)
				{
					case DIO_PIN_IN:
							GPIO_PORTA_DIR_R &= ~pins_mask;
						break;
					case DIO_PIN_OUT:
							GPIO_PORTA_DIR_R |= pins_mask;
						break;
				}
					break;
			
			case PORTB :
				switch(pins_direction)
				{
					case DIO_PIN_IN:
							GPIO_PORTB_DIR_R &= ~pins_mask;
						break;
					case DIO_PIN_OUT:
							GPIO_PORTB_DIR_R |= pins_mask;
						break;
				}
					break;
			
			case PORTC :
				switch(pins_direction)
				{
					case DIO_PIN_IN:
							GPIO_PORTC_DIR_R &= ~pins_mask;
						break;
					case DIO_PIN_OUT:
							GPIO_PORTC_DIR_R |= pins_mask;
						break;
				}
					break;
			
			case PORTD :
				switch(pins_direction)
				{
					case DIO_PIN_IN:
							GPIO_PORTD_DIR_R &= ~pins_mask;
						break;
					case DIO_PIN_OUT:
							GPIO_PORTD_DIR_R |= pins_mask;
						break;
				}
					break;
			
			case PORTE :
				switch(pins_direction)
				{
					case DIO_PIN_IN:
							GPIO_PORTE_DIR_R &= ~pins_mask;
						break;
					case DIO_PIN_OUT:
							GPIO_PORTE_DIR_R |= pins_mask;
						break;
				}
					break;
			
			case PORTF :
				switch(pins_direction)
				{
					case DIO_PIN_IN:
							GPIO_PORTF_DIR_R &= ~pins_mask;
						break;
					case DIO_PIN_OUT:
							GPIO_PORTF_DIR_R |= pins_mask;
						break;
				}
					break;
		}
}


void DIO_SetPinPullUp( Dio_PortName port_name, uint8 pins_mask )
{
	switch(port_name){
		case PORTA: 
			GPIO_PORTA_PUR_R|=pins_mask; 
			 break;
		case PORTB: 
			GPIO_PORTB_PUR_R|=pins_mask; 
			 break;
		case PORTC: 
			GPIO_PORTC_PUR_R|=pins_mask; 
				break;
		case PORTD: 
			GPIO_PORTD_PUR_R|=pins_mask; 
				break;
		case PORTE: 
			GPIO_PORTE_PUR_R|=pins_mask; 
				break;
		case PORTF: 
			GPIO_PORTF_PUR_R|=pins_mask; 
				break;
	}
}

void DIO_SetPinPullDown( Dio_PortName port_name, uint8 pins_mask )
{
	switch(port_name){
		case PORTA: 
			GPIO_PORTA_PDR_R|=pins_mask; 
				break;
		case PORTB: 
			GPIO_PORTB_PDR_R|=pins_mask; 
				break;
		case PORTC: 
			GPIO_PORTC_PDR_R|=pins_mask; 
				break;
		case PORTD: 
			GPIO_PORTD_PDR_R|=pins_mask; 
				break;
		case PORTE: 
			GPIO_PORTE_PDR_R|=pins_mask; 
				break;
		case PORTF: 
			GPIO_PORTF_PDR_R|=pins_mask; 
				break;
	
	}
}






