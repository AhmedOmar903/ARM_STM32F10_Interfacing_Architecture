/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 3 September 2020           */
/* version     : ver 1                      */
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


volatile u8 Start_Flag=0;
volatile u32 ARRAY[50]={0};
volatile u8 Counter=0;
volatile u8 InfraRedData=0;
volatile u8 Pending_Flag=0;



void HINFRA_VidIntial(void){

	    MNVIC_VidInit();
		MNVIC_VidInterruptEnable(EXTI_NAME );

  //*********GPIO*************************//

     GPIOX_VidSetPinDirection(EXTI_PORT,EXTI_MAPPING,INPUT_FLOATING);

	//*********EXTI*************************//
		MEXTI_VidSetCallBack(EXTI_VidIsr,EXTI_MAPPING);//ISR Interrupt
		MEXTI_VidInit();
		MEXTI_VidExtiEnable(EXTI_MAPPING);//
	//*************SYSTICK*********************//

		MSYSTCIK_VidInit();

}

void EXTI_VidIsr(void){
	
	if(Start_Flag==0){
		
		MSTK_VidSetIntervalSingle(50000,SYSTICK_VidIsr);//Start Counter
		Start_Flag=1;
	}
	else{
		ARRAY[Counter]=MSTK_u32GetEclipsedTime();// load the Index zero with Eclipsed time
		MSTK_VidSetIntervalSingle(50000,SYSTICK_VidIsr);//Start Counter
		Counter++;
	}
	
	
}
void SYSTICK_VidIsr(void){
	
	u8 Local_u8Index;
	
	for(Local_u8Index=0;Local_u8Index<8;Local_u8Index++){
		
		if( (ARRAY[Local_u8Index+17]>=2000) && (ARRAY[Local_u8Index+17]<=2300)  ){
			
			SET_BIT(InfraRedData,Local_u8Index);
		}
		else{
			CLR_BIT(InfraRedData,Local_u8Index);			
		}
		
	}
  Start_Flag=0;
  ARRAY[0]=0;
  Counter=0;
  Pending_Flag=1;

#if  IR_INTERRUPT == IR_ENABLE

   Global_INFRA_RED_FUNCTION(InfraRedData);

#endif
}

u8 HINFRA_VidGetData(void){

	u8 Local_u8Data=0;

   if(Pending_Flag==1){
	Local_u8Data=InfraRedData;
	Pending_Flag=0;//Clear the Flag
   }
		return Local_u8Data;//Return Data
}

u8 HINFRA_u8ReadFlag(void){


   return Pending_Flag;
}

void HINFRA_VidSetCallBack(void (*Local_Pointer)(u8 Copy_u8InfraRedData)){

	Global_INFRA_RED_FUNCTION=Local_Pointer;

}

