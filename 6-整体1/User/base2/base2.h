#ifndef _BASE2_H
#define _BASE2_H

#include "stm32f10x.h"

    													   //使用基本定时器TIM7
#define          BASIC_TIM7                      TIM7
#define          BASIC_TIM7_APBxClock_FUN        RCC_APB1PeriphClockCmd
#define          BASIC_TIM7_CLK                  RCC_APB1Periph_TIM7
#define          BASIC_TIM7_Period               (1000-1)
#define          BASIC_TIM7_Prescaler            71
#define          BASIC_TIM7_IRQ                  TIM7_IRQn
#define          BASIC_TIM7_IRQHandler           TIM7_IRQHandler


void BASIC_TIM7_Init(void);

#endif /*_BASE2_H*/


