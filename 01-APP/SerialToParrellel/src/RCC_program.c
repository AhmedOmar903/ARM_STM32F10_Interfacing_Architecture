/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 11 August 2020             */
/* version     : ver 1                      */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_VoidInitSystemClk(void){
	
#if CLK_TYPE==RCC_HSE_CRYSTAL
   RCC_CR=0x00010000;//ENABLE HSE_CRYSTAL//
   RCC_CFGR=0x00000001;
#elif CLK_TYPE==RCC_HSE_RC
   RCC_CR=0x00050000;//ENABLE HSE_RC//
   RCC_CFGR=0x00000001;
#elif CLK_TYPE==RCC_HSI
   RCC_CR=0x00000081;//ENABLE HSI//
   RCC_CFGR=0x00000000;
   
#elif CLK_TYPE==RCC_PLL

   #if RCC_PLL_BYP==ON
   SET_BIT(RCC_CR,18);//BYPASS//
   #endif

   #if RCC_PLL_INPUT==RCC_PLL_IN_HSI_DIV_2
     RCC_CR=0x00000081;
	 RCC_CFGR=((0x00000002)|(RCC_PLL_MAX<<18));
	 SET_BIT(RCC_CR,24);//PLL ON//
   #elif RCC_PLL_INPUT==RCC_PLL_IN_HSE_DIV_2
     RCC_CR=0x00010000;
	 RCC_CFGR=((0x00030002)|(RCC_PLL_MAX<<18));
	 SET_BIT(RCC_CR,24);//PLL ON//
   #elif RCC_PLL_INPUT==RCC_PLL_IN_HSE
	 RCC_CR=0x00010000;
	 RCC_CFGR=((0x00010002)|(RCC_PLL_MAX<<18));
	 SET_BIT(RCC_CR,24);//PLL ON//
   #endif
#else
	#error("you choosed wrong CLK Type")
#endif
	

}





//ENABLE THE BuS that the peripheral connected to it//
void RCC_VoidEnableClock(u8 Copy_u8BusName,u8 Copy_u8PreId){
	
	if(Copy_u8PreId<=31){
		
		switch(Copy_u8BusName){
			
			case RCC_AHB : SET_BIT(RCC_AHBENR ,Copy_u8PreId); break;
			case RCC_APB1: SET_BIT(RCC_APB1ENR,Copy_u8PreId); break;
			case RCC_APB2: SET_BIT(RCC_APB2ENR,Copy_u8PreId); break;
				
		}
	}
}
void RCC_VoidDisableClock(u8 Copy_u8BusName,u8 Copy_u8PreId){
	
	if(Copy_u8PreId<=31){
		
		switch(Copy_u8BusName){
			
			case RCC_AHB : CLR_BIT(RCC_AHBENR ,Copy_u8PreId); break;
			case RCC_APB1: CLR_BIT(RCC_APB1ENR,Copy_u8PreId); break;
			case RCC_APB2: CLR_BIT(RCC_APB2ENR,Copy_u8PreId); break;		
		}
	}
}



