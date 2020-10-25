/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 7 September 2020           */
/* version     : ver 1                      */
/* Description : DAC                        */
/********************************************/
#ifndef _DAC_INTERFACE_H
#define _DAC_INTERFACE_H

/*
 * Remeber to include the file that is holding the Song Array in DAC_program.c
 *
 * */

void DAC_VidInitial(void);
void DAC_VidStartDigitalToAnlog(u16 Copy_u16Frequancy,u8*Copy_u8SongArray);

#endif
