/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 12 August 2020             */
/* version     : ver 1                      */
/* Description : GPIO                       */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
/***************************************PIN DIRECTION******************************************************/

void GPIOX_VidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode){
	
	switch(Copy_u8Port){
		
		case PORTA: 
		          if(Copy_u8Pin<=7){
				      GPIOA_CRL &=~((0b1111)<<(Copy_u8Pin*4)); //CLR//
				      GPIOA_CRL |=((Copy_u8Mode)<<(Copy_u8Pin*4));//SET THE MODE//
			      }
				  else if(Copy_u8Pin<=15){
					  Copy_u8Pin=Copy_u8Pin-8;
					  GPIOA_CRH &=~((0b1111)<<(Copy_u8Pin*4)); //CLR//
				      GPIOA_CRH |=((Copy_u8Mode)<<(Copy_u8Pin*4));//SET THE MODE//
				  }
		          break;
		case PORTB:
		          if(Copy_u8Pin<=7){
				      GPIOB_CRL &=~((0b1111)<<(Copy_u8Pin*4)); //CLR//
				      GPIOB_CRL |=((Copy_u8Mode)<<(Copy_u8Pin*4));//SET THE MODE//
			      }
				  else if(Copy_u8Pin<=15){
					  Copy_u8Pin=Copy_u8Pin-8;
					  GPIOB_CRH &=~((0b1111)<<(Copy_u8Pin*4)); //CLR//
				      GPIOB_CRH |=((Copy_u8Mode)<<(Copy_u8Pin*4));//SET THE MODE//
				  }
		          break;
		case PORTC:
		          if(Copy_u8Pin<=7){
				      GPIOC_CRL &=~((0b1111)<<(Copy_u8Pin*4)); //CLR//
				      GPIOC_CRL |=((Copy_u8Mode)<<(Copy_u8Pin*4));//SET THE MODE//
			      }
				  else if(Copy_u8Pin<=15){

					  Copy_u8Pin=Copy_u8Pin-8;
					  GPIOC_CRH &=~((0b1111)<<(Copy_u8Pin*4)); //CLR//
				      GPIOC_CRH |=((Copy_u8Mode)<<(Copy_u8Pin*4));//SET THE MODE//
				  }
		          break;
	}
}
