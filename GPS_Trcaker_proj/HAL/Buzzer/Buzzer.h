/*
 * Buzzer.h
 *
 * Created: 14/5/2024 
 * Author: Ahmed Afifi
 */ 

#ifndef BUZZER_H_
#define BUZZER_H_

#include "../../MCAL/Systick/Systick.h"
#include "../../MCAL/GPIO/GPIO.h"


#define Buzzer_PORT PORTB_ID
#define Buzzer_PIN 	PIN7


void Buzzer_Init();

void start_sound(u8 first_value);

void dest_sound(u8 first_value);

#endif /*BUZZER_H*/