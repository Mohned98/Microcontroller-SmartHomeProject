#include "lcd.h"

/**
  * @brief This function used to send command to data pins (DB0-DB7). 
  * @param command specifies the command to be sent.
  * @retval None
  */
	
void LCD_sendCommand4bit(uint8 command)
{
	DIO_WritePort(LCD_CTRL_PORT,1<<RS,STD_LOW);
	DIO_WritePort(LCD_CTRL_PORT,1<<RW,STD_LOW);


	DIO_WritePort(LCD_DATA_PORT,command&0x0f,STD_HIGH);
	DIO_WritePort(LCD_DATA_PORT,(~command)&0x0f,STD_LOW);
	
	DIO_WritePort(LCD_CTRL_PORT,1<<E,STD_HIGH);
	SysTick_delay_ms(2);
	DIO_WritePort(LCD_CTRL_PORT,1<<E,STD_LOW);
	
}


void LCD_sendCommand(uint8 command)
{
	LCD_sendCommand4bit(command>>4);
	LCD_sendCommand4bit(command);
}