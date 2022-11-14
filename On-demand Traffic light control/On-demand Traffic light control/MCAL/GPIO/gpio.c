/*
 * gpio.c
 *
 * Created: 11/8/2022 1:29:03 PM
 *  Author: rafik
 */ 
#include "gpio.h"

EN_Error_t GPIO_INIT (uint8_t pin, uint8_t port, uint8_t direction)
{
	switch(port){
		case PORT_A:
			if(direction == INPUT)
				RESET_BIT(DDRA, pin);
			else if(direction == OUTPUT)
				SET_BIT(DDRA, pin);
			else
				return ERROR;
			break;
		
		case PORT_B:
			if(direction == INPUT)
				RESET_BIT(DDRB, pin);
			else if(direction == OUTPUT)
				SET_BIT(DDRB, pin);
			else
				return ERROR;
			break;
		
		case PORT_C:
			if(direction == INPUT)
				RESET_BIT(DDRC, pin);
			else if(direction == OUTPUT)
				SET_BIT(DDRC, pin);
			else
				return ERROR;
			break;
		
		case PORT_D:
			if(direction == INPUT)
				RESET_BIT(DDRD, pin);
			else if(direction == OUTPUT)
				SET_BIT(DDRD, pin);
			else
				return ERROR;
			break;
		
		default:
			return ERROR;
	}
	return OK;
}	

EN_Error_t GPIO_WRITE (uint8_t pin, uint8_t port, uint8_t data)
{
	switch(port){
		case PORT_A:
			if(data == LOW)
				RESET_BIT(PORTA, pin);
			else if(data == HIGH)
				SET_BIT(PORTA, pin);
			else
				return ERROR;
			break;
		
		case PORT_B:
			if(data == LOW)
				RESET_BIT(PORTB, pin);
			else if(data == HIGH)
				SET_BIT(PORTB, pin);
			else
				return ERROR;
			break;
		
		case PORT_C:
			if(data == LOW)
				RESET_BIT(PORTC, pin);
			else if(data == HIGH)
				SET_BIT(PORTC, pin);
			else
				return ERROR;
			break;
		
		case PORT_D:
			if(data == LOW)
				RESET_BIT(PORTD, pin);
			else if(data == HIGH)
				SET_BIT(PORTD, pin);
			else
				return ERROR;
			break;
		
		default:
			return ERROR;
	}
	return OK;
}	

uint8_t GPIO_READ (uint8_t pin, uint8_t port)
{
	uint8_t value = 0;
	switch(port){
		case PORT_A:
			value = GET_BIT(PINA, pin);
			break;
		
		case PORT_B:
			value = GET_BIT(PINB, pin);
			break;
		
		case PORT_C:
			value = GET_BIT(PINC, pin);
			break;
		
		case PORT_D:
			value = GET_BIT(PIND, pin);
			break;
		
		default:
			return ERROR;
	}
	return value;
}
EN_Error_t GPIO_TOGGLE (uint8_t pin, uint8_t port)
{
	switch(port)
	{
		case PORT_A:
			TOGGLE_BIT(PORTA, pin);
			break;
		
		case PORT_B:
			TOGGLE_BIT(PORTB, pin);
			break;
		
		case PORT_C:
			TOGGLE_BIT(PORTC, pin);
			break;
		
		case PORT_D:
			TOGGLE_BIT(PORTD, pin);
			break;
		default:
			return ERROR;
	}
	return OK;
}					
