/*
 * main.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Ramadona
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "TFT_interface.h"
#include "SPI_interface.h"


#include "SYSTICK_interface.h"




void init(void);
void main(void)
{


	init();


	TFT_voidFillDisplay(TFT_PURPLE);




	 TFT_voidPrintText("Ahmed Ramadan" ,0 , 0,1 , TFT_WHITE  , TFT_PURPLE );

	 TFT_voidPrintText("Mohamed Ramadan" ,0, 8,1 , TFT_GREEN   , TFT_PURPLE );



   while(1)
   {







   }




}


void init(void)
{

	RCC_VoidInitSystemClk();
	 RCC_VoidEnableClock(RCC_APB2 , IOPA );
	 RCC_VoidEnableClock(RCC_APB2 , SPI1  );
	 SPI_VoidIntialize();


	 TFT_voidInit();



}

/*TFT_voidPrintText("DIGITAL" , 0 , 0, 3 ,TFT_RED, TFT_BLACK );
	 TFT_voidPrintText("CLOCK" , 0 , 25, 3 ,TFT_RED, TFT_BLACK );


	 TFT_voidPrintText("00:00:00" , 0 , 60, 2 ,TFT_RED, TFT_BLACK );



	 MSTK_VidSetIntervalPeriodic(1000000,STK_ISR);
*/


/*
void STK_ISR(void)
{

static u8 counter=49;
static u8 counter2=49;




	if(counter==58)
	{
		TFT_voidPrintChar(counter2 , 72 , 60, 2 ,TFT_RED, TFT_BLACK );
		counter=48;
		TFT_voidPrintChar(counter , 83 , 60, 2 ,TFT_RED, TFT_BLACK );
		counter2++;

	}
	else
	{
		TFT_voidPrintChar(counter , 83 , 60, 2 ,TFT_RED, TFT_BLACK );
		TFT_voidPrintChar(counter, 48 , 60, 2 ,TFT_RED, TFT_BLACK );
		TFT_voidPrintChar(counter, 35 , 60, 2 ,TFT_RED, TFT_BLACK );
		TFT_voidPrintChar(counter, 11 , 60, 2 ,TFT_RED, TFT_BLACK );
		TFT_voidPrintChar(counter, 0 , 60, 2 ,TFT_RED, TFT_BLACK );

	}
counter++;
}
*/
