/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 28 September 2020          */
/* version     : ver 1                      */
/* Description : ADC                        */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSTICK_interface.h"
#include "GPIO_interface.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_VoidInit(void)
{
	

	GPIOX_VidSetPinDirection(PORTA,PIN1,INPUT_ANALOG);//ADC CHANNEL 1
	
	
	
	SET_BIT(ADC1 ->CR2,0);//Enable ADC
	SET_BIT(ADC1 ->CR2,11);//Enable ADC

	
	
}

void ADC_VoidStartConversionSingle(u32* Copy_AdcValue)
{
	
	SET_BIT(ADC1 ->CR2,0);//Enable ADC
	SET_BIT(ADC1 ->CR2,22);//Start Conversion
	while(GET_BIT(ADC1 ->SR,4)==0);

	while(GET_BIT(ADC1 ->SR,1)==0);//wait until the Conversion Complete
	CLR_BIT(ADC1 ->SR,4);//Clr Channel Start Flag
	*Copy_AdcValue=ADC1 ->DR;
	
}
