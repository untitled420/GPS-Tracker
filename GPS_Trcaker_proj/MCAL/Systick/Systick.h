/*
 * Systick.h
 *
 * Created: 4/21/2024
 *  Author: Ahmed & Andrew
 */


#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>
#include "common_macros.h"
#include "tm4c123gh6pm.h"


/****************************************************************************************************************
												Some imprtant defintions
****************************************************************************************************************/

#define preload_value		0x00000000		//

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


/*
 * Description :
	Initializing the Systick timer with system's clk
 */
void Systick_INIT (void);

/*
 * Description :
 Function that makes delay by Micro seconds
*/
void delay_us(uint32_t count);

/*
 * Description :
 Function that makes delay by Milli seconds
*/
void delay_ms(uint32_t count);

/*
 * Description :
 Function that loads number of ticks to the RELOAD register
*/
void Systick_wait(uint32_t delay);
#endif /* SYSTICK_H_ */
