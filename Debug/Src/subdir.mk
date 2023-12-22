################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/CMD_Parse_Brightness.c \
../Src/GPIO_Init.c \
../Src/TIM2_PWM_Init.c \
../Src/USART_Init.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/CMD_Parse_Brightness.o \
./Src/GPIO_Init.o \
./Src/TIM2_PWM_Init.o \
./Src/USART_Init.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/CMD_Parse_Brightness.d \
./Src/GPIO_Init.d \
./Src/TIM2_PWM_Init.d \
./Src/USART_Init.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/Unic_Lab/STM32F4_FreeRTOS_Led_Brightness_AT_Com_CMSIS/Inc" -I"D:/Unic_Lab/STM32F4_FreeRTOS_Led_Brightness_AT_Com_CMSIS/CMSIS/inc" -I"D:/Unic_Lab/STM32F4_FreeRTOS_Led_Brightness_AT_Com_CMSIS/FreeRTOS/inc" -I"D:/Unic_Lab/STM32F4_FreeRTOS_Led_Brightness_AT_Com_CMSIS/CMSIS/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/CMD_Parse_Brightness.cyclo ./Src/CMD_Parse_Brightness.d ./Src/CMD_Parse_Brightness.o ./Src/CMD_Parse_Brightness.su ./Src/GPIO_Init.cyclo ./Src/GPIO_Init.d ./Src/GPIO_Init.o ./Src/GPIO_Init.su ./Src/TIM2_PWM_Init.cyclo ./Src/TIM2_PWM_Init.d ./Src/TIM2_PWM_Init.o ./Src/TIM2_PWM_Init.su ./Src/USART_Init.cyclo ./Src/USART_Init.d ./Src/USART_Init.o ./Src/USART_Init.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

