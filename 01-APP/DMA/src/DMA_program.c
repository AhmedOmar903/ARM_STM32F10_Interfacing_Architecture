/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 13 September 2020          */
/* version     : ver 1                      */
/* Description : DMA                        */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"



void DMA_VoidChannelInitial(void)
{
  		
		/*Intialize RCC CLK*/
		RCC_VoidInitSystemClk();
        RCC_VoidEnableClock(RCC_AHB,DMA1);
		
		
	
}

void DMA_VoidChannelConfig(u8 Copy_u8ChannelX,u8 Copy_u8MemMode,u8 Copy_u8Pirority,u8 Copy_u8Msiz,u8 Copy_u8Psize)
{
	/*MEMORY MODE*/
	switch(Copy_u8MemMode)
	{
		case MemDisabled:CLR_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),MEM2MEM); break;
		case MemEnabled:SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),MEM2MEM); break;
	}
	/*Channel Pirority*/
	switch(Copy_u8Pirority)
	{
		case VERY_HIGH_PIRORITY  :
							SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),12);
							SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),13);
							break;
		case HIGH_PIRORITY       :
							CLR_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),12);
							SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),13);
							break;
		case MEDIUM_PIRORITY     :
							SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),12);
							CLR_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),13);
							break;
		case LOW_PIRORITY        :
							SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),12);
							SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),13);
							break;
	}
	/*MSIZE*/
	switch(Copy_u8Msiz)
	{
		case BYTE          : 
							CLR_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),10);
							CLR_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),11);
							break;
            		
		case TWO_BYTE      : 
							SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),10);
							CLR_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),11);
							break;
		case FOUR_BYTE     :  
							CLR_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),10);
							SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),11);
							break;
	}  
        /* Peripheral Size*/	
	switch(Copy_u8Psize)
	{
		case BYTE          : 
							CLR_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),8);
							CLR_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),9);
							break;
            		
		case TWO_BYTE      : 
							SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),8);
							CLR_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),9);
							break;
		case FOUR_BYTE     :  
							CLR_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),8);
							SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),9);
							break;
	}   
	
	
	
}

void DMA_VoidChannelEnable(u8 Copy_u8ChannelX,u8 Copy_u8ChannelNvic,u8 Copy_u8Minc,u8 Copy_u8Pinc,u8 Copy_u8DataDirection)
{
	MNVIC_VidInterruptEnable(Copy_u8ChannelNvic);//Enable Channel Active Flag
	/*Memory Increment or Fixed Address*/
	switch(Copy_u8Minc)
	{
		case INCREMENT_DISABLED   :CLR_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),7); break;                
		case INCREMENT_ENABLED    :SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),7); break;
	}
	/*Periheral Increment or Fixed Address*/
	switch(Copy_u8Pinc)
	{
		case INCREMENT_DISABLED   :CLR_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),6); break;                
		case INCREMENT_ENABLED    :SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),6); break;
	}
	/*THE Source will be the preipheral or the memory*/
	switch(Copy_u8DataDirection)
	{
		case PSOURCE   :CLR_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),4); break;                
		case MSOURCE   :SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),4); break;
	}
	/*Enabel The Transfer Complete Interrupt*/
	SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),1);
	/*Enabel The Selected Channel*/
	SET_BIT((DMA-> Channel[Copy_u8ChannelX].CCR),EN);
}


void DMA_VidChannelStart(u8 Copy_ChannelX,u32 *Copy_u32SourceAddress,u32 *Copy_u32DestinationAddress, u16 Copy_u16BlockLength)
{
	/*    make sure that CCR Disabled  */
	CLR_BIT(DMA-> Channel[Copy_ChannelX].CCR,EN );	
	/*    Write Address  of the Source */
	DMA -> Channel[Copy_ChannelX].CPAR=Copy_u32SourceAddress;
	/*    Write Address  of the Destination */
	DMA -> Channel[Copy_ChannelX].CMAR=Copy_u32DestinationAddress;
	/*   Block Length */
	DMA -> Channel[Copy_ChannelX].CNDTR=Copy_u16BlockLength;
	
	SET_BIT(DMA-> Channel[Copy_ChannelX].CCR,EN );/*ENABLE*/
}


void DMA_VoidSetCallBack(void (*LocalPoniterToFunction)(void),u8 Copy_u8ChannelX)
{
	GlobalPointerToFunction[Copy_u8ChannelX]=LocalPoniterToFunction;
}

void DMA1_Channel1_IRQHandler(void)
{

	GlobalPointerToFunction[CHANNEL1]();
	/*Clear the Flag*/
	SET_BIT(DMA->IFCR,0);
	SET_BIT(DMA->IFCR,1);


}

void DMA1_Channel2_IRQHandler(void)
{

	GlobalPointerToFunction[CHANNEL2]();
	/*Clear the Flag*/
	SET_BIT(DMA->IFCR,4);
	SET_BIT(DMA->IFCR,5);


}
void DMA1_Channel3_IRQHandler(void)
{

	GlobalPointerToFunction[CHANNEL3]();
	/*Clear the Flag*/
	SET_BIT(DMA->IFCR,8);
	SET_BIT(DMA->IFCR,9);


}
void DMA1_Channel4_IRQHandler(void)
{

	GlobalPointerToFunction[CHANNEL4]();
	/*Clear the Flag*/
	SET_BIT(DMA->IFCR,12);
	SET_BIT(DMA->IFCR,13);


}
void DMA1_Channel5_IRQHandler(void)
{

	GlobalPointerToFunction[CHANNEL5]();
	/*Clear the Flag*/
	SET_BIT(DMA->IFCR,16);
	SET_BIT(DMA->IFCR,17);


}
void DMA1_Channel6_IRQHandler(void)
{

	GlobalPointerToFunction[CHANNEL6]();
	/*Clear the Flag*/
	SET_BIT(DMA->IFCR,20);
	SET_BIT(DMA->IFCR,21);


}
void DMA1_Channel7_IRQHandler(void)
{

	GlobalPointerToFunction[CHANNEL7]();
	/*Clear the Flag*/
	SET_BIT(DMA->IFCR,24);
	SET_BIT(DMA->IFCR,25);

}


 
 
