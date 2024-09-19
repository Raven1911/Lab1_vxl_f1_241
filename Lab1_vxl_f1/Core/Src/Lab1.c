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



uint8_t A3, A2, A1, A0;
bool Led[12];


void calculator_Led_Clock(int num){
	uint8_t buffer;

	unsigned int Led_Clock[] = {
			0b0000, //0
			0b0001,
			0b0010,
			0b0011,
			0b0100,
			0b0101,
			0b0110,
			0b0111,
			0b1000,
			0b1001,
			0b1010,
			0b1011, //11
	};
	buffer = Led_Clock[num];
	A3 = (buffer>>3) & 1;
	A2 = (buffer>>2) & 1;
	A1 = (buffer>>1) & 1;
	A0 = (buffer>>0) & 1;

	Led[0] = (A3) || (A2) || (A1) || (A0);
	Led[1] = (A3) || (A2) || (A1) || (!A0);
	Led[2] = (A3) || (A2) || (!A1) || (A0);
	Led[3] = (A3) || (A2) || (!A1) || (!A0);
	Led[4] = (A3) || (!A2) || (A1) || (A0);
	Led[5] = (A3) || (!A2) || (A1) || (!A0);
	Led[6] = (A3) || (!A2) || (!A1) || (A0);
	Led[7] = (A3) || (!A2) || (!A1) || (!A0);
	Led[8] = (!A3) || (A2) || (A1) || (A0);
	Led[9] = (!A3) || (A2) || (A1) || (!A0);
	Led[10] = (!A3) || (A2) || (!A1) || (A0);
	Led[11] = (!A3) || (A2) || (!A1) || (!A0);
//
//	printf("A3: %d ", A3);
//	printf("A2: %d ", A2);
//	printf("A1: %d ", A1);
//	printf("A0: %d \n", A0);
//
//	printf("Led0: %d ", Led_0);
//	printf("Led1: %d ", Led_1);
//	printf("Led2: %d ", Led_2);
//	printf("Led3: %d ", Led_3);
//	printf("Led4: %d ", Led_4);
//	printf("Led5: %d ", Led_5);
//	printf("Led6: %d ", Led_6);
//	printf("Led7: %d ", Led_7);
//	printf("Led8: %d ", Led_8);
//	printf("Led9: %d ", Led_9);
//	printf("Led10: %d ", Led_10);
//	printf("Led11: %d \n", Led_11);
//	printf("------------------------- \n");
}

void SEL_LED_ON(int num){
	calculator_Led_Clock(num);
	HAL_GPIO_WritePin(Led_0_GPIO_Port, Led_0_Pin, Led[0]);
	HAL_GPIO_WritePin(Led_1_GPIO_Port, Led_1_Pin, Led[1]);
	HAL_GPIO_WritePin(Led_2_GPIO_Port, Led_2_Pin, Led[2]);
	HAL_GPIO_WritePin(Led_3_GPIO_Port, Led_3_Pin, Led[3]);
	HAL_GPIO_WritePin(Led_4_GPIO_Port, Led_4_Pin, Led[4]);
	HAL_GPIO_WritePin(Led_5_GPIO_Port, Led_5_Pin, Led[5]);
	HAL_GPIO_WritePin(Led_6_GPIO_Port, Led_6_Pin, Led[6]);
	HAL_GPIO_WritePin(Led_7_GPIO_Port, Led_7_Pin, Led[7]);
	HAL_GPIO_WritePin(Led_8_GPIO_Port, Led_8_Pin, Led[8]);
	HAL_GPIO_WritePin(Led_9_GPIO_Port, Led_9_Pin, Led[9]);
	HAL_GPIO_WritePin(Led_10_GPIO_Port, Led_10_Pin, Led[10]);
	HAL_GPIO_WritePin(Led_11_GPIO_Port, Led_11_Pin, Led[11]);

}





