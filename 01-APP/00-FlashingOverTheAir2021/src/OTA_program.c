/********************************************/  
/* Author          : Ahmed Ramadan          */
/* Date            : 2 April 2021           */
/* version         : ver 2                  */
/* Descripsion     : Over The Air           */
/********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_interface.h"
#include "TIMER_interface.h"
#include "WIFI_interface.h"
#include "NVIC_interface.h"
#include"RCC_interface.h"
#include "FPEC_interface.h"
#include "OTA_private.h"
#include "OTA_interface.h"
#include "OTA_config.h"




u8 FlashingOverTheAir_ArrayThatIsHoldTheRecoreds[19000]={0};
u8 FlashingOverTheAir_Buffer[100]={0};
u32 FlashingOverTheAir_u8Iterator=0;




void Parser_voidParseRecord(u8* Copy_u8BufData);



void FlashingOverTheAir_VoidInitialization(void)
{
	RCC_VoidEnableClock(RCC_APB1 ,0);		   //TIMER 2
	MNVIC_VidInterruptEnable(28);			  // Enable Timer 2
	TIMER_VoidTimerStartAsyncrouonas(TIMER2, 65500,FlashingOverTheAir_VoidExcuteTheMainApplication);
	TIMER_VoidInitailze(TIMER2,UP_COUNTER);
}









void FlashingOverTheAir_VoidDownloadTheHexFile(void)
{
	u8 Local_u8TempVar=0;

	TIMER_VoidDisableTheTimer(TIMER2);//Disable The Timer

	UART_VoidReceiveCompleteDisable();	// Disable The Uart Interrupt
	while(		Local_u8TempVar		!=255			)
	{
		Local_u8TempVar=UART_VoidWiFiCmdValidate();
		FlashingOverTheAir_VoidReceivedDataValidation(Local_u8TempVar);
	}
	
	if(		FlashingOverTheAir_u8Iterator	<	100		){TIMER_FireTheInterrupt=ALLOWED;TIMER_VoidTimerStartAsyncrouonas(TIMER2,1,FlashingOverTheAir_VoidExcuteTheMainApplication);}
	else FlashingOverTheAir_VoidParseTheRecords();
}








static void FlashingOverTheAir_VoidParseTheRecords(void)
{	
	u8 *PointerToTheFlashingOverTheAirArray=FlashingOverTheAir_ArrayThatIsHoldTheRecoreds,Local_Index=0;
	
	FPEC_voidEraseAppArea();

	while(		*PointerToTheFlashingOverTheAirArray	!=	'L'		)
	{

		if(*PointerToTheFlashingOverTheAirArray!='\n')
		{
			FlashingOverTheAir_Buffer[Local_Index++]=*PointerToTheFlashingOverTheAirArray;
		}
		else
		{
			Local_Index=0;
			Parser_voidParseRecord(FlashingOverTheAir_Buffer);
		}
		PointerToTheFlashingOverTheAirArray++;
	}

	TIMER_FireTheInterrupt=ALLOWED;
	TIMER_VoidTimerStartAsyncrouonas(TIMER2,1,FlashingOverTheAir_VoidExcuteTheMainApplication);
}








static void FlashingOverTheAir_VoidReceivedDataValidation(u8 Copy_u8RecoredData)
{
	static unsigned char  StorageStatus=DISALLOWED,NumberOfPlus=0;
	
	if(  Copy_u8RecoredData=='+'   ||  (Copy_u8RecoredData==':' && StorageStatus==DISALLOWED) || Copy_u8RecoredData=='L' )
	{
		
		if(			NumberOfPlus			< 2		)
		{
			switch(Copy_u8RecoredData)
			{
				case '+':	StorageStatus=DISALLOWED;  NumberOfPlus++;	   break;
				case ':':	StorageStatus=ALLOWED;							break;
				case 'L':	
				StorageStatus=DISALLOWED; FlashingOverTheAir_ArrayThatIsHoldTheRecoreds[FlashingOverTheAir_u8Iterator-1]='L';
				break;
			}
		}
		else if(		NumberOfPlus == 2  &&  Copy_u8RecoredData==':')
		{
			FlashingOverTheAir_u8Iterator--;
			NumberOfPlus--;
			StorageStatus=ALLOWED;
		}
	}
	else if(	StorageStatus  	==		ALLOWED	 && Copy_u8RecoredData!='\r' )
	{
		FlashingOverTheAir_ArrayThatIsHoldTheRecoreds[FlashingOverTheAir_u8Iterator++]=Copy_u8RecoredData;
	}	
}










static void FlashingOverTheAir_VoidExcuteTheMainApplication(void)
{
	u16 Counter=0;
	Counter++;

	if(		Counter==153		|| 	TIMER_FireTheInterrupt==ALLOWED)
	{
		SCB_VTOR=APPLICATION_START_ADDRESS;//0x08002800;
		TheMainApplication=*(FunctionToCall*)(APPLICATION_START_ADDRESS+4);//0x08002804
		TheMainApplication();
	}
}





