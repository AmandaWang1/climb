#ifndef _HC_H
#define _HC_H

#include "stm32f10x.h"

#define ON     1
#define OFF    0


#define GY53_PIN                  GPIO_Pin_0
#define GY53_PORT                 GPIOD
#define GY53_CLK                  RCC_APB2Periph_GPIOD

void GY53_Init (void);
void BASIC_TIM_IRQHandler(void);
uint32_t GetGYTimer(void);
float Hcsr04GetLength(void);


#endif /*_HC_H*/



