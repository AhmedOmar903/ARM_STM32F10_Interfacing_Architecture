/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 6 September 2020           */
/* version     : ver 1                      */
/* Description : OS                         */
/********************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "SYSTICK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"


static TASK OS_Tasks[NUMBER_OF_TASKS]={NULL}; // ARRAY 


void OS_VidTaskCreate(u8 Copy_u8TaskPirority,u16 COpy_u16Priodicity, void (*LocalPointerToFunction)(void),u8 Copy_u8FirstDelay)
{


	OS_Tasks[Copy_u8TaskPirority].Priodicity=COpy_u16Priodicity;	
	OS_Tasks[Copy_u8TaskPirority].PointerToFunction=LocalPointerToFunction;
	OS_Tasks[Copy_u8TaskPirority].FirstDelay=Copy_u8FirstDelay;
	OS_Tasks[Copy_u8TaskPirority].TaskState=Resumed;
	
	
}
void OS_VidStartSchedular(void)
{
	
	/*Initial Systick  AHB/8*/
	MSYSTCIK_VidInit();
	//Tick Time =1ms
	MSTK_VidSetIntervalPeriodic(1000,OS_VidSchedular);
	
	
}


static void OS_VidSchedular(void)
{
	u8 Local_u8Index=0;
	
	for(Local_u8Index=0;Local_u8Index<NUMBER_OF_TASKS;Local_u8Index++)
	{
		if((OS_Tasks[Local_u8Index].PointerToFunction!=NULL)&&(OS_Tasks[Local_u8Index].TaskState==Resumed))
		{
			if((OS_Tasks[Local_u8Index].FirstDelay)==0)
			{
				OS_Tasks[Local_u8Index].FirstDelay=OS_Tasks[Local_u8Index].Priodicity-1;
				OS_Tasks[Local_u8Index].PointerToFunction();
			}
			else
			{
				OS_Tasks[Local_u8Index].FirstDelay--;
			}
			
		}
	}
}`



void OS_vidSchedularSuspend(u8 Copy_u8TaskId)
{
	
	OS_Tasks[Copy_u8TaskId].TaskState=SUSPENDED;
}
void OS_vidSchedularResume(u8 Copy_u8TaskId)
{
	
OS_Tasks[Copy_u8TaskId].TaskState=Resumed;

}

void OS_vidSchedularKillTask(u8 Copy_u8TaskId)
{
	OS_Tasks[Copy_u8TaskId].PointerToFunction=NULL;
}

/*
static void OS_VidSchedular(void)
{
	volatile u16 TickCounts=0;

	u8 Local_u8Index=0;
	
	for(Local_u8Index=0;Local_u8Index<NUMBER_OF_TASKS;Local_u8Index++)
	{
		if((TickCounts %OS_Tasks[Local_u8Index].Priodicity)==0)
		{
			OS_Tasks[Local_u8Index].PointerToFunction();
		}
	}
	TickCounts++;
}
*/

