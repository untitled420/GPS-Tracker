/*
 * LED.c
 *
 * Created: 4/30/2024 
 *  Author: Ali Elsayed
 */ 
#include "LED.h"


void RGBLED_Int(void){
	SYSCTL_RCGCGPIO_R |= 0x20;			//Port F clock
	while((SYSCTL_PRGPIO_R & 0x20)==0);	//Delay
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;	// Unlock Port F commit register
	GPIO_PORTF_CR_R |= 0x0E;			//Allow change to PF321
	GPIO_PORTF_AMSEL_R &= ~0x0E;		//Disable analog function
	GPIO_PORTF_PCTL_R &= ~0x0000FFF0;	//GPIO clear bit PCTL
	GPIO_PORTF_DIR_R 	|= 0x0E;		//setting direction
	GPIO_PORTF_AFSEL_R &= ~0x0E;		//no alternate function
	GPIO_PORTF_DEN_R 	|= 0x1F;		// Enable Digital I/O function
	GPIO_PORTF_DATA_R	&= ~0x0E;		//initialization to leds to zero(off)
}



void RGBLED_ON(u8 color){
	GPIO_PORTF_DATA_R |= color;
}


void RGBLED_OFF(u8 color){
	GPIO_PORTF_DATA_R &= ~color;
}


void TurnOn_LED (u8	PORT, u8 PIN ){
		
	GPIO_setupPinDirection(PORT, PIN, PIN_OUTPUT);
	GPIO_writePin(PORT, PIN, LOGIC_HIGH);
}

void TurnOff_LED (u8 PORT, u8 PIN ){
	
	GPIO_setupPinDirection(PORT, PIN, PIN_OUTPUT);
	GPIO_writePin(PORT, PIN, LOGIC_LOW);
}
