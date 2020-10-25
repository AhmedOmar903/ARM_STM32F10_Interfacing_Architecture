
/* Library includes */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/* module includes */
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"


volatile TIMER_type*TIM[4]=
{
	 ((volatile TIMER_type*)(0x40012C00)) , //TIMER 1
     ((volatile TIMER_type*)(0x40000000)) ,//TIMER2
     ((volatile TIMER_type*)(0x40000400)),//Timer3
	 ((volatile TIMER_type*)(0x40000800))//Timer4
};

u16 Global_u16OverFlow=0;

u8 Global_u8Counter=0;


void TIMER_VoidInitailze(TIMERS_Channel Copy_TimerChannelIntit, u8 Copy_u8TimerMode)
{

	MNVIC_VidInterruptEnable(28);
	RCC_VoidEnableClock(RCC_APB1   ,TIME2  );
	switch(Copy_u8TimerMode)
	{
	case DOWN_COUNTER : SET_BIT((TIM[Copy_TimerChannelIntit]->CR1),4);/*DownCounter*/ break;
	case UP_COUNTER   : CLR_BIT((TIM[Copy_TimerChannelIntit]->CR1),4);/*DownCounter*/ break;
	}
	SET_BIT((TIM[Copy_TimerChannelIntit]->DIER),0);/*Enable The Interrupt*/
	(TIM[Copy_TimerChannelIntit]->PSC) =7;   /*	1MHZ	*/
	SET_BIT((TIM[Copy_TimerChannelIntit]->CR1),0);/*Enable The Timer*/

}


void TIMER_VoidTimerStartAsyncrouonas(TIMERS_Channel Copy_TimerChannelIntit, u32 Copy_u16TickTime,void (*LocalPointerToFunction)(void))
{

     Global_u16OverFlow=0;
	(TIM[Copy_TimerChannelIntit]->CNT)=0;
	(TIM[Copy_TimerChannelIntit]->ARR)=Copy_u16TickTime;
	GlobalPointerToFunction=LocalPointerToFunction;
}


/************** ISR handlers ******************/

void TIM2_IRQHandler (void){
	/* Clear flag */


	GlobalPointerToFunction();
	CLR_BIT ((TIM[1]->SR), 0);

	Global_u16OverFlow++;
}
void TIM3_IRQHandler (void){
	/* Clear flag */
	GlobalPointerToFunction();

	CLR_BIT ((TIM[2]->SR), 0);
	Global_u16OverFlow++;
}
void TIM4_IRQHandler (void){
	/* Clear flag */
	GlobalPointerToFunction();
	CLR_BIT ((TIM[3]->SR), 0);
	Global_u16OverFlow++;
}
