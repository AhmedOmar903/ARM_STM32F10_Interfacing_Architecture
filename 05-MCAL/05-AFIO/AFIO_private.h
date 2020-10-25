/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 22 August 2020             */
/* version     : ver 1                      */
/* Description : AFIO                       */
/********************************************/
#ifndef _AFIO_PRIVATE_H
#define _AFIO_PRIVATE_H

typedef Struct{
	volatile u32 EVCR;
	volatile u32 MAPR;
    volatile u32 EXTICR[4];
	volatile u32 MAPR2;
}AFIO_t;

#define AFIO  ((volatile AFIO_t*)0x40010000)


#endif