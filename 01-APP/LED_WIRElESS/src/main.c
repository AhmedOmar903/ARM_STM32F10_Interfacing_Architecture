/*
 * main.c
 *
 *  Created on: Aug 24, 2020
 *      Author: Ahmed Ramadan
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "IR_interface.h"






#define  iterations            4
#define  Reapeted_times        4

u8 flag=0;

void ISR(u8 Data);

void Flashing(void);
void PING_PONG(void);
void Inital(void);
void TURN_ON_OFF(void);
void main(void){

	Inital();
	HINFRA_VidIntial();
   HINFRA_VidSetCallBack(ISR);


	while(1){


		if(flag==1){
			Flashing();

		}
		else if(flag==2){
			PING_PONG();
		}
		else if(flag==3){
			TURN_ON_OFF();
		}


	}



}



void ISR(u8 Data){
	switch(  Data){
					     case 69 :flag=1;break;
					     case 70 :flag=2;break;
					     case 12 :flag=3;break;

					  }

}



void TURN_ON_OFF(void){

	u8 i=0;
	for(i=8;i<12;i++){

		GPIOX_VidSetPinValue(PORTB,i,HIGH);
		GPIOX_VidSetPinValue(PORTB,23-i,HIGH);
		MSTK_VidSetBusyWait(100);
	}
	for(i=8;i<12;i++){

			GPIOX_VidSetPinValue(PORTB,i,LOW);
			GPIOX_VidSetPinValue(PORTB,23-i,LOW);
			MSTK_VidSetBusyWait(100);
		}


}



void PING_PONG(void){

static	u8 i=8;

		GPIOX_VidTogPin(PORTB,i);
		 MSTK_VidSetBusyWait(100);
		 GPIOX_VidTogPin(PORTB,i);
	i++;
	if(i==15){

		i=8;
	}

}



void Flashing(void){


	GPIOX_VidSetPortValue(PORTB,0xFF00);
    MSTK_VidSetBusyWait(200);
	GPIOX_VidSetPortValue(PORTB,0x0000);
    MSTK_VidSetBusyWait(200);

}







void Inital(void){
RCC_VoidInitSystemClk();//intialize CLK
RCC_VoidEnableClock( RCC_APB2 ,IOPA);//enable GPIO CLK
RCC_VoidEnableClock( RCC_APB2 ,IOPB);//enable GPIO CLK
GPIOX_VidSetPortDirection(PORTB,OUTPUT_SPEED_2M_PUSH_PULL ,SECAND_HALF);//PORTB Direction OUTput


}



