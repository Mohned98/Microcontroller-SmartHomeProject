#include "UART.h"
#include "Systick.h"
#include "RGB_LED.h"
#include "PLL.h"
#include "Temp_Sensor.h"
#include "servo.h"

int main(void)
{
	
	uint8 data,device;	
	SysTick_Init();
	PLL_Init(); 	
	Servo_Init(PWMModule1,PWM0,90);
	Servo_SetDegree(PWMModule1,PWM0,90);
	UART_Init(uart3, 9600, Parity_OFF, Interrupt_OFF);
	UART_Init(uart0, 9600, Parity_OFF, Interrupt_OFF);
	BLUE_LED_PWM_Init();
	BLUE_LED_Set_Intensity(100);
	data = 20;
	ADC_init(AN0);
	while(1)
	{
		while(UART_Available(uart3))
		{
			device = UART_Read(uart3);
			data = UART_Read(uart3);
			switch (device){
				case 'M': //motor angle
					Servo_SetDegree(PWMModule1,PWM0,data);
					break;
				case 'L': //led intensity
					BLUE_LED_Set_Intensity(data);
					break;	
			}
		}
		data = InternalTempSensor_read();
		UART_Write(uart3,'T');
		UART_Write(uart3,data);
		SysTick_delay_ms(200);
	}
}

