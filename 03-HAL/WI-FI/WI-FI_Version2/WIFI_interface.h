/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 2 April 2021	            */
/* version     : ver 2                      */
/* Description : WI-FI                      */
/********************************************/
#ifndef _WIFI_INTERFACE_H
#define _WIFI_INTERFACE_H



void ESP8266_VoidInitialization(void);
void ESP8266_VoidResetTheConfigurations(void);
void ESP8266_VoidConnectToWiFi(u8 * SSID,		u8*  Password);
void ESP8266_VoidConnectToSrvTcp (u8*Protocol ,u8 * Copy_u8Domain , u8  *Copy_u8Port );
void ESP8266_u8ReceiveHttpReq( u8 * Copy_u8ChannelID , u8 * Copy_u8Length );
u8 ESP8266_u8ReturnTheReceviedData(u8*Protocol ,u8 * Copy_u8Domain , u8  *Copy_u8Port,u8 * Copy_u8ChannelID , u8 * Copy_u8Length);

#endif
