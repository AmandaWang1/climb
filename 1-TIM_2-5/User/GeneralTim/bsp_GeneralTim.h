#ifndef __BSP_GENERALTIME_H
#define __BSP_GENERALTIME_H


#include "stm32f10x.h"

#define            GENERAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd





/**************************º¯ÊýÉùÃ÷********************************/

void GENERAL_TIMX_Init(uint32_t X,uint32_t ARR,uint32_t PSC);


#endif	/* __BSP_GENERALTIME_H */


