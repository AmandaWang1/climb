#ifndef _BASE_H
#define _BASE_H

#include "stm32f10x.h"

#define BASIC_TIM6                     //如果不是TIM6,即注释掉此行，那么#ifdef为假，执行#else,即TIM7

#ifdef  BASIC_TIM6										 //使用基本定时器TIM6
#define          BASIC_TIM                      TIM6
#define          BASIC_TIM_APBxClock_FUN        RCC_APB1PeriphClockCmd
#define          BASIC_TIM_CLK                  RCC_APB1Periph_TIM6
#define          BASIC_TIM_Period               (1000-1)
#define          BASIC_TIM_Prescaler            71
#define          BASIC_TIM_IRQ                  TIM6_IRQn
#define          BASIC_TIM_IRQHandler           TIM6_IRQHandler


#else     													   //使用基本定时器TIM7
#define          BASIC_TIM                      TIM7
#define          BASIC_TIM_APBxClock_FUN        RCC_APB1PeriphClockCmd
#define          BASIC_TIM_CLK                  RCC_APB1Periph_TIM7
#define          BASIC_TIM_Period               (1000-1)
#define          BASIC_TIM_Prescaler            71
#define          BASIC_TIM_IRQ                  TIM7_IRQn
#define          BASIC_TIM_IRQHandler           TIM7_IRQHandler

#endif

void BASIC_TIM_Init(void);

#endif /*_BASE_H*/


