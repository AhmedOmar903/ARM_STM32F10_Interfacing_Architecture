/*
 * main.c
 *
 *  Created on: Sep 28, 2020
 *      Author: Ramadona
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "ADC_interface.h"

void main(void)
{

	u32 data=0;

	RCC_VoidInitSystemClk();
	RCC_VoidEnableClock(RCC_APB2 ,IOPA );
	RCC_VoidEnableClock(RCC_APB2 ,ADC1 );

	ADC_VoidInit();

	while(1)
	{

		 ADC_VoidStartConversionSingle(&data);

		 data=(data*3300)/4096;

		 GPIOX_VidSetPinDirection(PORTA,PIN5,INPUT_FLOATING);//ADC CHANNEL 1

	}




}


