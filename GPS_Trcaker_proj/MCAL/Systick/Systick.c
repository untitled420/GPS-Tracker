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


void Systick_wait(uint32_t delay){
	NVIC_ST_RELOAD_R = delay-1;			// delay-1 to handle the zero cycle
	NVIC_ST_CURRENT_R = 0;				// to empty the current value register
	while((NVIC_ST_CTRL_R & 0x00010000)==0){}; // wait until the counter finish counting and the Count flag is fired
}

void delay_ms(uint32_t count){
		//itirations for number of counts the user is deciding
		uint32_t i;
		for(i=0; i<count; i++){
			Systick_wait(16000);
		}
}

void delay_us(uint32_t count){
		uint32_t i;
		for(i=0; i<count; i++){
			Systick_wait(16);
		}
}

