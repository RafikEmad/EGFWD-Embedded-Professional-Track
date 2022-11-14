/*
 * led.h
 *
 * Created: 11/8/2022 6:45:17 PM
 *  Author: rafik
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/Timer/timer.h"

//led pins
#define GREEN_LED	0
#define YELLOW_LED	1
#define RED_LED		2

//prototypes
EN_Error_t LED_INIT				(uint8_t pin, uint8_t port);								// Initialize LED Pin
EN_Error_t LED_ON				(uint8_t pin, uint8_t port);								// Turn LED ON
EN_Error_t LED_OFF				(uint8_t pin, uint8_t port);								// Turn LED OFF
EN_Error_t LED_TOGGLE			(uint8_t pin, uint8_t port);								// Toggle LED
EN_Error_t LED_BLINK_5s			(uint8_t pin, uint8_t port);								// Blink LED
EN_Error_t TWO_LED_BLINK_5s		(uint8_t pin, uint8_t port, uint8_t port1);					// Blink 2LED
EN_Error_t LED_ON_5s			(uint8_t pin, uint8_t port);								// Turn LED ON 5sec
EN_Error_t LEDS_ON_5S();																	// Turn 2 LED ON 5sec


#endif /* LED_H_ */