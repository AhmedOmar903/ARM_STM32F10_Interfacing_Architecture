/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 28 September 2020          */
/* version     : ver 1                      */
/* Description : ADC                        */
/********************************************/
#ifndef _ADC_PRIVATE_H
#define _ADC_PRIVATE_H




typedef struct
{
	volatile u32 SR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMPR[2];
	volatile u32 JOFR[4];
	volatile u32 HTR;
	volatile u32 LTR;
	volatile u32 SQR[3];
	volatile u32 JSQR;
	volatile u32 JDR1[4];
	volatile u32 DR;
}ADC_type;

#define ADC1       ((volatile ADC_type*)0x40012400)



#endif


