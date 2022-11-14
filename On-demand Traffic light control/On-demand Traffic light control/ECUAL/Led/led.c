/*
 * led.c
 *
 * Created: 11/8/2022 6:45:05 PM
 *  Author: rafik
 */ 
#include "led.h"

EN_Error_t LED_INIT(uint8_t pin, uint8_t port)
{
	if(GPIO_INIT(pin, port, OUTPUT) == ERROR)
		return ERROR;
	return OK;
}
EN_Error_t LED_ON(uint8_t pin, uint8_t port)
{
	if(GPIO_WRITE(pin, port, HIGH) == ERROR)
		return ERROR;
	return OK;
}

EN_Error_t LED_OFF(uint8_t pin, uint8_t port)
{
	if(GPIO_WRITE(pin, port, LOW) == ERROR)
		return ERROR;
	return OK;
}

EN_Error_t LED_TOGGLE(uint8_t pin, uint8_t port)
{
	if(GPIO_TOGGLE(pin, port) == ERROR)
		return ERROR;
	return OK;
}
	
EN_Error_t LED_BLINK_5s(uint8_t pin, uint8_t port)
{
	uint8_t i = 0;
	uint8_t Flag = HIGH;
	while(i < 3 && Flag == HIGH){
		if(LED_TOGGLE(pin, port) == ERROR)
		return ERROR;
		Flag = DELAY_0_5s();
		i++;
	}
	return OK;
}
EN_Error_t TWO_LED_BLINK_5s(uint8_t pin, uint8_t port, uint8_t port1)
{
	uint8_t i = 0;
	uint8_t Flag = HIGH;
	while(i < 10 && Flag == HIGH){
		LED_TOGGLE(pin, port);
		LED_TOGGLE(pin, port1);
		Flag = DELAY_0_5s();
		i++;
	}
	return OK;
}
EN_Error_t LED_ON_5s(uint8_t pin, uint8_t port)
{
	if(LED_ON(pin, port) == ERROR)
		return ERROR;
	DELAY_5s();
	return OK;
}


EN_Error_t LEDS_ON_5S()
{
	if((LED_ON(RED_LED, PORT_A) == ERROR))
		return ERROR;
	if((LED_ON(GREEN_LED, PORT_B) == ERROR))
		return ERROR;
	DELAY_5s();
	return OK;
}