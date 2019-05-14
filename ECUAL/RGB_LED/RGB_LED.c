#include "RGB_LED.h"
#include "DIO.h"
#include "PWM.h"


void RGB_LED_Init(void) {
	DIO_Init(PORTF,0x0E);
	DIO_SetPinDirection(PORTF,0x0E,DIO_PIN_OUT);
	GPIO_PORTF321_DATA_R = dark;
}

void RGB_LED_Set_Color(LED_RGB_Color color){
	GPIO_PORTF321_DATA_R = color;
}

void RED_LED_PWM_Init(void)
{
	PWM_Init(PWMModule1, PWM5,LED_PERIOD,0); // PF1
}

void GREEN_LED_PWM_Init(void)
{
	PWM_Init(PWMModule1, PWM7,LED_PERIOD,0); // PF3
}

void BLUE_LED_PWM_Init(void)
{
	PWM_Init(PWMModule1, PWM6,LED_PERIOD,0); // PF2
}

void RED_LED_Set_Intensity(uint16 intensity)
{
	PWM_SetDuty(PWMModule1,PWM5,intensity);
}

void GREEN_LED_Set_Intensity(uint16 intensity)
{
	PWM_SetDuty(PWMModule1,PWM7,intensity);
}

void BLUE_LED_Set_Intensity(uint16 intensity)
{
	PWM_SetDuty(PWMModule1,PWM6,intensity);
}

