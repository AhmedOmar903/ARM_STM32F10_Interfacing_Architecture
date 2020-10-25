/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 5 September 2020           */
/* version     : ver 2                      */
/* Description : INFRA_RED                  */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSTICK_interface.h"
#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"


/******Global_variables********/
volatile u8  Global_u8StartFlag=Remote_FRAME_START;
volatile u32 Global_u8TimeArray[50]={0};
volatile u8  Global_u8CounterIndex=0;
volatile u8  Global_u8PendingFlag=0;

/*****DATA*********/
volatile u8 Global_u8Data=0;





void HINFRARED_VidInitail(void)
{
	
/*************NVIC_INIT**************************/	
	    MNVIC_VidInit();
		MNVIC_VidInterruptEnable(EXTI_NAME );
/*************GPIO_INIT**************************/

     GPIOX_VidSetPinDirection(EXTI_PORT,EXTI_MAPPING,INPUT_FLOATING);

/*************EXTI_INIT**************************/
		MEXTI_VidSetCallBack(EXTI_VidExtiHandle,EXTI_MAPPING);//ISR Interrupt
		MEXTI_VidInit();
		MEXTI_VidExtiEnable(EXTI_MAPPING);
/*************SYSTICK_INIT*********************/

		MSYSTCIK_VidInit();		
}

u8 HINFRARED_GetRemotePressedButton(void)
{

	u8 Local_u8Data=0;
	if(Global_u8PendingFlag==1)
	{
           Global_u8PendingFlag=0;
           Local_u8Data= Global_u8Data;
	}
	return Local_u8Data;
}

static void EXTI_VidExtiHandle(void)
{
	
	
	switch(Global_u8StartFlag)
	
	{
		case Remote_FRAME_START : 
				MSTK_VidSetIntervalSingle(200000,SYSTICK_VidSystickHandle);//Start Counter
		        Global_u8StartFlag=Remote_DATA_ADDRESS;
		             break;
		case Remote_DATA_ADDRESS : 
		        Global_u8TimeArray[Global_u8CounterIndex]=MSTK_u32GetEclipsedTime(); //Get the Eclipsed Timer
				MSTK_VidSetIntervalSingle(200000,SYSTICK_VidSystickHandle);//Start Counter
				Global_u8CounterIndex++;
		             break;
	}	
}

static void SYSTICK_VidSystickHandle(void)
{
   
         HINFRARED_u8CheckData();

      Global_u8PendingFlag=1;
	  Global_u8StartFlag=0;
      Global_u8TimeArray[0]=0;
	  Global_u8CounterIndex=0;
#if IR_INTERRUPT == IR_ENABLE
	Global_INFRA_RED_FUNCTION(Global_u8Data);
	Global_u8PendingFlag=0;
#endif
}





static void HINFRARED_u8CheckData(void)
{
	u8 Local_u8Index=0;
	/*Check the Right Data*/
  for(Local_u8Index=0;Local_u8Index<8;Local_u8Index++){
		
        if( ((Global_u8TimeArray[Local_u8Index+17]>=2000) && (Global_u8TimeArray[Local_u8Index+17]<=2400)))
		{
	            
				SET_BIT(Global_u8Data,Local_u8Index);
        }
		else
		{
			   CLR_BIT(Global_u8Data,Local_u8Index);
		}	 
    }

}



void HINFRA_VidSetCallBack(void (*Local_Pointer)(u8 Copy_u8InfraRedData))
{
	
	
	
	Global_INFRA_RED_FUNCTION=Local_Pointer;
}


u8 HINFRA_u8ReadPendingFlag(void){


   return Global_u8PendingFlag;
}


