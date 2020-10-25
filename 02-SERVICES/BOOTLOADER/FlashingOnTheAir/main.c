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



extern u8 Global_u8Record[16000];

void Parser_voidParseRecord(u8* Copy_u8BufData);


void OverTheAir_VoidParserEnable(void);


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
 * page 7=0x08001C00    ,  0x08001C04
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
	MSTK_VidSetIntervalSingle(15000000,func);/*Jump to The main Application After 15 s*/

	while(1)
	{

		Local_u8Status=FlashingOverTheAir_u8DownLoadTheHexFile();
		/*The previous Function Returns one If there is a new Application */

		if(Local_u8Status==1)
		{
			MSYSTICK_VidStopInterval();/*Stop the Timer*/
			OverTheAir_VoidParserEnable();
		}

	}
}



void OverTheAir_VoidParserEnable(void)
{
	static u32 Local_u32DataIndex=0;/*iteration for Local_u8Response Array */
	u8 Local_RecordIndex=0;/*iteration for Local_ParseRecordArray Array */

	u8 Local_ParseRecordArray[50];/*Array that is going to hold Each record */


	FPEC_voidEraseAppArea();/*Earse the Flash From Page 10 to page 63*/


	/*Local_u8Response Array contain all the Records , and every record start with semicolumn(:) and end with
	 * (\n)
	 * so i create an array called Local_ParseRecordArray inordered to upload in it each record alone and after
	 * that pass it to Parser_voidParseRecord function to burn it on the Flash memory
	 *
	 * */

	while(Global_u8Record[Local_u32DataIndex+1]!='\0')
	{
		Local_RecordIndex=0;
		for(;Global_u8Record[Local_u32DataIndex]!='\n';Local_u32DataIndex++)
		{
			Local_ParseRecordArray[Local_RecordIndex]=Global_u8Record[Local_u32DataIndex];
			Local_RecordIndex++;
		}
		Local_ParseRecordArray[Local_RecordIndex]='\n';
		Parser_voidParseRecord(Local_ParseRecordArray);
		Local_u32DataIndex++;
	}

	MSTK_VidSetIntervalSingle(1,func);/*Excute the main Application*/
}
