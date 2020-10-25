/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 13 September 2020          */
/* version     : ver 1                      */
/* Description : DMA                        */
/********************************************/
#ifndef _DMA_PRIVATE_H
#define _DMA_PRIVATE_H


typedef struct 
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
    volatile u32 Reserved;	
}DMA_Channel;



typedef struct 
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel Channel[7];
}DMA_t;





#define DMA          ((volatile DMA_t*)0x40020000)



static void (*GlobalPointerToFunction[7])(void);


#define EN                           0
#define MEM2MEM                     14






#endif
