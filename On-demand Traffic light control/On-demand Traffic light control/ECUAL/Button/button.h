/*
 * button.h
 *
 * Created: 11/8/2022 6:37:24 PM
 *  Author: rafik
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/GPIO/gpio.h"

//button port
#define BUTTON_PORT	PORT_D

//button pin
#define BUTTON_PIN	2

//prototypes
EN_Error_t BUTTON_INIT		(uint8_t pin, uint8_t port);	// Initialize Button Pin
uint8_t BUTTON_READ			(uint8_t pin, uint8_t port);	// Read Button Pin


#endif /* BUTTON_H_ */