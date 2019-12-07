#include "stm32f10x.h"
#include "bsp_GeneralTim.h"  
#include "bsp_AdvanceTim.h"
#include "usart.h" //串口3
#include "weidai.h"
#include "systick.h"
#include "base.h"
#include "GY53.h"

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
	
	uint16_t time = 0;
	uint16_t time2 = 0;
	
int main(void)
{
	/*             初始化            */
	
	/* 串口3初始化 */
	USART_Config();  
	
	/* 基本定时器初始化 */
	BASIC_TIM_Init();
	
	/* 激光测距模块 */
	GY53_Init();
	
	

	///********************************** 通用定时器 *********************//
	//T = ARR * (1/CLK_cnt) = （ARR+1）*(PSC+1) / 72M
	
	//周期改小转速变快
	
	/* TIM2初始化 */
		GENERAL_TIMX_Init(0,(20-1),(720-1));
		/* TIM3初始化 */
		GENERAL_TIMX_Init(1,(20-1),(720-1));
		/* TIM4初始化 */
		GENERAL_TIMX_Init(2,(20-1),(720-1));
		/* TIM5初始化 */
		GENERAL_TIMX_Init(3,(20-1),(720-1));
	
	
//***************************** 高级定时器 **********************************//
/* 高级定时器1初始化（假如这个是舵机周期设为20ms）
		那么对应的占空比为25（180°）,20（135°）,15（90°）,10（45°）,5（0°）  */
		ADVANCE_TIMx_Init(0,(200-1),(7200-1),0);
	
		/* 高级定时器2初始化 */
		ADVANCE_TIMx_Init(1,(20-1),(720-1),10);	
		

	/* 激光测距模块1，定时器6 所测距离 */
	printf("%fmm",Hcsr04GetLength());
	
	/* 激光测距模块2，定时器7 所测距离 */
	printf("%fmm",Hcsr04GetLength2());
	
	while(1){
	}
	
}
/*********************************************END OF FILE**********************/
