/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include "SysTick.h"
/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* LCD HW Pins */
#define RS 5 /*Select  0 for Instruction Register ,  1 for Data Register*/
#define RW 6 /*Select  0 for Write , 1 For Read*/
#define E  7 /*Starts Data read/Write ( Transaction From High To Low When Writing ,
 *             Transaction From Low to High when Reading Data will be Available as 
 *				 		 long as the signal is High)*/
#define LCD_CTRL_PORT 1
#define LCD_DATA_PORT 1

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define TWO_LINE_LCD_Four_BIT_MODE 0x02
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80 
#define CURSOR_BLINKING 0x0F
#define WAKEUP_COMMAND 0x30

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char *Str);
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_intgerToString(int data);
void LCD_displayCharacter4bit(uint8 data);
void LCD_sendCommand4bit(uint8 command);


#endif /* LCD_H_ */
