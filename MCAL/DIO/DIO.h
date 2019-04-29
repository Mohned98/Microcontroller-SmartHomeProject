#ifndef DIO_H_
#define DIO_H_

#include "MACROS.h"
#include "STANDARD_TYPES.h"
#include "tm4c123gh6pm.h"

#define __PORTA_IS_INT_SRC(pin_no)  (GPIO_PORTA_RIS_R&(1<<pin_no))
#define __PORTB_IS_INT_SRC(pin_no)  (GPIO_PORTB_RIS_R&(1<<pin_no))
#define __PORTC_IS_INT_SRC(pin_no)  (GPIO_PORTC_RIS_R&(1<<pin_no))
#define __PORTD_IS_INT_SRC(pin_no)  (GPIO_PORTD_RIS_R&(1<<pin_no))
#define __PORTE_IS_INT_SRC(pin_no)  (GPIO_PORTE_RIS_R&(1<<pin_no))
#define __PORTF_IS_INT_SRC(pin_no)  (GPIO_PORTF_RIS_R&(1<<pin_no))

#define __PORTA_INT_ACK(pin_no) GPIO_PORTA_ICR_R|=(1<<pin_no)
#define __PORTB_INT_ACK(pin_no) GPIO_PORTB_ICR_R|=(1<<pin_no)
#define __PORTC_INT_ACK(pin_no) GPIO_PORTC_ICR_R|=(1<<pin_no)
#define __PORTD_INT_ACK(pin_no) GPIO_PORTD_ICR_R|=(1<<pin_no)
#define __PORTE_INT_ACK(pin_no) GPIO_PORTE_ICR_R|=(1<<pin_no)
#define __PORTF_INT_ACK(pin_no) GPIO_PORTF_ICR_R|=(1<<pin_no)



typedef enum
	{
		STD_LOW,
		STD_HIGH
  }Dio_LevelType;
	
typedef enum
	{
		DIO_PIN_IN,
		DIO_PIN_OUT
	}Dio_PinDirectionType;
	
	typedef enum
	{
		PORTA,
		PORTB,
		PORTC,
		PORTD,
		PORTE,
		PORTF
	}Dio_PortName;
	
	typedef enum
	{
		FALLING_EDGE,
		RISING_EDGE,
		BOTH_EDGES,
		LOW_LEVEL,
		HIGH_LEVEL
	}Dio_IntType;
	
	/*Functions prototypes*/
	void DIO_Init( Dio_PortName port_name,uint8 pins_mask );
	void DIO_SetPinDirection( Dio_PortName port_name, uint8 pins_mask, Dio_PinDirectionType pins_direction );
	void DIO_SetPinPullUp( Dio_PortName port_name, uint8 pins_mask);
	void DIO_SetPinPullDown( Dio_PortName port_name, uint8 pins_mask);
	uint8 DIO_ReadPort( Dio_PortName port_name, uint8 pins_mask );
	void DIO_WritePort(Dio_PortName port_name, uint8 pins_mask, Dio_LevelType pins_level);
	void DIO_FlipPort(Dio_PortName port_name, uint8 pins_mask);
	void DIO_EnableExtInt(Dio_PortName port_name,uint8 pins_mask,Dio_IntType int_source);
	
	
#endif