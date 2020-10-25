/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 5 September 2020           */
/* version     : ver 2                      */
/* Description : INFRA_RED                  */
/********************************************/
#ifndef _IR_CONFIG_H
#define _IR_CONFIG_H

/*
EXTI_PORT : PORTA ,PORTB,PORTC


EXTI_MAPPING:  0 ||1 ||2  etc

EXTI_NAME:

 EXTI_NAME=  EXTI0      
 EXTI_NAME=  EXTI1      
 EXTI_NAME=  EXTI2      
 EXTI_NAME=  EXTI3      


 IR_INTERRUPT :

  1-IR_ENABLE
  2-IR_DISBALE

*/

#define EXTI_PORT        PORTA
#define EXTI_MAPPING       0
#define EXTI_NAME        EXTI0


#define IR_INTERRUPT     IR_DISBALE




#endif
