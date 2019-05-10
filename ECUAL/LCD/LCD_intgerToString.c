#include "lcd.h"
#include <stdio.h>

/**
  * @brief This function used to convert integer to string and displays it. 
  * @param data to be displayed on LCD.
  * @retval None
  */



void LCD_intgerToString(int data)
{
	char string[16];
	sprintf(string,"%d",data);
	LCD_displayString(string);
}

