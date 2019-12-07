
// TIM—通用定时器-4路PWM输出应用
#include "stm32f10x.h"
#include "bsp_led.h"
#include "TIM.h"  

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{
	/* TIM2初始化 */
	GENERAL_TIMX_Init(0,(20-1),(7200-1));
	/* TIM3初始化 */
	GENERAL_TIMX_Init(1,(20-1),(7200-1));
	/* TIM4初始化 */
	GENERAL_TIMX_Init(2,(20-1),(7200-1));
	/* TIM5初始化 */
	GENERAL_TIMX_Init(3,(20-1),(7200-1));
	
	
	/* TIM1初始化（假如这个是舵机周期设为20ms）
		那么对应的占空比为25（180°）,20（135°）,15（90°）,10（45°）,5（0°）  */
	ADVANCE_TIMx_Init(0,(200-1),(7200-1),0);
	/* TIM8初始化 */
	ADVANCE_TIMx_Init(1,(20-1),(7200-1),0);
	
	while(1);
	
}
/*********************************************END OF FILE**********************/
