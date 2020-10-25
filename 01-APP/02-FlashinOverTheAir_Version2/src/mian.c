/*
 * mian.c
 *
 *  Created on: Oct 20, 2020
 *      Author: Ahmed Ramadan
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "USART_interface.h"
#include "WIFI_interface.h"









typedef void (*Function_t)(void);
Function_t addr_to_call = 0;

void func(void)
{
#define SCB_VTOR   *((volatile u32*)0xE000ED08)

	SCB_VTOR = 0x08001C00;

	addr_to_call = *(Function_t*)(0x08001C04);
	addr_to_call();
}

/*start from page 10 =0x08002800  , 0x08002804
 *
 * page 7=08001C00    ,  08001C04
 *  */


void main(void)
{

	u8 Local_u8Status=0;
	RCC_VoidInitSystemClk();
	RCC_VoidEnableClock(RCC_APB2 ,IOPA  );/*PORTA*/
	RCC_VoidEnableClock(RCC_APB2 ,USART1   );/*USART*/
	RCC_VoidEnableClock(RCC_AHB  , 4   );/*FPEC*/
	
	
	UART_VoidIntilaization();/*Intialize UART*/
	MSYSTCIK_VidInit();/*Systick*/
	ESP_VoidInit();/*INTIALIZE WIFI*/
	
	
	//ESP_VoidWiFiConnection("iPhone","12345678"); /*Wifi Connection*/
	MSTK_VidSetIntervalSingle(480000000,func);/*Jump to The main Application After 15 s*/

	while(1)
	{

		Local_u8Status=FlashingOverTheAir_u8DownLoadTheHexFile();


	}
}


