#include "lcd.h"

void LCD_clearScreen(void){
	LCD_sendCommand(CLEAR_COMMAND); //clears the screen
}

