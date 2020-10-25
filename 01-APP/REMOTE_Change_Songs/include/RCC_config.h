/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 11 August 2020             */
/* version     : ver 1                      */
/********************************************/
#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

/*
types   RCC_HSE_CRYSTAL
        RCC_HSE_RC
        RCC_HSI
        RCC_PLL
*/


#define CLK_TYPE                    RCC_HSE_CRYSTAL


/*
PLL INPUT TYPES:
	RCC_PLL_IN_HSI_DIV_2
	RCC_PLL_IN_HSE_DIV_2
	RCC_PLL_IN_HSE    
	
MAX:
(PLL2,PLL3,PLL4,PLL5,PLL6,PLL7,PLL8,PLL9,PLL10,PLL11,PLL12,PLL13,PLL14,PLL15,PLL16,PLL17)
  
 while using External Crystal make  RCC_PLL_BYP=OFF else ON

*/
#if CLK_TYPE==RCC_PLL

   #define RCC_PLL_INPUT              RCC_PLL_IN_HSE_DIV_2 //PLL MODE//
   #define RCC_PLL_MAX                PLL15//Multi Factor//
   #define RCC_PLL_BYP                OFF  //while using HSE RC Enable RCC_PLL_BYP // 
   
#endif

#endif
