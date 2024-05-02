/*
 * APP.c
 *
 * Created: 5/1/2024 12:34:04 PM
 *  Author: Marwan
 */ 


#include "APP.h"
volatile uint32_t	distance;
u8 button2_in=1;
volatile u32 lat  = 0;
volatile u32 longt = 0;
u8 button_flag=1;


void system_init(){
	RGBLED_Int();		//to initialize the internal LEDS of PORTF
	SW2_Int();			//to initialize the internal switch of PORTF
	Systick_INIT();
	UART_INIT(2);		// enabling UART2 for GPS
	//GPS_int;			//for the GPS module "not ready yet"
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
