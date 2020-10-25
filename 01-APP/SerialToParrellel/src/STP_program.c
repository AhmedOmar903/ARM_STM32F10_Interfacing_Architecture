/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 14 September 2020          */
/* version     : ver 1                      */
/* Description : STP                        */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"




void STP_VoidSendSynchronus(u16 Copy_u8DataToSend)
{

#if	STP_ICS  ==      TWO_IC
	STP_VoidDataMsb((Copy_u8DataToSend>>8));

#endif
	STP_VoidDataLsb(Copy_u8DataToSend);
}



void STP_VoidDataMsb(u8 Copy_u8DataToSend)
{


    s8 Local_s8Counter=7;
    u8 Local_u8Bit=0;

	for(Local_s8Counter=7; Local_s8Counter>=0; Local_s8Counter--)
	{
		/*   Get The MSB   */
	   	Local_u8Bit= GET_BIT(Copy_u8DataToSend,Local_s8Counter);
		/*   PASS THE MSB  */
		GPIOX_VidSetPinValue(HSTP_SERIAL_DATA,Local_u8Bit);

		/*Send Pluse to Shift Register*/
		GPIOX_VidSetPinValue(HSTP_SHIFT_CLK,HIGH);
		MSTK_VidSetBusyWait(1);//wait 1 Micro
		GPIOX_VidSetPinValue(HSTP_SHIFT_CLK,LOW);
		MSTK_VidSetBusyWait(1);//wait 1 Micro

	}
}

void STP_VoidDataLsb(u8 Copy_u8DataToSend)
{
    s8 Local_s8Counter=7;
    u8 Local_u8Bit=0;
	for(Local_s8Counter=7; Local_s8Counter>=0; Local_s8Counter--)
	{
		/*   Get The MSB   */
	   	Local_u8Bit= GET_BIT(Copy_u8DataToSend,Local_s8Counter);
		/*   PASS THE MSB  */
		GPIOX_VidSetPinValue(HSTP_SERIAL_DATA,Local_u8Bit);

		/*Send Pluse to Shift Register*/
		GPIOX_VidSetPinValue(HSTP_SHIFT_CLK,HIGH);
		MSTK_VidSetBusyWait(1);//wait 1 Micro
		GPIOX_VidSetPinValue(HSTP_SHIFT_CLK,LOW);
		MSTK_VidSetBusyWait(1);//wait 1 Micro
	}
		/*Send Pluse to Storage Register*/
		GPIOX_VidSetPinValue(HSTP_STORAGE_CLK,HIGH);
		MSTK_VidSetBusyWait(1);//wait 1 Micro
		GPIOX_VidSetPinValue(HSTP_STORAGE_CLK,LOW);
		MSTK_VidSetBusyWait(1);//wait 1 Micro
}



