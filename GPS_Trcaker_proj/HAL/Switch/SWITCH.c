/*
 * SWITCH.c
 *
 * Created: 4/30/2024
 *  Author: Abdelrahman Awad
 */ 


#include "SWITCH.h"



void SW1_Int(void){
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;	// Unlock Port F commit register
	GPIO_PORTF_CR_R |= 0x10;			//Allow change to PF321
	GPIO_PORTF_AMSEL_R &= ~0x10;		//Disable analog function
	GPIO_PORTF_PCTL_R &= ~0x000F0000;	//GPIO clear bit PCTL
	GPIO_PORTF_DIR_R 	&= ~0x10;		//setting direction
	GPIO_PORTF_AFSEL_R &= ~0x10;		//no alternate function
	GPIO_PORTF_DEN_R 	|= 0x10;		// Enable Digital I/O function
	GPIO_PORTF_PUR_R	|= 0x10;
}


void SW2_Int(void){
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;	// Unlock Port F commit register
	GPIO_PORTF_CR_R |= 0x01;			//Allow change to PF321
	GPIO_PORTF_AMSEL_R &= ~0x01;		//Disable analog function
	GPIO_PORTF_PCTL_R &= ~0x0000000F;	//GPIO clear bit PCTL
	GPIO_PORTF_DIR_R 	&= ~0x01;		//setting direction
	GPIO_PORTF_AFSEL_R &= ~0x01;		//no alternate function
	GPIO_PORTF_DEN_R 	|= 0x01;		// Enable Digital I/O function
	GPIO_PORTF_PUR_R	|= 0x01;
}


u8 SW1_Input(void){

	return GPIO_PORTF_DATA_R & 0x10;
}

u8 SW2_Input(void){

	return GPIO_PORTF_DATA_R & 0x01;
}