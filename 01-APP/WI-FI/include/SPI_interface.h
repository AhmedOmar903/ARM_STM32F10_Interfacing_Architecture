/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 16 September 2020          */
/* version     : ver 1                      */
/* Description : SPI                        */
/********************************************/
#ifndef _SPI_INTERFACE_H
#define _SPI_INTERFACE_H


void SPI_VoidIntialize(void);


void SPI_VoidSendReciveSynch(u8 Copy_u8DataToTransmit,u8 *Copy_u8DataToRecive);
void SPI_VoidSendASynch(u8 Copy_u8DataToTransmit, void (*SPILocalPointerToFunction)(u8 Copy_u8SlaveData));

void SPI_VoidSlaveRecieve(u8 *CopyDataToRecieve);


#endif
