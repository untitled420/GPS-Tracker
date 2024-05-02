//*****************************************************************************
//
//
//Authors :Ahmed Osama Mohamed      25/4/2024    11:09 pm
//                edited            28/4/2024        4:24 am
//                     UART Generic  Setup Function   
// This function setup UART, Selection of UART is done by passing the need one as an argument
/////// in this file there is Transmision , Recieving Functions 
//*****************************************************************************
#include "stdint.h"
#include "tm4c123gh6pm.h"
#include <string.h>
#include "UART.h"
#include "GPIO.h"

void UART_INIT(uint8_t UART_MODULE){
switch (UART_MODULE) {
    case 0: // SETUP UART0     PA0 ->Rx , PA1 ->Tx
		   SYSCTL_RCGCUART_R    |=   SYSCTL_RCGCUART_R0;      //activate UART clock
           SYSCTL_RCGCGPIO_R    |=   SYSCTL_RCGCGPIO_R0;      // activate port clock
           while((SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R0 )== 0 );
           UART0_CTL_R          &=  ~ UART_CTL_UARTEN ;       // disable UART before setting BRD values
           UART0_IBRD_R          =     IBRD ;                 // Assign Integer part to Intger Baud Rate Div	
		   UART0_FBRD_R          =     FBRD ;                 // Assign Integer part to Fractional Baud Rate Div
		   UART0_LCRH_R          =    (UART_LCRH_FEN | UART_LCRH_WLEN_8);   // Enable parameters (8 Bit word length, FIFO , number of stop bits)
		   UART0_CTL_R          |=    (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);      // ENABLE (RXE, TXE, UART)
		   GPIO_PORTA_AFSEL_R   |=    (BIT0 | BIT1 ) ;               //MASK TO ENABLE ALTERNATE FUNCTION FOR UART
		   GPIO_PORTA_PCTL_R     =    (GPIO_PORTA_PCTL_R & ~(GPIO_PCTL_PA0_U0RX | GPIO_PCTL_PA1_U0TX) ) | (GPIO_PCTL_PA0_U0RX | GPIO_PCTL_PA1_U0TX);  //RESET VALUE OF PCTL FIRST THEN, MASK TO CONFIGURE  UART ALTERNATE FUNCTION Rx , Tx
		   GPIO_PORTA_DEN_R     |=    (BIT0 | BIT1 );   						// ENABLE DIGITAL I/O 
		   GPIO_PORTA_AMSEL_R   &=  ~ (BIT0 | BIT1 ); 					    // DISABLE ANALOG FUNCTION 
    break;
    case 1:  // SETUP UART1    PB0 ->Rx , PB1 ->Tx
           SYSCTL_RCGCUART_R    |=     SYSCTL_RCGCUART_R1;  
           SYSCTL_RCGCGPIO_R	|=     SYSCTL_RCGCGPIO_R1;   
           while((SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R1 )== 0 );
           UART1_CTL_R          &= ~   UART_CTL_UARTEN ;      
           UART1_IBRD_R          =     IBRD ;              
		   UART1_FBRD_R          =     FBRD ;               
		   UART1_LCRH_R          =    (UART_LCRH_FEN | UART_LCRH_WLEN_8); 
		   UART1_CTL_R          |=    (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
		   GPIO_PORTB_AFSEL_R   |=    (BIT0 | BIT1 ); 
		   GPIO_PORTB_PCTL_R     =    (GPIO_PORTB_PCTL_R & ~(GPIO_PCTL_PB0_U1RX | GPIO_PCTL_PB1_U1TX) ) | (GPIO_PCTL_PB0_U1RX | GPIO_PCTL_PB1_U1TX);
		   GPIO_PORTB_DEN_R     |=    (BIT0 | BIT1 ); 
		   GPIO_PORTB_AMSEL_R   &=  ~ (BIT0 | BIT1 ); 
    break;
	  case 2:  // SETUP UART2    PD6 ->Rx , PD7 ->Tx
		   SYSCTL_RCGCUART_R    |=     SYSCTL_RCGCUART_R2;  
           SYSCTL_RCGCGPIO_R	|=     SYSCTL_RCGCGPIO_R3;   
           while((SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R3 )== 0 );
     	   GPIO_PORTD_LOCK_R     =     GPIO_LOCK_KEY;
           GPIO_PORTD_CR_R      |=    (BIT6 | BIT7 )   ;  
           UART2_CTL_R          &= ~   UART_CTL_UARTEN ;      
           UART2_IBRD_R          =     IBRD ;            	
		   UART2_FBRD_R          =     FBRD ;               
		   UART2_LCRH_R          =    (UART_LCRH_FEN | UART_LCRH_WLEN_8); 
		   UART2_CTL_R          |=    (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN); 
		   GPIO_PORTD_AFSEL_R   |=    (BIT6 | BIT7 ) ;
		   GPIO_PORTD_PCTL_R     =    (GPIO_PORTD_PCTL_R & ~(GPIO_PCTL_PD6_U2RX | GPIO_PCTL_PD7_U2TX) ) | (GPIO_PCTL_PD6_U2RX | GPIO_PCTL_PD7_U2TX);
	  	   GPIO_PORTD_DEN_R     |=    (BIT6 | BIT7 ) ; 
	  	   GPIO_PORTD_AMSEL_R   &=  ~ (BIT6 | BIT7 ) ;  
    break;
/************************************************************************************************/
	  case 3:   // SETUP UART3    PC6 , PC7 // Refused to be used
    break;			
	  case 4:  // SETUP UART4    PC4 , PC5 // Refused to be used
	  break;
/************************************************************************************************/
		case 5:  // SETUP UART5    PE4 ->Rx , PE5 ->Tx
		   SYSCTL_RCGCUART_R    |=     SYSCTL_RCGCUART_R5;  
           SYSCTL_RCGCGPIO_R	|=     SYSCTL_RCGCGPIO_R4;   
           while((SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R4 )== 0 );
           UART5_CTL_R          &= ~   UART_CTL_UARTEN ;      
           UART5_IBRD_R          =     IBRD ;              
		   UART5_FBRD_R          =     FBRD ;             
		   UART5_LCRH_R          =    (UART_LCRH_FEN | UART_LCRH_WLEN_8);  
		   UART5_CTL_R          |=    (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN); 
		   GPIO_PORTE_AFSEL_R   |=    (BIT4 | BIT5 ); 
	       GPIO_PORTE_PCTL_R     =    (GPIO_PORTE_PCTL_R & ~ (GPIO_PCTL_PE4_U5RX | GPIO_PCTL_PE5_U5TX) ) | (GPIO_PCTL_PE4_U5RX | GPIO_PCTL_PE5_U5TX) ;
		   GPIO_PORTE_DEN_R     |=    (BIT6 | BIT7 ); 
		   GPIO_PORTE_AMSEL_R   &=  ~ (BIT6 | BIT7 ); 
    break;
   	case 6:  // SETUP UART6    PD4 ->Rx , PD5 ->Tx
		   SYSCTL_RCGCUART_R    |=     SYSCTL_RCGCUART_R6;  
           SYSCTL_RCGCGPIO_R	|=     SYSCTL_RCGCGPIO_R3;   
           while((SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R3 )== 0 );
	       GPIO_PORTD_LOCK_R     =     GPIO_LOCK_KEY;
           GPIO_PORTD_CR_R      |=    (BIT4 | BIT5 );  
           UART6_CTL_R          &= ~   UART_CTL_UARTEN ;      
           UART6_IBRD_R          =     IBRD ;              
	       UART6_FBRD_R          =     FBRD ;             
		   UART6_LCRH_R          =    (UART_LCRH_FEN | UART_LCRH_WLEN_8);  
		   UART6_CTL_R          |=    (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN); 
		   GPIO_PORTD_AFSEL_R   |=    (BIT4 | BIT5 ); 
		   GPIO_PORTD_PCTL_R     =    (GPIO_PORTD_PCTL_R & ~ (GPIO_PCTL_PD4_U6RX | GPIO_PCTL_PD5_U6TX) ) | (GPIO_PCTL_PD4_U6RX | GPIO_PCTL_PD5_U6TX) ;
		   GPIO_PORTD_DEN_R     |=    (BIT4 | BIT5 ); 
		   GPIO_PORTD_AMSEL_R   &=  ~ (BIT4 | BIT5 ); 
    break;
		case 7:  // SETUP UART7    PE0 ->Rx , PE1 ->Tx
		   SYSCTL_RCGCUART_R    |=     SYSCTL_RCGCUART_R5;  
           SYSCTL_RCGCGPIO_R    |=     SYSCTL_RCGCGPIO_R4;   
           while((SYSCTL_RCGCGPIO_R & SYSCTL_RCGCGPIO_R4 )== 0 );
           UART7_CTL_R          &= ~   UART_CTL_UARTEN ;      
           UART7_IBRD_R          =     IBRD ;              
		   UART7_FBRD_R          =     FBRD ;             
		   UART7_LCRH_R          =    (UART_LCRH_FEN | UART_LCRH_WLEN_8);  
		   UART7_CTL_R          |=    (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN); 
		   GPIO_PORTE_AFSEL_R   |=    (BIT0 | BIT1 ); 
  		   GPIO_PORTE_PCTL_R     =    (GPIO_PORTE_PCTL_R & ~ (GPIO_PCTL_PE0_U7RX | GPIO_PCTL_PE1_U7TX) ) | (GPIO_PCTL_PE0_U7RX | GPIO_PCTL_PE1_U7TX) ;
		   GPIO_PORTE_DEN_R     |=    (BIT0 | BIT1 ); 
		   GPIO_PORTE_AMSEL_R   &=  ~ (BIT0 | BIT1 ); 			
	  break;
    default:
		break;
}
}



void UART_TX (uint8_t UART_MODULE ,char data){
	switch (UART_MODULE) {
    case 0:   
		    	 while((UART0_FR_R & UART_FR_TXFF)!= 0); 	// Check data availability by checking FIFO FULL , break loop if FIFO NOT FULL
           UART0_DR_R = data ;
		break;
		case 1:
		    	 while((UART1_FR_R & UART_FR_TXFF)!= 0); 
           UART1_DR_R = data ;			
		break;
		case 2:
		    	 while((UART2_FR_R & UART_FR_TXFF)!= 0); 
           UART2_DR_R = data ;			
		break;
/************************************************************************************************/
	  case 3:   // SETUP UART3    PC6 , PC7 // Refused to be used
    break;			
	  case 4:  // SETUP UART4    PC4 , PC5 // Refused to be used
	  break;
/************************************************************************************************/
		case 5:
		    	 while((UART5_FR_R & UART_FR_TXFF)!= 0); 
           UART5_DR_R = data ;					
		break;
		case 6:
		    	 while((UART6_FR_R & UART_FR_TXFF)!= 0); 
           UART6_DR_R = data ;					
		break;
		case 7:
		    	 while((UART7_FR_R & UART_FR_TXFF)!= 0); 
           UART7_DR_R = data ;					
		break;		
		default:
		break;
	}
}



char UART_RX (uint8_t UART_MODULE ){
switch (UART_MODULE) {
    case 0:  
           while ((UART0_FR_R & UART_FR_RXFE) != 0); 			  	// Check data availability by checking FIFO Empty , break loop if FIFO NOT Empty
					 return ((uint8_t) UART0_DR_R & UART_DR_DATA_M);    // masking UART Data register with 0xFF to remove error flages bits
		break;
		case 1:
		    	 while ((UART1_FR_R & UART_FR_RXFE) != 0); 
					 return ((uint8_t) UART1_DR_R & UART_DR_DATA_M);  
		break;
		case 2:
		    	while ((UART2_FR_R & UART_FR_RXFE) != 0); 
					return ((uint8_t) UART2_DR_R & UART_DR_DATA_M);  	
		break;
/************************************************************************************************/
	  case 3:   // SETUP UART3    PC6 , PC7 // Refused to be used
      break;			
	  case 4:  // SETUP UART4    PC4 , PC5 // Refused to be used
	  break;
/************************************************************************************************/
		case 5:
		    	 while ((UART5_FR_R & UART_FR_RXFE) != 0); 
					 return ((uint8_t) UART5_DR_R & UART_DR_DATA_M);  		
		break;
		case 6:
		    	 while ((UART6_FR_R & UART_FR_RXFE) != 0); 
					 return ((uint8_t) UART6_DR_R & UART_DR_DATA_M);  			
		break;
		case 7:
		    	while ((UART7_FR_R & UART_FR_RXFE) != 0); 
					return ((uint8_t) UART7_DR_R & UART_DR_DATA_M);  			
		break;		
		default: 	
			   return 0;  	
		break;
	}
// Return 0 in case of wrong calling
  return 0;  
}

//*****************************************************************************
//
//     Authors :abdallah tamer      30/4/2024    5:09 pm
//           
//*****************************************************************************                 

void GET_COMMAND (char *input, uint8_t max_command_length) {
  char element = 0 , i ;
	for(i = 0 ; i < max_command_length ; i++){     // looping till the max number of available chars sent 
	    element = UART_RX(0);                      // receive element 
		if(element  == '\n' || element  == '\r' ){   // break if input was enter
			break;
		}else{ 
			input[i] = element ;
  		UART_TX(0,element);  //  important in Serial Window --> Echo characters typed in Command Window
		}
	}
}
