/*
 * main.c
 *
 *  Created on: Sep 28, 2020
 *      Author: Ahmed Ramadan
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "WIFI_interface.h"



void INIT(void);

void main(void)
{
u8 Data=0;




	 INIT();
	 GPIOX_VidSetPinDirection(PORTA,PIN0,OUTPUT_SPEED_10M_PUSH_PULL);

	ESP_VoidWiFiConnection("NETGEAR97","myroom1234");

	while(1)
	{
   Data= ESP_u8ReturnTheRecivedValue();
	    switch(Data)
	    {

	    case 0: GPIOX_VidSetPinValue(PORTA,PIN0,LOW); break;
	    case 1:GPIOX_VidSetPinValue(PORTA,PIN0,HIGH); break;


	    }

}
}

void INIT(void)
{


	RCC_VoidInitSystemClk();
	RCC_VoidEnableClock(RCC_APB2 ,IOPA );
	RCC_VoidEnableClock(RCC_APB2 ,USART1 );


	ESP_VoidInit();
}
