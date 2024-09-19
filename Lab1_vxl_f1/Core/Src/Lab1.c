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
	setTimer(1, 1000); // step led 7 segment

}


////////////////            DISPLAY-7SEG             ////////////////

// 4bit [3:0] -> [A:B]
uint8_t A, B, C, D;
// f(ABCD)
bool a, b, c, d, e, f, g;

void calculator_BCD_to_7SEG(int num){
	uint8_t  buffer;
	unsigned int LED_4bit[] = {
		    0b0000, //  0
		    0b0001, //  1
		    0b0010, //  2
		    0b0011, //  3
		    0b0100, //  4
		    0b0101, //  5
		    0b0110, //  6
		    0b0111, //  7
		    0b1000, //  8
		    0b1001  //  9
		};
	buffer = LED_4bit[num];
	// 4bit [3:0] -> [A:B]
	A = (buffer >> 3) & 1;
	B = (buffer >> 2) & 1;
	C = (buffer >> 1) & 1;
	D = (buffer >> 0) & 1;

	// f(ABCD)
	a = (!B&!D) | C | (B&D) | A ;
	b = (!B) | (!C&!D) | (C&D);
	c = (!C) | D | B;
	d = (!B&!D) | ((!B)&C) | (B&!C&D) | (C&!D) | A;
	e = (!B&!D) | (C&!D);
	f = (!C&!D) | (B&!C) | (B&!D) | A;
	g = ((!B)&C) | (B&(!C)) | A | (B&(!D));


//	printf("A: %d \n", A);
//	printf("B: %d \n", B);
//	printf("C: %d \n", C);
//	printf("D: %d \n", D);
//	printf(" \n");
//	printf("a: %d \n", !a);
//	printf("b: %d \n", !b);
//	printf("c: %d \n", !c);
//	printf("d: %d \n", !d);
//	printf("e: %d \n", !e);
//	printf("f: %d \n", !f);
//	printf("g: %d \n", !g);
//	printf("-------------- \n");
}


void display7SEG(int index, int num){
	calculator_BCD_to_7SEG(num);
	switch (index) {
		case 0:
		    HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, !a);
		    HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, !b);
		    HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, !c);
		    HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, !d);
		    HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, !e);
		    HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, !f);
		    HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, !g);
			break;
		case 1:
		    HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, !a);
		    HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, !b);
		    HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, !c);
		    HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, !d);
		    HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, !e);
		    HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, !f);
		    HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, !g);
			break;
		default:
			break;
	}

}



//////////////////////
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

uint8_t count_7seg = 3;
uint8_t count_7seg1 = 5;
void Exercise_5(){
	switch (pre_state) {

		case state_0:
			//7segment display
			display7SEG(0, count_7seg);
			display7SEG(1, count_7seg1);
			//traffic
			decoder_Led(0, 1, 1, 1, 1, 0);

			if(flag_timer[0]){
				pre_state = state_1;
				flag_timer[0] = 0;
				setTimer(0, 2000);
			}

			if(flag_timer[1]){
				count_7seg--;
				if(count_7seg < 1) count_7seg = 2;
				count_7seg1--;

				flag_timer[1] = 0;
			}
			break;

		case state_1:
			//7segment display
			display7SEG(0, count_7seg);
			display7SEG(1, count_7seg1);
			//traffic
			decoder_Led(0, 1, 1, 1, 0, 1);

			if(flag_timer[0]){
				pre_state = state_2;
				flag_timer[0] = 0;
				setTimer(0, 3000);
			}
			if(flag_timer[1]){
				count_7seg--;
				if(count_7seg < 1) count_7seg = 5;
				count_7seg1--;
				if(count_7seg1 < 1) count_7seg1 = 3;
				flag_timer[1] = 0;
			}
			break;

		case state_2:
			//7segment display
			display7SEG(0, count_7seg);
			display7SEG(1, count_7seg1);
			//traffic
			decoder_Led(1, 1, 0, 0, 1, 1);

			if(flag_timer[0]){
				pre_state = state_3;
				flag_timer[0] = 0;
				setTimer(0, 2000);
			}
			if(flag_timer[1]){
				count_7seg--;
				//if(count_7seg < 1) count_7seg = 2;
				count_7seg1--;
				if(count_7seg1 < 1) count_7seg1 = 2;
				flag_timer[1] = 0;
			}
			break;

		case state_3:
			//7segment display
			display7SEG(0, count_7seg);
			display7SEG(1, count_7seg1);
			//traffic
			decoder_Led(1, 0, 1, 0, 1, 1);;

			if(flag_timer[0]){
				pre_state = state_0;
				flag_timer[0] = 0;
				setTimer(0, 3000);
			}
			if(flag_timer[1]){
				count_7seg--;
				if(count_7seg < 1) count_7seg = 3;
				count_7seg1--;
				if(count_7seg1 < 1) count_7seg1 = 5;
				flag_timer[1] = 0;
			}
			break;
		default:
			break;
	}
}


