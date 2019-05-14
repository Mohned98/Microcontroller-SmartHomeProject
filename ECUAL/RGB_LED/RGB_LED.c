#include "RGB_LED.h"
#include "DIO.h"
#include "PWM.h"


void RGB_LED_Init(void) {
	DIO_Init(PORTF,0x0E);
	DIO_SetPinDirection(PORTF,0x0E,DIO_PIN_OUT);
	GPIO_PORTF321_DATA_R = dark;
	PWM_Init(PWMModule1, PWM5,1250,100); // PF1
}

void RGB_LED_Set_Color(LED_RGB_Color color){
	GPIO_PORTF321_DATA_R = color;
}
void RGB_LED_Set_Intensity(uint16 intensity){
	PWM_SetDuty(PWMModule1,PWM5,intensity);
}
