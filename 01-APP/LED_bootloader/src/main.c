/*
 * main.c
 *
 *  Created on: Oct 14, 2020
 *      Author: Ramadona
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

//0x08002800
void main(void)
{
	RCC_VoidInitSystemClk();
	RCC_VoidEnableClock(2,2);
	MSYSTCIK_VidInit();

	GPIOX_VidSetPortDirection(PORTA,OUTPUT_SPEED_10M_PUSH_PULL,FIRST_HALF );


while(1)
{


	GPIOX_VidSetPortValue(PORTA,0xFFFF);
		MSTK_VidSetBusyWait(600000);
		GPIOX_VidSetPortValue(PORTA,0x0000);
				MSTK_VidSetBusyWait(600000);




}

}
