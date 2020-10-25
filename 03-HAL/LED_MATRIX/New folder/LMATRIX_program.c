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
#include "LMATRIX_interface.h"
#include "LMATRIX_config.h"



void HLEDMRX_VidInit(void){
	
	GPIOX_VidSetPortDirection(COLUMN_PORT,OUTPUT_SPEED_2M_PUSH_PULL,COLUMN_CONNECTION);
	GPIOX_VidSetPortDirection(ROW_PORT,OUTPUT_SPEED_2M_PUSH_PULL,ROW_CONNECTION);	
}
/*
Brief this Function is used to Display the Letter and shifted it
*/
void HLEDMRX_VidDisplay(u8 *Copy_u8Data){
u8 SHIFTED,COL_NUM,REAPETED;
for(SHIFTED=0;SHIFTED<8;SHIFTED++){
    for(REAPETED=0;REAPETED<7;REAPETED++){
	          for(COL_NUM=0;COL_NUM<8;COL_NUM++){
		            GPIOX_VidSetPortValue(COLUMN_PORT,0xFFFF);//disable all coulmns
		            GPIOX_VidSetPortValue(ROW_PORT,Copy_u8Data[COL_NUM]);// write the Value in the row port
		            GPIOX_VidSetPinValue(COLUMN_PORT,COULMN_START_PIN+COL_NUM+SHIFTED,LOW);//WRITE IN THE  COLUMN x ZERO//
		            MSTK_VidSetBusyWait(2.5);// wait 2.5 ms to Prevent flickring or ghosting
	           }
         }
    }
}

