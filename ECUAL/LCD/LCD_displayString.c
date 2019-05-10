#include "lcd.h"

void LCD_displayString(const char *Str){
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}

}

