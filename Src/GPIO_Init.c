#include "GPIO_Init.h"

void GPIO_Init (void)
{
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //Тактирование на порт A

		GPIOA->MODER &= ~GPIO_MODER_MODER5; // очистили режим для нужного пина

		GPIOA->MODER |= GPIO_MODER_MODER5_0; // пин на выход

		GPIOA->OSPEEDR |= (GPIO_OSPEEDR_OSPEED5_0 | GPIO_OSPEEDR_OSPEED5_1 ); // скорость very high

		GPIOA->BSRR = GPIO_BSRR_BS5; // установили в высокое состояние
}
