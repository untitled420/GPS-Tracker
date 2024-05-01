/*
 * Systick.c
 *
 * Created: 4/21/2024
 *  Author: Ahmed & Andrew
 */
#include "Systick.h"


void Systick_INIT(void){
	NVIC_ST_CTRL_R = 0x0;				//Disabling the Systick timer
	NVIC_ST_RELOAD_R = preload_value;	//Pre-loading the timer
	NVIC_ST_CURRENT_R = 0x0;			// Initializing the current value in the register with zero
	NVIC_ST_CTRL_R = 0x05;				//enabling the systick time & and the source clk bits

}
