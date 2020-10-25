/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 14 octbar    2020          */
/* version     : ver 1                      */
/* Description : FPEC                       */
/********************************************/
#ifndef _FPEC_PRIVATE_H
#define _FPEC_PRIVATE_H



typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 AR;
	volatile u32 Reserved;
	volatile u32 OBR;
	volatile u32 WRPR;
	
}FPEC_type;

#define FPEC      ((volatile FPEC_type*)0x4002 2000)

#define RDPRT       0x00A5
#define KEY_1		0x45670123
#define KEY_2		0xCDEF89AB
		
void FPEC_VoidFlashPageErase(u8 Copy_u8PageNumber);


#endif


