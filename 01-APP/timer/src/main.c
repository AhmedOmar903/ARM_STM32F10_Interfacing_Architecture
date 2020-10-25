/*
 * main.c
 *
 *  Created on: Oct 4, 2020
 *      Author: Ramadona
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "TIMER_interface.h"





void ISR0(void);
void ISR1(void);
void ISR2(void);


void main(void)
{

	RCC_VoidInitSystemClk();
	RCC_VoidEnableClock(RCC_APB2 , IOPA );//GPIO A
	RCC_VoidEnableClock(RCC_APB1 ,TIM2 );//TIMER 2



	 MNVIC_VidInterruptEnable(28);

	GPIOX_VidSetPinDirection(PORTA,0,OUTPUT_SPEED_10M_PUSH_PULL );
	GPIOX_VidSetPinDirection(PORTA,2,OUTPUT_SPEED_10M_PUSH_PULL );
	GPIOX_VidSetPinDirection(PORTA,1,OUTPUT_SPEED_10M_PUSH_PULL );





	TIMER_VoidTimerStartAsyncrouonas(TIMER2, 65500,ISR0);
	TIMER_VoidInitailze(TIMER2,UP_COUNTER);



	while(1)
	{





	}


}

void ISR0(void)
{
static u8 counter =0;

if(counter==16)
{
	GPIOX_VidTogPin(PORTA,0);
	counter=0;
}
counter++;

}
void ISR1(void)
{

	GPIOX_VidTogPin(PORTA,1);
}
void ISR2(void)
{
	GPIOX_VidTogPin(PORTA,2);
}



/*
void ISR(void){

	static u8 couter=0;

	if(couter==16)
	{
		 GPIOX_VidTogPin(PORTA,0);
		 couter=0;
	}
	couter++;



}*/

