/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 21 September 2020          */
/* version     : ver 1                      */
/* Description : TFT                        */
/********************************************/
#ifndef _TFT_PRIVATE_H
#define _TFT_PRIVATE_H

u8 font[][8]={

		{0,0,0,0,0,0,0,0},// space
		{0, 144, 240, 144, 144, 96, 0, 0},//A
		{0, 240, 144, 224, 144, 240, 0, 0},//B
		{0, 112, 128, 128, 128, 112, 0, 0}, //C
		{0, 224, 144, 144, 144, 224, 0, 0},//D
		{0, 240, 128, 240, 128, 240, 0, 0},//E
		{0, 128, 128, 240, 128, 240, 0, 0},//F
		{0, 112, 144, 176, 128, 112, 0, 0},//G
		{0, 144, 144, 240, 144, 144, 0, 0},//H
		{0, 224, 64, 64, 64, 224, 0, 0},//I



};



static void TFT_VoidResetPulse(void);

static void TFT_VoidWriteCommand(u8 Copy_u8Command);
static void TFT_VoidWriteData(u8 Copy_u8Data);

static void TFT_VoidSetYaxis(u8 Copy_YaxisStart,u8 Copy_YaxisEnd);

static void TFT_VoidSetXaxis(u8 Copy_XaxisStart,u8 Copy_XaxisEnd);

static void TFT_VoidDrawPixel(u8 Copy_Xaxis,u8 Copy_Yaxis,u16 Copy_u16Color);

#endif
