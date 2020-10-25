/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 16 September 2020          */
/* version     : ver 1                      */
/* Description : SPI                        */
/********************************************/
#ifndef _SPI_PRIVATE_H
#define _SPI_PRIVATE_H


typedef struct
{
  volatile u32 CR1		;	 /*Config Register*/
  volatile u32 CR2		;
  volatile u32 SR 		;
  volatile u32 DR 		;	/*Data Register*/
  volatile u32 CRCPR 	;
  volatile u32 RXCRCR 	;
  volatile u32 TXCRCR 	;
  volatile u32 I2SCFGR 	;
  volatile u32 I2SPR 	;

}SPI_t;


#define SPI          ((volatile SPI_t*)0x40013000)

static void (*SPIGlobalPointerToFunction)(u8 Copy_u8SlaveData);


#define LSB       0
#define MSB       1
#define MASTER       2
#define SLAVE       3

#define CLK_DIV_2           0
#define CLK_DIV_4			1
#define CLK_DIV_8           2
#define CLK_DIV_16          3
#define CLK_DIV_32          4
#define CLK_DIV_64          5
#define CLK_DIV_128         6
#define CLK_DIV_256         7


#define ZERO_IDEL       22
#define ONE_IDEL        55

#define FIRST_READ          25
#define FIRST_WITE          66


#define SPI_ENABLE           5
#define SPI_DISABLE          3

#define TWO_BYTE          57
#define ONE_BYTE          14



#endif


