/*
 * EEPROM.c
 *
 * Created: 8/5/2024 6:13 AM
 *  Author: Ahmed Osama
 */ 

#include "../../tm4c123gh6pm.h"
#include "EEPROM.h"

uint32_t data_read = 0;

void EEPROMINIT(void){
	SYSCTL_RCGCEEPROM_R |= SYSCTL_RCGCEEPROM_R0;    // enable eprom clk
	while((SYSCTL_PREEPROM_R & SYSCTL_RCGCEEPROM_R0)==0); /// delay // stuck here using simulation 
	while((EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING) != 0 );   // wait untill 	(EEDONE) be clear (ready)
	if(((EEPROM_EESUPP_R & EEPROM_EESUPP_PRETRY) | (EEPROM_EESUPP_R & EEPROM_EESUPP_PRETRY ) ) != 0){
       //error , need to reach error handler
	}
	SYSCTL_SREEPROM_R |=  SYSCTL_SREEPROM_R0; //Reset the EEPROM module 
	SYSCTL_SREEPROM_R &= ~SYSCTL_SREEPROM_R0;
	while((SYSCTL_PREEPROM_R & SYSCTL_SREEPROM_R0)==0);  /// delay
	while((EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING) != 0 ); //  wait till be ready 
}



void EEPROM_Write(uint32_t address, float data) {
    while((EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING)!=0);     // Wait for the EEPROM to be ready
    // Set the address to write to
    EEPROM_EEBLOCK_R = address / 16;         // 16 words per block
    EEPROM_EEOFFSET_R = (address % 16);  // 4 words per offset
    EEPROM_EERDWR_R = data;    // Write the data THIS IS NEW BOODY
    
    while((EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING)!=0); // Wait for the write to complete
    // Check for any errors
    if(EEPROM_EESUPP_R & (EEPROM_EESUPP_PRETRY | EEPROM_EESUPP_ERETRY)) {
        // Handle error
    }
}



float EEPROM_Read(uint32_t address) {
    while((EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING)!=0);    // Wait for the EEPROM to be ready
    // Set the address to read from
    EEPROM_EEBLOCK_R = address / 16;        // 16 words per block
    EEPROM_EEOFFSET_R = (address % 16); // 4 words per offset REMOVE DIVIDE BY 4
    data_read = EEPROM_EERDWR_R;   // Read the data
    // Check for any errors
    if(EEPROM_EESUPP_R & (EEPROM_EESUPP_PRETRY | EEPROM_EESUPP_ERETRY)) {
        // Handle error
    }
    return data_read;
}


