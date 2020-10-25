/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 12 August 2020             */
/* version     : ver 1                      */
/* Description : GPIO                       */
/********************************************/
#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H
/*******************PORT_SIZE*********************/
#define FIRST_HALF        0
#define SECAND_HALF       1
#define PORTC_HIGH        111
#define PORTC_LOW         000

/*******************PORTS*********************/
#define PORTA           0
#define PORTB           1
#define PORTC           2
/*******************PINS*********************/
#define PIN0            0
#define PIN1            1
#define PIN2            2
#define PIN3            3
#define PIN4            4
#define PIN5            5
#define PIN6            6
#define PIN7            7
#define PIN8            8
#define PIN9            9
#define PIN10           10
#define PIN11           11
#define PIN12           12
#define PIN13           13
#define PIN14           14
#define PIN15           15
/**********************OUTPUT_MODES****************************/

/**********************MODES FOR SPEED 10MHZ**********************/
#define   OUTPUT_SPEED_10M_PUSH_PULL           0b0001
#define   OUTPUT_SPEED_10M_OPEN_DRAIN          0b0101
#define   OUTPUT_SPEED_10M_AF_PUSH_PULL        0b1001
#define   OUTPUT_SPEED_10M_AF_OPEN_DRAIN       0b1101
/**********************MODES FOR SPEED 2MHZ**********************/
#define   OUTPUT_SPEED_2M_PUSH_PULL            0b0010
#define   OUTPUT_SPEED_2M_OPEN_DRAIN           0b0110
#define   OUTPUT_SPEED_2M_AF_PUSH_PULL         0b1010
#define   OUTPUT_SPEED_2M_AF_OPEN_DRAIN        0b1110
/**********************MODES FOR SPEED 50MHZ**********************/
#define   OUTPUT_SPEED_50M_PUSH_PULL           0b0011
#define   OUTPUT_SPEED_50M_OPEN_DRAIN          0b0111
#define   OUTPUT_SPEED_50M_AF_PUSH_PULL        0b1011
#define   OUTPUT_SPEED_50M_AF_OPEN_DRAIN       0b1111
/**********************INPUT_MODES****************************/
#define INPUT_ANALOG          0b0000
#define INPUT_FLOATING        0b0100
#define INPUT_PULL_UP_DOWN    0b1000
/**********************Values**************************/
#define  LOW      0
#define  HIGH     1
/**********************FUNCTIONS_Prototypes**************************/





/***************************************PIN DIRECTION******************************************************/

void GPIOX_VidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode); //PIN DIRECTION//
void GPIOX_VidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);//PIN VALUE//
u8 GPIOX_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin);// GET PIN VALUE//

/***************************************PORT DIRECTION******************************************************/

void GPIOX_VidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Mode,u8 Copy_u8PortSize);//PORT DIRECTION//

void GPIOX_VidSetPortValue(u8 Copy_u8Port,u16 Copy_u16Value);


/***************************************GET_BIN******************************************************/

void GPIOX_VidTogPin(u8 Copy_u8Port,u8 Copy_u8Pin);

void delay(void);
#endif
