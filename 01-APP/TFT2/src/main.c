/*
 * main.c
 *
 *  Created on: Oct 13, 2020
 *      Author: Ramadona
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "file.h"






void APP_VoidIntialization(void);


void main(void)
{


	APP_VoidIntialization();

	HTFT_VoidDisplayImage(array);


	//TFT_VoidFillColour( TFT_BLACK  );

	while(1)
	{



	}

}

void APP_VoidIntialization(void)
{
	RCC_VoidInitSystemClk();
	RCC_VoidEnableClock(RCC_APB2 ,IOPA );
	RCC_VoidEnableClock(RCC_APB2 ,SPI1);

	SPI_VoidIntialize();

	HTFT_VoidInitialize();


}

/*
 *
 * u8 x=0,y=0;
	u8 RESULT;
	for(u8 i=0;i<8;i++)
	{

		for(u8 j=0;j<8;j++)
		{
			RESULT=GET_BIT(array[i],j);
			if(RESULT==0)
			{
				TFT_VoidDrawPixel(50+j+x,50+i+y,0xFFE0);
			}
			else
			{
				TFT_VoidDrawPixel(50+j+x,50+i+y,0);
			}
			x+=3;
		}
		x=0;
		y+=2;
	}

*/
