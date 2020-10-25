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

void MSYSTCIK_VidInit(void){

#if CLK==SYTK_AHB_8
 CLR_BIT(STK->CTRL,STK_CLK_SOURCE);
#elif  CLK ==SYTK_AHB
 SET_BIT(STK->CTRL,STK_CLK_SOURCE);
#endif

}

void MSTK_VidSetBusyWait(u32 Copy_u32Delay){
	
     u8 Read_flag;
	 Copy_u32Delay*=1000;  //MS//
	 STK->VAL=0;
	 STK->LOAD= Copy_u32Delay;//Send the Value//
	 SET_BIT(STK->CTRL,STK_ENABLE ); //ENABLE the Timer//
	while(GET_BIT(STK->CTRL,STK_FLAG)==0);// wait

	Read_flag=GET_BIT(STK->CTRL,STK_FLAG);//read the flag to clear

}

void MSTK_VidSetIntervalSingle(u32 Copy_u32Delay,void (*PTR)(void)){
	
	STK->VAL=0;
	Copy_u32Delay*=1000;
    STK->LOAD= Copy_u32Delay;//Send the Value//
	SET_BIT(STK->CTRL,STK_INTERRUPT); //ENABLE the Timer//
	SET_BIT(STK->CTRL,STK_ENABLE ); //ENABLE the Timer//
	GlobalPointer=PTR;//ISR
	STK->LOAD=0;//STop Timer//
}

void MSTK_VidSetIntervalPeriodic(u32 Copy_u32Delay,void (*PTR)(void)){
	
	STK->VAL=0;
	Copy_u32Delay*=1000;
    STK->LOAD= Copy_u32Delay;//Send the Value//
	SET_BIT(STK->CTRL,STK_INTERRUPT); //ENABLE the Timer//
	SET_BIT(STK->CTRL,STK_ENABLE ); //ENABLE the Timer//
	

	GlobalPointer=PTR;

}

void MSYSTICK_VidStopInterval(void){

	STK->VAL=0;
	STK->LOAD=0;
	CLR_BIT(STK->CTRL,STK_INTERRUPT); //DISABLE the Timer//
	CLR_BIT(STK->CTRL,STK_ENABLE ); //  DISABLE the Timer//
}

u32 MSTK_u32GetEclipsedTime(void){
	
	//Return Eclipsed Time in Ms//
	u32 Result=(STK->LOAD)-(STK->VAL);
	
	Result=(Result*0.001);
	
	return Result;
	
	
}
u32 MSTK_u32GetRemainingTime(void){
	//Return Remaining Time in Ms//
	u32 Result=STK->VAL;
	Result=(Result*0.001);
	return Result;
}


 
void SysTick_Handler(void){
	
	GlobalPointer();
}
 
 
 
