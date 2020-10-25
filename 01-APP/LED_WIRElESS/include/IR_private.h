/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 3 September 2020           */
/* version     : ver 1                      */
/* Description : INFRA_RED                  */
/********************************************/
#ifndef _IR_PRIVATE_H
#define _IR_PRIVATE_H

static void EXTI_VidIsr(void);
static void SYSTICK_VidIsr(void);
static void (*Global_INFRA_RED_FUNCTION)(u8 Copy_u8InfraRedData);

#define IR_ENABLE           51
#define IR_DISBALE          50


#endif
