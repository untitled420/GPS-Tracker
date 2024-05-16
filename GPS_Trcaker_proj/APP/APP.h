/*
 * APP.h
 *
 * Created: 5/1/2024 12:34:27 PM
 *  Author: Marwan & Shams & Ali
 */ 


#ifndef APP_H_
#define APP_H_


#include "../HAL/LED/LED.h"
#include "../HAL/SWITCH/SWITCH.h"
#include "../MCAL/Systick/Systick.h"
#include "../MCAL/UART/UART.h"
#include "../HAL/GPS/GPS.h"
#include "../MCAL/EEPROM/EEPROM.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/Buzzer/Buzzer.h"



/************************************************************************/
/*						functions prototypes                            */
/************************************************************************/

/*
 * Description :
 * Initializing the system
 */
void system_init();

/*
 * Description :
 * calculating distance from gps readings
 */
void get_readings();

/*
 * Description :
 * A function to make an action according to the distance or pressed switch
 */
void RGBLED_Status();

/*
 * Description :
 * A function to Send the Data stored in the EEPROM
 */
void EEPROM_send();



#endif /* APP_H_ */
