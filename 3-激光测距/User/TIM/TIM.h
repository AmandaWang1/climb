#ifndef _TIM_H
#define _TIM_H

#include "stm32f10x.h"

#define          ADVANCE_TIM                      TIM1
#define          ADVANCE_TIM_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define          ADVANCE_TIM_CLK                  RCC_APB2Periph_TIM1


// CLK_cnt：计数器的时钟，等于 Fck_int / (psc+1) = 72M/(psc+1)
// PWM 信号的周期 T = (ARR+1) * (1/CLK_cnt) = (ARR+1)*(PSC+1) / 72M
// 占空比P=CCR/(ARR+1)
#define          ADVANCE_TIM_PERIOD               (200-1)      //周期 ,20ms
#define          ADVANCE_TIM_PSC            			(7200-1)      //决定了计数器计一次的时间
#define          ADVANCE_TIM_PULSE          			0       //更改此项可更改占空比

#define          ADVANCE_TIM_IRQ        					TIM1_UP_IRQn
#define          ADVANCE_TIM_IRQHandler    				TIM1_UP_IRQHandler

//TIM1 输出比较通道
#define      		 ADVANCE_TIM_CH1_GPIO_CLK          RCC_APB2Periph_GPIOA
#define          ADVANCE_TIM_CH1_PORT        			 GPIOA
#define        	 ADVANCE_TIM_CH1_PIN       				 GPIO_Pin_8

//TIM1 输出比较通道的互补通道CLK     		 
#define          ADVANCE_TIM_CH1N_GPIO_CLK         RCC_APB2Periph_GPIOB
#define					 ADVANCE_TIM_CH1N_PORT        		 GPIOB
#define      		 ADVANCE_TIM_CH1N_PIN      				 GPIO_Pin_13

//TIM1 输出比较通道的刹车通道
#define          ADVANCE_TIM_BKIN_GPIO_CLK         RCC_APB2Periph_GPIOB
#define			     ADVANCE_TIM_BKIN_PORT     				 GPIOB
#define          ADVANCE_TIM_BKIN_PIN      				 GPIO_Pin_12

void TIM_Init(void);

#endif /*_TIM_H*/


