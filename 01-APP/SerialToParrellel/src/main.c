/*
 * main.c
 *
 *  Created on: Sep 14, 2020
 *      Author: Ahmed Ramadan
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "STP_interface.h"
#include "LMATRIX_interface.h"








u16 array[][8]={
			 {0xFF00, 0xFF00, 0xFF00, 0xFF00,0xFF3C, 0xFF12, 0xFF12, 0xFF3C},
			 { 0xFF00, 0xFF00, 0xFF00, 0xFF00,0xFF3E, 0xFF08, 0xFF08, 0xFF3E},
			 { 0xFF00, 0xFF00, 0xFF00, 0xFF00,0xFF00, 0xFF00, 0xFF00, 0xFF00}




};//A







int main(void)
{
u8 i=0;
u16 x=1;
	RCC_VoidInitSystemClk();
	RCC_VoidEnableClock(RCC_APB2  ,IOPA);
	GPIOX_VidSetPortDirection(PORTA,OUTPUT_SPEED_2M_PUSH_PULL,FIRST_HALF);
	MSYSTCIK_VidInit();

	while(1)
	{


for(i=0;i<8;i++)
{
	STP_VoidSendSynchronus((x<<(i+8)));
	MSTK_VidSetBusyWait(100000);


}





	}
	return 0;
}
