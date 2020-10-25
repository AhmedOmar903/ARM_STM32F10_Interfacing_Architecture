/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 22 August 2020             */
/* version     : ver 1                      */
/* Description : SYSTICK                    */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
#include "SYSTICK_private.h"

 
 
void MSYSTCIK_VidInit(void){


#if SYSTICK_INTERRUPT  ==  ENABLE

	SET_BIT(STK->CTRL,STK_INTERRUPT);
#elif SYSTICK_INTERRUPT  ==  DISABLE

	CLR_BIT(STK->CTRL,STK_INTERRUPT);


#endif

#if CLK==SYTK_AHB_8

 CLR_BIT(STK->CTRL,STK_CLK_SOURCE);


#elif  CLK ==SYTK_AHB
 SET_BIT(STK->CTRL,STK_CLK_SOURCE);

#endif

}


void MSYSTICK_VidEnableInterruptDelayMs(u32 Copy_u32DelayMs){
	STK->VAL=0;
	Copy_u32DelayMs*=1000;
    STK->LOAD= Copy_u32DelayMs;//Send the Value//
	SET_BIT(STK->CTRL,STK_ENABLE ); //ENABLE the Timer//
}

void MSYSTICK_VidDisableInterruptDelay(void){

	STK->VAL=0;
	STK->LOAD=0;
	SET_BIT(STK->CTRL,STK_ENABLE ); //ENABLE the Timer//
}

void MSYSTICK_VidDelayMs(u32 Copy_u32Delay){


	u8 Read_flag=0;

	 Copy_u32Delay*=1000;  //MS//
	 STK->VAL=0;
	 STK->LOAD= Copy_u32Delay;//Send the Value//
	 SET_BIT(STK->CTRL,STK_ENABLE ); //ENABLE the Timer//
	while(GET_BIT(STK->CTRL,STK_FLAG)==0);// wait
	Read_flag=GET_BIT(STK->CTRL,STK_FLAG);//read the flag to clear
    CLR_BIT(STK->CTRL,STK_ENABLE ); //DISABLE the Timer//

}
 
 
 
 
 
