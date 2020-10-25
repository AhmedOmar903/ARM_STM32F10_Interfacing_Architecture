/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 7 September 2020           */
/* version     : ver 1                      */
/* Description : DAC                        */
/********************************************/
#ifndef _DAC_CONFIG_H
#define _DAC_CONFIG_H

/*
DAC_PORT     : 

	1-PORTA
	2-PORTB
	3-PORTC
	
	
DAC_PORT_CONNECTION   :
    
	1-FIRST_HALF	
	1-SECAND_HALF	

DAC_ARRAY :    Name of the ARRAY  ex AMR[Local_u16Index]   HINT : Local_u16Index is Fixed in the Array

DAC_ARRAY_LENGTH : Lenght of the Array to repeat the song
*/


#define DAC_PORT                           PORTB
#define DAC_PORT_CONNECTION                SECAND_HALF
#define DAC_ARRAY_LENGTH                   55078







#endif
