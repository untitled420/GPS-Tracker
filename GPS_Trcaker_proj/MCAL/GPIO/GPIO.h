/*
 * GPIO.h
 *
 * Created: 4/21/2024 12:32:15 PM
 *  Author: Marwan Yasser
 */ 


#ifndef GPIO_H_
#define GPIO_H_


#include <stdint.h>
#include "std_types.h"
#include "tm4c123gh6pm.h"
#include "common_macros.h"
/****************************************************************************************************************
												Some imprtant defintions
****************************************************************************************************************/
#define NUM_OF_PORTS		6
#define NUM_OF_PINS			8


#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3
#define PORTE_ID               4
#define PORTF_ID               5


#define PIN0				0
#define PIN1				1
#define PIN2				2
#define PIN3				3
#define PIN4				4
#define PIN5				5
#define PIN6				6
#define PIN7				7
#define NULL			((void*)0)

#define BIT0				0x1
#define BIT1				0x2
#define BIT2				0x4
#define BIT3				0x8
#define BIT4				0x10
#define BIT5				0x20
#define BIT6				0x40
#define BIT7				0x80



#define GPIO_LOCK_KEY   0x4C4F434B  // Unlocks the GPIO_CR register



/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 * Initializing PORT A for General Purpose IO
 */
void GPIO_INIT_PORTA(void);

/*
 * Description :
 * Initializing PORT B for General Purpose IO
 */
void GPIO_INIT_PORTB(void);

/*
 * Description :
 * Initializing PORT C for General Purpose IO
 */
void GPIO_INIT_PORTC(void);

/*
 * Description :
 * Initializing PORT D for General Purpose IO
 */
void GPIO_INIT_PORTD(void);

/*
 * Description :
 * Initializing PORT E for General Purpose IO
 */
void GPIO_INIT_PORTE(void);

/*
 * Description :
 * Initializing PORT F for General Purpose IO
 */
void GPIO_INIT_PORTF(void);



/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(u8 port_num, u8 pin_num, GPIO_PinDirectionType direction);
/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin( u8 port_num, u8 pin_num, u8 value);

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
u8 GPIO_readPin(u8 port_num,u8 pin_num);


#endif /* GPIO_H_ */
