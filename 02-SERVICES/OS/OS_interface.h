/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 6 September 2020           */
/* version     : ver 1                      */
/* Description : OS                         */
/********************************************/

#ifndef _OS_INTERFACE_H_
#define _OS_INTERFACE_H_


/*
TASK ID & TASK Pirority are the Same
*/

void OS_VidTaskCreate(u8 Copy_u8TaskPirority,u16 COpy_u16Priodicity, void (*LocalPointerToFunction)(void),u8 Copy_u8FirstDelay);
void OS_VidStartSchedular(void);
void OS_vidSchedularSuspend(u8 Copy_u8TaskId);
void OS_vidSchedularResume(u8 Copy_u8TaskId);
void OS_vidSchedularKillTask(u8 Copy_u8TaskId);



#endif
