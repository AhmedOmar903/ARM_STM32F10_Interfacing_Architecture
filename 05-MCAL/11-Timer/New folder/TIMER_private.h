/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 28 September 2020          */
/* version     : ver 1                      */
/* Description : ADC                        */
/********************************************/
#ifndef _TIMER_PRIVATE_H
#define _TIMER_PRIVATE_H


typedef struct
{

	volatile u32 CR1 ;
	volatile u32 CR2 ;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR  ;
	volatile u32 EGR ;
	volatile u32 CCMR;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT ;
	volatile u32 PSC ;
	volatile u32 ARR ;
	volatile u32 RCR ;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 BDTR;
	volatile u32 DCR ;
	volatile u32 DMAR;
}TIMER_type;


void (*GlobalPointerToFunction)(void);



#endif


