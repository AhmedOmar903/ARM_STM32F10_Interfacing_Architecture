/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 16 September 2020          */
/* version     : ver 1                      */
/* Description : SPI                        */
/********************************************/
#ifndef _SPI_CONFIG_H
#define _SPI_CONFIG_H

/*
SPI_DATA_ORDER:

			LSB   
            MSB 
			
SPI_SELECTION:
			
            MASTER
            SLAVE 

SPI_CPOLARITY:

			ZERO_IDEL
			ONE_IDEL 

SPI_CPHASE:
			FIRST_READ
			FIRST_WITE


SPI_BAUD_RATE:

			CLK_DIV_2  
			CLK_DIV_4	
			CLK_DIV_8  
			CLK_DIV_16 
			CLK_DIV_32 
			CLK_DIV_64 
			CLK_DIV_128
			CLK_DIV_256


SPI_INTERRUPT:

			SPI_ENABLE
			SPI_DISABLE


			ONE_BYTE
			TWO_BYTE
*/


#define SPI_DATA_ORDER				MSB
									
#define SPI_BAUD_RATE	            CLK_DIV_2
									
#define SPI_SELECTION                MASTER
									
#define SPI_CPOLARITY	            ZERO_IDEL
									
#define SPI_CPHASE	                FIRST_WITE
	

#define SPI_INTERRUPT 				SPI_DISABLE


#define SPI_DATA_FORMATE 		    ONE_BYTE

#endif
