/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 6 September 2020           */
/* version     : ver 1                      */
/* Description : OS                         */
/********************************************/

#ifndef _OS_PRIVATE_H_
#define _OS_PRIVATE_H_

typedef struct OS
{
	
	u16 Priodicity;
	void (*PointerToFunction)(void);
	u16 FirstDelay;
	u8 TaskState;
	
}TASK;


static void OS_VidSchedular(void)=NULL;

#define SUSPENDED      0
#define Resumed        1



#endif