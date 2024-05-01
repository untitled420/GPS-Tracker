/*
 * SWITCH.h
 *
 * Created: 4/30/2024 
 *  Author: Abdelrahman Awad
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_

#include "GPIO.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*

/*
 * Description :
 * Initializing Switch 1 in PORT F
 */
void SW1_Int(void);

/*
 * Description :
 * Initializing Switch 2 in PORT F
 */
void SW2_Int(void);

/*
 * Description :
 * Initializing Switch 2 in PORT F
 */
u8 SW2_Input(void);

/*
 * Description :
 * Initializing Switch 2 in PORT F
 */
u8 SW1_Input(void);



#endif /* SWITCH_H_ */