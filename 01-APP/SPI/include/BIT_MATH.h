/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 29/7/2020                  */
/* version     : ver 1                      */
/********************************************/

#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(VAR,BITNUM)        (VAR) |=   (1 << (BITNUM))
#define CLR_BIT(VAR,BITNUM)        (VAR) &= ~ (1 << (BITNUM))
#define TOG_BIT(VAR,BITNUM)        (VAR) ^=   (1 << (BITNUM))
#define GET_BIT(VAR,BITNUM)        (((VAR) >>(BITNUM))&1)
#endif