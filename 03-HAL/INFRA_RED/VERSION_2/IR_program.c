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
volatile u8 Global_u8Address=0;





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

Remote_button_t HINFRARED_GetRemotePressedButton(void)
{
	Remote_button_t ReturnedData=Remote_ERROR;
	
	if(Global_u8PendingFlag==1)
	{
	    switch(Global_u8Data)
		{
			case POWER        :      ReturnedData=    Remote_POWER                ; break;
			case MODE         :      ReturnedData=    Remote_MODE                 ; break;
			case MUTE         :      ReturnedData=    Remote_MUTE                 ; break;
			case PLAY_RESUME  :      ReturnedData=    Remote_PLAY_RESUME          ; break;
			case RIGHT        :      ReturnedData=    Remote_RIGHT                ; break;
			case LEFT         :      ReturnedData=    Remote_LEFT                 ; break;
			case EQ           :      ReturnedData=    Remote_EQ                   ; break;
			case VOL_DOWN     :      ReturnedData=    Remote_VOL_DOWN             ; break;
			case VOL_UP       :      ReturnedData=    Remote_VOL_UP               ; break;
			case ZERO         :      ReturnedData=    Remote_ZERO                 ; break;
			case RPT          :      ReturnedData=    Remote_RPT                  ; break;
			case U_USD        :      ReturnedData=    Remote_U_USD                ; break;
			case ONE          :      ReturnedData=    Remote_ONE                  ; break;
			case TWO          :      ReturnedData=    Remote_TWO                  ; break;
			case THREE        :      ReturnedData=    Remote_THREE                ; break;
			case FOUR         :      ReturnedData=    Remote_FOUR                 ; break;
			case FIVE         :      ReturnedData=    Remote_FIVE                 ; break;
			case SIX          :      ReturnedData=    Remote_SIX                  ; break;
			case SEVEN        :      ReturnedData=    Remote_SEVEN                ; break;
			case EIGHT        :      ReturnedData=    Remote_EIGHT                ; break;
			case NINE         :      ReturnedData=    Remote_NINE                 ; break;
			
		}


           Global_u8PendingFlag=0;
	
	}
	
	
	return ReturnedData;
	
	
	
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
	INFRARED_STATUS Adress_state=NOK;
	INFRARED_STATUS Data_state=NOK;
   
   Adress_state=HINFRARED_u8CheckAddress();
   if(Adress_state==OK){
	  Data_state=HINFRARED_u8CheckData();
	  if(Data_state==OK){
            Global_u8PendingFlag=1;
			#if IR_INTERRUPT == IR_ENABLE
				Global_INFRA_RED_FUNCTION(Global_u8Data);
				Global_u8PendingFlag=0;
			#endif
	  }
   }
	  Global_u8StartFlag=0;
      Global_u8TimeArray[0]=0;
	  Global_u8CounterIndex=0;
}



static INFRARED_STATUS HINFRARED_u8CheckAddress(void)
{

	u8 Local_u8Index=0;

    u8 Local_u8InvertedAddress=0;


	INFRARED_STATUS State=NOK;
	/*Check the  Right Address*/

  for(Local_u8Index=0;Local_u8Index<8;Local_u8Index++){

        if( ((Global_u8TimeArray[Local_u8Index+1]>=2000) && (Global_u8TimeArray[Local_u8Index+1]<=2400)))
		{

				SET_BIT(Global_u8Address,Local_u8Index);
        }
		else
		{
			CLR_BIT(Global_u8Address,Local_u8Index);
		}
    }

	  /*Check the  Inverted Address*/

	 for(Local_u8Index=0;Local_u8Index<8;Local_u8Index++){

        if( ((Global_u8TimeArray[Local_u8Index+9]>=2000) && (Global_u8TimeArray[Local_u8Index+9]<=2400)))
		{

			  CLR_BIT(Local_u8InvertedAddress,Local_u8Index);
        }
		else
		{
			  SET_BIT(Local_u8InvertedAddress,Local_u8Index);
		}
    }


    if((Global_u8Address)==(Local_u8InvertedAddress)){
		State=OK;
	}

  return State;
}



static INFRARED_STATUS HINFRARED_u8CheckData(void)
{
	u8 Local_u8Index=0;
	u8 Local_u8InvertedData=0;
	INFRARED_STATUS State=NOK;
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


	 for(Local_u8Index=0;Local_u8Index<8;Local_u8Index++){

        if( ((Global_u8TimeArray[Local_u8Index+25]>=2000) && (Global_u8TimeArray[Local_u8Index+25]<=2400)))
		{

			  CLR_BIT(Local_u8InvertedData,Local_u8Index);
        }
		else
		{
			  SET_BIT(Local_u8InvertedData,Local_u8Index);
		}
    }


    if((Global_u8Data)==(Local_u8InvertedData)){
		State=OK;
	}

  return State;
}



void HINFRA_VidSetCallBack(void (*Local_Pointer)(u8 Copy_u8InfraRedData))
{
	
	
	
	Global_INFRA_RED_FUNCTION=Local_Pointer;
}


u8 HINFRA_u8ReadPendingFlag(void){


   return Global_u8PendingFlag;
}


