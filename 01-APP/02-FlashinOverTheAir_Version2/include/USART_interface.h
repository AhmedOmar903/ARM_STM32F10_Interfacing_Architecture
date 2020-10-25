/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 19 September 2020          */
/* version     : ver 1                      */
/* Description : USART                      */
/********************************************/
#ifndef _USART_INTERFACE_H
#define _USART_INTERFACE_H
/*UART 1 Connecting to APB2 BUS*/





void UART_VoidIntilaization(void);
void UART_VoidDataToTransmit(u8 *Copy_u8Data);//Send Array of Data

u8 UART_VoidWiFiCmdValidate(u32 Copy_32TimeOut);





#endif
