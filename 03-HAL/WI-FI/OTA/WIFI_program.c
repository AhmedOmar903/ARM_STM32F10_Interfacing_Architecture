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



u8 Local_u8Response[5000];

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

u8 FlashingOnTheAir_u8DownLoadTheHexFile(void)
{
   u8 Local_u8ValidFlag = 0;

   for(u8 i=0;i<2;i++)
   {
	   ESP_VoidServerConnection(SERVER_MODE,SERVER_IP,PORT_NUMBER);
	   while(Local_u8ValidFlag ==0)
	   {
		   UART_VoidDataToTransmit("AT+CIPSEND=51\r\n");
		   Local_u8ValidFlag=WIFI_u8ValidateCmd(PREREQUEST_TIMEOUT);
	   }
	   Local_u8ValidFlag=0;
	   UART_VoidDataToTransmit(SERVER_LINK);
	   UART_VoidDataToTransmit("\r\n");
	   Local_u8ValidFlag=FlashingOnTheAir_u8OTACmdValidate(REQUEST_TIMEOUT);
   }


   return Local_u8ValidFlag;
}






static u8 FlashingOnTheAir_u8OTACmdValidate(u32 Copy_32TimeOut)
{
	u8 Local_u8Result=0;

	u32 Local_u8DataIndex=0;

	u8 Local_u8Status=1;

	u8 Local_u8NewRecordFlag=0;

	u8 Local_u8Counter=0;

	u8 Local_ClosedFlag=0;

	u8 Local_u8DataLength=0;

	while(Local_u8Result!=255)
	{
		/*Read The Data From The UART*/
		Local_u8Result=UART_VoidWiFiCmdValidate(Copy_32TimeOut);
		/*Check If the Data is : After that Checking the number of : Becouse The wifi Send
		 * +IPD Length : (data)   and the hex file record is always starting with : */
		if(Local_u8Result==':')
		{
			if(Local_u8Counter==0)
			{
				Local_u8NewRecordFlag=0;
				Local_u8Counter=1;
			}
			else if(Local_u8Counter==1 &&Local_u8DataLength==0)
			{
				Local_u8NewRecordFlag=1;
			}
		}
		/*If the data is + or \r ,make the Flag equal zero inorder to doesn't save (+IPD Length :) in the Array */
		else if(Local_u8Result=='+' || Local_u8Result=='\r')
		{
			Local_u8NewRecordFlag=0;
			switch(Local_u8Result)
			{
			case '\r': Local_u8DataLength=1; break;
			}
		}
		/*Checking if the recived data is Closed \r\n , if true Then break .*/
		else if(Local_u8Result=='C' || Local_ClosedFlag==1)
		{
			Local_ClosedFlag=1;
			if(Local_u8Result=='L')
			{
				Local_u8Response[Local_u8DataIndex-1]='\n';
				Local_u8NewRecordFlag=0;
				break;
			}
		}

        /*if the Recived Data is not Equal to (+IPD Length :) && (CLOSED \r\n) .then upload the Data to the
         * ARRAY*/
		if(Local_u8NewRecordFlag==1)
		{
			Local_u8Response[Local_u8DataIndex]=Local_u8Result;
		    Local_u8DataIndex++;

		}
		else if(Local_u8DataLength==1 && Local_u8Result==':')
		{
			Local_u8NewRecordFlag=1;
			Local_u8DataLength=0;
		}

	}

	if(Local_u8DataIndex<100)
	{
		Local_u8Status=0;
	}
	else
	{
		Local_u8Status=1;
	}

	return Local_u8Status;
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


