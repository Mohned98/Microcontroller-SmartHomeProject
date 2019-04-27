#include "DIO.h"

uint8 DIO_ReadPort( Dio_PortName port_name, uint8 pins_mask )
{ 
	uint8 pins_level; 

	switch(port_name)
	{	
		case GPIOA:
			pins_level = GPIO_PORTA_DATA_R & pins_mask;
			break;
		case GPIOB:
			pins_level = GPIO_PORTB_DATA_R & pins_mask;
			break;
		case GPIOC:
			pins_level = GPIO_PORTC_DATA_R & pins_mask;
			break;
		case GPIOD:
			pins_level = GPIO_PORTD_DATA_R & pins_mask;
			break;
		case GPIOE:
			pins_level = GPIO_PORTE_DATA_R & pins_mask;
			break;
		case GPIOF:
			pins_level = GPIO_PORTF_DATA_R & pins_mask;
			break;
	}
	return pins_level;
}

void DIO_WritePort(Dio_PortName port_name, uint8 pins_mask, Dio_LevelType pins_level)
{
		switch(port_name)
		{
			case GPIOA:
				if(pins_level == STD_HIGH)
					GPIO_PORTA_DATA_R |= pins_mask;
				else
					GPIO_PORTA_DATA_R &= ~(pins_mask);
			break;
			case GPIOB:
				if(pins_level == STD_HIGH)
					GPIO_PORTB_DATA_R |= pins_mask;
				else
					GPIO_PORTB_DATA_R &= ~(pins_mask);
			break;
			case GPIOC:
				if(pins_level == STD_HIGH)
					GPIO_PORTC_DATA_R |= pins_mask;
				else
					GPIO_PORTC_DATA_R &= ~(pins_mask);
			break;
			case GPIOD:
				if(pins_level == STD_HIGH)
					GPIO_PORTD_DATA_R |= pins_mask;
				else
					GPIO_PORTD_DATA_R &= ~(pins_mask);
			break;
			case GPIOE:
				if(pins_level == STD_HIGH)
					GPIO_PORTE_DATA_R |= pins_mask;
				else
					GPIO_PORTE_DATA_R &= ~(pins_mask);
			break;
			case GPIOF:
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
	{	case GPIOA:
			GPIO_PORTA_DATA_R =(GPIO_PORTA_DATA_R ^ pins_mask);
			break;
		case GPIOB:
			GPIO_PORTB_DATA_R =(GPIO_PORTB_DATA_R ^ pins_mask);
			break;
		case GPIOC:
			GPIO_PORTC_DATA_R =(GPIO_PORTC_DATA_R ^ pins_mask);
			break;
		case GPIOD:
			GPIO_PORTD_DATA_R =(GPIO_PORTD_DATA_R ^ pins_mask);
			break;
		case GPIOE:
			GPIO_PORTE_DATA_R =(GPIO_PORTE_DATA_R ^ pins_mask);
			break;
		case GPIOF:
			GPIO_PORTF_DATA_R =(GPIO_PORTF_DATA_R ^ pins_mask);
			break;
	}
}