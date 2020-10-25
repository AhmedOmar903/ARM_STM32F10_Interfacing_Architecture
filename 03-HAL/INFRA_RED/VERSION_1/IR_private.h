/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 5 September 2020           */
/* version     : ver 2                      */
/* Description : INFRA_RED                  */
/********************************************/
#ifndef _IR_PRIVATE_H
#define _IR_PRIVATE_H





static void EXTI_VidExtiHandle(void);

static void SYSTICK_VidSystickHandle(void);


static void HINFRARED_u8CheckData(void);

static void (*Global_INFRA_RED_FUNCTION)(u8 Copy_u8InfraRedData);


#define Remote_FRAME_START            0
#define Remote_DATA_ADDRESS           1


#define IR_DISBALE             0
#define IR_ENABLE              1


    


#endif
