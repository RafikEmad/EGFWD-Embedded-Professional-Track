/*
 * timer.h
 *
 * Created: 11/8/2022 2:57:06 PM
 *  Author: rafik
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../GPIO/gpio.h"

//calculated delay parameter for 5 seconds
#define NUMBER_OF_OVERFLOWS_0_5s	2
#define	TIMER_INITIAL_VALUE			12
#define NUMBER_OF_OVERFLOWS_5s		20

//timers clock
#define TIMER_OFF			0
#define INTERNAL_1024		5

//modes
#define NORMAL_MODE		0X00

//prototypes
EN_Error_t TIMER0_INIT();
EN_Error_t TIMER0_START();
EN_Error_t TIMER0_STOP();
uint8_t DELAY_5s();
uint8_t DELAY_0_5s();


#endif /* TIMER_H_ */