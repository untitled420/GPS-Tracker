/*
 * GPS.h
 *
 * Created: 5/13/2024 12:31:31 PM
 *  Author: Abdelrahman Emad & Shams Khaled 
 */
 

#ifndef GPS_H_
#define GPS_H_


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "../../MCAL/UART/UART.h"
#include "../../MCAL/EEPROM/EEPROM.h"


/************************************************************************/
/*           some important defintions                                  */
/************************************************************************/
#define PI 3.142857


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*


/*
 * Description :
 * A Function to convert Radian angle to degress
 * it has 1 argument : arg 1 -> the angle in Radian
*/
float ToDEGREE(float angle);

/*
 * Description :
 * A Function to convert  angle in Degrees into Radian
 * it has 1 argument : arg 1 -> the angle in Degrees
*/
float ToRAD(float angle);

/*
 * Description :
 * A Function to Extract the desired data from a sequence of data sent from the GPS 
 * it has no arguments 
*/
void GPSread();

/*
 * Description :
 * A Function to calculate the distance between two consective coordinates read by the GPS
 * it has no arguments 
*/
float dist(void);



/*
 * Description :
 * A Function to calculate the distance between the currnt coordinate to the destination's
 * it has no arguments 
*/
float Finaldist(void);

/*
 * Description :
 * A Function to View the Readings of the GPS on the Serial through UART 0
 * it has no arguments 
*/
void GPS_test ();

/*
 * Description :
 * A Function to View the Readings of a given number on the Serial through UART 0
 * it has 2 arguments: arg 1 -> the string to be stored in the result, arg 2 -> the float number to be shown 
*/
void testing(char *str, float num);

#endif
