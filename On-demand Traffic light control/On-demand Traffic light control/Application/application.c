/*
 * application.c
 *
 * Created: 11/8/2022 7:42:40 PM
 *  Author: rafik
 */ 

#include "application.h"

EN_Car_State_t car_State = DISABLED_CAR;
EN_Traffic_t traffic = DISABLED;
EN_Mode_t mode = NORMAL;
uint64_t long_press = 1500;

EN_Error_t APPLICATION_INIT(){
	// Initialize Car LEDs
	LED_INIT(GREEN_LED, PORT_A);
	LED_INIT(YELLOW_LED, PORT_A);
	LED_INIT(RED_LED, PORT_A);
	
	// Initialize Pedestrian LEDs
	LED_INIT(GREEN_LED, PORT_B);
	LED_INIT(YELLOW_LED, PORT_B);
	LED_INIT(RED_LED, PORT_B);
	
	// Initialize PB
	BUTTON_INIT(BUTTON_PIN, BUTTON_PORT);
	
	// Initialize Timer
	TIMER0_INIT();
	
	// Initialize Interrupts
	sei();
	RISING_EDGE_BIT0();
	RISING_EDGE_BIT1();
	INT0_ENABLE();
	
	return OK;
}

EN_Error_t APPLICATION_START(){
	
	//NORMAL mode
	switch(mode)
	{
		//NORMAL mode
		case NORMAL:
		//red
		if((traffic == RED && car_State == YELLOW_CAR))
		{
			car_State = RED_CAR;
			LED_ON_5s(RED_LED, PORT_A);
			traffic=RED;
		}
		//yellow
		else if(car_State == RED_CAR || car_State == GREEN_CAR)
		{
			car_State = YELLOW_CAR;
			LED_BLINK_5s(YELLOW_LED, PORT_A);
			LED_OFF(YELLOW_LED, PORT_A);
			if(traffic == GREEN)
			{
				LED_OFF(GREEN_LED, PORT_A);
				traffic = RED;
			}
			else if(traffic == RED)
			{
				LED_OFF(RED_LED, PORT_A);
				traffic = GREEN;
			}
			
			
		}
		//green
		else if(car_State == DISABLED_CAR || (car_State == YELLOW_CAR && traffic == GREEN))
		{
			car_State = GREEN_CAR;
			traffic = GREEN;
			LED_ON_5s(GREEN_LED, PORT_A);
		}
		break;
		
		//PEDESTRIAN mode
		case PEDESTRIAN:
		//red pedestrian
		if(car_State == GREEN_CAR || car_State == YELLOW_CAR)
		{
			LED_ON(RED_LED,PORT_B);
			TWO_LED_BLINK_5s(YELLOW_LED,PORT_B,PORT_A);
			LED_OFF(RED_LED,PORT_B);
			LED_OFF(GREEN_LED,PORT_A);
			LEDS_ON_5S();
		}
		
		//green pedestrian
		else if(car_State == RED_CAR)
		{
			LEDS_ON_5S();
		}
		//at the end of two states
		LED_OFF(RED_LED,PORT_A);
		TWO_LED_BLINK_5s(YELLOW_LED,PORT_A,PORT_B);
		LED_OFF(GREEN_LED,PORT_B);
		LED_ON(RED_LED,PORT_B);
		car_State = YELLOW_CAR;
		traffic = GREEN;
		mode = NORMAL;
		break;
	}
	return OK;
}

ISR(EXT_INT_0)
{
	INT0_DISABLE();
	uint64_t count = 0;
	while(BUTTON_READ(BUTTON_PIN, BUTTON_PORT) == HIGH)
	{
		count++;
	}
	if(count < long_press && mode == NORMAL)
	{
		TIMER0_STOP();
		mode = PEDESTRIAN;
	}
	INT0_ENABLE();
}

