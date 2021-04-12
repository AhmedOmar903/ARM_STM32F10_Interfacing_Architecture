/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 28 September 2020          */
/* version     : ver 1                      */
/* Description : ADC                        */
/********************************************/
#ifndef _TIMER_INTERFACE_H
#define _TIMER_INTERFACE_H



typedef enum
{
  TIMER1,
  TIMER2,
  TIMER3,
  TIMER4


}TIMERS_Channel;



#define UP_COUNTER       0
#define DOWN_COUNTER     1



void TIMER_VoidInitailze(TIMERS_Channel Copy_TimerChannelIntit, u8 Copy_u8TimerMode);

void TIMER_VoidTimerStartAsyncrouonas(TIMERS_Channel Copy_TimerChannelIntit, u32 Copy_u16TickTime,void (*LocalPointerToFunction)(void));

void TIMER_VoidDisableTheTimer(TIMERS_Channel Copy_TimerChannelIntit);

#endif
