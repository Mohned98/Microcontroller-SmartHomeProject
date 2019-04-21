#ifndef DIO_H_
#define DIO_H_

#include "MACROS.h"
#include "STANDARD_TYPES.h"
#include "tm4c123gh6pm.h"


typedef enum
	{
		STD_LOW,
		STD_HIGH
  }Dio_LevelType;
	
typedef enum
	{
		PORT_PIN_IN,
		PORT_PIN_OUT
	}Dio_PinDirectionType;
	
	typedef enum
	{
		GPIOA,
		GPIOB,
		GPIOC,
		GPIOD,
		GPIOE,
		GPIOF
	}Dio_PortName;
	
	/*Functions prototypes*/
	void DIO_Init( Dio_PortName port_name,uint8 pins_mask );
	void DIO_SetPinDirection( Dio_PortName port_name, uint8 pins_mask, Dio_PinDirectionType pins_direction );
	void DIO_SetPinPullUp( Dio_PortName port_name, uint8 pins_mask);
	void DIO_SetPinPullDown( Dio_PortName port_name, uint8 pins_mask);
	uint8 DIO_ReadPort( Dio_PortName port_name, uint8 pins_mask );
	void DIO_WritePort(Dio_PortName port_name, uint8 pins_mask, Dio_LevelType pins_level);
	void DIO_FlipPort(Dio_PortName port_name, uint8 pins_mask);
	

#endif