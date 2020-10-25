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
#include "NVIC_interface.h"
#include "TFT_interface.h"
#include "SYSTICK_interface.h"
#include "SPI_interface.h"
#include "WIFI_interface.h"
#include "USART_interface.h"




void TFT_VoidPrintCharacter(u8 Copy_u8Value);

void APP_VoidIntialization(void);

void main(void)
{
	u8 Local_u8WifiValue=0;

	u8 Local_u8Comparing=0;

	APP_VoidIntialization();

	while(1)
	{
		Local_u8WifiValue=ESP_u8ReturnTheRecivedValue();
		if(Local_u8WifiValue!=Local_u8Comparing)
		{
			TFT_VoidPrintCharacter(Local_u8WifiValue);
			Local_u8Comparing=Local_u8WifiValue;
		}

	}

}



void TFT_VoidPrintCharacter(u8 Copy_u8Value)
{
 static u8 Local_u8Xaxis=0;
 static u8 Local_u8Yaxis=0;

    if(Local_u8Xaxis>=120)
    {
    	Local_u8Xaxis=0;
    	Local_u8Yaxis+=20;
    }

	switch(Copy_u8Value)
	{
	 case 0:TFT_voidPrintChar('A' , Local_u8Xaxis ,Local_u8Yaxis, 2 , TFT_WHITE  , TFT_BLUE ); break;

	 case 1 :TFT_voidPrintChar('H' , Local_u8Xaxis ,Local_u8Yaxis, 2 , TFT_WHITE  , TFT_BLUE ); break;
	}

	Local_u8Xaxis+=15;
}




void APP_VoidIntialization(void)
{
	/*RCC Initaliazation*/
	RCC_VoidInitSystemClk();
    /*	 Init PORTA CLK			*/
	RCC_VoidEnableClock(RCC_APB2,IOPA);
    /*	Init SPI CLK			*/
	RCC_VoidEnableClock(RCC_APB2,SPI1 );
	/*	Init UART CLK			*/
	RCC_VoidEnableClock(RCC_APB2, USART1);

/******************************************************************************/

	/*	 Init	SYSTICK		*/
	MSYSTCIK_VidInit();
	/*	 Init	spi	*/
	SPI_VoidIntialize();
	/*	 Init	TFT	*/
	TFT_voidInit ();
	/*	 Init	TFT	*/
	TFT_voidFillDisplay (TFT_BLUE );
	/*	 Init	UART*/
	UART_VoidIntilaization();
	/*	 Init	WIFI*/
	ESP_VoidInit();

	ESP_VoidWiFiConnection("iPhone","12345678");
}


