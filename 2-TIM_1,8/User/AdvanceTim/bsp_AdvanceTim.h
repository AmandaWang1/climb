#ifndef __BSP_ADVANCETIME_H
#define __BSP_ADVANCETIME_H


#include "stm32f10x.h"


/************高级定时器TIM参数定义，只限TIM1和TIM8************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 这里我们使用高级控制定时器TIM1

#define            ADVANCE_TIM_APBxClock_FUN     RCC_APB2PeriphClockCmd

// PWM 信号的频率 F = TIM_CLK/{(ARR+1)*(PSC+1)}



/**************************函数声明********************************/

void ADVANCE_TIMx_Init(uint32_t X,uint32_t ARR,uint32_t PSC,uint32_t pulse);


#endif	/* __BSP_ADVANCETIME_H */


