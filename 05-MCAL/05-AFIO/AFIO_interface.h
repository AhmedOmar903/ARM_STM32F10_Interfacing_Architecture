/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 22 August 2020             */
/* version     : ver 1                      */
/* Description : AFIO                       */
/********************************************/
#ifndef _AFIO_INTERFACE_H
#define _AFIO_INTERFACE_H

#define PORTA_AF       0
#define PORTB_AF       1
#define PORTC_AF       2

//line 0 is to choose PIN number ex 0,1,2,3,  ETC       port to identify which PORT ex A0 or A1 B6
void MAFIO_VoidSetExtiConfig(u8 Copy_u8Line,u8 Copy_u8Portmap); 



#endif
