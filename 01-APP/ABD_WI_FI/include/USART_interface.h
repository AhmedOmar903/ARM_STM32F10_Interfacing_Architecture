#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void MUSART1_voidInit(void);

void MUSART1_voidTransmit(char* word);

u8 MUSART1_u8Receive(u32 Copy_u32timeout);

#endif