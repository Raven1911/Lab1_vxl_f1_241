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

//////////////   LED TOGGLE ///////////////////
bool bool_red = 1;
bool bool_yellow = 0;

void Exercise_1(){
	if(flag_timer[0]){
		HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, bool_red);
		HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, bool_yellow);
		bool_red = !bool_red;
		bool_yellow = !bool_yellow;
		flag_timer[0] = 0;
	}
}







