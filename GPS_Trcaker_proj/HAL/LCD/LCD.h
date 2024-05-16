/*
 * LCD.h
 *
 * Created: 4/30/2024 10:45:39 PM
 *  Author: Ali Elsayed & Abdelrahman Awad
 */

#ifndef LCD_H_
#define LCD_H_
#include <stdint.h>
#include "../../MCAL/Systick/Systick.h"
#include "../../MCAL/GPIO/GPIO.h"

/************************************************************************/
/*           some important defintions                                  */
/************************************************************************/
#define lcd_Clear            0x01          // replace all characters with ASCII 'space'
#define lcd_Home             0x02          // return cursor to first position on first line
#define lcd_EntryMode        0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff       0x08          // turn display off
#define lcd_DisplayOn        0x0F          // display on & cursor blink
#define Set5x7FontSize    	 0x20					 // set font size to 5x7
#define four_bit_mode		     0x28					 // select 4-bit mode
#define lcd_FunctionReset    0x30          // reset the LCD
#define first_row            0x80          // set cursor position in first row
#define second_row           0xC0          // set cursor position in second row
#define CURSOR_OFF           0x0C					 // Cursor off
#define CURSOR_ON            0x0E					 // Cursor on
#define EN									 0x04					 // lcd enable
#define RS									 0x01					 // register select


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*

/*
 * Description :
 * Initializing LCD for using
 */
void lcd_init(void);

/*
 * Description :
 * A Function to send the command in a sequence for the LCD
 * it has 1 arguments : arg 1 -> the command desired to be done
 */
void lcd_cmd(unsigned char cmd);

/*
 * Description :
 * A Function to write the data you need in a sequence for the LCD, either it's a command or just data
 * it has 2 arguments : arg 1 -> the sequence you need to send, arg 2 -> a specifier for the type of the data(RS)
 */
void lcd_write(unsigned char c, unsigned char ctrl);

/*
 * Description :
 * A Function to send a Char for the LCD
 * it has 2 arguments : arg 1 -> the command desired to be done, arg 2 ->
 */
void lcd_char(unsigned char data, unsigned char ctrl);

/*
 * Description :
 * A Function to send a String for the LCD to view
 * it has 1 arguments : arg 1 -> the string to be sent
 */
void lcd_str( char *str);

/*
 * Description :
 * A to reverse the string sequence
 * it has 2 arguments : arg 1 -> the string to be reversed , arg 2 ->the length of the string
 */
void reverse(char* str, int len);

/*
 * Description :
 * A Function to convert an integer to a String
 * it has 3 arguments : arg 1 ->  integer x to be converted, arg 2 ->the array of char to store in the result,
 *arg 3 ->number of digits to display in the output
 */
int intToStr(int x, char str[], int d);

/*
 * Description :
 * A Function to send a String for the LCD to view on Second row
 * it has 1 arguments : arg 1 -> the string to be sent
 */
void lcd_str_2nd_row(char *str);

/*
 * Description :
 * A Function to send a String for the LCD to view on First row
 * it has 1 arguments : arg 1 -> the string to be sent
 */
void lcd_str_1st_row( char *str);

/*
 * Description :
 * A Function to move the cursor for a desired place
 * it has 1 arguments : arg 1 -> the row num, arg2 ->the colm num
 */
void lcd_moveCursor(u8 row,u8 col);





#endif
