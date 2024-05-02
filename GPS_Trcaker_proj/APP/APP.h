/*
 * APP.h
 *
 * Created: 5/1/2024 12:34:27 PM
 *  Author: Marwan
 */ 


#ifndef APP_H_
#define APP_H_


#include "LED.h"
#include "SWITCH.h"
#include "Systick.h"
#include "UART.h"


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
uint32_t get_distance(u32 lat, u32 longt);

/*
 * Description :
 * A function to make an action according to the distance or pressed switch
 */
void RGBLED_Status();


#endif /* APP_H_ */