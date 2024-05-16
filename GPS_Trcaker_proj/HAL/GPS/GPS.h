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
