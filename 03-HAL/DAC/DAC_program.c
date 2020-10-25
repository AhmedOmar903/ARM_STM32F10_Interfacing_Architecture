/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 7 September 2020           */
/* version     : ver 1                      */
/* Description : DAC                        */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"


static u8*Global_u8SongArray;


void DAC_VidInitial(void)
{
	
  GPIOX_VidSetPortDirection(DAC_PORT,OUTPUT_SPEED_2M_PUSH_PULL,DAC_PORT_CONNECTION);//PORT DIRECTION OUTPUT//		
  MSYSTCIK_VidInit();// intial Systick AT AHB/8

}

void DAC_VidStartDigitalToAnlog(u16 Copy_u16Frequancy,u8*Copy_u8SongArray)
{
	
    MSTK_VidSetIntervalPeriodic(Copy_u16Frequancy,DAC_VidSetCallBack);//Change the Frequancy 
	Global_u8SongArray=Copy_u8SongArray;
	
}
static void DAC_VidSetCallBack(void)
{
	static u16 Local_u16Index=0;

#if DAC_PORT_CONNECTION==SECAND_HALF
	u16 Local_u16Data=0;
	Local_u16Data=(Global_u8SongArray[Local_u16Index]<<8);
	GPIOX_VidSetPortValue(DAC_PORT,Local_u16Data);
	Local_u16Index++;
	if(Local_u16Index>DAC_ARRAY_LENGTH)
	{
	    Local_u16Index=0;
	}
#elif	DAC_PORT_CONNECTION==FIRST_HALF

	    GPIOX_VidSetPortValue(DAC_PORT,Global_u8SongArray[Local_u16Index]);
		Local_u16Index++;
		if(Local_u16Index>DAC_ARRAY_LENGTH)
		{
			Local_u16Index=0;
		}

#endif
}












