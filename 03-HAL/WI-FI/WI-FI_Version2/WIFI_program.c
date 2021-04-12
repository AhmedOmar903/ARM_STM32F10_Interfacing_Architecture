/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 2 April 2021	            */
/* version     : ver 2                      */
/* Description : WI-FI                      */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "USART_interface.h"
#include "NVIC_interface.h"
#include "SYSTICK_interface.h"
#include "WIFI_interface.h"
#include "WIFI_private.h"
#include "WIFI_config.h"






volatile u8 ESP8266_DATACOME[	100		] ={0};
volatile u8 ESP8266_Iterator=0;

void ESP8266_VoidInitialization(void)
{
	

	MNVIC_VidInit();//  Intialize The NVIC
	MNVIC_VidInterruptEnable(USART1_1);// Enable USART Interrupt


//*********************************************************************************************************//

	UART_VoidReceiverSetCallBack(ESP8266_VoidSetCallBack,Receive);//Enable UART Interrupt
	UART_VoidIntilaization();
	GPIOX_VidSetPinDirection(PORTA,PIN10,INPUT_FLOATING );// RX
	GPIOX_VidSetPinDirection(PORTA,PIN9, OUTPUT_SPEED_50M_AF_PUSH_PULL);// TX
	MSYSTCIK_VidInit();
}



void ESP8266_VoidResetTheConfigurations(void)
{

	UART_VoidDataToTransmit("AT+RST\r\n");		// RESET The Wifi
	MSTK_VidSetBusyWait(10000);


	UART_VoidDataToTransmit("ATE0\r\n");		// Disable The Echo
	MSTK_VidSetBusyWait(10000);

	UART_VoidDataToTransmit("AT+CWMODE=1\r\n");		// Allow Station Mode.
	MSTK_VidSetBusyWait(10000);

	EPS8266_VoidClearTheBuffer();
}




void ESP8266_VoidConnectToWiFi(u8 * SSID,		u8*  Password)
{
	UART_VoidDataToTransmit("AT+CWJAP=\"");
	UART_VoidDataToTransmit(SSID);
	UART_VoidDataToTransmit("\",\"");
	UART_VoidDataToTransmit(Password);
	UART_VoidDataToTransmit("\"\r\n");


	MSTK_VidSetBusyWait(2000000);
	EPS8266_VoidClearTheBuffer();
}


void ESP8266_VoidConnectToSrvTcp (u8*Protocol ,u8 * Copy_u8Domain , u8  *Copy_u8Port )
{

	UART_VoidDataToTransmit("ATE0\r\n");		// Disable The Echo
	MSTK_VidSetBusyWait(10000);


	UART_VoidDataToTransmit("AT+CIPSTART=\"");
	UART_VoidDataToTransmit(Protocol);
	UART_VoidDataToTransmit("\",\"");
	UART_VoidDataToTransmit(Copy_u8Domain);
	UART_VoidDataToTransmit("\",");
	UART_VoidDataToTransmit(Copy_u8Port);
	UART_VoidDataToTransmit("\r\n");

	MSTK_VidSetBusyWait(2000000);
	EPS8266_VoidClearTheBuffer();
}



void ESP8266_u8ReceiveHttpReq( u8 * Copy_u8ChannelID , u8 * Copy_u8Length )
{


	UART_VoidDataToTransmit("AT+CIPSEND=");
	UART_VoidDataToTransmit(Copy_u8Length);
	UART_VoidDataToTransmit("\r\n");
	MSTK_VidSetBusyWait(10000);

	UART_VoidDataToTransmit("GET ");
	UART_VoidDataToTransmit(Copy_u8ChannelID);
	UART_VoidDataToTransmit("\r\n");

}


u8 ESP8266_u8ReturnTheReceviedData(u8*Protocol ,u8 * Copy_u8Domain , u8  *Copy_u8Port,u8 * Copy_u8ChannelID , u8 * Copy_u8Length)
{
	u8 DATA=0;

	ESP8266_VoidConnectToSrvTcp (Protocol , Copy_u8Domain , Copy_u8Port );
	ESP8266_u8ReceiveHttpReq(  Copy_u8ChannelID ,Copy_u8Length );

	MSTK_VidSetBusyWait(2000000);// Wait Till The Data

	for(int i=0;		i<100;		i++)
	{
		if(		ESP8266_DATACOME[i]		=='+'		)
		{
			DATA=ESP8266_DATACOME[i+7];
			break;
		}
	}

	return ( DATA-48);
}














static void EPS8266_VoidClearTheBuffer(void)
{

	ESP8266_Iterator=0;
	for(int i=0;		i<100;			i++	)
	{
		ESP8266_DATACOME[i]=0;
	}
}




static void ESP8266_VoidSetCallBack(u8 Copy_u8ReceviedData)
{
	ESP8266_DATACOME[	ESP8266_Iterator++	]=Copy_u8ReceviedData;
}














