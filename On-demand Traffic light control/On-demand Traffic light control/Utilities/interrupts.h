/*
 * interrupts.h
 *
 * Created: 11/8/2022 12:50:14 PM
 *  Author: rafik
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "bitmanipulation.h"
#include "registers.h"

//set global interrupt
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

//clear global interrupt
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

//int0 sense bits
#define  ISC00	0
#define  ISC01	1

//int0 pin
#define  INT0	6

//int vector
#define EXT_INT_0	__vector_1

//ISR definition
#define ISR(INT_VECT) \
void INT_VECT(void) __attribute__ ((signal, used)); \
void INT_VECT(void)

//Set int0 as rising edge
#define RISING_EDGE_BIT0() SET_BIT(MCUCR, ISC00)
#define RISING_EDGE_BIT1() SET_BIT(MCUCR, ISC01)

//enable external interrupt
#define INT0_ENABLE() SET_BIT(GICR, INT0)

//disable external interrupt
#define INT0_DISABLE() RESET_BIT(GICR, INT0)

#endif /* INTERRUPTS_H_ */