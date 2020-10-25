/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 14 September 2020          */
/* version     : ver 1                      */
/* Description : STP                        */
/********************************************/
#ifndef _STP_CONFIG_H
#define _STP_CONFIG_H

/*Please Write Pins in pairs PORTA,PIN0*/

/*
 * ONE_IC
  TWO_IC
 *
 * */


#define HSTP_SERIAL_DATA         PORTA,PIN0
#define HSTP_SHIFT_CLK		     PORTA,PIN2
#define HSTP_STORAGE_CLK         PORTA,PIN1

#define STP_ICS        TWO_IC



#endif
