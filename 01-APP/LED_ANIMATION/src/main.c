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





#define  iterations            4
#define  Reapeted_times        4



void Flashing(void);

void PING_PONG(void);

void turn_on_off(void);
void Inital(void);
void main(void){


	Inital();

	while(1){

		PING_PONG();

		turn_on_off();

		Flashing();
	}



}





void turn_on_off(void){

u8 Turn_on_OFF_iterations,Turn_on;


GPIOX_VidSetPortValue(PORTA,0x0000);//Close the Port //
for(Turn_on_OFF_iterations=0;Turn_on_OFF_iterations<Reapeted_times;Turn_on_OFF_iterations++){
//used to Turn on Leds //
	 for(Turn_on=0;Turn_on<iterations;Turn_on++){
		   GPIOX_VidTogPin(PORTA,Turn_on);
	       GPIOX_VidTogPin(PORTA,7-Turn_on);
	       MSYSTICK_VidDelayMs(200);
	 }
	   //used to Turn off Leds //
	 for(Turn_on=0;Turn_on<iterations;Turn_on++){
	 	  GPIOX_VidTogPin(PORTA,Turn_on);
	      GPIOX_VidTogPin(PORTA,7-Turn_on);
	 	    MSYSTICK_VidDelayMs(200);
	}
  }

}









void PING_PONG(void){

  u8 NUMBER_OF_ITERATION=0,MOVE_RIGHT=0,MOVE_LEFT=0;


  for(NUMBER_OF_ITERATION=0;NUMBER_OF_ITERATION<Reapeted_times;NUMBER_OF_ITERATION++){

	   for(MOVE_RIGHT=0; MOVE_RIGHT<8; MOVE_RIGHT++){

		   GPIOX_VidTogPin(PORTA,MOVE_RIGHT);
		   MSYSTICK_VidDelayMs(200);
		   GPIOX_VidTogPin(PORTA,MOVE_RIGHT);
	   }

	   for(MOVE_LEFT=6; MOVE_LEFT>0; MOVE_LEFT--){

		   GPIOX_VidTogPin(PORTA,MOVE_LEFT);
		   MSYSTICK_VidDelayMs(200);
		   GPIOX_VidTogPin(PORTA,MOVE_LEFT);

	   	}


  }
}



void Flashing(void){
u8 iterantion=0;

 for(iterantion=0;iterantion<8;iterantion++){


	 GPIOX_VidSetPortValue(PORTA,0x00FF);
	  MSYSTICK_VidDelayMs(500);
	 GPIOX_VidSetPortValue(PORTA,0x0000);
	  MSYSTICK_VidDelayMs(500);
 }




}







void Inital(void){
RCC_VoidInitSystemClk();//intialize CLK
RCC_VoidEnableClock( RCC_APB2 ,IOPA);//enable GPIO CLK
GPIOX_VidSetPortDirection(PORTA,OUTPUT_SPEED_2M_PUSH_PULL ,FIRST_HALF);//PORTA Direction OUTput
MSYSTCIK_VidInit();
}



/*
 * void turn_on_off(void){

u8 Turn_on_OFF_iterations,Turn_on,Turn_off,Realated=1;


GPIOX_VidSetPortValue(PORTA,0x0000);//Close the Port //
for(Turn_on_OFF_iterations=0;Turn_on_OFF_iterations<Reapeted_times;Turn_on_OFF_iterations++){
//used to Turn on Leds //
	 for(Turn_on=0;Turn_on<iterations;Turn_on++){
		   GPIOX_VidTogPin(PORTA,Turn_on);
	       GPIOX_VidTogPin(PORTA,7-Turn_on);
	       MSYSTICK_VidDelayMs(200);
	 }
	   //used to Turn off Leds //
     for(Turn_off=iterations;Turn_off<8;Turn_off++){
	  		   GPIOX_VidTogPin(PORTA,Turn_off);
	  	       GPIOX_VidTogPin(PORTA,Turn_off-Realated);
	  	     MSYSTICK_VidDelayMs(200);
	  	     Realated+=2;
     }
	   Realated=1;
  }

}
 *
 * */



