#include "LCD.h"

/////////  Enabling The Clock of PORT B   ////////
void lcd_init(void){
	SYSCTL_RCGCGPIO_R |= 0x02;
	while((SYSCTL_PRGPIO_R & 0x02)==0)
	{
	}
	GPIO_PORTB_LOCK_R = 0x4C4F434B; // UNLOCKING PORT B
	GPIO_PORTB_CR_R |= 0xFF;				// Allowing changes to all bits in PORT B
	GPIO_PORTB_AMSEL_R = 0;         // Disabling Analog
	GPIO_PORTB_AFSEL_R = 0;					// Disabling Alternate function
	GPIO_PORTB_PCTL_R = 0;					// GPIO clear bit PCTL
	GPIO_PORTB_DEN_R = 0xFF;				// Enabling Digital
	GPIO_PORTB_DIR_R = 0xFF;				// DIRECTION ---> OUTPUT

	/////// Initializing LCD with predefined commands   //////////
	lcd_cmd(four_bit_mode);
	lcd_cmd(Set5x7FontSize);
	lcd_cmd(lcd_EntryMode);
	lcd_cmd(lcd_Clear);
	lcd_cmd(lcd_DisplayOn);
	lcd_cmd(first_row);
}
////////// Sending command to LCD in 4-bit mode  /////////////
void lcd_cmd(unsigned char cmd){
	lcd_write(cmd & 0xF0, 0);							// Sending higher nibble of command
	lcd_write(cmd<<4, 0);									// Sending lower nibble of command
	if(cmd < 4){
		delay_ms (20);
	}
	else{
		delay_us (400);
	}
}

// Writing data to LCD
void lcd_write(unsigned char c, unsigned char ctrl){
	c &= 0XF0;								// Masking lower nibble
	ctrl &= 0x0F;							// Masking higher nibble
	GPIO_PORTB_DATA_R = c | ctrl;		// Sending data and control signals to PORT B
	GPIO_PORTB_DATA_R = c | ctrl | EN;    // Setting Enable (EN) signal
	delay_ms(50);                 //delay is 50 millisec.
	GPIO_PORTB_DATA_R = c;				// Clearing EN signal
	GPIO_PORTB_DATA_R = 0;				// Clearing data
}

//////////  Writing a character to LCD ///////////////
void lcd_char(unsigned char data){
	lcd_write(data&0xF0, RS);					// Sending higher nibble of data with RS (Register Select) signal
	lcd_write(data<<4, RS);						// Sending lower nibble of data with RS signal
	delay_us(40);
}

///////////  Writing a string to the first row of LCD  ///////////////
void lcd_str_1st_row( char *str){
	int i;
	lcd_cmd(first_row);
	for( i = 0; *str!=0; i++){
		lcd_char(*(str++),RS);
	}
}




