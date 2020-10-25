/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 5 September 2020           */
/* version     : ver 2                      */
/* Description : INFRA_RED                  */
/********************************************/
#ifndef _IR_INTERFACE_H
#define _IR_INTERFACE_H


#define POWER                      69
#define MODE                       70
#define MUTE                       71
#define PLAY_RESUME                68
#define RIGHT                      64
#define LEFT                       67
#define EQ                         7
#define VOL_DOWN                   21
#define VOL_UP                     9
#define ZERO                       22
#define RPT                        25
#define U_USD                      13
#define ONE                        12
#define TWO                        24
#define THREE                      94
#define FOUR                       8
#define FIVE                       28
#define SIX                        90
#define SEVEN                      60
#define EIGHT                      82
#define NINE                       74

/*
the funtion will initialize the NVIC ,Enable The Chossen EXTI in NVIC ,INIT EXTI ,Enable The Chossen EXTI LINE,SYSTICK,
and Set Pin direction.

*/

void HINFRARED_VidInitail(void);

/*
Create Avariable its type Remote_button_t then you will receive the value of the pressed button in the created variable

*/
u8 HINFRARED_GetRemotePressedButton(void);

u8 HINFRA_u8ReadPendingFlag(void);
//this Flag will set if the DATA and ADDRESS are right .Also,it cleared after Recieving the Value From GetRemotePressedButton

void HINFRA_VidSetCallBack(void (*Local_Pointer)(u8 Copy_u8InfraRedData)); 

/*
Create A function That is take u8 Paramater then pass it to  HINFRARED_SetcallBack function.
 this parameter will be the value of the pressed button
 loop on it .Also,don't forget to enable IR_INTERRUPT

*/


#endif
