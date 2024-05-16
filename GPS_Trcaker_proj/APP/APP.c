/*
 * APP.c
 *
 * Created: 5/1/2024 12:34:04 PM
 *  Author: Marwan Yasser & Shams Khaled& Ali Elsayed
 */ 


#include "APP.h"

char * Out_LCD;						// a pointer to a string to send data for LCD
char Reading[100]="\0";		//an array to send readings to the LCD
char Out_UART[100]= "\0";	//an array to send data for the PC for UART0 
u8 buzzer_status = 1;			// a buzzer status variable to intiate it with an ON or OFF sound
u8 button2_in=1;					// used for checking the Output of the switch 
u8 status_flag = 1;				// a variable to terminate from the program when we reach our destination OR the switch is pressed
volatile f32 total_distance=0;	//the accumlated calculated distance 
volatile u8 Intiate_Reading =0; //a dummy variable for printing "Distance=" on the screen during the operation
extern u8 address;							//the number of addresses we have stored data in, inside the EEPROM
extern u8 num_readings;					// number of (lat,long) readings we have


void system_init(){
	UART_INIT(0);		//initialize UART0 for PC communication
	UART_INIT(2);		//initialize UART2 for GPS communication
	Systick_INIT();	//initialize the Systick Timer, for delays requied
	lcd_init();			//initialize LCD for showing the distance and status 
	Buzzer_Init();	//initialize the Buzzer PIN
	EEPROMINIT(); 	//initialize the EEPROM for storing Data 
	RGBLED_Int();		//to initialize the internal LEDS of PORTF
	SW2_Int();			//initialize SW2 in the Tiva kit 
	
	/*Welcoming message*/
	Out_LCD = " Welcome to our ";
	lcd_str(Out_LCD);
	Out_LCD = "GPS Tracking Sys";
	lcd_str_2nd_row(Out_LCD);
	delay_ms(500);
	lcd_cmd(lcd_Clear);
	
	/*Loading status till the GPS Reads coordinates*/
	Out_LCD = "Loading...";
	lcd_str(Out_LCD);
	start_sound(buzzer_status);
}


uint32_t get_distance(u32 lat, u32 longt){
	/*will be ready with the gps module
	 *just for testing i will increment the value of distance gradually
	 */
	distance++;
	delay_ms(1000);	
	return distance;
}

void RGBLED_Status(){
	distance = get_distance(lat, longt);
	button2_in = SW2_Input();
	if ((button2_in == LOGIC_LOW)||(distance>100)){ //if button 2 is pressed OR the distance exceeds 100 meters, turn the LED GREEN
		RGBLED_OFF(PF123_mask);
		RGBLED_ON(GREEN);
		button_flag=0; //set flag to zero , so the other conditions fails
		
	}
	else if((distance <100)&&(distance>95)&&(button_flag)){ //if the distance less than 100 AND more than 95 meters , turn the LED to yellow
		RGBLED_OFF(PF123_mask);
		RGBLED_ON(GREEN|RED);
	}
	else if ((distance<95)&&(button_flag)){ //if the distance less than 95 AND the button is not pressed , turn the LED to RED
		RGBLED_OFF(PF123_mask);
		RGBLED_ON(RED);
	}
	 
}



/*Here we send the Data stored from the EEPROM*/
void EEPROM_send(){
	int address_eeprom; 
	int final_address = ((int) EEPROM_Read(0)) - 1; //the final address we need to access
	testing(Out_UART, (f32) (final_address));
  for (address_eeprom = 1 ; address_eeprom <= 2 * final_address ; address_eeprom++ ){
		testing(Out_UART,(f32)(EEPROM_Read(address_eeprom))/1000000.0);
		}
	
}