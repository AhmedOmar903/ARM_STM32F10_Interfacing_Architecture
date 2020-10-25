/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 29 September 2020          */
/* version     : ver 1                      */
/* Description : TFT                        */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_interface.h"
#include "WIFI_interface.h"
#include "WIFI_private.h"
#include "WIFI_config.h"



u8 Local_u8Response[100]={0};

/*BRR=0x45   BaudRate=115200*/

void ESP_VoidInit(void)
{


	u8 Local_u8ValidFlag = 0;
	    /*Initialize Uart*/
    UART_VoidIntilaization();

    /*		Disable Echo		*/
    while(Local_u8ValidFlag == 0)
    {
    	UART_VoidDataToTransmit("ATE0");
    	UART_VoidDataToTransmit("\r\n");
    	Local_u8ValidFlag=WIFI_u8ValidateCmd(ECHO_TIMEOUT);
    }
    Local_u8ValidFlag = 0;
    while(Local_u8ValidFlag == 0)
    {
    	UART_VoidDataToTransmit("AT+CWMODE=1");
    	UART_VoidDataToTransmit("\r\n");
    	Local_u8ValidFlag=WIFI_u8ValidateCmd(MODE_TIMEOUT);
    }

}

void ESP_VoidWiFiConnection(u8*Copy_u8UserName,u8*Copyu8Password)
{
	u8 Local_u8ValidFlag =0;

	while(Local_u8ValidFlag == 0)
	{
		/*AT+CWJAP= "SSID","Password"  */
		UART_VoidDataToTransmit("AT+CWJAP_CUR=\"");
		UART_VoidDataToTransmit(Copy_u8UserName);
		UART_VoidDataToTransmit("\",\"");
		UART_VoidDataToTransmit(Copyu8Password);
		UART_VoidDataToTransmit("\"\r\n");
		Local_u8ValidFlag=WIFI_u8ValidateCmd(ROUTER_TIMEOUT);
	}
}

static void ESP_VoidServerConnection(u8*Copy_u8Protocol,u8*Copy_u8ServerIp,u8*Copy_u8PortNumber)
{
	u8 Local_u8ValidFlag = 0;

	while(Local_u8ValidFlag == 0)
	{
		/*AT+CIPSTART= "TCP" , "ServerIp"    ,  PortNumber*/
		UART_VoidDataToTransmit("AT+CIPSTART=\"");
		UART_VoidDataToTransmit(Copy_u8Protocol);
		UART_VoidDataToTransmit("\",\"");
		UART_VoidDataToTransmit(Copy_u8ServerIp);
		UART_VoidDataToTransmit("\",");
		UART_VoidDataToTransmit( Copy_u8PortNumber);
		UART_VoidDataToTransmit("\r\n");
		Local_u8ValidFlag=WIFI_u8ValidateCmd(SERVER_TIMEOUT);
	}
}

static void ESP_VoidSendHttpRequest(void)
{
   u8 Local_u8ValidFlag = 0;

    ESP_VoidServerConnection(SERVER_MODE,SERVER_IP,PORT_NUMBER);
	while(Local_u8ValidFlag ==0)
	{
		UART_VoidDataToTransmit("AT+CIPSEND=51\r\n");
		Local_u8ValidFlag=WIFI_u8ValidateCmd(PREREQUEST_TIMEOUT);
	}
	Local_u8ValidFlag =0;
	while(Local_u8ValidFlag ==0)
	{
		UART_VoidDataToTransmit(SERVER_LINK);
		UART_VoidDataToTransmit("\r\n");
		Local_u8ValidFlag=WIFI_u8ValidateCmd(REQUEST_TIMEOUT);
	}
}


static u8 WIFI_u8ValidateCmd(u32 Copy_u32TimeOut)
{

	u8 Local_u8Index=0;
	u8 Dummy=0;
	u8 Result=1;

	Local_u8Response[0] = 0;
	while(Dummy!=255)
	{
	   Dummy=UART_VoidWiFiCmdValidate(Copy_u32TimeOut);
	   Local_u8Response[Local_u8Index]=Dummy;
	   Local_u8Index++;
	}
	return Result;
}


u8 ESP_u8ReturnTheRecivedValue(void)
{
	u8 Local_u8Data=0;
	ESP_VoidSendHttpRequest();
	for(u8 i=0	;	i<100;		i++)
	{
		if( Local_u8Response[i]=='I' && Local_u8Response[i+1]=='P' && Local_u8Response[i+2]=='D' )
		{
			Local_u8Data=Local_u8Response[i+6];
		}
	}
	Local_u8Data-=48;
	return Local_u8Data;
}


