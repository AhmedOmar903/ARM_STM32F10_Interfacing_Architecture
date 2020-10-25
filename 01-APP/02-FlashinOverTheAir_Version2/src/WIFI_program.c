/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 23 October 2020            */
/* version     : ver 1                      */
/* Description : On The Air                 */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_interface.h"
#include "FPEC_interface.h"
#include "SYSTICK_interface.h"

#include "WIFI_interface.h"
#include "WIFI_private.h"
#include "WIFI_config.h"


void Parser_voidParseRecord(u8* Copy_u8BufData);

u8 Global_u8Record[150];

/*BRR=0x45   BaudRate=115200*/

void ESP_VoidInit(void)
{


	u8 Local_u8ValidFlag = 0;
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

u8 FlashingOverTheAir_u8DownLoadTheHexFile(void)
{
   u8 Local_u8ValidFlag = 0;

   
   ESP_VoidServerConnection(SERVER_MODE,SERVER_IP,PORT_NUMBER);
   while(Local_u8ValidFlag ==0)
   {
       UART_VoidDataToTransmit("AT+CIPSEND=51\r\n");
	   Local_u8ValidFlag=WIFI_u8ValidateCmd(PREREQUEST_TIMEOUT);
   }
    Local_u8ValidFlag=0;
	UART_VoidDataToTransmit(SERVER_LINK);
	UART_VoidDataToTransmit("\r\n");
	Local_u8ValidFlag=FlashingOverTheAir_u8OTACmdValidate(REQUEST_TIMEOUT);
   

   return Local_u8ValidFlag;
}


static u8 FlashingOverTheAir_u8OTACmdValidate(u32 Copy_32TimeOut)
{

	u32 Local_u8DataIndex=0;/*iteration of the record array*/
	u8 Local_u8Result=0;/*variable that is used to recieve the data*/
	u8 Local_u8Status=1;/*check if there is a new application or not*/
	u8 Local_u8NewRecordFlag=0;/*flag to enable to saved the recevied data*/
	u8 Local_u8SemiColumnCounter=0;/*Check if the received semicolumn is Start of each record or not */
	u8 Local_EndOfTheHexFile=0;/*Check if the received Data is Closed word or not*/
	u8 Local_u8EndOfTheLength=0;/*check the Length*/

	u8 Local_u8Flag=0;
	u8 Local_u8EraseFlag=0;

	u8 Local_ApplicationFalg=0;

	while(Local_u8Result!=255)
	{
     	/*Read The Data From The UART*/
		Local_u8Result=UART_VoidWiFiCmdValidate(Copy_32TimeOut);
		/*Check If the Data is SemiColumn(:) After that Checking the number of (:) Becouse The wifi Send
		 * +IPD Length : (data)   and the hex file record is always starting with : */
		if(Local_u8Result==':')
		{
			/*if Local_u8SemiColumnCounter equal zero thats mean the recevied semicolum is
			 * the one thats come after the length   (+IPD Length :),so don't save it in the array */
			if(Local_u8SemiColumnCounter==0)
			{
				Local_u8NewRecordFlag=0;
				Local_u8SemiColumnCounter=1;
			}
			/*the max length is 1400 byte so after 1400 byte the wifi send /r/n : then continue to send
			 * the rest of the record.So,when Local_u8EndOfTheLength is equal to one thats mean
			 * neglect the semicolumn  */
			else if(Local_u8SemiColumnCounter==1 &&Local_u8EndOfTheLength==0)
			{
				Local_u8NewRecordFlag=1;
				Local_u8Flag=1;
			}
		}
		/*If the data is + or \r ,make the Flag equal zero inorder to doesn't save (+IPD Length :) in the Array */
		else if(Local_u8Result=='+' || Local_u8Result=='\r')
		{
			Local_u8NewRecordFlag=0;
			/*Local_u8EndOfTheLength=1 means neglect the /r/n:*/
			switch(Local_u8Result)
			{
			case '\r': Local_u8EndOfTheLength=1; break;
			}
		}
		/*Checking if the recived data is Closed \r\n , if true Then break .*/
		else if(Local_u8Result=='C' || Local_EndOfTheHexFile==1)
		{
			Local_EndOfTheHexFile=1;
			if(Local_u8Result=='L')
			{
				Global_u8Record[Local_u8DataIndex-1]='\n';
				Local_u8Result='\n';

			}
		}

        /*if the Recived Data is not Equal to (+IPD Length :) && (CLOSED \r\n) .then upload the Data to the
         * ARRAY*/
		if(Local_u8NewRecordFlag==1)
		{
			Global_u8Record[Local_u8DataIndex]=Local_u8Result;
		    Local_u8DataIndex++;
		}
		else if(Local_u8EndOfTheLength==1 && Local_u8Result==':')
		{
			/*the length had been reach its max so the wifi will neglect the /r/n:
			 *
			 * so if (Local_u8EndOfTheLength==1 && Local_u8Result==':') enable the array to save the next data*/
			Local_u8NewRecordFlag=1;
			Local_u8EndOfTheLength=0;
		}

		if(Local_u8Result=='\n' && Local_u8EndOfTheLength==0 &&Local_u8Flag==1)
		{
			if(Local_u8EraseFlag==0)
			{
				FPEC_voidEraseAppArea();
				Local_u8EraseFlag=1;
				Local_ApplicationFalg=1;
				MSYSTICK_VidStopInterval();
			}
			Parser_voidParseRecord(Global_u8Record);
			Local_u8DataIndex=0;
		}

	}

	/*if index less than 150 thats mean there is no another application to burn it on the flash memory*/
	if(Local_ApplicationFalg==0)
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

	Global_u8Record[0] = 0;
	while(Dummy!=255)
	{
	   Dummy=UART_VoidWiFiCmdValidate(Copy_u32TimeOut);
	   Global_u8Record[Local_u8Index]=Dummy;
	   Local_u8Index++;
	}
	return Result;
}

