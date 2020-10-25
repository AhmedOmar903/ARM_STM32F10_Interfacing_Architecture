/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 12 August 2020             */
/* version     : ver 1                      */
/* Description : GPIO                       */
/********************************************/
#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

#define GPIOA_BASE_ADDRESS             0x40010800
#define GPIOB_BASE_ADDRESS             0x40010C00 
#define GPIOC_BASE_ADDRESS             0x40011000

 /*         REGISTER ADRESSES FOR PORTA           */
#define GPIOA_CRL             *(( u32*)(0x00+GPIOA_BASE_ADDRESS))
#define GPIOA_CRH             *(( u32*)(0x04+GPIOA_BASE_ADDRESS))
#define GPIOA_IDR             *((volatile u32*)(0x08+GPIOA_BASE_ADDRESS)) 
#define GPIOA_ODR             *((volatile u32*)(0x0C+GPIOA_BASE_ADDRESS)) 
#define GPIOA_BSRR            *((volatile u32*)(0x10+GPIOA_BASE_ADDRESS)) 
#define GPIOA_BRR             *((volatile u32*)(0x14+GPIOA_BASE_ADDRESS)) 
#define GPIOA_LCKR            *((volatile u32*)(0x18+GPIOA_BASE_ADDRESS)) 

 /*         REGISTER ADRESSES FOR PORTB            */
#define GPIOB_CRL             *(( u32*)(0x00+GPIOB_BASE_ADDRESS))
#define GPIOB_CRH             *(( u32*)(0x04+GPIOB_BASE_ADDRESS))
#define GPIOB_IDR             *((volatile u32*)(0x08+GPIOB_BASE_ADDRESS)) 
#define GPIOB_ODR             *((volatile u32*)(0x0C+GPIOB_BASE_ADDRESS)) 
#define GPIOB_BSRR            *((volatile u32*)(0x10+GPIOB_BASE_ADDRESS)) 
#define GPIOB_BRR             *((volatile u32*)(0x14+GPIOB_BASE_ADDRESS)) 
#define GPIOB_LCKR            *((volatile u32*)(0x18+GPIOB_BASE_ADDRESS)) 

 /*         REGISTERS ADRESSES FOR PORTC           */
#define GPIOC_CRL             *(( u32*)(0x00+GPIOC_BASE_ADDRESS))
#define GPIOC_CRH             *(( u32*)(0x04+GPIOC_BASE_ADDRESS))
#define GPIOC_IDR             *((volatile u32*)(0x08+GPIOC_BASE_ADDRESS)) 
#define GPIOC_ODR             *((volatile u32*)(0x0C+GPIOC_BASE_ADDRESS)) 
#define GPIOC_BSRR            *((volatile u32*)(0x10+GPIOC_BASE_ADDRESS)) 
#define GPIOC_BRR             *((volatile u32*)(0x14+GPIOC_BASE_ADDRESS)) 
#define GPIOC_LCKR            *((volatile u32*)(0x18+GPIOC_BASE_ADDRESS))
			





#endif
