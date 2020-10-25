/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 1 September 2020           */
/* version     : ver 1                      */
/* Description : LEDMRX                     */
/********************************************/


#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "STP_interface.h"
#include "LMATRIX_interface.h"
#include "LMATRIX_config.h"



void HLEDMRX_VidInit(void){
	
	GPIOX_VidSetPortDirection(COLUMN_PORT,OUTPUT_SPEED_2M_PUSH_PULL,COLUMN_CONNECTION);
	GPIOX_VidSetPortDirection(ROW_PORT,OUTPUT_SPEED_2M_PUSH_PULL,ROW_CONNECTION);	
}

void HLEDMRX_VidDisplayAnimation(u8 *Copy_u8Data)
{
	  u8 SHIFTED,COL_NUM,REAPETED;
      for(SHIFTED=0;SHIFTED<8;SHIFTED++)
	  {
          for(REAPETED=0;REAPETED<7;REAPETED++)
		  {
	          for(COL_NUM=0;COL_NUM<8;COL_NUM++)
			  {
		            GPIOX_VidSetPortValue(COLUMN_PORT,0xFFFF);//disable all coulmns
		            GPIOX_VidSetPortValue(ROW_PORT,Copy_u8Data[COL_NUM]);// write the Value in the row port
		            GPIOX_VidSetPinValue(COLUMN_PORT,COULMN_START_PIN+COL_NUM+SHIFTED,LOW);//WRITE IN THE  COLUMN x ZERO//
		            MSTK_VidSetBusyWait(2.5);// wait 2.5 ms to Prevent flickring or ghosting
	           }
         }
    }
}

void HLEDMRX_VoidDisplayAnimationSerialToParallel(u16 *Copy_u8RowsData)
{
    
	u8 SHIFTED,COL_NUM,REAPETED;
	for(SHIFTED=8;SHIFTED>4;SHIFTED--)
	{
		for(REAPETED=0;REAPETED<25;REAPETED++)
		{
			for(COL_NUM=0;COL_NUM<8;COL_NUM++)
			{
				CLR_BIT(Copy_u8RowsData[COL_NUM],(COL_NUM+SHIFTED));//Clear THE Selected Column
				STP_VoidSendSynchronus(Copy_u8RowsData[COL_NUM]);//Send The Data
				MSTK_VidSetBusyWait(1000);
				SET_BIT(Copy_u8RowsData[COL_NUM],(COL_NUM+SHIFTED));//Set THE Selected Column
			}
		}
	}
}

void HLEDMRX_VoidCharcterDisplaySerialToParallel(u16 *Copy_u16Data)
{

	u8 Local_u8Index=0,Local_u8Reapeted;
  for(Local_u8Reapeted=0;Local_u8Reapeted<25;Local_u8Reapeted++)
  {
	for(Local_u8Index=0;Local_u8Index<8;Local_u8Index++)
	{
		CLR_BIT(Copy_u16Data[Local_u8Index],(Local_u8Index+8));//Clear THE Selected Column
		STP_VoidSendSynchronus(Copy_u16Data[Local_u8Index]);//Send The Data
		MSTK_VidSetBusyWait(300);
		SET_BIT(Copy_u16Data[Local_u8Index],(Local_u8Index+8));//Set THE Selected Column
	}
  }



}













