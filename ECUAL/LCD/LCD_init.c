#include "lcd.h"

 
/**
  * @brief This function Initialize the LCD based on port A for control and port B for command /data .
  * @param No parameters required
  * @retval None
  */

void LCD_init(void){

	DIO_Init(LCD_CTRL_PORT,0xf0); //port B
	DIO_SetPinDirection(LCD_CTRL_PORT, 1<<RS, DIO_PIN_OUT );
	DIO_SetPinDirection(LCD_CTRL_PORT, 1<<RW, DIO_PIN_OUT );
	DIO_SetPinDirection(LCD_CTRL_PORT, 1<<E, DIO_PIN_OUT );

	DIO_Init(LCD_DATA_PORT,0x0f); // port B 
	DIO_SetPinDirection(LCD_DATA_PORT, 0xFF, DIO_PIN_OUT );
	
	
	LCD_sendCommand4bit(0x02);
	LCD_sendCommand(0x28);
	//LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);   //8-bits data 
	LCD_sendCommand(SET_CURSOR_LOCATION);           // start from the beginning of the first line
	LCD_sendCommand(CURSOR_ON);                		//cursor blinking command
	LCD_sendCommand(CLEAR_COMMAND);                 //clear command
	LCD_sendCommand(1);

}

