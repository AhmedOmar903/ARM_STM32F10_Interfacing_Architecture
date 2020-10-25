/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 11 August 2020             */
/* version     : ver 1                      */
/********************************************/


#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H
//Register Defintion//
#define RCC_BASE_ADDRESS              0x40021000
#define RCC_CR                       *((volatile u32*)(0x00+RCC_BASE_ADDRESS)) //choose Clk to proccesor//
#define RCC_CFGR                     *((volatile u32*)(0x04+RCC_BASE_ADDRESS)) //choose Clk to proccesor//
#define RCC_CIR                      *((volatile u32*)(0x08+RCC_BASE_ADDRESS))
#define RCC_APB2RSTR                 *((volatile u32*)(0x0C+RCC_BASE_ADDRESS))
#define RCC_APB1RSTR                 *((volatile u32*)(0x010+RCC_BASE_ADDRESS))
#define RCC_AHBENR                   *((volatile u32*)(0x14+RCC_BASE_ADDRESS)) //ENABLE AND DISABLE CLK//
#define RCC_APB2ENR                  *((volatile u32*)(0x18+RCC_BASE_ADDRESS)) //ENABLE AND DISABLE CLK//
#define RCC_APB1ENR                  *((volatile u32*)(0x1C+RCC_BASE_ADDRESS)) //ENABLE AND DISABLE CLK//
#define RCC_BDCR                     *((volatile u32*)(0x20+RCC_BASE_ADDRESS))
#define RCC_CSR                      *((volatile u32*)(0x24+RCC_BASE_ADDRESS))

//*****************************************************************************************************//

//CLK TYPES//
#define RCC_HSE_CRYSTAL       0
#define RCC_HSE_RC            1
#define RCC_HSI               2
#define RCC_PLL               3
//*****************************************************************************************************//


//PLL TYPES//
#define RCC_PLL_IN_HSI_DIV_2            0
#define RCC_PLL_IN_HSE_DIV_2            1
#define RCC_PLL_IN_HSE                  2
//MULTI//
//*****************************************************************************************************//

#define PLL2      0
#define PLL3      1
#define PLL4      2
#define PLL5      3
#define PLL6      4
#define PLL7      5
#define PLL8      6
#define PLL9      7
#define PLL10     8
#define PLL11     9
#define PLL12     10
#define PLL13     11
#define PLL14     12
#define PLL15     13
#define PLL16     14
#define PLL17     15
//*****************************************************************************************************//
#define ON     0
#define OFF    1

#endif
