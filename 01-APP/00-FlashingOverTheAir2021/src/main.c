/*
 * main.c
 *
 *  Created on: Apr 2, 2021
 *      Author: Ahmed Ramadan
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"WIFI_interface.h"
#include"OTA_interface.h"







void FlashingOverTheAir_VoidInitializeTheHardwareComponents(void);


void main(void)
{

	FlashingOverTheAir_VoidInitializeTheHardwareComponents();
	while(1);



}





void FlashingOverTheAir_VoidInitializeTheHardwareComponents(void)
{

	RCC_VoidInitSystemClk();  						  // Initialize The RCC on HSI
	RCC_VoidEnableClock(RCC_APB2,IOPA);  			 // Enable PortA Clock
	RCC_VoidEnableClock(RCC_APB2,USART1);  			// Enable USART1 Clock
	RCC_VoidEnableClock(RCC_AHB  , 4   );/*FPEC*/



	
	FlashingOverTheAir_VoidInitialization();





	ESP8266_VoidInitialization();
	//ESP8266_VoidResetTheConfigurations();
	//ESP8266_VoidConnectToWiFi( "iPhone","12345678");
	ESP8266_VoidConnectToSrvTcp("TCP","69.197.143.14","80");
	ESP8266_u8ReceiveHttpReq("http://ahmedramadanarm.freevar.com/script.txt" , "51" );



   FlashingOverTheAir_VoidDownloadTheHexFile();


}




