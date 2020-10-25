/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 27 August 2020             */
/* version     : ver 2                      */
/* Description : SYSTICK                    */
/********************************************/
#ifndef _SYSTICK_INTERFACE_H
#define _SYSTICK_INTERFACE_H



void MSYSTCIK_VidInit(void);



void MSTK_VidSetIntervalSingle(u32 Copy_u32Delay,void (*PTR)(void));


void MSYSTICK_VidStopInterval(void);

#endif
