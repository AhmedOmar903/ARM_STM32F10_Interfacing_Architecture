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
void GPIOX_VidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value){
	
	switch(Copy_u8Port){
		case PORTA: 
		          if(Copy_u8Value==HIGH){
					  
					  GPIOA_BSRR=(1<<Copy_u8Pin);
				      
			      }
				  else if(Copy_u8Value==LOW){
					  
					  GPIOA_BRR=(1<<Copy_u8Pin);
					  
				  }
		          break;
		case PORTB:
		          if(Copy_u8Value==HIGH){
				      GPIOB_BSRR=(1<<Copy_u8Pin);
			      }
				  else if(Copy_u8Value==LOW){
					  GPIOB_BRR=(1<<Copy_u8Pin);
				  }
		          break;
		case PORTC:
		          if(Copy_u8Value==HIGH){
				      GPIOC_BSRR=(1<<Copy_u8Pin);
			      }
				  else if(Copy_u8Value==LOW){
					  GPIOC_BRR=(1<<Copy_u8Pin);
				  }
		          break;
	}
}

u8 GPIOX_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin){

	u8 LOC_u8Result=0;
		switch(Copy_u8Port){
		case PORTA:
		          LOC_u8Result=GET_BIT(GPIOA_IDR,Copy_u8Pin);
		          break;
		case PORTB:
		          LOC_u8Result=GET_BIT(GPIOB_IDR,Copy_u8Pin);
		          break;
		case PORTC:
		          LOC_u8Result=GET_BIT(GPIOC_IDR,Copy_u8Pin);
		          break;
	}
   return LOC_u8Result;
}

/***************************************PORT DIRECTION******************************************************/
void GPIOX_VidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Mode,u8 Copy_u8PortSize){
	u8 i=0,flag=0;
	u32*PORT_NAME=0;
	
    switch(Copy_u8Port){

		case PORTA:   
		            if(Copy_u8PortSize==FIRST_HALF){
						  PORT_NAME=&GPIOA_CRL; //pointer takes the address of GPIO Register//
						 }
		            else if(Copy_u8PortSize==SECAND_HALF){      
						 PORT_NAME=&GPIOA_CRH;  //pointer takes the address of GPIO Register//
					   }
						 break;
		case PORTB:      
		            if(Copy_u8PortSize==FIRST_HALF){
						  PORT_NAME=&GPIOB_CRL; //pointer takes the address of GPIO Register//
						 }
		            else if(Copy_u8PortSize==SECAND_HALF){      
						 PORT_NAME= &GPIOB_CRH;   //pointer takes the address of GPIO Register//
					   }
						 break;
       case PORTC:
		         for(i=5;i<8;i++){
					 GPIOC_CRH &=~((0b1111)<<i*4);
					 GPIOC_CRH |=((Copy_u8Mode)<<(i*4));
				 }
				 flag=1;
				 break;
	 }
	if(flag==0){
			for(i=0;i<8;i++){   
			   *PORT_NAME &=~((0b1111)<<(i*4));     
			   *PORT_NAME |=((Copy_u8Mode)<<(i*4));
			}
       }
}




void GPIOX_VidSetPortValue(u8 Copy_u8Port,u16 Copy_u16Value){

	switch(Copy_u8Port){
		case PORTA:  GPIOA_ODR=Copy_u16Value; break;
		case PORTB:  GPIOB_ODR=Copy_u16Value; break;
		case PORTC:  GPIOC_ODR|=(Copy_u16Value<<13); break;
	}

}
/***************************************GET_PIN******************************************************/



void GPIOX_VidTogPin(u8 Copy_u8Port,u8 Copy_u8Pin){

	switch(Copy_u8Port){

		case PORTA: TOG_BIT(GPIOA_ODR,Copy_u8Pin); break;
		case PORTB: TOG_BIT(GPIOB_ODR,Copy_u8Pin); break;
		case PORTC: TOG_BIT(GPIOC_ODR,Copy_u8Pin); break;
	}
}


void delay(void){
	u16 i=0,j,x=600;

	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
            asm("NOP");
 		}

		}

	}
