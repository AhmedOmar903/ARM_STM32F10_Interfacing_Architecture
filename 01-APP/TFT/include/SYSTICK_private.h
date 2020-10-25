/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 27 August 2020             */
/* version     : ver 2                      */
/* Description : SYSTICK                    */
/********************************************/
#ifndef _SYSTICK_PRIVATE_H
#define _SYSTICK_PRIVATE_H

typedef struct{
	
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL ;
	volatile u32 CALIB;
	
	
}SYSTICK_t;


#define STK      ((volatile SYSTICK_t*)0xE000E010)


#define SYTK_AHB           0
#define SYTK_AHB_8         1


#define STK_ENABLE         0
#define STK_INTERRUPT      1
#define STK_CLK_SOURCE     2
#define STK_FLAG           16


#define DISABLE           0
#define ENABLE            1

#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1

static void (*GlobalPointer)(void); 

#endif
