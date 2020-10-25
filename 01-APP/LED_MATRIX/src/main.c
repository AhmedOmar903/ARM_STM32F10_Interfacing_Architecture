/*
 * main.c
 *
 *  Created on: Aug 31, 2020
 *      Author: Ahmed Ramadan
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "LMATRIX_interface.h"



void Init(void);
void main(void){

	u8 array[][8]={
			{60, 18, 18, 60, 0, 0, 0, 0},//A
			{62, 8, 8, 62, 0, 0, 0, 0},//H
			{62, 2, 4, 2, 62, 0, 0, 0},//M
			{42, 42, 62, 0, 0, 0, 0, 0},//E
			{28, 34, 62, 0, 0, 0, 0, 0},//D
			{36, 26, 10, 62, 0, 0, 0, 0},//R
			{60, 18, 18, 60, 0, 0, 0, 0},//A
			{62, 2, 4, 2, 62, 0, 0, 0},//M
			{60, 18, 18, 60, 0, 0, 0, 0},//A
			{28, 34, 62, 0, 0, 0, 0, 0},//D
			{60, 18, 18, 60, 0, 0, 0, 0},//A
			{62, 64, 124, 2, 126, 0, 0, 0}//A
	           };

	Init();
	while(1){

		/*HLEDMRX_VidDisplay(array[0]);
		HLEDMRX_VidDisplay(array[1]);
		HLEDMRX_VidDisplay(array[2]);
		HLEDMRX_VidDisplay(array[3]);
		HLEDMRX_VidDisplay(array[4]);
*/
		HLEDMRX_VidDisplay(array[5]);
		/*HLEDMRX_VidDisplay(array[6]);
		HLEDMRX_VidDisplay(array[7]);
		HLEDMRX_VidDisplay(array[8]);
		HLEDMRX_VidDisplay(array[9]);

		HLEDMRX_VidDisplay(array[10]);*/
		HLEDMRX_VidDisplay(array[11]);



	}

}


void Init(void){


/******************RCC***********************************/
	RCC_VoidInitSystemClk();//Intial RCC at RCC_HSE_CRYSTAL
	RCC_VoidEnableClock(RCC_APB2,IOPA);//Enable PORTA CLK
	RCC_VoidEnableClock(RCC_APB2,IOPB);//Enable PORTB CLK
	MSYSTCIK_VidInit();
	HLEDMRX_VidInit();
}
