![Static Badge](https://img.shields.io/badge/Unic_Lab-green)
![Static Badge](https://img.shields.io/badge/STM32-red)
![GitHub last commit (by committer)](https://img.shields.io/github/last-commit/Vernicovskiy/STM32_TIM)
![GitHub Repo stars](https://img.shields.io/github/stars/Vernicovskiy/STM32_TIM)
![GitHub watchers](https://img.shields.io/github/watchers/Vernicovskiy/STM32_TIM)
![GitHub top language](https://img.shields.io/github/languages/top/Vernicovskiy/STM32_TIM)







# Управление яркостью светодиода с компьютера посредством AT-команд.
 * NUCLEO-F401RE
 * STM32F401RET6U
 * ARM Cortex M4
 * CMSIS
 * STM32 CubeIDE v1.13.2
 
Программа предназначена для управления яркостью светодиода с компьютера посредством AT-команд, используя операционную систему FreeRTOS. 

Программа состоит из двух основных частей: 

1)задачи декодирования AT-команд 
2)задачи установки яркости светодиода

Эти задачи обмениваются данными посредством очередей, реализованных с помощью API FreeRTOS. 

Программа использует прерывания для приема символов команд от компьютера и отправки ответов обратно.

Форматы AT-команд определены следующим образом:

* AT+LED=яркость_светодиода Enter

* at+led=яркость_светодиода Enter 

Яркость_светодиода принимает значения от 0 (выключен) до 255 (полная яркость).
 
* AT Enter 

* at Enter 

Ответом на любую команду является строка вида luminance=яркость_светодиода, отображающая текущее значение яркости светодиода.

Для управления яркостью светодиода используется режим PWM (ШИМ). ШИМ-сигнал генерируется с помощью таймера микроконтроллера, позволяя изменять яркость светодиода.

Программа состоит из следующих модулей: 
* Включение и инициализация необходимых периферийных устройств, таких как GPIO, USART и TIM2.

* Создание двух задач FreeRTOS: vTaskLed и vTaskAT.

* Создание двух очередей FreeRTOS: xCmdQueue и xLedQueue, которые используются для обмена данными между задачами.

* Определение обработчика прерывания USART1, который принимает символы команд от компьютера и помещает их в xCmdQueue.

* Реализация функции (задачи) vTaskLed, которая ожидает получения значения яркости светодиода из xLedQueue и устанавливает его в регистр таймера TIM2->CCR1, который контролирует ширину импульса PWM сигнала на выходе TIM2_CH1.

* Реализация функции (задачи) vTaskAT, которая периодически считывает символы команд из xCmdQueue в линейный буфер и декодирует их, проверяя соответствие формату AT-команд.

