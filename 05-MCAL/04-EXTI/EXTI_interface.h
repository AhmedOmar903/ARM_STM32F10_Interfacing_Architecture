/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 22 August 2020             */
/* version     : ver 1                      */
/* Description : EXTI                       */
/********************************************/
#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H

#define FALLING         0
#define RISING          1
#define ON_CHANGE       2

//LINE is choosed according to wanted pin  From the A0 to A15   ,  B0 to B15   ,  C0 to C15   ETC//

void MEXTI_VidInit(void);
void MEXTI_VidExtiEnable(u8 Copy_u8ExtiNum);
void MEXTI_VidExtiDisable(u8 Copy_u8ExtiNum);
void MEXTI_VidSwTrigger(u8 Copy_u8ExtiNum);


// line which pin     mode falling or rising

void MEXTI_VidSetSignalLactch(u8 Copy_u8PinNum,u8 Copy_u8Mode);

void MEXTI_VidSetCallBack(void (*LocalPointer)(void), u8 Copy_u8ExtiNum);
#endif
