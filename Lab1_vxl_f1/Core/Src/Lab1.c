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


void display7SEG(int num){
	calculator_BCD_to_7SEG(num);
    HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, !a);
    HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, !b);
    HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, !c);
    HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, !d);
    HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, !e);
    HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, !f);
    HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, !g);
}

int counter = 0;
void test_case_7seg(){
	if(flag_timer[0]){
		if(counter >= 10) counter = 0;
		display7SEG(counter++);
		flag_timer[0] = 0;

	}


}




