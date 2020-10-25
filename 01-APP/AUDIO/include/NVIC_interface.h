/********************************************/  
/* Author      : Ahmed Ramadan              */
/* Date        : 19 August 2020             */
/* version     : ver 1                      */
/* Description : NVIC                       */
/********************************************/
#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H
/**********************************INTERRRUPT_Postions*************************************************/
#define  WWDG_1                   0
#define  PVD                      1
#define  TAMPER                   2
#define  RTC                      3
#define  FLASH                    4
#define  RCC                      5
#define  EXTI0                    6
#define  EXTI1                    7
#define  EXTI2                    8
#define  EXTI3                    9
#define  EXTI4                    10
#define  DMA1_Channel1            11
#define  DMA1_Channel2            12
#define  DMA1_Channel3            13
#define  DMA1_Channel4            14
#define  DMA1_Channel5            15
#define  DMA1_Channel6            16
#define  DMA1_Channel7            17
#define  ADC1_2                   18
#define  USB_HP_CAN_TX            19
#define  USB_HP_CAN_RX0           20
#define  CAN_RX1                  21
#define  CAN_SCE                  22
#define  EXTI9_5                  23
#define  TIM1_BRK                 24
#define  TIM1_UP                  25
#define  TIM1_TRG_COM             26  
#define  TIM1_CC                  27
#define  TIM2_1                   28
#define  TIM3_1                   29
#define  TIM4_1                   30
#define  I2C1_EV                  31
#define  I2C1_ER                  32
#define  I2C2_EV                  33
#define  I2C2_ER                  34
#define  SPI1_1                   35
#define  SPI2_1                   36
#define  USART1_1                 37
#define  USART2_1                 38
#define  USART3_1                 39
#define  EXTI15_10                40
#define  RTCAlarm                 41
#define  USBWakeup                42
#define  TIM8_BRK                 43
#define  TIM8_UP                  44
#define  TIM8_TRG_COM             45  
#define  TIM8_CC                  46
#define  ADC_3                    47
#define  FSMC_1                   48
#define  SDIO_1                   49
#define  TIM5_1                   50
#define  SPI3_1                   51
#define  UART4                    52
#define  UART5                    53
#define  TIM6_1                   54
#define  TIM7_1                   55
#define  DMA2_Channel1            56   
#define  DMA2_Channel2            57  
#define  DMA2_Channel3            58   
#define  DMA2_Channel4_5          59     
/*********************************************************************************************************/

																		  
/**********************************Initialization*************************************************/

void MNVIC_VidInit(void);

/**********************************INTERRRUPT_ENABLE*************************************************/
void MNVIC_VidInterruptEnable(u8 Copy_u8InterruptNumber);   //Enable Interrupt//
void MNVIC_VidInterruptDisable(u8 Copy_u8InterruptNumber);  //disable Interrupt//
/**********************************PENDING_FLAG******************************************************/
void MNVIC_VidSetPendingFlag(u8 Copy_u8InterruptNumber);//ENABLE PENDING//
void MNVIC_VidClrPendingFlag(u8 Copy_u8InterruptNumber);//Disable PENDING//
/**********************************ACTIVE_FLAG*******************************************************/
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptNumber);

/**********************************Set_Priority*******************************************************/


                          // inter ID            which group            sub group index    number of groups and sub//
void MNVIC_VidSetPirority(s8 Copy_s8IntId,u8 Copy_u8GroupPriority,u8 Copy_u8SubGroupPriority);

#endif
