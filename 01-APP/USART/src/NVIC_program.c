/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 19 August 2020             */
/* version     : ver 1                      */
/* Description : NVIC                       */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"



void MNVIC_VidInterruptEnable(u8 Copy_u8InterruptNumber){
	if(Copy_u8InterruptNumber<=31){
		
		NVIC_ISER0=(1<<Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber<=59){
		
		Copy_u8InterruptNumber-=32;
		NVIC_ISER1=(1<<Copy_u8InterruptNumber);
	}	
}

void MNVIC_VidInterruptDisable(u8 Copy_u8InterruptNumber){
	
	if(Copy_u8InterruptNumber<=31){
		
		NVIC_ICER0=(1<<Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber<=59){
		Copy_u8InterruptNumber-=32;
		NVIC_ICER1=(1<<Copy_u8InterruptNumber);
	}	
}


void MNVIC_VidSetPendingFlag(u8 Copy_u8InterruptNumber){
	
	if(Copy_u8InterruptNumber<=31){
		
		NVIC_ISPR0=(1<<Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber<=59){
		
		Copy_u8InterruptNumber-=32;
		NVIC_ISPR0=(1<<Copy_u8InterruptNumber);
	}	
	
	
}
void MNVIC_VidClrPendingFlag(u8 Copy_u8InterruptNumber){
	
	if(Copy_u8InterruptNumber<=31){
		
		NVIC_ICPR0=(1<<Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber<=59){
		
		Copy_u8InterruptNumber-=32;
		NVIC_ICPR0=(1<<Copy_u8InterruptNumber);
	}	
}



u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptNumber){
	
 	u8 Local_u8Result;
	
	if(Copy_u8InterruptNumber<=31){
		
		Local_u8Result= GET_BIT(NVIC_IABR0,Copy_u8InterruptNumber);
		
	}
	else if(Copy_u8InterruptNumber<=59){
		
		Copy_u8InterruptNumber-=32;
		Local_u8Result= GET_BIT(NVIC_IABR1,Copy_u8InterruptNumber);
	}
	
	return Local_u8Result;
}


//this function is to Set the software Priority //
void MNVIC_VidSetPirority(s8 Copy_s8IntId,u8 Copy_u8GroupPriority,u8 Copy_u8SubGroupPriority){
	/*Check if its is core Peripheral (-Ve Priority)or external */
	 u8 Local_u8Priority=Copy_u8SubGroupPriority|((Copy_u8GroupPriority)<<((PRIORITY_GROUP-0x05FA0300)/(256)));
	 
	if(Copy_s8IntId>=0){ //external// 
		NVIC_IPR[Copy_s8IntId]=(Local_u8Priority<<4); 
      	
	}
}

void MNVIC_VidInit(void){
	
	 SOC_AIRCR=PRIORITY_GROUP;
	
}




