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


void get_readings(){
	/*first we get the readings from the GPS*/
	GPSread();
	
	/*a condition to print "Distance=" pemenantly through walking*/
	if(num_readings !=0 && Intiate_Reading ==0){
		
	lcd_cmd(lcd_Clear);
	Out_LCD = "Distance=";
	lcd_str_2nd_row(Out_LCD);
	Intiate_Reading =1;
		
	}
	/*after reading and storing the coordinates, calculate the distance between the current and latest point
	*then accumlate this distance and show it on the LCD
	*/
	total_distance += dist();
	sprintf(Reading,"%.*f",0,total_distance);
	lcd_moveCursor(1,10);
	lcd_str(Reading);
	
	/*after then, show a Notification through the LEDs in the TIVA
	*if we are near,far or almost near the destination
	*/
	RGBLED_Status();
}


/*Here we Determine the User Status,whether he have reached his destination OR he is near it, OR he is still far away*/
void RGBLED_Status(){
	
	/*First, Calculate the distance between the current place and the destination*/
	f32 distance = Finaldist();
	char c = '\0';	//variable to recive data from PC
	
	/*Get the status of the Push Button*/
	button2_in= SW2_Input();
	
	/*Now, after calculating the distance, show the status according to it*/	
	if ((button2_in == LOGIC_LOW)||(distance<5)){ //if button 2 is pressed OR the distance less than 5 meters, turn the LED Blue
		RGBLED_OFF(PF123_mask);
		RGBLED_ON(BLUE);
		status_flag=0; //set flag to zero , so the other conditions fails
		
	/*You have reached the Place you want, So you have the option to send U and get your Data*/
		Out_LCD = "Here we are! :D";
		lcd_str_1st_row(Out_LCD);
		dest_sound(buzzer_status);
		lcd_cmd(lcd_Clear);
		Out_LCD = "Send U for data.";
		lcd_str_1st_row(Out_LCD);
		
		while (c != 'U' && c != 'u'){ //check if you have recived a U command or not
			c = UART_RX(0);
		}
		EEPROM_send();
		lcd_cmd(lcd_Clear);
		Out_LCD = "Thanks :D";
		lcd_str_1st_row(Out_LCD);
	}
	else if((distance >5)&&(distance<50)&&(status_flag)){ //if the distance less than 50 AND more than 5 meters , turn the LED to yellow
		Out_LCD = "Almost There!";
		lcd_str_1st_row(Out_LCD);
		RGBLED_OFF(PF123_mask);
		RGBLED_ON(GREEN|RED);
	}
	else if ((distance>50)&&(status_flag)){ //if the distance more than 50 and the button is not pressed , turn the LED to RED
		Out_LCD = "Go ON!";
		lcd_str_1st_row(Out_LCD);
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
