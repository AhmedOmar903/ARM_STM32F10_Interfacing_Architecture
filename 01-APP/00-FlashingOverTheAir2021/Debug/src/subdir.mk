################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FPEC_program.c \
../src/GPIO_program.c \
../src/NVIC_program.c \
../src/OTA_program.c \
../src/Parse.c \
../src/RCC_program.c \
../src/SYSTICK_program.c \
../src/TIMER_program.c \
../src/USART_program.c \
../src/WIFI_program.c \
../src/main.c 

OBJS += \
./src/FPEC_program.o \
./src/GPIO_program.o \
./src/NVIC_program.o \
./src/OTA_program.o \
./src/Parse.o \
./src/RCC_program.o \
./src/SYSTICK_program.o \
./src/TIMER_program.o \
./src/USART_program.o \
./src/WIFI_program.o \
./src/main.o 

C_DEPS += \
./src/FPEC_program.d \
./src/GPIO_program.d \
./src/NVIC_program.d \
./src/OTA_program.d \
./src/Parse.d \
./src/RCC_program.d \
./src/SYSTICK_program.d \
./src/TIMER_program.d \
./src/USART_program.d \
./src/WIFI_program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


