/*
 * GPS_tracker.c
 *
 * Created: 4/21/2024 12:28:35 PM
 * Author : Marwan
 */ 

#include "APP/APP.h"


extern u8 status_flag;
extern u8 button2_in;

int main(){
	system_init(); //intialize the system

	while(1){
		
		get_readings(); //get the readings and status from the system
		delay_ms(800);	//wait for 0.8 seconds beween each update
		
		if(status_flag==0) //if we have reached the destination, terminate the program
		{
			break;
		}
	}

}

