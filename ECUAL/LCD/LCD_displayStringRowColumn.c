#include "lcd.h"

/**
  * @brief This function used to display string in a specific row and column. 
  * @param number of row , column & string to be displayed.
  * @retval None
  */

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_goToRowColumn(row,col);
  LCD_displayString(Str);
}
