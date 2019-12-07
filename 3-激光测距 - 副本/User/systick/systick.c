#include "systick.h"

//us
void delay_us(uint32_t us)
{
	uint32_t i;
	SysTick_Config(72);
	
	for(i=0;i<us;i++)
	{
		while( !((SysTick->CTRL) & (1<<16)) );
	}
	
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


//ms
void delay_ms(uint32_t ms)
{
	uint32_t i;
	SysTick_Config(72000);
	
	for(i=0;i<ms;i++)
	{
		while( !((SysTick->CTRL) & (1<<16)) );             //等待置1，若置1 则1ms时间到了
	}
	
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


