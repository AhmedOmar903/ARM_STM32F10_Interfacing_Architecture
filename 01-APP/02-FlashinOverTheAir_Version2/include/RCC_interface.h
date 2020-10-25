/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 11 August 2020             */
/* version     : ver 1                      */
/********************************************/
#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

//************BUS NAME*****************//
#define RCC_AHB             0
#define RCC_APB1            1
#define RCC_APB2            2


//************APB2 BITS*****************//

#define  IOPA               2
#define  USART1             14

//*************************************//




void RCC_VoidInitSystemClk(void);
void RCC_VoidEnableClock(u8 Copy_u8BusName,u8 Copy_u8PreId);//BUS_NAME,Prepherial ID//


#endif
