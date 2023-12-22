#include "stm32f4xx.h"

void USART_Init (void);
void USART_Send(char chr);
void USART_Send_Data(uint8_t data);
void USART_Send_String(char* str);
