#include "RGB_LED.h"
#include "DIO.h"

void RGB_LED_Init(void) {
	DIO_Init(PORTF,0x0E);
	DIO_SetPinDirection(PORTF,0x0E,DIO_PIN_OUT);
	GPIO_PORTF321_DATA_R = dark;
}

void RGB_LED_Set_Color(LED_RGB_Color color){
	GPIO_PORTF321_DATA_R = color;
}