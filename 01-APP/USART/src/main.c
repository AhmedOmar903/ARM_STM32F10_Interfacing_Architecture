/*
 * main.c
 *
 *  Created on: Sep 19, 2020
 *      Author: Ahmed Ramadan
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "USART_interface.h"
#include "USART_private.h"


int main(void)
{

 u8 data=0;


	RCC_VoidInitSystemClk();
	RCC_VoidEnableClock(RCC_APB2 ,IOPA);//inital PORTA
	RCC_VoidEnableClock(RCC_APB2 ,USART1);//inital UART


	UART_VoidIntilaization();




	while(1)
	{
		data=UART_VoidDataRecieve();

		UART_VoidDataToTransfer(data);


	}
	return 0;
}


