#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "GPIO_Init.h"
#include "USART_Init.h"
#include "TIM2_PWM_Init.h"
#include "string.h"
#include  "stdio.h"
#include "CMD_Parse_Brightness.h"
//#include "CMD_Parse_Brightness.h"

#define CMD_END '\r' // Символ конца команды
#define CMD_LEN 8 // Максимальная длина команды
#define LED_QUEUE_SIZE 10 // Размер очереди для яркости
#define CMD_RESPONSE "luminance=" // Ответ на команду
#define CMD_QUEUE_SIZE 11 // Размер очереди для яркости
#define CMD_PREFIX_AT "AT\n"
#define CMD_PREFIX_at "at\n"

xQueueHandle xCmdQueue;
xQueueHandle xLedQueue;



void vTaskLed (void *argument);
void vTaskAT (void *argument);

