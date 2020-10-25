/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 23 October 2020            */
/* version     : ver 1                      */
/* Description : On The Air                 */
/********************************************/
#ifndef _WIFI_INTERFACE_H
#define _WIFI_INTERFACE_H




void ESP_VoidInit(void);
void ESP_VoidWiFiConnection(u8*Copy_u8UserName,u8*Copyu8Password);


u8 FlashingOverTheAir_u8DownLoadTheHexFile(void);


#endif
