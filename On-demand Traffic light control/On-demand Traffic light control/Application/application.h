/*
 * application.h
 *
 * Created: 11/8/2022 7:42:25 PM
 *  Author: rafik
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../ECUAL/Button/button.h"
#include "../ECUAL/LED/led.h"


//status
typedef enum EN_Car_State_t{
	DISABLED_CAR, RED_CAR, YELLOW_CAR, GREEN_CAR
}EN_Car_State_t;

typedef enum EN_Traffic_t{
	GREEN,YELLOW,RED, DISABLED
}EN_Traffic_t;

typedef enum EN_Mode_t{
	NORMAL, PEDESTRIAN
}EN_Mode_t;

//prototypes
EN_Error_t APPLICATION_INIT();
EN_Error_t APPLICATION_START();

#endif /* APPLICATION_H_ */