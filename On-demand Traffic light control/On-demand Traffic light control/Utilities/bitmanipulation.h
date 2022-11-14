/*
 * bitmanipulation.h
 *
 * Created: 11/8/2022 11:44:28 AM
 *  Author: rafik
 */ 


#ifndef BITMANIPULATION_H_
#define BITMANIPULATION_H_

#define SET_BIT(ADDRESS,BIT)	ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS,BIT)	ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT)	ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS,BIT)	((ADDRESS & (1<<BIT))>>BIT)
#define GET_BIT(ADDRESS, BIT)	((ADDRESS >> BIT) & 1)								// Get Bit Macro



#endif /* BITMANIPULATION_H_ */