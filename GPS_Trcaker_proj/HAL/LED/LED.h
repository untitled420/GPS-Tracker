/*
 * LED.h
 *
 * Created: 4/30/2024 10:45:39 PM
 *  Author: Ali Elsayed
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/GPIO/GPIO.h"

/************************************************************************/
/*           some important defintions                                  */
/************************************************************************/

//RGB LEDS for PORTF
#define RED					0x02
#define BLUE				0x04
#define GREEN				0x08

#define PF123_mask          0x0E
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*

/*
 * Description :
 * Initializing RGB LED in PORT F
 */
void RGBLED_Int(void);


/*
 * Description :
 * Turn ON a color in PortF Internal RGB LED	
 */
void RGBLED_ON(u8 color);


/*
 * Description :
 * Turn Off a color in PortF Internal RGB LED	 
 */
void RGBLED_OFF(u8 color);


/*
 * Description :
 * Turn Off a specific LED connected to some pin 
 */

void TurnOn_LED (u8	PORT, u8 PIN );

/*
 * Description :
 * Turn Off a specific LED connected to some pin 
 */
void TurnOff_LED (u8 PORT, u8 PIN );

#endif /* LED_H_ */