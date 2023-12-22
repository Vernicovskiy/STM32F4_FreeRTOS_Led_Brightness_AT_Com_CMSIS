#include "USART_Init.h"
#include "FreeRTOS.h"

void USART_Init (void){
// Настраиваем порт A для работы с USART1
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Включаем тактирование порта A
  GPIOA->MODER |= GPIO_MODER_MODER5_0; /* set pin to output mode */
  GPIOA->MODER |= GPIO_MODER_MODER9_1; // Устанавливаем режим альтернативной функции для пина PA9 (TX)
  GPIOA->MODER |= GPIO_MODER_MODER10_1;
  GPIOA->AFR[1] |= (GPIO_AFRH_AFSEL9_2 | GPIO_AFRH_AFSEL9_1 | GPIO_AFRH_AFSEL9_0); // Выбираем альтернативную функцию 7 (USART1) для пина PA9
  GPIOA->AFR[1] |= (GPIO_AFRH_AFSEL10_2 | GPIO_AFRH_AFSEL10_1 | GPIO_AFRH_AFSEL10_0); // Выбираем альтернативную функцию 7 (USART1) для пина PA9
  // Настраиваем USART1 для передачи данных
  RCC->APB2ENR |= RCC_APB2ENR_USART1EN; // Включаем тактирование USART1
  USART1->BRR = 0x683; // Устанавливаем скорость передачи 9600 бод при частоте 16 МГц
  USART1->CR1 |= USART_CR1_TE; // Включаем передатчик
  USART1->CR1 |= USART_CR1_RE;
  USART1->CR1 |= USART_CR1_RXNEIE;
  NVIC_EnableIRQ(USART1_IRQn);
  USART1->CR1 |= USART_CR1_UE; // Включаем USART1
  NVIC_SetPriority(USART1_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
}

void USART_Send(char chr)
{
			while(!(USART1->SR & USART_SR_TC));
			USART1->DR = chr;

}

void USART_Send_Data(uint8_t data)
{
			while(!(USART1->SR & USART_SR_TC));
			char buffer[10];
			USART1->DR = data;

}

void USART_Send_String(char* str)
{
			uint8_t i = 0;
			while(str[i])
	{
			USART_Send(str[i++]);
	}
}


