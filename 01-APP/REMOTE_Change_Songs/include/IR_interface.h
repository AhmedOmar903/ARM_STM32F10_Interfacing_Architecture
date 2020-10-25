/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 5 September 2020           */
/* version     : ver 2                      */
/* Description : INFRA_RED                  */
/********************************************/
#ifndef _IR_INTERFACE_H
#define _IR_INTERFACE_H

typedef enum{
	Remote_POWER           ,
	Remote_MODE           ,
	Remote_MUTE           ,
	Remote_PLAY_RESUME    ,
	Remote_RIGHT          ,
	Remote_LEFT           ,
	Remote_EQ             ,
	Remote_VOL_DOWN       ,
	Remote_VOL_UP         ,
	Remote_ZERO           ,
	Remote_RPT            ,
	Remote_U_USD          ,
	Remote_ONE            ,
	Remote_TWO            ,
	Remote_THREE          ,
	Remote_FOUR           ,
	Remote_FIVE           ,
	Remote_SIX            ,
	Remote_SEVEN          ,
	Remote_EIGHT          ,
	Remote_NINE           ,
	Remote_ERROR
	
}Remote_button_t;

/*
the funtion will initialize the NVIC ,Enable The Chossen EXTI in NVIC ,INIT EXTI ,Enable The Chossen EXTI LINE,SYSTICK,
and Set Pin direction.

*/

void HINFRARED_VidInitail(void);

/*
Create Avariable it type Remote_button_t then you will receive the value of the pressed button in the created variable

*/
Remote_button_t HINFRARED_GetRemotePressedButton(void);

u8 HINFRA_u8ReadPendingFlag(void);
//this Flag will set if the DATA and ADDRESS are right .Also,it cleared after Recieving the Value From GetRemotePressedButton

void HINFRA_VidSetCallBack(void (*Local_Pointer)(u8 Copy_u8InfraRedData)); 

/*
Create A function That is take u8 Paramater then pass it to  HINFRARED_SetcallBack function.
 this parameter will be the value of the pressed button
 loop on it .Also,don't forget to enable IR_INTERRUPT

*/


#endif
