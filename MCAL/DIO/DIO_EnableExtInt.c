#include "DIO.h"

#define NVIC_EN_PORTA (1<<0)
#define NVIC_EN_PORTB (1<<1)
#define NVIC_EN_PORTC (1<<2)
#define NVIC_EN_PORTD (1<<3)
#define NVIC_EN_PORTE (1<<4)
#define NVIC_EN_PORTF (1<<30)

void DIO_EnableExtInt(Dio_PortName port_name,uint8 pins_mask,Dio_IntType int_source)
{
	DIO_Init(port_name, pins_mask );
	DIO_SetPinDirection(port_name, pins_mask,DIO_PIN_IN);
	switch(port_name)
	{
		case PORTA:
			GPIO_PORTA_IM_R&=~pins_mask;
			switch(int_source)
			{
				case FALLING_EDGE:
					GPIO_PORTA_IS_R&=~pins_mask;
					GPIO_PORTA_IBE_R&=~pins_mask;
					GPIO_PORTA_IEV_R&=~pins_mask;
					break;
				case RISING_EDGE:
					GPIO_PORTA_IS_R&=~pins_mask;
					GPIO_PORTA_IBE_R&=~pins_mask;
					GPIO_PORTA_IEV_R|=pins_mask;
					break;
				case BOTH_EDGES:
					GPIO_PORTA_IS_R&=~pins_mask;
					GPIO_PORTA_IBE_R|=pins_mask;
					break;
				case LOW_LEVEL:
					GPIO_PORTA_IS_R|=pins_mask;
					GPIO_PORTA_IBE_R&=~pins_mask;
					GPIO_PORTA_IEV_R&=~pins_mask;
					break;
				case HIGH_LEVEL:
					GPIO_PORTA_IS_R|=pins_mask;
					GPIO_PORTA_IBE_R&=~pins_mask;
					GPIO_PORTA_IEV_R|=pins_mask;
					break;	
			}
			GPIO_PORTA_ICR_R|=pins_mask;
			GPIO_PORTA_IM_R|=pins_mask;
			NVIC_EN0_R|=NVIC_EN_PORTA;
			break;
		case PORTB:
			GPIO_PORTB_IM_R&=~pins_mask;
			switch(int_source)
			{
				case FALLING_EDGE:
					GPIO_PORTB_IS_R&=~pins_mask;
					GPIO_PORTB_IBE_R&=~pins_mask;
					GPIO_PORTB_IEV_R&=~pins_mask;
					break;
				case RISING_EDGE:
					GPIO_PORTB_IS_R&=~pins_mask;
					GPIO_PORTB_IBE_R&=~pins_mask;
					GPIO_PORTB_IEV_R|=pins_mask;
					break;
				case BOTH_EDGES:
					GPIO_PORTB_IS_R&=~pins_mask;
					GPIO_PORTB_IBE_R|=pins_mask;
					break;
				case LOW_LEVEL:
					GPIO_PORTB_IS_R|=pins_mask;
					GPIO_PORTB_IBE_R&=~pins_mask;
					GPIO_PORTB_IEV_R&=~pins_mask;
					break;
				case HIGH_LEVEL:
					GPIO_PORTB_IS_R|=pins_mask;
					GPIO_PORTB_IBE_R&=~pins_mask;
					GPIO_PORTB_IEV_R|=pins_mask;
					break;	
			}
			GPIO_PORTB_ICR_R|=pins_mask;
			GPIO_PORTB_IM_R|=pins_mask;
			NVIC_EN0_R|=NVIC_EN_PORTB;
			break;
		case PORTC:
			GPIO_PORTC_IM_R&=~pins_mask;
			switch(int_source)
			{
				case FALLING_EDGE:
					GPIO_PORTC_IS_R&=~pins_mask;
					GPIO_PORTC_IBE_R&=~pins_mask;
					GPIO_PORTC_IEV_R&=~pins_mask;
					break;
				case RISING_EDGE:
					GPIO_PORTC_IS_R&=~pins_mask;
					GPIO_PORTC_IBE_R&=~pins_mask;
					GPIO_PORTC_IEV_R|=pins_mask;
					break;
				case BOTH_EDGES:
					GPIO_PORTC_IS_R&=~pins_mask;
					GPIO_PORTC_IBE_R|=pins_mask;
					break;
				case LOW_LEVEL:
					GPIO_PORTC_IS_R|=pins_mask;
					GPIO_PORTC_IBE_R&=~pins_mask;
					GPIO_PORTC_IEV_R&=~pins_mask;
					break;
				case HIGH_LEVEL:
					GPIO_PORTC_IS_R|=pins_mask;
					GPIO_PORTC_IBE_R&=~pins_mask;
					GPIO_PORTC_IEV_R|=pins_mask;
					break;	
			}
			GPIO_PORTC_ICR_R|=pins_mask;
			GPIO_PORTC_IM_R|=pins_mask;
			NVIC_EN0_R|=NVIC_EN_PORTC;
			break;
		case PORTD:
			GPIO_PORTD_IM_R&=~pins_mask;
			switch(int_source)
			{
				case FALLING_EDGE:
					GPIO_PORTD_IS_R&=~pins_mask;
					GPIO_PORTD_IBE_R&=~pins_mask;
					GPIO_PORTD_IEV_R&=~pins_mask;
					break;
				case RISING_EDGE:
					GPIO_PORTD_IS_R&=~pins_mask;
					GPIO_PORTD_IBE_R&=~pins_mask;
					GPIO_PORTD_IEV_R|=pins_mask;
					break;
				case BOTH_EDGES:
					GPIO_PORTD_IS_R&=~pins_mask;
					GPIO_PORTD_IBE_R|=pins_mask;
					break;
				case LOW_LEVEL:
					GPIO_PORTD_IS_R|=pins_mask;
					GPIO_PORTD_IBE_R&=~pins_mask;
					GPIO_PORTD_IEV_R&=~pins_mask;
					break;
				case HIGH_LEVEL:
					GPIO_PORTD_IS_R|=pins_mask;
					GPIO_PORTD_IBE_R&=~pins_mask;
					GPIO_PORTD_IEV_R|=pins_mask;
					break;	
			}
			GPIO_PORTD_ICR_R|=pins_mask;
			GPIO_PORTD_IM_R|=pins_mask;
			NVIC_EN0_R|=NVIC_EN_PORTD;
			break;
		case PORTE:
			GPIO_PORTE_IM_R&=~pins_mask;
			switch(int_source)
			{
				case FALLING_EDGE:
					GPIO_PORTE_IS_R&=~pins_mask;
					GPIO_PORTE_IBE_R&=~pins_mask;
					GPIO_PORTE_IEV_R&=~pins_mask;
					break;
				case RISING_EDGE:
					GPIO_PORTE_IS_R&=~pins_mask;
					GPIO_PORTE_IBE_R&=~pins_mask;
					GPIO_PORTE_IEV_R|=pins_mask;
					break;
				case BOTH_EDGES:
					GPIO_PORTE_IS_R&=~pins_mask;
					GPIO_PORTE_IBE_R|=pins_mask;
					break;
				case LOW_LEVEL:
					GPIO_PORTE_IS_R|=pins_mask;
					GPIO_PORTE_IBE_R&=~pins_mask;
					GPIO_PORTE_IEV_R&=~pins_mask;
					break;
				case HIGH_LEVEL:
					GPIO_PORTE_IS_R|=pins_mask;
					GPIO_PORTE_IBE_R&=~pins_mask;
					GPIO_PORTE_IEV_R|=pins_mask;
					break;	
			}
			GPIO_PORTE_ICR_R|=pins_mask;
			GPIO_PORTE_IM_R|=pins_mask;
			NVIC_EN0_R|=NVIC_EN_PORTE;
			break;
		case PORTF:
			GPIO_PORTF_IM_R&=~pins_mask;
			switch(int_source)
			{
				case FALLING_EDGE:
					GPIO_PORTF_IS_R&=~pins_mask;
					GPIO_PORTF_IBE_R&=~pins_mask;
					GPIO_PORTF_IEV_R&=~pins_mask;
					break;
				case RISING_EDGE:
					GPIO_PORTF_IS_R&=~pins_mask;
					GPIO_PORTF_IBE_R&=~pins_mask;
					GPIO_PORTF_IEV_R|=pins_mask;
					break;
				case BOTH_EDGES:
					GPIO_PORTF_IS_R&=~pins_mask;
					GPIO_PORTF_IBE_R|=pins_mask;
					break;
				case LOW_LEVEL:
					GPIO_PORTF_IS_R|=pins_mask;
					GPIO_PORTF_IBE_R&=~pins_mask;
					GPIO_PORTF_IEV_R&=~pins_mask;
					break;
				case HIGH_LEVEL:
					GPIO_PORTF_IS_R|=pins_mask;
					GPIO_PORTF_IBE_R&=~pins_mask;
					GPIO_PORTF_IEV_R|=pins_mask;
					break;	
			}
			GPIO_PORTF_ICR_R|=pins_mask;
			GPIO_PORTF_IM_R|=pins_mask;
			NVIC_EN0_R|=NVIC_EN_PORTF;
			break;
		
	}
}
