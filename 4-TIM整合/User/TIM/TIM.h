#ifndef _TIM_H
#define _TIM_H

#include "stm32f10x.h"

/******   TIM2-5      *******/
#define            GENERAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd

/******   TIM1&8      *******/
#define            ADVANCE_TIM_APBxClock_FUN     RCC_APB2PeriphClockCmd


/**************************º¯ÊýÉùÃ÷********************************/

void GENERAL_TIMX_Init(uint32_t X,uint32_t ARR,uint32_t PSC);
void ADVANCE_TIMx_Init(uint32_t X,uint32_t ARR,uint32_t PSC,uint32_t pulse);



#endif /*_TIM_H*/
