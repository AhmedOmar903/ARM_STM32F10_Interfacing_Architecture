/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 1 September 2020           */
/* version     : ver 1                      */
/* Description : LEDMRX                     */
/********************************************/


#ifndef _LMATRIX_CONFIG_H_
#define _LMATRIX_CONFIG_H_


/*
PORT                : PORTA,PORTB

CONNECTION          : FIRST_HALF,SECAND_HALF

COULMN_START_PIN    :  Choose FROM PIN 0 to PIN 8   

HINT: Colums must be connected to the Same Port Beyond each other Starts from the Choosen COULMN_START_PIN 
*/





#define ROW_PORT                     PORTA
#define ROW_CONNECTION               FIRST_HALF







#define COLUMN_PORT                   PORTB
#define COLUMN_CONNECTION             SECAND_HALF
#define COULMN_START_PIN                 8








#endif
