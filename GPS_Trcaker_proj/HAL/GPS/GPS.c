/*
 * GPS.c
 *
 * Created: 5/13/2024 12:31:31 PM
 *  Author: Abdelrahman Emad & Shams Khaled 
 */
 
 #include "GPS.h"



const f32 FINAL_lng = 31.2778535, FINAL_lat =30.0643884; // Our Destination's Coordinates 
static uint8_t check = 0; 								//a variable to check that we received the word "$GPRMC,", word right
f32 currentLat=0, currentLong=0; 						// variables to store the results of conversion
f32 oldLat, oldLong;									// variables to store the previous results before our current 
u8 num_readings = 0;									// indicator for how many readings we have 
u8 address= 1;								   		   //the initial address in EEPROM to save DATA
char Out_UART2[100]= "\0";							  // an array 


void GPSread()
{
	char  GPSValues[100], parseValue[12][20], *token;
/*Here we Check on the sequence we recive if it's the right line of data we need*/
	f32 latitude = 0.0, longitude = 0.0, sec = 0.0, result = 0.0, min = 0.0;
	uint32_t index = 0, deg;
	char recived_char;
	do
	{
		recived_char = UART_RX(2);
		switch (recived_char)
		{
			case '$':
			check++;
			break;
			case 'G':
			check = check==1?2:0;
			break;
			case 'P':
			check = check==2?3:0;
			break;
			case 'R':
			check = check==3?4:0;
			break;
			case 'M':
			check = check==4?5:0;
			break;
			case 'C':
			check = check==5?6:0;
			break;
			case ',':
			if(check != 6) break;
			check=7;
			recived_char =  UART_RX(2);
			//get values in GPMRC until *A
			while (recived_char != '*') {
				GPSValues[index] = recived_char;
				recived_char =  UART_RX(2);
				index++;
			}
			//cut string GPS values put it in ParseValue
			index = 0;
			token = strtok(GPSValues, ",");//cut until you find ","
			//walk through other tokens
			while (token != NULL) {
				strcpy(parseValue[index], token);//copy what is in token into parseValue
				token = strtok(NULL, ",");
				index++;
			}
			/*if SaveValue[1] = "A" Active , or , "V" Void*/
			if (strcmp(parseValue[1], "A") == 0)
			{
				latitude = atof(parseValue[2]);			//convert latitude value from string to f32
				longitude = atof(parseValue[4]);		//convert longitude value from string to f32 
				/*caluclate latitude*/
				deg = latitude / 100.0;
				min = latitude - (f32)(deg * 100.0);
				sec = min / 60.00;
				result = deg + sec;
				
				oldLat = currentLat;
				currentLat = result;			//save the latitude reading
				testing(Out_UART2,currentLat); // show on UART0 to check the reading we have extracted
				
				
				/*calculate longitude*/
				deg = longitude / 100;
				min = longitude - (f32)(deg * 100);
				sec = min / 60.00;
				result = deg + sec;
				
				oldLong = currentLong;
				currentLong = result;    //save the longitude reading
				testing(Out_UART2,currentLong);
				
				/*Saving the results to the EEPROM*/
				EEPROM_Write(address,(currentLat*1000000)); //store the reading as an integer form
				EEPROM_Write(address+1,(currentLong*1000000));//store the reading as an integer form
				
				address +=2; //increament the address by 2, to be right for saving next readings
				num_readings++; //(lat, long);
				EEPROM_Write(0,num_readings);
			}
			else
			{
				check = 0;		// means that extracting the sequence of the word $GPRMC was wrong
			}

			break;
			default:
			check = 0;
			break;
		}
		
	} while (check != 7); //do until you find the last character right 
}

