
#include "main.h"



uint8_t rxIndex = 0;


int main(void)
{

	GPIO_Init();
	USART_Init();
	TIM2_PWM_Init();

	xTaskCreate(vTaskLed, "LED", 128, NULL, 1, NULL );
	xTaskCreate(vTaskAT, "AT_Waiting", 128, NULL, 1, NULL );
	xCmdQueue = xQueueCreate(CMD_QUEUE_SIZE, sizeof (int));
	xLedQueue = xQueueCreate(LED_QUEUE_SIZE, sizeof (int));

	vTaskStartScheduler();

	while(1)
	{

	}
}

//---------------------------------------------------------------

void vTaskLed (void *argument)
{
	uint8_t brightness_res;

	while(1)
	{
		if(uxQueueMessagesWaiting(xLedQueue) != 0)   // Check queue
		{
		if(xQueueReceive(xLedQueue, &brightness_res, portMAX_DELAY) == pdTRUE){
			TIM2->CCR1 = brightness_res;
			asm("NOP");
		}

	}
}
}


void vTaskAT (void *argument)
{
	char cmdBuffer[CMD_QUEUE_SIZE];
	static char linearBuffer[CMD_QUEUE_SIZE]; // Declare linear
	int16_t brightness;
	char data;
	uint32_t linearIndex = 0;
	while(1)
	{
		if(uxQueueMessagesWaiting(xCmdQueue) != 0)   // Check queue
		{
		if(xQueueReceive(xCmdQueue, &data, portMAX_DELAY) == pdTRUE){
			linearBuffer[linearIndex] = data;
			linearIndex = (linearIndex + 1) % CMD_QUEUE_SIZE;
			if(data == '\n')
			{
				brightness = CMD_Parse_Brightness(linearBuffer);
				if (brightness<=255 && brightness>=0){
				xQueueSend(xLedQueue,&brightness,0);
				}
				//USART_Send_String(brightness);

				linearIndex = 0;
			}
		}
		asm("NOP");
	}


 }
}

	void USART1_IRQHandler(void)
	{
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;

		    /* We have not woken a task at the start of the ISR. */

			if((USART1->SR & USART_SR_RXNE) && (USART1->CR1 & USART_CR1_RXNEIE))
			{
				USART1->SR &= ~USART_SR_RXNE;

				xQueueSendFromISR(xCmdQueue,&USART1->DR,&xHigherPriorityTaskWoken);


				portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);


			}

	}
