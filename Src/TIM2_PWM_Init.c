#include "TIM2_PWM_Init.h"

void TIM2_PWM_Init(void) {
		// Включение тактирования TIM1
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
		// Настройка вывода PA8 в режим альтернативной функции AF1 (TIM2_CH1)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //Тактирование на порт A
		GPIOA->MODER &= ~GPIO_MODER_MODER5; // очистили режим для нужного пина
		GPIOA->MODER |= GPIO_MODER_MODER5_1;
		GPIOA->OSPEEDR |= (GPIO_OSPEEDR_OSPEED5_0 | GPIO_OSPEEDR_OSPEED5_1 ); // скорость very high
		GPIOA->AFR[0] |= GPIO_AFRL_AFSEL5_0; /////////////////////////
		// Установка предделителя таймера TIM2
		TIM2->PSC = 1600-1;
		// Установка периода таймера TIM2
		TIM2->ARR = 255-1;
		// Установка коэффициента заполнения таймера TIM2
		TIM2->CCR1 = 0;
		// Включение канала 1 таймера TIM2 в режиме PWM
		TIM2->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2; // Output Compare 1 mode 110: PWM mode 1 - In upcounting
		TIM2->CCER |= TIM_CCER_CC1E; // Capture/Compare 1 output enable
		// Включение таймера TIM2
		TIM2->CR1 |= TIM_CR1_CEN;
		TIM2->BDTR |= TIM_BDTR_MOE;
	}
