/*
 * main.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Ramadona
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "SPI_interface.h"


void main(void)
{
	u8 reciev=0;

	RCC_VoidInitSystemClk();
	RCC_VoidEnableClock(RCC_APB2 ,IOPA );//BUS_NAME,Prepherial ID//
	RCC_VoidEnableClock(RCC_APB2 ,SPI1 );//BUS_NAME,Prepherial ID//
	GPIOX_VidSetPinDirection(PORTA,0, OUTPUT_SPEED_50M_PUSH_PULL );
	SPI_VoidIntialize();

   while(1)
   {


	   SPI_VoidSendReciveSynch(50,&reciev);

	   switch(reciev)
	   {
	   case 40 :GPIOX_VidSetPinValue(PORTA,0,HIGH); break;
	   default :GPIOX_VidSetPinValue(PORTA,0,LOW); break;

	   }


	   }



   }







