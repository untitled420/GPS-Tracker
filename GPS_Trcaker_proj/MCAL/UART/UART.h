//*****************************************************************************
//UART.h
// Author : abdallah tamer    30/4/2024
// I added some Macros Maskes , control for baud rate
//
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
#ifndef UART_H_
#define UART_H_

/****************************************************************************************************************
												  Baud Rate Controlling 
****************************************************************************************************************/
//Macros For All Baud Rates
#define IBRD_4800         208
#define IBRD_9600         104
#define IBRD_57600        17 
#define IBRD_115200       8

#define FBRD_4800         21
#define FBRD_9600         11
#define FBRD_57600        23 
#define FBRD_115200       44


#define IBRD              IBRD_9600 
// Controlling Baud Rate by chaging x  IBRD_x where x [4800, 9600, 57600, 115200]
#define FBRD              FBRD_9600
// Controlling Baud Rate by chaging x  FBRD_x where x [4800, 9600, 57600, 115200]


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Initializing UART By selecting the desired UART MODULE as Argument
 * Function Argument: 0 , 1 , 2 , 5 , 6 , 7  
 *  Arg  3,4 are refused to be used (No action if used)
*/
void UART_INIT(uint8_t UART_MODULE);



/*
 * Description :
 * Transmit Data From selected UART MODULE 
 * Function take 2 argument
 * First Arg --> UART MODULE
 * Second Arg -- Data to be transmitied 
 */
void UART_TX (uint8_t UART_MODULE ,char data);


/*
 * Description :
 * Recieve Data From selected UART MODULE 
 * Arg --> UART MODULE
 */
char UART_RX (uint8_t UART_MODULE );


/*
 * Description :
 * Getting data from Serial Window UART0
 * Function take 2 argument
 * First Arg --> Array Pointer to save data in it 
 * Second Arg -- Max number of chars allowed as input
 */
void GET_COMMAND (char *input, uint8_t max_command_length);


#endif // UART_H
