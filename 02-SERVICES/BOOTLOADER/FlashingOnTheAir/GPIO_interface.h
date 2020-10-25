/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 12 August 2020             */
/* version     : ver 1                      */
/* Description : GPIO                       */
/********************************************/
#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H
/*******************PORT_SIZE*********************/

/*******************PORTS*********************/
#define PORTA           0
#define PORTB           1
#define PORTC           2
/*******************PINS*********************/

#define PIN9            9
#define PIN10           10



#define   OUTPUT_SPEED_50M_AF_PUSH_PULL        0b1011

#define INPUT_FLOATING        0b0100




/***************************************PIN DIRECTION******************************************************/

void GPIOX_VidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode); //PIN DIRECTION//

#endif
