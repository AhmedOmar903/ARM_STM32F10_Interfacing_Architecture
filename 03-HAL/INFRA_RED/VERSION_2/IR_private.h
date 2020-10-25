/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 5 September 2020           */
/* version     : ver 2                      */
/* Description : INFRA_RED                  */
/********************************************/
#ifndef _IR_PRIVATE_H
#define _IR_PRIVATE_H

typedef enum{
	
	OK,
	NOK
	
	
}INFRARED_STATUS;



static void EXTI_VidExtiHandle(void);

static void SYSTICK_VidSystickHandle(void);

static INFRARED_STATUS HINFRARED_u8CheckAddress(void);

static INFRARED_STATUS HINFRARED_u8CheckData(void);

static void (*Global_INFRA_RED_FUNCTION)(u8 Copy_u8InfraRedData);


#define Remote_FRAME_START            0
#define Remote_DATA_ADDRESS           1


#define IR_DISBALE             0
#define IR_ENABLE              1

#define POWER                      69
#define MODE                       70
#define MUTE                       71
#define PLAY_RESUME                68
#define RIGHT                      64
#define LEFT                       67
#define EQ                         7
#define VOL_DOWN                   21
#define VOL_UP                     9
#define ZERO                       22
#define RPT                        25
#define U_USD                      13
#define ONE                        12
#define TWO                        24
#define THREE                      94
#define FOUR                       8
#define FIVE                       28
#define SIX                        90
#define SEVEN                      60
#define EIGHT                      82
#define NINE                       74
    


#endif
