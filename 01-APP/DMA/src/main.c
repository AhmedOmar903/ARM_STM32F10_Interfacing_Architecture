/*
 * main.c
 *
 *  Created on: Sep 12, 2020
 *      Author: Ahmed Ramadan
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "DMA_interface.h"
#include "DMA_private.h"

void ISR(void);

int main(void)
{

	u32 arr1[3]={1,10,12};
	u32 arr2[3]={18,22,25};
	
	DMA_VoidSetCallBack(ISR,CHANNEL2);

	DMA_VoidChannelInitial();
	DMA_VoidChannelConfig(CHANNEL2,MemEnabled,HIGH_PIRORITY ,BYTE,BYTE);
	DMA_VoidChannelEnable(CHANNEL2,DMA1_Channel2,INCREMENT_ENABLED,INCREMENT_ENABLED,MSOURCE);
	DMA_VidChannelStart(CHANNEL2,arr2,arr1, 12);





	while(1){


	}

return 0;
}

void ISR(void){

	u8 count=0;
	count++;

}
