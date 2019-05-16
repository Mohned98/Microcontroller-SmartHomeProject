#include "button.h"
#include "lcd.h"
#include "UART.h"
#include "ADC.h"
#include "Systick.h"
#include "PLL.h"

#define BAUD_RATE 9600
#define SW1 0
#define SW2 4
#define BUTTONS_MASK 0x11
#define POTENTIOMETER AN0

uint8 ch,data;
sint16 servo_angle=90;

//Function declarations
void Rotate_clkwise(void);
void Rotate_counterclkwise(void);
void Send_potReading();
void Print_tempReading(void);
	
int main(void)
{
	PLL_Init();
	SysTick_Init();
	UART_Init(uart3, BAUD_RATE, Parity_OFF, Interrupt_OFF);   
	LCD_init();
	ADC_init(POTENTIOMETER);
	Button_Init(PORTF, BUTTONS_MASK, PULL_UP); //Switch 1,2 init
	while(1)
	{
		ch=UART_Read(uart3);
		if(ch=='T')
		{
			Print_tempReading();
		}
		Button_ActOnPressing(PORTF,SW1,Rotate_clkwise);
		Button_ActOnPressing(PORTF,SW2,Rotate_counterclkwise );
		Send_potReading();
		SysTick_delay_ms(50);
	}
}

void Rotate_clkwise(void)
{
	UART_Write( uart3,'M');
	servo_angle+=30;
	if(servo_angle>=180)
	{
		servo_angle=180;
	}
	UART_Write( uart3, servo_angle);
}

void Rotate_counterclkwise(void)
{
	UART_Write( uart3,'M'); //control motor
	servo_angle-=30;
	if(servo_angle<=0)
	{
		servo_angle=0;
	}
	UART_Write( uart3, servo_angle);
}

void Send_potReading()
{
	uint16 reading;
	UART_Write(uart3,'L'); //led intensity
	reading=(ADC_read(POTENTIOMETER)*100)/4096;
	UART_Write( uart3, reading);
}

void Print_tempReading(void)
{
	ch = UART_Read(uart3);
	if( ch !='T')
	{
		LCD_clearScreen();
		LCD_goToRowColumn(0,7);
		LCD_intgerToString(ch);
	}
}

