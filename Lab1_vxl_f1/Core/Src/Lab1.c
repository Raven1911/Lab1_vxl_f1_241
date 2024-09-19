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
	setTimer(0, 3000);

}

void decoder_Led(int R, int Y, int G, int R2, int Y2, int G2){
	//traffic light 1
	HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, R);
	HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, Y);
	HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, G);

	//traffic light 2
	HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, R2);
	HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, Y2);
	HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, G2);
}
/////////////////////////////////////////TRAFFIC_LIGHT////////////////////////////////////////////////////
//// 4 way traffic light
typedef enum {state_0, state_1, state_2, state_3} state;
state pre_state = state_0;
void Exercise_3(){
	switch (pre_state) {

		case state_0:
			decoder_Led(0, 1, 1, 1, 1, 0);
			if(flag_timer[0]){
				pre_state = state_1;
				flag_timer[0] = 0;
				setTimer(0, 2000);
			}
			break;

		case state_1:
			decoder_Led(0, 1, 1, 1, 0, 1);
			if(flag_timer[0]){
				pre_state = state_2;
				flag_timer[0] = 0;
				setTimer(0, 3000);
			}
			break;

		case state_2:
			decoder_Led(1, 1, 0, 0, 1, 1);
			if(flag_timer[0]){
				pre_state = state_3;
				flag_timer[0] = 0;
				setTimer(0, 2000);
			}
			break;

		case state_3:
			decoder_Led(1, 0, 1, 0, 1, 1);;
			if(flag_timer[0]){
				pre_state = state_0;
				flag_timer[0] = 0;
				setTimer(0, 3000);
			}
			break;
		default:
			break;
	}
}








