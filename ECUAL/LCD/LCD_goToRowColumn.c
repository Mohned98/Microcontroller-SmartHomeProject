#include "lcd.h"

 
/**
  * @brief This function make the crusorof the LCD for to a specific Row and column on the LCD Display.
  * @param Desired Location (Row and Column)
  * @retval None void function
  */
	
	void LCD_goToRowColumn(uint8 row,uint8 col)
	{
		
		uint8 Address;
	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
	}					
		/* to write to a specific address in the LCD 
		* we need to apply the corresponding command 0b10000000+Address */
		LCD_sendCommand(Address | SET_CURSOR_LOCATION);
	}
	