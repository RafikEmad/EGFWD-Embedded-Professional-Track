/*
 * button.c
 *
 * Created: 11/8/2022 6:37:36 PM
 *  Author: rafik
 */ 

#include "button.h"

// Initialize Button Pin
EN_Error_t BUTTON_INIT(uint8_t pin, uint8_t port)
{
	if(GPIO_INIT(pin, port, INPUT) == ERROR)
		return ERROR;
	return OK;
}

// read Button Pin
uint8_t BUTTON_READ(uint8_t pin, uint8_t port)
{
	uint8_t value;
	value = GPIO_READ(pin, port);
	return value;
}