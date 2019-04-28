#include "DIO.h"

uint8 DIO_ReadPort( Dio_PortName port_name, uint8 pins_mask )
{ 
	uint8 pins_level; 
	switch(port_name)
	{	
		case PORTA:
			pins_level = GPIO_PORTA_DATA_R & pins_mask;
			break;
		case PORTB:
			pins_level = GPIO_PORTB_DATA_R & pins_mask;
			break;
		case PORTC:
			pins_level = GPIO_PORTC_DATA_R & pins_mask;
			break;
		case PORTD:
			pins_level = GPIO_PORTD_DATA_R & pins_mask;
			break;
		case PORTE:
			pins_level = GPIO_PORTE_DATA_R & pins_mask;
			break;
		case PORTF:
			pins_level = GPIO_PORTF_DATA_R & pins_mask;
			break;
	}
	return pins_level;
}

void DIO_WritePort(Dio_PortName port_name, uint8 pins_mask, Dio_LevelType pins_level)
{
		switch(port_name)
		{
			case PORTA:
				if(pins_level == STD_HIGH)
					GPIO_PORTA_DATA_R |= pins_mask;
				else
					GPIO_PORTA_DATA_R &= ~(pins_mask);
			break;
			case PORTB:
				if(pins_level == STD_HIGH)
					GPIO_PORTB_DATA_R |= pins_mask;
				else
					GPIO_PORTB_DATA_R &= ~(pins_mask);
			break;
			case PORTC:
				if(pins_level == STD_HIGH)
					GPIO_PORTC_DATA_R |= pins_mask;
				else
					GPIO_PORTC_DATA_R &= ~(pins_mask);
			break;
			case PORTD:
				if(pins_level == STD_HIGH)
					GPIO_PORTD_DATA_R |= pins_mask;
				else
					GPIO_PORTD_DATA_R &= ~(pins_mask);
			break;
			case PORTE:
				if(pins_level == STD_HIGH)
					GPIO_PORTE_DATA_R |= pins_mask;
				else
					GPIO_PORTE_DATA_R &= ~(pins_mask);
			break;
			case PORTF:
				if(pins_level == STD_HIGH)
					GPIO_PORTF_DATA_R |= pins_mask;
				else
					GPIO_PORTF_DATA_R &= ~(pins_mask);
			break;
		}
}

void DIO_FlipPort(Dio_PortName port_name, uint8 pins_mask)
{ 
	switch(port_name)
	{	case PORTA:
			GPIO_PORTA_DATA_R =(GPIO_PORTA_DATA_R ^ pins_mask);
			break;
		case PORTB:
			GPIO_PORTB_DATA_R =(GPIO_PORTB_DATA_R ^ pins_mask);
			break;
		case PORTC:
			GPIO_PORTC_DATA_R =(GPIO_PORTC_DATA_R ^ pins_mask);
			break;
		case PORTD:
			GPIO_PORTD_DATA_R =(GPIO_PORTD_DATA_R ^ pins_mask);
			break;
		case PORTE:
			GPIO_PORTE_DATA_R =(GPIO_PORTE_DATA_R ^ pins_mask);
			break;
		case PORTF:
			GPIO_PORTF_DATA_R =(GPIO_PORTF_DATA_R ^ pins_mask);
			break;
	}
}