/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 19 September 2020          */
/* version     : ver 1                      */
/* Description : USART                      */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

/*  0x341   9600   */


 void UART_VoidIntilaization(void)
{
	 UART  ->BRR=0x45;  		 /*Baud Rate =115200        */
	 SET_BIT(UART -> CR1,13 );  /*UART ENABLE              */
	 SET_BIT(UART -> CR1,3 );  /*TX ENABLE                */
	 SET_BIT(UART -> CR1,2 ); /*RX ENABLE				 */

	 #if RECEIVE_COMPLETE_INTERRUPT == ENABLE

		SET_BIT(UART -> CR1,5 );  /*Recevie Complete Interrupt ENABLE                */
	 #endif

	 #if TRASMITE_COMPLETE_INTERRUPT == ENABLE

		SET_BIT(UART -> CR1,7 );  /*TRASMITE Complete Interrupt ENABLE                */
	 #endif


	 UART ->SR=0;			 /*Clear the Status Register*/

		GPIOX_VidSetPinDirection(PORTA,PIN10,INPUT_FLOATING );// RX
		GPIOX_VidSetPinDirection(PORTA,PIN9, OUTPUT_SPEED_50M_AF_PUSH_PULL);// TX


}
 
 
void UART_VoidDataToTransmit(u8 *Copy_u8Data)
{
	 u8 Local_u8Index=0;
	 while(Copy_u8Data[Local_u8Index] !='\0')
	 {      /* casting to make sure that the data is 8 bit*/
	      UART ->DR=Copy_u8Data[Local_u8Index]; 	  /*Send the Data						*/
		  while(GET_BIT(UART ->SR,6)==0);    			 /*Wait until the Transmission complete*/
		  	  	  	  	  	  	  	  	  	  	  	  	 /*Clear the Flag					  */
		  Local_u8Index++;							   /* Increment 						 */
	 } 
}

u8 UART_VoidDataRecieve(void)
{

  while(GET_BIT(UART ->SR,5)==0);		 /* Wait          */


  return (0xFF &UART ->DR);			  /* return        */
}
 
 
void UART_VoidDataToTransfer(u8 Copy_u8DataToSend)
{
	  UART ->DR=0xFF&Copy_u8DataToSend; /*Send the Data*/
	 
	 while((UART ->SR & (1<<6))==0); /*Wait until the Transmission complete*/
	 
	 CLR_BIT(UART ->SR,6); 			/*Clear the Flag*/
	 
}
 

 
void UART_VoidReceiverSetCallBack(void (*UartLocalPointerToFucnction)(u8 Copy_u8ReceviedData),INTERRUPT_Type CopyType)
{
	 UartGlobalPointerToFucnction[CopyType]=UartLocalPointerToFucnction;
}



void USART1_IRQHandler(void)
{


 #if RECEIVE_COMPLETE_INTERRUPT == ENABLE
	UartGlobalPointerToFucnction[0](UART ->DR);
	CLR_BIT(UART ->SR,5);//Clear the RX Flag
 #elif TRASMITE_COMPLETE_INTERRUPT == ENABLE
	UartGlobalPointerToFucnction[1](UART ->DR);
	CLR_BIT(UART ->SR,7);//Clear the  TX Flag
#endif
}


u8 UART_VoidWiFiCmdValidate(u32 Copy_32TimeOut)
{
  u32 Local_u16TimeOut=0;
  s8 Local_s8Result=0;
  while(GET_BIT(UART ->SR,5)==0) /* Wait          */
  {
	  Local_u16TimeOut++;
	  if(Local_u16TimeOut==Copy_32TimeOut)
	  {
		  Local_s8Result=255;
		 break;
	  }
  }
  if(Local_s8Result==0)
  {
	  Local_s8Result= UART ->DR;
  }

  return (Local_s8Result);			  /* return        */
}



