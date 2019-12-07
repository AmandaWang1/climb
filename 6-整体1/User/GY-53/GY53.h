#ifndef _HC_H
#define _HC_H

#include "stm32f10x.h"

#define ON     1
#define OFF    0


#define GY53_PIN                  GPIO_Pin_6
#define GY53_PORT                 GPIOB
#define GY53_CLK                  RCC_APB2Periph_GPIOB

#define GY53_PIN2                  GPIO_Pin_7
#define GY53_PORT2                 GPIOB
#define GY53_CLK2                 RCC_APB2Periph_GPIOB

void GY53_Init (void);
void BASIC_TIM_IRQHandler(void);
uint32_t GetGYTimer(void);
float Hcsr04GetLength(void);

void GY53_Init2 (void);
void BASIC_TIM7_IRQHandler(void);
uint32_t GetGYTimer2(void);
float Hcsr04GetLength2(void);


#endif /*_HC_H*/



