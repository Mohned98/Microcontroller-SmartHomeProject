#ifndef __RGB_LED_H__
#define __RGB_LED_H__
#include "STANDARD_TYPES.h"

#define GPIO_PORTF321_DATA_R      (*((volatile unsigned long *)0x40025038))

typedef enum{
	dark = 0x00,
	red = 0x02,
	blue = 0x04,
	pink = 0x06,
	green = 0x08,
	yellow = 0x0A,
	sky = 0x0C,
	white = 0x0E
} LED_RGB_Color;



void RGB_LED_Init(void);

void RGB_LED_Set_Color(LED_RGB_Color color);

void RGB_LED_Set_Intensity(uint16 intensity);
#endif // __LED_RGB_H__
