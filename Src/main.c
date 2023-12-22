
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
	while(1)
	{

	}
}


void vTaskAT (void *argument)
{
	char cmdBuffer[CMD_QUEUE_SIZE];
	while(1)
	{
		if(uxQueueMessagesWaiting(xCmdQueue) != 0)   // Check queue
		{
		xQueueReceive(xCmdQueue, cmdBuffer, 0);
		USART_Send_String(cmdBuffer);

	}

 }
}

	void USART1_IRQHandler(void)
	{
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		char rxBuffer[CMD_QUEUE_SIZE];

		    /* We have not woken a task at the start of the ISR. */

			if((USART1->SR & USART_SR_RXNE) && (USART1->CR1 & USART_CR1_RXNEIE))
			{
				USART1->SR &= ~USART_SR_RXNE;

				xQueueSendFromISR(xCmdQueue,&USART1->DR,&xHigherPriorityTaskWoken);

				portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);


			}
	}

