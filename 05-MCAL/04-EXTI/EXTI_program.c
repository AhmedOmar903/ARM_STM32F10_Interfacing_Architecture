/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 22 August 2020             */
/* version     : ver 1                      */
/* Description : EXTI                       */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


void MEXTI_VidInit(void){
	
	#if MODE==RISING
	  SET_BIT(EXTI->RTSR,EXTI_LINE);//RISING//
	#elif MODE==FALLING
	  SET_BIT(EXTI->FTSR,EXTI_LINE);//FALLING//
	#elif MODE== ON_CHANGE
       SET_BIT(EXTI->RTSR,EXTI_LINE);//RISING//
	   SET_BIT(EXTI->FTSR,EXTI_LINE);//FALLING//
	#endif
      CLR_BIT(EXTI->IMR,EXTI_LINE);	//to Disable the Interrupt//
}
void MEXTI_VidExtiEnable(u8 Copy_u8ExtiNum){
	
	SET_BIT(EXTI->IMR,Copy_u8ExtiNum);
}
void MEXTI_VidExtiDisable(u8 Copy_u8ExtiNum){
	
	CLR_BIT(EXTI->IMR,Copy_u8ExtiNum);
}
void MEXTI_VidSwTrigger(u8 Copy_u8ExtiNum){
	//Software Interrupt//
	
	
	
	SET_BIT(EXTI->SWIER,Copy_u8ExtiNum);
	SET_BIT(EXTI->PR,Copy_u8ExtiNum);//Clear Pending Flag
	
}

void MEXTI_VidSetSignalLactch(u8 Copy_u8PinNum,u8 Copy_u8Mode){
	
	
	switch(Copy_u8Mode){
		case RISING    : SET_BIT(EXTI->RTSR,Copy_u8PinNum); break;
		case FALLING   : SET_BIT(EXTI->FTSR,Copy_u8PinNum); break;
		case ON_CHANGE : SET_BIT(EXTI->RTSR,Copy_u8PinNum);//RISING//
	                     SET_BIT(EXTI->FTSR,Copy_u8PinNum);//FALLING//
		                  break;
	}
	SET_BIT(EXTI->IMR,Copy_u8PinNum);
}

void MEXTI_VidSetCallBack(void (*LocalPointer)(void), u8 Copy_u8ExtiNum){
	
		GlobalPointer[Copy_u8ExtiNum]=LocalPointer;
	
}



void EXTI0_IRQHandler(void){
	GlobalPointer[0]();
	SET_BIT(EXTI->PR,0); //CLEAR Pending Bit or CLR Flag
}
void EXTI1_IRQHandler(void){
	GlobalPointer[1]();
	SET_BIT(EXTI->PR,1);//CLEAR Pending Bit or CLR Flag
}

void EXTI2_IRQHandler(void){
	GlobalPointer[2]();
	SET_BIT(EXTI->PR,2);//CLEAR Pending Bit or CLR Flag
}
void EXTI3_IRQHandler(void){
	GlobalPointer[3]();
	SET_BIT(EXTI->PR,3);//CLEAR Pending Bit or CLR Flag
}















