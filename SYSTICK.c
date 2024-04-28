/*
 * SYSTICK.C
 *
 * Created: 4/24/2024 
 *  Author: Afifi , Andrew
 */ 

#include "SYSTICK.h"




/******************************************* 
 *Function: SysTick timer initialization   *
 *******************************************/ 
void SysTick_Init(void){
NVIC_ST_CTRL_R = 0;					              // To Disable systick during setup
NVIC_ST_RELOAD_R = 0X00FFFFFF ;		              // Maximum reload value (all 24 bits are ones)
NVIC_ST_CURRENT_R = 0;			                  // To Clear the counter 
NVIC_ST_CTRL_R = 0X05;					          // To Enable the counter and system CLK 
}


/******************************************* 
 *      Function: Delays by n counts       *
 *******************************************/
void systick_Wait (uint32_t counts) {
NVIC_ST_RELOAD_R = counts-1 ;                      // number of counts 
NVIC_ST_CURRENT_R = 0;			                   // To Clear the counter 
while ((NVIC_ST_CTRL_R & 0X00010000) == 0 ) {}     // Wait for COUNT bit to be = 1 
}


/******************************************* 
 *    Function: Delays by n microsecond    *
 *******************************************/
void systick_Wait_us (uint32_t delay_us) {
unsigned long i ;
for (i=0 ; i<delay_us ; i++){                       // each loop take 1us to complet --> total delay = delay_us * 1us 
    systick_Wait (16) ;
}
}


/******************************************* 
 *    Function: Delays by n millisecond    *
 *******************************************/
void systick_Wait_ms (uint32_t delay_ms) {
unsigned long i ;
for (i=0 ; i<delay_ms ; i++){                       // each loop take 1ms to complet --> total delay = delay_ms * 1ms 
    systick_Wait (16000) ;
}
}



