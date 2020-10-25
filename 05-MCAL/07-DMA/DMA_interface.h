/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 13 September 2020          */
/* version     : ver 1                      */
/* Description : DMA                        */
/********************************************/
#ifndef _DMA_INTERFACE_H
#define _DMA_INTERFACE_H

/*
 Copy_u8ChannelNvic  :      DMA1_Channel1            
							DMA1_Channel2            
							DMA1_Channel3            
							DMA1_Channel4            
							DMA1_Channel5            
							DMA1_Channel6            
							DMA1_Channel7 
		  
*/
/***               Channel Config API				***/
#define MemDisabled         0
#define MemEnabled          1

#define VERY_HIGH_PIRORITY     3
#define HIGH_PIRORITY          2
#define MEDIUM_PIRORITY        1
#define LOW_PIRORITY           0

#define BYTE                   0
#define TWO_BYTE               1
#define FOUR_BYTE              2
/*******************************************************/

/***               Channel Enable API				***/
#define INCREMENT_DISABLED        0
#define INCREMENT_ENABLED         1
/*data direction*/
#define PSOURCE        0
#define MSOURCE        1
/*******************************************************/
#define CHANNEL1               0
#define CHANNEL2               1
#define CHANNEL3               2
#define CHANNEL4               3
#define CHANNEL5               4
#define CHANNEL6               5
#define CHANNEL7               6

/*******************************************************/

/*
 * HINT : if you Choose the Data Direction Mode is Peripheral mode so
 *
 * Copy_u32MemoryAdd      : will be the Destenation
 * Copy_u32PeripheralAdd  : will be the  source
 *
 *
 * else if Memory mode
 *
 *
 *  Copy_u32MemoryAdd      : will be the  source
 * Copy_u32PeripheralAdd  : will be the  Destenation
 *
 *
 *
 *Enable MemToMem  to transfer the Data From Ram to RAM  ex From ARRAY1   to  ARRAY2
 *
 * */

void DMA_VoidChannelInitial(void);
void DMA_VoidChannelConfig(u8 Copy_u8ChannelX,u8 Copy_u8MemMode,u8 Copy_u8Pirority,u8 Copy_u8Msiz,u8 Copy_u8Psize);
void DMA_VoidChannelEnable(u8 Copy_u8ChannelX,u8 Copy_u8ChannelNvic,u8 Copy_u8Minc,u8 Copy_u8Pinc,u8 Copy_u8DataDirection);
void DMA_VidChannelStart(u8 Copy_ChannelX,u32 *Copy_u32PeripheralAdd,u32 *Copy_u32MemoryAdd, u16 Copy_u16BlockLength);
void DMA_VoidSetCallBack(void (*LocalPoniterToFunction)(void),u8 Copy_u8ChannelX);//Data Transfer Interrupt

#endif
