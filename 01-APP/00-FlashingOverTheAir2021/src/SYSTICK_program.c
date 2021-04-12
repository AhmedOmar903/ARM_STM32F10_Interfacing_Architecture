/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 27 August 2020             */
/* version     : ver 2                      */
/* Description : SYSTICK                    */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
#include "SYSTICK_private.h"

static u8 MSTK_u8ModeOfInterval;

void MSYSTCIK_VidInit(void){

#if CLK==SYTK_AHB_8
 CLR_BIT(STK->CTRL,STK_CLK_SOURCE);
#elif  CLK ==SYTK_AHB
 SET_BIT(STK->CTRL,STK_CLK_SOURCE);
#endif

}

void MSTK_VidSetBusyWait(u32 Copy_u32Delay){
	
     u8 Read_flag;
	 STK->VAL=0;
	 STK->LOAD= Copy_u32Delay;//Send the Value//
	 SET_BIT(STK->CTRL,STK_ENABLE ); //ENABLE the Timer//
	while(GET_BIT(STK->CTRL,STK_FLAG)==0);// wait

	Read_flag=GET_BIT(STK->CTRL,STK_FLAG);//read the flag to clear

}
void MSTK_VidSetIntervalSingle(u32 Copy_u32Delay,void (*PTR)(void)){
	/*        STOP TIMER*/
	CLR_BIT(STK->CTRL,STK_ENABLE ); //ENABLE the Timer//
	STK->VAL=0;
	
    STK->LOAD= Copy_u32Delay;//Send the Value//
	GlobalPointer=PTR;//ISR
	SET_BIT(STK->CTRL,STK_INTERRUPT); //ENABLE the Timer//
	SET_BIT(STK->CTRL,STK_ENABLE ); //ENABLE the Timer//
	
	MSTK_u8ModeOfInterval=MSTK_SINGLE_INTERVAL;
	

}



void MSTK_VidSetIntervalPeriodic(u32 Copy_u32Delay,void (*PTR)(void)){
	
	CLR_BIT(STK->CTRL,STK_ENABLE ); //DISABLE the Timer//
	STK->VAL=0;

    STK->LOAD= Copy_u32Delay;//Send the Value//
	GlobalPointer=PTR;
	SET_BIT(STK->CTRL,STK_INTERRUPT); //ENABLE the Timer//
	SET_BIT(STK->CTRL,STK_ENABLE ); //ENABLE the Timer//

	MSTK_u8ModeOfInterval=MSTK_PERIOD_INTERVAL ;


}

void MSYSTICK_VidStopInterval(void){

	
	CLR_BIT(STK->CTRL,STK_INTERRUPT); //DISABLE the Timer Interrupt//
	CLR_BIT(STK->CTRL,STK_ENABLE ); //  DISABLE the Timer//
	STK->VAL=0;
	STK->LOAD=0;
}

u32 MSTK_u32GetEclipsedTime(void){
	
	//Return Eclipsed Time in Ms//
	
	u32 Local_u32EclipsedTime;
	Local_u32EclipsedTime=(STK->LOAD)-(STK->VAL);
	
	
	return Local_u32EclipsedTime;
	
	
}
u32 MSTK_u32GetRemainingTime(void){

    u32 Local_u32RemainingTime;

	Local_u32RemainingTime=STK->VAL;

	return Local_u32RemainingTime;
}


 
void SysTick_Handler(void){
	u8 Read_flag;
	
	if(MSTK_u8ModeOfInterval==MSTK_SINGLE_INTERVAL){
		
          CLR_BIT(STK->CTRL,STK_INTERRUPT); //DISABLE the Timer Interrupt//
          CLR_BIT(STK->CTRL,STK_ENABLE ); //  DISABLE the Timer//
          STK->VAL=0;
          STK->LOAD=0;	
	}
	
	GlobalPointer();
	Read_flag=GET_BIT(STK->CTRL,STK_FLAG);//read the flag to clear
}
 
 
 
