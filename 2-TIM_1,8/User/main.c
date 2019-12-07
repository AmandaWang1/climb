#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_AdvanceTim.h"  

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	
	/* 高级定时器1初始化（假如这个是舵机周期设为20ms）
		那么对应的占空比为25（180°）,20（135°）,15（90°）,10（45°）,5（0°）  */
	ADVANCE_TIMx_Init(0,(200-1),(7200-1),0);
	
	/* 高级定时器2初始化 */
	ADVANCE_TIMx_Init(1,(20-1),(720-1),10);
	
	
	
	
  while(1)
  {      
  }
}
/*********************************************END OF FILE**********************/

