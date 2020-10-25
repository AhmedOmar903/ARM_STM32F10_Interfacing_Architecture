/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 23 October 2020            */
/* version     : ver 1                      */
/* Description : On The Air                 */
/********************************************/
#ifndef _WIFI_PRIVATE_H
#define _WIFI_PRIVATE_H


static u8 WIFI_u8ValidateCmd(u32 Copy_u32TimeOut);

#define ECHO_TIMEOUT		100000
#define MODE_TIMEOUT		150000
#define ROUTER_TIMEOUT		300000
#define SERVER_TIMEOUT		150000
#define PREREQUEST_TIMEOUT	2000
#define REQUEST_TIMEOUT		100000

static void ESP_VoidServerConnection(u8*Copy_u8Protocol,u8*Copy_u8ServerIp,u8*Copy_u8PortNumber);



static u8 FlashingOverTheAir_u8OTACmdValidate(u32 Copy_32TimeOut);

#endif
