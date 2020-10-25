/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 22 August 2020             */
/* version     : ver 1                      */
/* Description : SYSTICK                    */
/********************************************/
#ifndef _SYSTICK_INTERFACE_H
#define _SYSTICK_INTERFACE_H




void MSYSTCIK_VidInit(void);
void MSYSTICK_VidEnableInterruptDelayMs(u32 Copy_u32DelayMs);
void MSYSTICK_VidDisableInterruptDelay(void);
void MSYSTICK_VidDelayMs(u32 Copy_u32Delay);
// void SysTick_Handler(void);     ISR


#endif
