/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 1 September 2020           */
/* version     : ver 1                      */
/* Description : LEDMRX                     */
/********************************************/

#ifndef _LMATRIX_INTERFACE_H_
#define _LMATRIX_INTERFACE_H_

void HLEDMRX_VidInit(void);
void HLEDMRX_VidDisplayAnimation(u8 *Copy_u8Data);

void HLEDMRX_VoidDisplayAnimationSerialToParallel(u16 *Copy_u8RowsData);


void HLEDMRX_VoidCharcterDisplaySerialToParallel(u16 *Copy_u16Data);
#endif
