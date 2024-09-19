/*
 * Lab1.c
 *
 *  Created on: Sep 5, 2024
 *      Author: Admin
 */
#include "Lab1.h"

///////         SYSTEM INIT  	////////////////////////////

void System_init_Lab1(){
	timer_init();
	setTimer(0, 1000);

}

/////////////////////////////////////////TRAFFIC_LIGHT////////////////////////////////////////////////////
typedef enum {state_0, state_1, state_2, state_3} state;
state pre_state = state_0;
void Exercise_2(){
	switch (pre_state) {
		case state_0:
			//traffic light 1
			HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, SET);
			HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, SET);
			HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, RESET);
			if(flag_timer[0]){
				pre_state = state_1;
				flag_timer[0] = 0;
				setTimer(0, 2000);
			}
			break;

		case state_1:
			//traffic light 1
			HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, SET);
			HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, RESET);
			HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, SET);
			if(flag_timer3){
				pre_state = state_2;
				flag_timer[0] = 0;
				setTimer(0, 5000);
			}
			break;

		case state_2:
			HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, RESET);
			HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, SET);
			HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, SET);
			if(flag_timer3){
				pre_state = state_0;
				flag_timer[0] = 0;
				setTimer(0, 3000);
			}
			break;

		default:
			break;
	}


}








