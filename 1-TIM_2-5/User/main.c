
// TIM—通用定时器-4路PWM输出应用
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_GeneralTim.h"  

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{
	/* led 端口配置 */ 
//	LED_GPIO_Config();
	//T = ARR * (1/CLK_cnt) = （ARR+1）*(PSC+1) / 72M
	/* TIM2初始化 */
		GENERAL_TIMX_Init(0,(20-1),(7200-1));
		/* TIM3初始化 */
		GENERAL_TIMX_Init(1,(20-1),(7200-1));
		/* TIM4初始化 */
		GENERAL_TIMX_Init(2,(20-1),(7200-1));
		/* TIM5初始化 */
		GENERAL_TIMX_Init(3,(20-1),(7200-1));
	while(1)
	{
	}
	
}
/*********************************************END OF FILE**********************/
