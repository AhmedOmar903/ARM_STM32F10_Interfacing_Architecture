/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 21 September 2020          */
/* version     : ver 1                      */
/* Description : TFT                        */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "SPI_interface.h"
#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


   	   /*	RST PULSE 							  		  */
      /*	Sleep Out Command	 0x11			         */
     /*		Wait 150 ms 	    	   		     		*/
    /*		Colour ID   	  0x3A  WCom 	 		   */
   /*		Colour Paramater  0x05 RGB565	WDta 	  */
  /*		DisplayOn 			0x29 			 	 */







void HTFT_VoidInitialize(void)
{
	GPIOX_VidSetPinDirection(TFT_RST_PIN,OUTPUT_SPEED_10M_PUSH_PULL); /*RST*/
	GPIOX_VidSetPinDirection(TFT_A0_PIN,OUTPUT_SPEED_10M_PUSH_PULL); /*AO*/
   	
    TFT_VoidResetPulse(); /*RST PULES*/
	TFT_VoidWriteCommand(0x11);/*SLEEP OUT*/
	MSTK_VidSetBusyWait(150000);
	TFT_VoidWriteCommand(0x3A);/*Colour ID*/
	TFT_VoidWriteData(0x05);/*Colour Paramter*/
	
    TFT_VoidWriteCommand(0x29);/*Colour on*/


	
	
	
}

void HTFT_VoidDisplayImage( const u16 *Copy_u16Image)
{

	u16 Local_u16Counter=0;


	TFT_VoidSetXaxis(0,127);
	TFT_VoidSetYaxis(0,159);
  /*					RAM WRITE								*/
	TFT_VoidWriteCommand(0x2C);
    for(Local_u16Counter=0;Local_u16Counter<20480;Local_u16Counter++)
	{
		TFT_VoidWriteData((Copy_u16Image[Local_u16Counter]>>8));      /*	High Byte	*/
		TFT_VoidWriteData((Copy_u16Image[Local_u16Counter] &0xFF));	 /*	    LOW Byte   */
	}

}

void TFT_VoidFillColour(u16 Copy_u16Colour)
{
	
	u16 Local_u16Counter=0;


	TFT_VoidSetXaxis(0,127);
	TFT_VoidSetYaxis(0,159);
  /*					RAM WRITE								*/
	TFT_VoidWriteCommand(0x2C);
    for(Local_u16Counter=0;Local_u16Counter<20480;Local_u16Counter++)
	{
		TFT_VoidWriteData((Copy_u16Colour>>8));      /*	High Byte	*/
		TFT_VoidWriteData((Copy_u16Colour&0xFF));	 /*	    LOW Byte   */
	}
}

void TFT_VoidDrawRectangle(u8 Copy_Xstart,u8 Copy_Xend,u8 Copy_Ystart,u8 Copy_Yend,u16 Copy_u16Colour)
{
	
	u16 Local_u16Counter=0;
	
	u16 Local_u16Size = (Copy_Xend-(Copy_Xstart-1))*(Copy_Yend-(Copy_Ystart-1));

	TFT_VoidSetXaxis(Copy_Xstart,Copy_Xend);//X axis 
	TFT_VoidSetYaxis(Copy_Ystart,Copy_Yend);//Y axis
	
	
	TFT_VoidWriteCommand(0x2C);//Write Ram
    for(Local_u16Counter=0;Local_u16Counter<Local_u16Size;Local_u16Counter++)
	{
		TFT_VoidWriteData((Copy_u16Colour>>8));      /*	High Byte	*/
		TFT_VoidWriteData((Copy_u16Colour));	 /*	    LOW Byte   */
	}
}








static void TFT_VoidSetXaxis(u8 Copy_XaxisStart,u8 Copy_XaxisEnd)
{
	/*			SET X axis ID			*/
	TFT_VoidWriteCommand(0x2A);

	TFT_VoidWriteData(0); /*MSR Start From  0  */
	TFT_VoidWriteData(Copy_XaxisStart); /*LSR Start From  0  */

	TFT_VoidWriteData(0); /*MSR END AT  0 */
	TFT_VoidWriteData(Copy_XaxisEnd); /*LSR END AT  127 */


}

static void TFT_VoidSetYaxis(u8 Copy_YaxisStart,u8 Copy_YaxisEnd)
{

	  /*			SET Y axis ID			*/
	TFT_VoidWriteCommand(0x2B);

	TFT_VoidWriteData(0); /*MSR Start From  0  */
	TFT_VoidWriteData(Copy_YaxisStart); /*LSR Start From  0  */

	TFT_VoidWriteData(0); /*MSR END AT  0 */
	TFT_VoidWriteData(Copy_YaxisEnd); /*LSR END AT  127 */
	
}

