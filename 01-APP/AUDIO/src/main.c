/*
 * main.c
 *
 *  Created on: Oct 6, 2020
 *      Author: Ramadona
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "DAC_interface.h"
#include "file.h"


void main(void)
{
	RCC_VoidInitSystemClk();
	RCC_VoidEnableClock(2,2);


	 DAC_VidInitial();
	 DAC_VidStartDigitalToAnlog(140,AMR_raw);

	while(1)
	{}



}
