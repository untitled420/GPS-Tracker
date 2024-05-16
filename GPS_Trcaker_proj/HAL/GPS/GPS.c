/*
 * GPS.c
 *
 * Created: 5/13/2024 12:31:31 PM
 *  Author: Abdelrahman Emad & Shams Khaled 
 */
 
 #include "GPS.h"



const f32 FINAL_lng = 31.2778535, FINAL_lat =30.0643884; // Our Destination's Coordinates 
static uint8_t check = 0; 								//a variable to check that we recived the word "$GPRMC,", word right
f32 currentLat=0, currentLong=0; 						// variables to store the results of conversion
f32 oldLat, oldLong;									// variables to store the previous results before our current 
u8 num_readings = 0;									// indicator for how many readings we have 
u8 address= 1;								   		   //the intial address in EEPROM to save DATA
char Out_UART2[100]= "\0";							  // an array 
