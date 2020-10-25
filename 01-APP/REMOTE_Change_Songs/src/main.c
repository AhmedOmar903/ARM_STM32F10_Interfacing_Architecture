/*
 * main.c
 *
 *  Created on: Sep 7, 2020
 *      Author: Ahmed Ramadan
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "IR_interface.h"
#include "DAC_interface.h"
#include "file.h" //that is the file which is holding the Song ARRAY


void INIT(void);


int main(void)
{

	Remote_button_t BUTTON=0;
	 INIT();

 
	while(1)
	{

		BUTTON=HINFRARED_GetRemotePressedButton();
		switch(BUTTON)
		{
		case Remote_TWO  : DAC_VidStartDigitalToAnlog(125,AMR_raw); break;
		case Remote_THREE   : DAC_VidStartDigitalToAnlog(160,AMR_raw) ; break;
		case Remote_FOUR  : DAC_VidStartDigitalToAnlog(100,AMR_raw); break;
		case Remote_ONE    : DAC_VidStartDigitalToAnlog(140,AMR_raw); break;
		default            : break;
		}

	}
	return 0;

}

void INIT(void){
	RCC_VoidInitSystemClk();
	RCC_VoidEnableClock(RCC_APB2 ,IOPA);
	RCC_VoidEnableClock(RCC_APB2 ,IOPB);
	DAC_VidInitial();
	HINFRARED_VidInitail();

}
/*void ISR(u8 DATA)
{

	switch(DATA)
			{
			case 69  : DAC_VidStartDigitalToAnlog(125,Amaren_raw); break;
			case 70   : DAC_VidStartDigitalToAnlog(160,Amaren_raw) ; break;
			case 71   : DAC_VidStartDigitalToAnlog(100,Amaren_raw); break;
			case 12    : DAC_VidStartDigitalToAnlog(140,Amaren_raw); break;
			default            : break;
			}
}*/
