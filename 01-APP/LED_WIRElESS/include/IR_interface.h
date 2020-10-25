/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 3 September 2020           */
/* version     : ver 1                      */
/* Description : INFRA_RED                  */
/********************************************/
#ifndef _IR_INTERFACE_H
#define _IR_INTERFACE_H


void HINFRA_VidIntial(void);

void HINFRA_VidSetCallBack(void (*Local_Pointer)(u8 Copy_u8InfraRedData));
u8 HINFRA_VidGetData(void);
u8 HINFRA_u8ReadFlag(void);

#endif
