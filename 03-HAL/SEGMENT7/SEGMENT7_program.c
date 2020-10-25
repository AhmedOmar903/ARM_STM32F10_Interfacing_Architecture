#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GPIO_interface.h"
#include"SEGMENT7_config.h"




void SEGMENT7_VidDisplay(u8 Copy_u8PortName,u8 Copy_u8Value,u8 Copy_u8PortConnections){
	

	u8 numbers[]={zero,one,two,three,four,five,six,seven,eight,nine,off};
	
#if SEGMENT_TYPE==ANODE	

	switch(Copy_u8PortConnections){

	case FIRST_HALF:GPIOX_VidSetPortValue(Copy_u8PortName,(~numbers[Copy_u8Value])); break;
	case SECAND_HALF:GPIOX_VidSetPortValue(Copy_u8PortName,(~((numbers[Copy_u8Value])<<8))); break;
	}

#elif	SEGMENT_TYPE==CATHODE
	switch(Copy_u8PortConnections){

		case FIRST_HALF:GPIOX_VidSetPortValue(Copy_u8PortName,(numbers[Copy_u8Value])); break;
		case SECAND_HALF:GPIOX_VidSetPortValue(Copy_u8PortName,(((numbers[Copy_u8Value])<<8))); break;
		}
#endif	
	
	
	
}

