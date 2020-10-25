/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 14 octbar    2020          */
/* version     : ver 1                      */
/* Description : FPEC                       */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "FPEC_interface.h"
#include "FPEC_private.h"
#include "FPEC_config.h"



void FPEC_VoidEraseAppArea(void)
{
	for(u8 Local_u8Index=4;Local_u8Index<64;Local_u8Index++)
	{
		FPEC_VoidFlashPageErase(Local_u8Index);
		
	}
}


void FPEC_VoidFlashPageErase(u8 Copy_u8PageNumber)
{
	
	while(GET_BIT(FPEC->SR,0)==1);
	
	if(GET_BIT(FPEC->CR,7)==1)
	{
		FPEC->KEYR=0x45670123;
		FPEC->KEYR=0xCDEF89AB;
	}
	
	SET_BIT(FPEC->CR,1); /*Erase Mode is Choosen*/
	
	
	FPEC ->ARR = (u32)(Copy_u8PageNumber * 1024) + 0x08000000 ; /**/
	
	SET_BIT(FPEC->CR,6); /*Start the Erasing Operation*/
	
	while(GET_BIT(FPEC->SR,0)==1);
	
	SET_BIT(FPEC->SR,5);/*END OF Page*/
	CLR_BIT(FPEC->CR,1); /*Erase Mode Cleared*/	
}



void FPEC_VoidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length)
{
	while (GET_BIT(FPEC->SR,0) == 1);

	
	if (GET_BIT(FPEC->CR,7) == 1 )
	{
		FPEC -> KEYR = 0x45670123;
		FPEC -> KEYR = 0xCDEF89AB;
	}
	
	
	SET_BIT(FPEC->CR,0); /*Flashing mode is Chossen*/
	
	FPEC ->ARR=Copy_u32Address;
	
	
}

