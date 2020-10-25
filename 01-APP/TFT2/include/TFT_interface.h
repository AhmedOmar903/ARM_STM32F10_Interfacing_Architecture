/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 21 September 2020          */
/* version     : ver 1                      */
/* Description : TFT                        */
/********************************************/
#ifndef _TFT_INTERFACE_H
#define _TFT_INTERFACE_H

/* Colours */
#define     TFT_BLACK        0x0000
#define     TFT_WHITE        0xffff
#define     TFT_RED          0xf800
#define     TFT_BLUE         0x39df
#define     TFT_YELLOW       0xffc0
#define     TFT_ORANGE       0xfd20
#define     TFT_PURPLE       0xf1df
#define     TFT_GREEN        0x1427



void HTFT_VoidInitialize(void);
void HTFT_VoidDisplayImage( const u16 *Copy_u16Image); /*Const to Download the Image in the Flash*/
void TFT_VoidFillColour(u16 Copy_u16Colour);
void TFT_VoidDrawRectangle(u8 Copy_Xstart,u8 Copy_Xend,u8 Copy_Ystart,u8 Copy_Yend,u16 Copy_u16Colour);

void TFT_VoidDrawCharacter(u8 *Copy_u8Character ,u8 Copy_Xaxis,u8 Copy_Yaxis,u16 Copy_u16Colour,u16 Copy_u16BackGroundColor);

void TFT_VoidWriteText(u8 *Copy_u8Character ,u8 Copy_Xaxis,u8 Copy_Yaxis,u16 Copy_u16Colour,u16 Copy_u16BackGroundColor);


#endif




/*
x AXIS Start From 100

differance between y axis is 15

for TFT COnfigration   SPI->CR1=0x0347 ;   

1-CLK Ideal High   Cpol=1
2-CPhase =1   	   write at first adge   spi 
3-MSB


		
*/
