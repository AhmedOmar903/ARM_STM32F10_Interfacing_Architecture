/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 16 September 2020          */
/* version     : ver 1                      */
/* Description : SPI                        */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


void SPI_VoidIntialize(void)
{

 u8 Local_u8ConfigVariable=0; 	
	
	GPIOX_VidSetPinDirection(PORTA,PIN7,OUTPUT_SPEED_10M_AF_PUSH_PULL ); /*MOSI*/
	GPIOX_VidSetPinDirection(PORTA,PIN6,INPUT_FLOATING);             /*MISO*/
	GPIOX_VidSetPinDirection(PORTA,PIN5,OUTPUT_SPEED_10M_AF_PUSH_PULL ); /*CLK*/
    Local_u8ConfigVariable|=(SPI_BAUD_RATE<<3); /*Baud Rate Selection*/

   #if SPI_DATA_ORDER==LSB
     SET_BIT(Local_u8ConfigVariable,7);
   #elif SPI_DATA_ORDER==MSB
     CLR_BIT(Local_u8ConfigVariable,7);
   #endif
   
   #if SPI_SELECTION==MASTER
     SET_BIT(Local_u8ConfigVariable,2);
   #elif SPI_SELECTION==SLAVE 
     CLR_BIT(Local_u8ConfigVariable,2);
   #endif

   #if SPI_CPOLARITY==ZERO_IDEL										
     CLR_BIT(Local_u8ConfigVariable,1);                             
   #elif SPI_CPOLARITY==ONE_IDEL 
     SET_BIT(Local_u8ConfigVariable,1);
   #endif
   
   #if  SPI_CPHASE==FIRST_READ													
     CLR_BIT(Local_u8ConfigVariable,0);                                 
   #elif SPI_CPHASE==FIRST_WITE
     SET_BIT(Local_u8ConfigVariable,0);
   #endif 


  


  SPI-> CR1=(0x03<<8)|(Local_u8ConfigVariable);

#if SPI_DATA_FORMATE 	==	    TWO_BYTE

  SET_BIT(SPI-> CR1,11);
#endif


  SET_BIT(SPI-> CR1,6); // ENABLE SPI
	//Reciveing Interrupt//
 #if SPI_INTERRUPT ==SPI_ENABLE   
    SET_BIT(SPI-> CR2,6);
 #endif  






}

 

void SPI_VoidSendReciveSynch(u8 Copy_u8DataToTransmit,u8 *Copy_u8DataToRecive)
{
	/*  Clear Slave PIN */
    GPIOX_VidSetPinValue(PORTA,PIN4,LOW);
	/*	Send The Data */
	SPI ->DR=Copy_u8DataToTransmit;
	/* wait Busy Flag To Finished  */


	while(GET_BIT((SPI->SR),7)==1);
	 /*	Recieve The Data */
	*Copy_u8DataToRecive=SPI ->DR; 
	/*  SET Slave PIN */
   GPIOX_VidSetPinValue(PORTA,PIN4,HIGH);	
}

void SPI_VoidSendASynch(u8 Copy_u8DataToTransmit, void (*SPILocalPointerToFunction)(u8 Copy_u8SlaveData))
{
	/*  Clear Slave PIN */
    GPIOX_VidSetPinValue(PORTA,PIN4,LOW);
	/*	Send The Data */
	SPI ->DR=Copy_u8DataToTransmit;
	/* Interrupt Service Routine */
	SPIGlobalPointerToFunction=SPILocalPointerToFunction;
	/*  SET Slave PIN */
    GPIOX_VidSetPinValue(PORTA,PIN4,HIGH);	
}

void SPI_VoidSlaveRecieve(u8 *CopyDataToRecieve)
{

	*CopyDataToRecieve=SPI ->DR;

}


void SPI1_IRQHandler(void)
{
	
	
	SPIGlobalPointerToFunction(SPI ->DR);
	
}





