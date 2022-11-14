/*
 * registers.h
 *
 * Created: 11/8/2022 11:51:20 AM
 *  Author: rafik
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"

//==============================
//GPIO REGISTERS
//==============================

//PORTA
#define PINA			(*((volatile uint8_t*)(0x39)))			// PORTA Status Register
#define DDRA			(*((volatile uint8_t*)(0x3A)))			// PORTA Data Direction Register
#define PORTA			(*((volatile uint8_t*)(0x3B)))			// PORTA Data Register

//PORTB
#define PINB			(*((volatile uint8_t*)(0x36)))			// PORTB Status Register
#define DDRB			(*((volatile uint8_t*)(0x37)))			// PORTB Data Direction Register
#define PORTB			(*((volatile uint8_t*)(0x38)))			// PORTB Data Register

//PORTC
#define PINC			(*((volatile uint8_t*)(0x33)))			// PORTC Status Register
#define DDRC			(*((volatile uint8_t*)(0x34)))			// PORTC Data Direction Register
#define PORTC			(*((volatile uint8_t*)(0x35)))			// PORTC Data Register

//PORTD
#define PIND			(*((volatile uint8_t*)(0x30)))			// PORTD Status Register
#define DDRD			(*((volatile uint8_t*)(0x31)))			// PORTD Data Direction Register
#define PORTD			(*((volatile uint8_t*)(0x32)))			// PORTD Data Register

//==============================
//EXTERNAL INTERRUPTS REGISTERS
//==============================

#define MCUCR			(*((volatile uint8_t*)(0x55)))			// MCU Control Register
#define MCUCSR			(*((volatile uint8_t*)(0x54)))			// MCU Control and Status Register
#define GIFR			(*((volatile uint8_t*)(0x5A)))			// General Interrupt Flag Register
#define GICR			(*((volatile uint8_t*)(0x5B)))			// General Interrupt Control Register

//==============================
//TIMER REGISTERS
//==============================

#define TCNT0			(*((volatile uint8_t*)(0x52)))			// Timer0 Register
#define TCCR0			(*((volatile uint8_t*)(0x53)))			// Timer0 Control Register
#define TIFR			(*((volatile uint8_t*)(0x58)))			// Timer0 Interrupt Flag Register
#define TIMSK			(*((volatile uint8_t*)(0x59)))			// Timer0 Interrupt Mask Register

//==============================
//STATUS REGISTER
//==============================

#define SREG			(*((volatile uint8_t*)(0x5F)))			// AVR Status Register


#endif /* REGISTERS_H_ */