/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 19 September 2020          */
/* version     : ver 1                      */
/* Description : USART                      */
/********************************************/
#ifndef _USART_INTERFACE_H
#define _USART_INTERFACE_H
/*UART 1 Connecting to APB2 BUS*/


typedef enum
{

	Receive,
	Transmit

}INTERRUPT_Type;



void UART_VoidIntilaization(void);
void UART_VoidDataToTransmit(u8 *Copy_u8Data);//Send Array of Data
u8 UART_VoidDataRecieve(void);//Recieve Data
void UART_VoidDataToTransfer(u8 Copy_u8DataToSend);//Send Data


u8 UART_VoidWiFiCmdValidate(u32 Copy_32TimeOut);

void UART_VoidReceiverSetCallBack(void (*UartLocalPointerToFucnction)(u8 Copy_u8ReceviedData),INTERRUPT_Type CopyType);//SetCallBack




#endif
