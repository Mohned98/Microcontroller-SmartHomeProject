#include "lcd.h"

/**
  * @brief This function used to send data to data pins (DB0-DB7). 
  * @param data specifies the data to be sent.
  * @retval None
  */
	
void LCD_displayCharacter4bit(uint8 data)
{
	DIO_WritePort(LCD_CTRL_PORT,1<<RS,STD_HIGH);
	DIO_WritePort(LCD_CTRL_PORT,1<<RW,STD_LOW);
		
	DIO_WritePort(LCD_DATA_PORT,data&0x0f,STD_HIGH);
	DIO_WritePort(LCD_DATA_PORT,(~data)&0x0f,STD_LOW);
	
	DIO_WritePort(LCD_CTRL_PORT,1<<E,STD_HIGH);
	SysTick_delay_ms(2);
	DIO_WritePort(LCD_CTRL_PORT,1<<E,STD_LOW);
	
}


void LCD_displayCharacter(uint8 data)
{
	LCD_displayCharacter4bit(data>>4);
	LCD_displayCharacter4bit(data);
}