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
//************AHB BITS*****************//
#define  SDIO               10
#define  FSMC               8
#define  CRCE               6
#define  FLITF              4
#define  SRAM               2
#define  DMA2               1
#define  DMA1               0
//*************************************//

//************APB2 BITS*****************//
#define  AFIO               0
#define  IOPA               2
#define  IOPB               3 
#define  IOPC               4
#define  IOPD               5 
#define  IOPE               6 
#define  IOPF               7 
#define  IOPG               8 
#define  ADC1               9 
#define  ADC2               10 
#define  TIM1               11 
#define  SPI1               12 
#define  TIM8               13 
#define  USART1             14 
#define  ADC3               15 
#define  TIM9               19 
#define  TIM10              20 
#define  TIM11              21 
//*************************************//

//************APB1 BITS*****************//
#define  TIM2                0
#define  TIM3                1
#define  TIM4                2
#define  TIM5                3 
#define  TIM6                4
#define  TIM7                5 
#define  TIM12               6 
#define  TIM13               7 
#define  TIM14               8 
#define  WWDG                11 
#define  SPI2                14 
#define  SPI3                15 
#define  USART2              17
#define  USART3              18
#define  USART4              19
#define  USART5              20
#define  I2C1                21 
#define  I2C2                22 
#define  USB                 23 
#define  CAN                 25 
#define  BKP                 27 
#define  PWR                 28 
#define  DAC                 29 

//*************************************//


void RCC_VoidInitSystemClk(void);
void RCC_VoidEnableClock(u8 Copy_u8BusName,u8 Copy_u8PreId);//BUS_NAME,Prepherial ID//
void RCC_VoidDisableClock(u8 Copy_u8BusName,u8 Copy_u8PreId);


#endif
