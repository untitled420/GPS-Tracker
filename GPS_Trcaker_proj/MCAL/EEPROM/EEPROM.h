/*
 * EEPROM.h
 *
 * Created: 8/5/2024 6:13 AM
 *  Author: abdallah tamer
 */ 

#ifndef EEPROM_H_
#define EEPROM_H_

#include <stdint.h>
#include "../../LIB/common_macros.h"
#include "../../tm4c123gh6pm.h"


/***************************
 *                              Functions Prototypes                           *
 ***************************/
 
/*
 * Description :
 * Initializing EEPROM and it's clock 
 */
 void EEPROMINIT(void); 
 
 /*
 * Description :
 * Function to write data from the EEPROM
 * Function need 2 arguments
 * user pass address from 0 to 512
 * Second arg : data to be stored
 */
void EEPROM_Write(uint32_t address, float data);

 /*
 * Description :
 * Function to read data from the EEPROM
 * user pass address from 0 to 512
 * Function need 1 argument
 */
float EEPROM_Read(uint32_t address);





#endif /* EEPROM_H_ */
