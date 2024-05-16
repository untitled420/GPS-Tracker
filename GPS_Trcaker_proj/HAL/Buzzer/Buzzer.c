/*
 * Buzzer.c
 *
 * Created: 14/5/2024 
 * Author: Ahmed Afifi
 */ 

#include "Buzzer.h"

void Buzzer_Init(){
	GPIO_setupPinDirection(Buzzer_PORT,Buzzer_PIN,PIN_OUTPUT);
}

void start_sound(u8 first_value){
	GPIO_writePin(Buzzer_PORT,Buzzer_PIN,first_value);
	delay_ms(500);
	GPIO_writePin(Buzzer_PORT,Buzzer_PIN,~first_value);
	delay_ms(250);
	GPIO_writePin(Buzzer_PORT,Buzzer_PIN,first_value);
	delay_ms(500);
	GPIO_writePin(Buzzer_PORT,Buzzer_PIN,~first_value);
	delay_ms(100);
}


void dest_sound(u8 first_value){
	GPIO_writePin(Buzzer_PORT,Buzzer_PIN,first_value);
	delay_ms(1250);
	GPIO_writePin(Buzzer_PORT,Buzzer_PIN,~first_value);
	delay_ms(250);
	GPIO_writePin(Buzzer_PORT,Buzzer_PIN,first_value);
	delay_ms(1250);
	GPIO_writePin(Buzzer_PORT,Buzzer_PIN,~first_value);
	delay_ms(250);
}