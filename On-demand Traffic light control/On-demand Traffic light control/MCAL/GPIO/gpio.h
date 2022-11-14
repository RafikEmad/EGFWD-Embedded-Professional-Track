/*
 * gpio.h
 *
 * Created: 11/8/2022 1:29:15 PM
 *  Author: rafik
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "../../Utilities/types.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/interrupts.h"
#include "../../Utilities/bitmanipulation.h"
#include "../../Utilities/error.h"


//states
#define INPUT	0
#define OUTPUT	1

#define OFF		0
#define ON		1

#define LOW		0
#define HIGH	1

//ports
#define PORT_A	'A'
#define PORT_B	'B'
#define PORT_C	'C'
#define PORT_D	'D'

//prototypes
EN_Error_t GPIO_INIT		(uint8_t pin, uint8_t port, uint8_t direction);	// Initialize GPIO Pin
EN_Error_t GPIO_WRITE		(uint8_t pin, uint8_t port, uint8_t state);		// Write data on Pin
uint8_t GPIO_READ			(uint8_t pin, uint8_t port);					// Read Pin
EN_Error_t GPIO_TOGGLE		(uint8_t pin, uint8_t port);					// Toggle Pin

#endif /* GPIO_H_ */