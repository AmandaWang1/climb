#include "GY53.h"
#include "base.h"
#include "weidai.h"
#include "systick.h"

#define  GY53_Receive    PBin(6)

extern uint16_t time;


void GY53_Init (void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(GY53_CLK , ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = GY53_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;     //GPIO_Mode_IN_FLOATING;//浮空输入
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GY53_PORT, &GPIO_InitStruct);
	
}


/* 打开定时器 */
static void OpenTimerForGY(void)         
{  
	//设置TIM计数器寄存器的值
	TIM_SetCounter(BASIC_TIM,0); //清除计数  
	time = 0;  
	TIM_Cmd(BASIC_TIM,ENABLE);  //使能TIMX外设  
}  
   
/* 关闭定时器 */
static void CloseTimerForGY(void)           
{  
	TIM_Cmd(BASIC_TIM,DISABLE); //使能TIMX外设  
}  


/*这个是从之前stmf10x_it.c里边挪过来的*/
void BASIC_TIM_IRQHandler(void)
{
	if( TIM_GetITStatus( BASIC_TIM,TIM_IT_Update) != RESET)
	{
		time++;
		TIM_ClearITPendingBit(BASIC_TIM,TIM_FLAG_Update);
	}
}


//获取定时器时间  
uint32_t GetGYTimer(void)  
{  
	uint32_t t = 0;  
	t = time * 1000;      //将ms转化为us 
  t = t + TIM_GetCounter(BASIC_TIM);    //得到总us  
	TIM6-> CNT = 0;       //将TIM6计数寄存器的计数值清零 （上一个函数返回值）  
	delay_ms(50);
	return t;  
}  

  
//一次获取测距数据两次测距之间需要相隔一段时间，隔断回响信号  
float Hcsr04GetLength(void)  
{  
	uint32_t t = 0;  
	float  lengthTemp = 0;  
	
	delay_ms(500);

	while (GY53_Receive == 0);      //等待接收口高电平输出  
	OpenTimerForGY();               //打开定时器  
		
	while (GY53_Receive == 1);    //
	CloseTimerForGY();           //关闭定时器 
	
	t = GetGYTimer();           //获取时间，分辨率为1US   
	
	lengthTemp = (float)t / 10;
		
	return lengthTemp;
}  



