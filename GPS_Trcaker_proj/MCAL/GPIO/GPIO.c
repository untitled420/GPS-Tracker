/*
 * GPIO.c
 *
 * Created: 4/21/2024 12:31:49 PM
 *  Author: Marwan Yasser
 */ 
#include "GPIO.h"

void GPIO_INIT_PORTA(void){
	SYSCTL_RCGCGPIO_R |= 0x01;			//Port A clock
	while((SYSCTL_PRGPIO_R & 0x01)==0);	//Delay
	GPIO_PORTA_CR_R |= 0xFF;			//Allow change to the whole port
	GPIO_PORTA_AMSEL_R &= ~0xFF;		//Disable analog function
	GPIO_PORTA_PCTL_R &= ~0xFFFFFFFF;	//GPIO clear bit PCTL
	//GPIO_PORTA_DIR_R 	|= 0x80;		//setting direction, Depends on your use
	GPIO_PORTA_AFSEL_R &= ~0xFF;		//no alternate function
	GPIO_PORTA_DEN_R 	|= 0xFF;		// Enable Digital I/O function
}

void GPIO_INIT_PORTB(void){
	SYSCTL_RCGCGPIO_R |= 0x02;			//Port B clock
	while((SYSCTL_PRGPIO_R & 0x02)==0);	//Delay
	GPIO_PORTB_CR_R |= 0xFF;			//Allow change to the whole port
	GPIO_PORTB_AMSEL_R &= ~0xFF;		//Disable analog function
	GPIO_PORTB_PCTL_R &= ~0xFFFFFFFF;	//GPIO clear bit PCTL
	//GPIO_PORTB_DIR_R 	|= 0x00;		//setting direction, Depends on your use
	GPIO_PORTB_AFSEL_R &= ~0xFF;		//no alternate function
	GPIO_PORTB_DEN_R 	|= 0xFF;		// Enable Digital I/O function
	//GPIO_PORTB_DATA_R	&= ~0x0E;		//initialization, Depends on your use
}

void GPIO_INIT_PORTC(void){
	SYSCTL_RCGCGPIO_R |= 0x04;			//Port C clock
	while((SYSCTL_PRGPIO_R & 0x04)==0);	//Delay
	GPIO_PORTC_CR_R |= 0xF0;			//Allow change to the whole port
	GPIO_PORTC_AMSEL_R &= ~0xFF;		//Disable analog function
	GPIO_PORTC_PCTL_R &= ~0xFFFF0000;	//GPIO clear bit PCTL
	//GPIO_PORTC_DIR_R 	|= 0x00;		//setting direction, Depends on your use
	GPIO_PORTC_AFSEL_R &= ~0xFF;		//no alternate function
	GPIO_PORTC_DEN_R 	|= 0xFF;		// Enable Digital I/O function
	//GPIO_PORTC_DATA_R	&= ~0x0E;		//initialization, Depends on your use
}


void GPIO_INIT_PORTD(void){
	SYSCTL_RCGCGPIO_R |= 0x08;			//Port D clock
	while((SYSCTL_PRGPIO_R & 0x08)==0);	//Delay
	GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;	// Unlock Port D commit register
	GPIO_PORTD_CR_R |= 0xFF;			//Allow change to the whole port
	GPIO_PORTD_AMSEL_R &= ~0xFF;		//Disable analog function
	GPIO_PORTD_PCTL_R &= ~0xFFFFFFFF;	//GPIO clear bit PCTL
	//GPIO_PORTD_DIR_R 	|= 0x00;		//setting direction, Depends on your use
	GPIO_PORTD_AFSEL_R &= ~0xFF;		//no alternate function
	GPIO_PORTD_DEN_R 	|= 0xFF;		// Enable Digital I/O function
}

void GPIO_INIT_PORTE(void){
	SYSCTL_RCGCGPIO_R |= 0x10;			//Port D clock
	while((SYSCTL_PRGPIO_R & 0x10)==0);	//Delay
	GPIO_PORTE_CR_R |= 0x1F;			//Allow change to the whole port
	GPIO_PORTE_AMSEL_R &= ~0x1F;		//Disable analog function
	GPIO_PORTE_PCTL_R &= ~0x000FFFFF;	//GPIO clear bit PCTL
	//GPIO_PORTE_DIR_R 	|= 0x20;		//setting direction, Depends on your use
	GPIO_PORTE_AFSEL_R &= ~0x1F;		//no alternate function
	GPIO_PORTE_DEN_R 	|= 0x1F;		// Enable Digital I/O function
}


void GPIO_INIT_PORTF(void){
	SYSCTL_RCGCGPIO_R |= 0x20;			//Port D clock
	while((SYSCTL_PRGPIO_R & 0x20)==0);	//Delay
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;	// Unlock Port D commit register
	GPIO_PORTF_CR_R |= 0x1F;			//Allow change to the whole port
	GPIO_PORTF_AMSEL_R &= ~0x1F;		//Disable analog function
	GPIO_PORTF_PCTL_R &= ~0x000FFFFF;	//GPIO clear bit PCTL
	//GPIO_PORTF_DIR_R 	|= 0x00;		//setting direction, Depends on your use
	GPIO_PORTF_AFSEL_R &= ~0x1F;		//no alternate function
	GPIO_PORTF_DEN_R 	|= 0x1F;		// Enable Digital I/O function
}


void GPIO_setupPinDirection(u8 port_num, u8 pin_num, GPIO_PinDirectionType direction)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(GPIO_PORTA_DIR_R,pin_num);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_DIR_R,pin_num);
			}
			break;
		case PORTB_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(GPIO_PORTB_DIR_R,pin_num);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTB_DIR_R,pin_num);
			}
			break;
		case PORTC_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(GPIO_PORTC_DIR_R,pin_num);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTC_DIR_R,pin_num);
			}
			break;
		case PORTD_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(GPIO_PORTD_DIR_R,pin_num);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTD_DIR_R,pin_num);
			}
		case PORTE_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(GPIO_PORTE_DIR_R,pin_num);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTE_DIR_R,pin_num);
			}
			break;
		case PORTF_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(GPIO_PORTF_DIR_R,pin_num);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTF_DIR_R,pin_num);
			}
			break;
		}
	}
}



void GPIO_writePin(u8 port_num, u8 pin_num, u8 value)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the pin value as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(GPIO_PORTA_DATA_R,pin_num);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_DATA_R,pin_num);
			}
			break;
		case PORTB_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(GPIO_PORTB_DATA_R,pin_num);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTB_DATA_R,pin_num);
			}
			break;
		case PORTC_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(GPIO_PORTC_DATA_R,pin_num);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTC_DATA_R,pin_num);
			}
			break;
		case PORTD_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(GPIO_PORTD_DATA_R,pin_num);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTD_DATA_R,pin_num);
			}
			break;
		case PORTE_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(GPIO_PORTE_DATA_R,pin_num);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTE_DATA_R,pin_num);
			}
			break;
		case PORTF_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(GPIO_PORTF_DATA_R,pin_num);
			}
			else
			{
				CLEAR_BIT(GPIO_PORTF_DATA_R,pin_num);
			}
			break;
		}
	}
}





