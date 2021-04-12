/********************************************/  
/* Author          : Ahmed Ramadan          */
/* Date            : 2 April 2021           */
/* version         : ver 2                  */
/* Descripsion     : Over The Air           */
/********************************************/

#ifndef _OTA_PRIVATE_H
#define _OTA_PRIVATE_H




#define SCB_VTOR   *((volatile u32*)0xE000ED08)
typedef void (*FunctionToCall)(void);

FunctionToCall TheMainApplication=0;



#define DISALLOWED  0
#define ALLOWED  	1

static TIMER_FireTheInterrupt=DISALLOWED;





static void FlashingOverTheAir_VoidReceivedDataValidation(u8 Copy_u8RecoredData);
static void FlashingOverTheAir_VoidParseTheRecords(void);

static void FlashingOverTheAir_VoidExcuteTheMainApplication(void);
#endif


