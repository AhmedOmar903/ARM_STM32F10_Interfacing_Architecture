/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 19 August 2020             */
/* version     : ver 1                      */
/* Description : NVIC                       */
/********************************************/
#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H

#define NVIC_BASE_ADDRESS                     0xE000E100

#define NVIC_ISER0         *((volatile u32*)(0x000+NVIC_BASE_ADDRESS)) //Enable of the NVIC from 0 to 31//
#define NVIC_ISER1         *((volatile u32*)(0x004+NVIC_BASE_ADDRESS)) //Enable of the NVIC from 31 to 63//

#define NVIC_ICER0         *((volatile u32*)(0x080+NVIC_BASE_ADDRESS)) //DISABLE of the NVIC from 0 to 31//
#define NVIC_ICER1         *((volatile u32*)(0x084+NVIC_BASE_ADDRESS)) //DISABLE of the NVIC from 31 to 63//

#define NVIC_ISPR0         *((volatile u32*)(0x100+NVIC_BASE_ADDRESS))    //Set Pending Flag for test || debg//
#define NVIC_ISPR1         *((volatile u32*)(0x104 +NVIC_BASE_ADDRESS))   //Set Pending Flag for test || debg//

#define NVIC_ICPR0         *((volatile u32*)(0x180 +NVIC_BASE_ADDRESS)) //CLR Pending Flag //
#define NVIC_ICPR1         *((volatile u32*)(0x184 +NVIC_BASE_ADDRESS)) //CLR Pending Flag //


#define NVIC_IABR0         *((volatile u32*)(0x200 +NVIC_BASE_ADDRESS)) //ACTIVE FLAG //
#define NVIC_IABR1         *((volatile u32*)(0x204 +NVIC_BASE_ADDRESS)) //ACTIVE FLAG //

#define NVIC_IPR           ((volatile u8*)(0xE000E100+0x300)) //we define it u8 becouse we can access bytes //

#define SOC_AIRCR          *((volatile u32*)(0xE000ED00+0x0C))//to control IPR//        



#define Group3         0x05FA0300   //4 BITS IPR for Groups and 1 for Sub &&* 16 Group & 0  subGroup//
#define Group4         0x05FA0400   //3 BITS IPR for Groups and 1 for Sub &&* 8  Group & 2  subGroup//
#define Group5         0x05FA0500   //2 BITS IPR for Groups and 2 for Sub &&* 4  Group & 4  subGroup//
#define Group6         0x05FA0600   //1 BITS IPR for Groups and 3 for Sub &&* 2  Group & 8  subGroup//
#define Group7         0x05FA0700   //0 BITS IPR for Groups and 4 for Sub &&* 0  Group & 16 subGroup//



#endif