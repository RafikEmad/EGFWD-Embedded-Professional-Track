/*
 * timer.c
 *
 * Created: 11/8/2022 2:56:56 PM
 *  Author: rafik
 */ 

#include "timer.h"

EN_Error_t TIMER0_INIT(){
	TCCR0 = NORMAL_MODE;
	return OK;
}

EN_Error_t TIMER0_START(){
	TCCR0 |= INTERNAL_1024;
	return OK;
}

EN_Error_t TIMER0_STOP(){
	RESET_BIT(TCCR0, 0);
	RESET_BIT(TCCR0, 1);
	RESET_BIT(TCCR0, 2);
	return OK;
}

uint8_t DELAY_5s(){
	TCNT0 = TIMER_INITIAL_VALUE;
	uint8_t overflows = 0;
	TIMER0_START();
	uint8_t Flag = GET_BIT(TCCR0, 0);
	SET_BIT(TIFR, 0);
	while(overflows <= NUMBER_OF_OVERFLOWS_5s && Flag == HIGH){
		while(!GET_BIT(TIFR, 0) && Flag == HIGH);
		SET_BIT(TIFR, 0);
		overflows++;
		Flag = GET_BIT(TCCR0, 0);
	}
	TIMER0_STOP();
	return Flag;
}

uint8_t DELAY_0_5s(){
	TCNT0 = TIMER_INITIAL_VALUE;
	uint8_t overflows = 0;
	TIMER0_START();
	uint8_t Flag = GET_BIT(TCCR0, 0);
	SET_BIT(TIFR, 0);
	while(overflows <= NUMBER_OF_OVERFLOWS_0_5s && Flag == HIGH){
		while(!GET_BIT(TIFR, 0) && Flag == HIGH);
		SET_BIT(TIFR, 0);
		overflows++;
		Flag = GET_BIT(TCCR0, 0);
	}
	TIMER0_STOP();
	return Flag;
}