void TFT_VoidDrawCharacter(u8 *Copy_u8Character ,u8 Copy_Xaxis,u8 Copy_Yaxis,u16 Copy_u16Colour,u16 Copy_u16BackGroundColor)
{
	u8 Local_u8Width=0,Local_u8Height=0;
	u8 Local_u8BinaryValue=0;
	u8 Local_u8CharcterAsci=0;
	u8 Global_u8XIncrement=0;
	u8 Global_u8YIncrement=0;

	if(Copy_u8Character==' ')
	{
		Local_u8CharcterAsci=0;
	}
	else
	{
		Local_u8CharcterAsci=(Copy_u8Character)-64;
	}

	for(Local_u8Height=0;Local_u8Height<8;Local_u8Height++)
	{
		for(Local_u8Width=0;Local_u8Width<8;Local_u8Width++)
		{
			Local_u8BinaryValue=GET_BIT(font[Local_u8CharcterAsci][Local_u8Height],Local_u8Width);
			if(Local_u8BinaryValue==1)
			{
				TFT_VoidDrawPixel((Copy_Xaxis+Local_u8Width+Global_u8XIncrement),(Copy_Yaxis+Local_u8Height+Global_u8YIncrement),Copy_u16Colour);//Chooseen Color
			}
			else
			{
				TFT_VoidDrawPixel((Copy_Xaxis+Local_u8Width+Global_u8XIncrement),(Copy_Yaxis+Local_u8Height+Global_u8YIncrement),Copy_u16BackGroundColor);//Black Pixel
			}
			Global_u8XIncrement+=2;
		 }
		Global_u8XIncrement=0;
		Global_u8YIncrement+=1;
	}
}
static void TFT_VoidDrawPixel(u8 Copy_Xaxis,u8 Copy_Yaxis,u16 Copy_u16Color)
{
    u8 Local_u8Index=0;
	TFT_VoidSetXaxis(Copy_Xaxis,Copy_Xaxis+3);
	TFT_VoidSetYaxis(Copy_Yaxis,Copy_Yaxis+3);
	TFT_VoidWriteCommand(0x2C);//Write Ram

	for(Local_u8Index=0;Local_u8Index<12;Local_u8Index++)
	{
	TFT_VoidWriteData((Copy_u16Color>>8));
	TFT_VoidWriteData(Copy_u16Color);
	}
}

void TFT_VoidWriteText(u8 *Copy_u8Character ,u8 Copy_Xaxis,u8 Copy_Yaxis,u16 Copy_u16Colour,u16 Copy_u16BackGroundColor)
{
	u8 Local_u8Index=0;
	while(Copy_u8Character[Local_u8Index]!='\0')
	{

		TFT_VoidDrawCharacter(Copy_u8Character[Local_u8Index],Copy_Xaxis,Copy_Yaxis,Copy_u16Colour,Copy_u16BackGroundColor);
		Copy_Xaxis-=15;
		Local_u8Index++;
	}



}



static void TFT_VoidResetPulse(void)
{
	/*				RST Pin HIGH		*/
	GPIOX_VidSetPinValue(TFT_RST_PIN,HIGH);
    /*				wait 100ms	    	*/
	MSTK_VidSetBusyWait(100);
	
	/*				RST Pin LOW		    */
	GPIOX_VidSetPinValue(TFT_RST_PIN,LOW);
    /*				wait 100ms	    	*/
	MSTK_VidSetBusyWait(1);
	
	/*				RST Pin HIGH		*/
	GPIOX_VidSetPinValue(TFT_RST_PIN,HIGH);
    /*				wait 100ms	    	*/
	MSTK_VidSetBusyWait(100);
	
	/*				RST Pin LOW		    */
	GPIOX_VidSetPinValue(TFT_RST_PIN,LOW);
    /*				wait 100ms	    	*/
	MSTK_VidSetBusyWait(100);
	
	
	/*				RST Pin HIGH		*/
	GPIOX_VidSetPinValue(TFT_RST_PIN,HIGH);
    /*				wait 100ms	    	*/
	MSTK_VidSetBusyWait(120000);
	
}


static void TFT_VoidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8TempCommand=0;
	/*	SET A0 TO LOW 	*/
	GPIOX_VidSetPinValue(TFT_A0_PIN,LOW);
	
	/*SEND COMMAND OVER SPI*/
	
	SPI_VoidSendReciveSynch(Copy_u8Command, &Local_u8TempCommand);
	
}


static void TFT_VoidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8TempData=0;
	/* SET A0 TO HIGH  */
	GPIOX_VidSetPinValue(TFT_A0_PIN,HIGH);
	/*	SEND DATA OVER SPI	*/
	SPI_VoidSendReciveSynch(Copy_u8Data, &Local_u8TempData);
	
}
