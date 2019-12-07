#include "TIM.h"

/******************* TIM2-5	*********************/
struct GeneralTimerx
{
	TIM_TypeDef *  GENERAL_TIMx;
	uint32_t       GENERAL_TIMx_CLK; 
	
	// TIMx 输出比较通道1
	uint32_t       GENERAL_TIMx_CH1_GPIO_CLK;
	GPIO_TypeDef * GENERAL_TIMx_CH1_PORT;
	uint16_t       GENERAL_TIMx_CH1_PIN;
	
	// TIMx 输出比较通道2
	uint32_t       GENERAL_TIMx_CH2_GPIO_CLK;
	GPIO_TypeDef * GENERAL_TIMx_CH2_PORT;
	uint16_t       GENERAL_TIMx_CH2_PIN;	
	
	// TIMx 输出比较通道3
	uint32_t       GENERAL_TIMx_CH3_GPIO_CLK;
	GPIO_TypeDef * GENERAL_TIMx_CH3_PORT;
	uint16_t       GENERAL_TIMx_CH3_PIN;	
	
	// TIMx 输出比较通道4
	uint32_t       GENERAL_TIMx_CH4_GPIO_CLK;
	GPIO_TypeDef * GENERAL_TIMx_CH4_PORT;
	uint16_t       GENERAL_TIMx_CH4_PIN;	
	
}TimX[] = {
	{TIM2,RCC_APB1Periph_TIM2,RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_15,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_3,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_10,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_11},
	
	{TIM3,RCC_APB1Periph_TIM3,RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_6,\
														RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_7,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_0,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_1},
	
	{TIM4,RCC_APB1Periph_TIM4,RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_6,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_7,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_8,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_9},
	
	{TIM5,RCC_APB1Periph_TIM5,RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_0,\
														RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_1,\
														RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_2,\
														RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_3}
};


static void GENERAL_TIM_GPIO_Config(uint32_t i) 
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
	if(i == 0)
	{
		/*** 依次开启AFIO/GPIOA/TIM2时钟 ***/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO | TimX[i].GENERAL_TIMx_CH1_GPIO_CLK, ENABLE);
	}
	else
  // 输出比较通道1 GPIO 初始化
	RCC_APB2PeriphClockCmd(TimX[i].GENERAL_TIMx_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  TimX[i].GENERAL_TIMx_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(TimX[i].GENERAL_TIMx_CH1_PORT, &GPIO_InitStructure);
	
	
	if(i == 0)
	{
		/*** 依次开启AFIO/GPIOA/TIM2时钟 ***/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO | TimX[i].GENERAL_TIMx_CH2_GPIO_CLK, ENABLE);
	}
	else
	// 输出比较通道2 GPIO 初始化
	RCC_APB2PeriphClockCmd(TimX[i].GENERAL_TIMx_CH2_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin = TimX[i]. GENERAL_TIMx_CH2_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(TimX[i].GENERAL_TIMx_CH2_PORT, &GPIO_InitStructure);
	
	
	if(i == 0)
	{
		/*** 依次开启AFIO/GPIOA/TIM2时钟 ***/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO | TimX[i].GENERAL_TIMx_CH3_GPIO_CLK, ENABLE);
	}
	else
	// 输出比较通道3 GPIO 初始化
	RCC_APB2PeriphClockCmd(TimX[i].GENERAL_TIMx_CH3_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin = TimX[i]. GENERAL_TIMx_CH3_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(TimX[i].GENERAL_TIMx_CH3_PORT, &GPIO_InitStructure);
	
	if(i == 0)
	{
		/*** 依次开启AFIO/GPIOA/TIM2时钟 ***/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO | TimX[i].GENERAL_TIMx_CH4_GPIO_CLK, ENABLE);
	}
	else
	// 输出比较通道4 GPIO 初始化
	RCC_APB2PeriphClockCmd(TimX[i].GENERAL_TIMx_CH4_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  TimX[i].GENERAL_TIMx_CH4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(TimX[i].GENERAL_TIMx_CH4_PORT, &GPIO_InitStructure);
}

//第一个参数定时器X(X=0 对应TIM2, X=1 对应TIM3, X=2 对应TIM4, X=3,对应TIM5)
//第二个参数ARR的值,第三个参数psc的值
static void GENERAL_TIM_Mode_Config(uint32_t j,uint32_t m,uint32_t n)
{
	
  
	
	if(j==0)
	{
		/*** 依次开启AFIO/GPIOA/TIM2时钟 ***/
//		RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA, ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
		/*** 配置JTAG禁用，SWD保留 ***/
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
		/*** 定时器2部分重映射1 ***/
		GPIO_PinRemapConfig( GPIO_PartialRemap1_TIM2, ENABLE);	
	}
	else
	{
		// 开启定时器时钟,即内部时钟CK_INT=72M
		GENERAL_TIM_APBxClock_FUN(TimX[j].GENERAL_TIMx_CLK,ENABLE);
	}
	
	
	// 配置周期，这里配置为100K
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
	TIM_TimeBaseStructure.TIM_Period = m;	
	// 驱动CNT计数器的时钟 = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler = n;	
	// 时钟分频因子 ，配置死区时间时需要用到
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// 计数器计数模式，设置为向上计数
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// 重复计数器的值，没用到不用管
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// 初始化定时器
	TIM_TimeBaseInit(TimX[j].GENERAL_TIMx, &TIM_TimeBaseStructure);

	
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// 配置为PWM模式1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// 输出使能
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// 输出通道电平极性配置	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = 6;///////////////////////
	
	// 输出比较通道 1
	TIM_OC1Init(TimX[j].GENERAL_TIMx, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TimX[j].GENERAL_TIMx, TIM_OCPreload_Enable);
	
	// 输出比较通道 2
	TIM_OC2Init(TimX[j].GENERAL_TIMx, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TimX[j].GENERAL_TIMx, TIM_OCPreload_Enable);
	
	// 输出比较通道 3
	TIM_OC3Init(TimX[j].GENERAL_TIMx, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TimX[j].GENERAL_TIMx, TIM_OCPreload_Enable);
	
	// 输出比较通道 4
	TIM_OC4Init(TimX[j].GENERAL_TIMx, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TimX[j].GENERAL_TIMx, TIM_OCPreload_Enable);
	
	// 使能计数器
	TIM_Cmd(TimX[j].GENERAL_TIMx, ENABLE);
}


/* ----------------   PWM信号 周期和占空比的计算--------------- */
// ARR ：自动重装载寄存器的值
// CLK_cnt：计数器的时钟，等于 Fck_int / (psc+1) = 72M/(psc+1)
// PWM 信号的周期 T = ARR * (1/CLK_cnt) = （ARR+1）*(PSC+1) / 72M
// 占空比P=CCR/(ARR+1)

//第一个参数定时器X(X=0 对应TIM2, X=1 对应TIM3, X=2 对应TIM4, X=3,对应TIM5)
//第二个参数ARR的值,第三个参数psc的值
void GENERAL_TIMX_Init(uint32_t X,uint32_t ARR,uint32_t PSC)
{
	GENERAL_TIM_GPIO_Config(X);
	GENERAL_TIM_Mode_Config(X,ARR,PSC);		
}





/**********************	TIM1&8	***********************/
struct AdvanceTimerx
{
	TIM_TypeDef *  ADVANCE_TIMx;
	uint32_t       ADVANCE_TIMx_CLK; 
	
	// TIMx 输出比较通道1
	uint32_t       ADVANCE_TIMx_CH1_GPIO_CLK;
	GPIO_TypeDef * ADVANCE_TIMx_CH1_PORT;
	uint16_t       ADVANCE_TIMx_CH1_PIN;
	
	// TIMx 输出比较通道2
	uint32_t       ADVANCE_TIMx_CH2_GPIO_CLK;
	GPIO_TypeDef * ADVANCE_TIMx_CH2_PORT;
	uint16_t       ADVANCE_TIMx_CH2_PIN;
	
	// TIMx 输出比较通道3
	uint32_t       ADVANCE_TIMx_CH3_GPIO_CLK;
	GPIO_TypeDef * ADVANCE_TIMx_CH3_PORT;
	uint16_t       ADVANCE_TIMx_CH3_PIN;
	
	// TIMx 输出比较通道4
	uint32_t       ADVANCE_TIMx_CH4_GPIO_CLK;
	GPIO_TypeDef * ADVANCE_TIMx_CH4_PORT;
	uint16_t       ADVANCE_TIMx_CH4_PIN;
	
}ATimX[] = {
	{TIM1,RCC_APB2Periph_TIM1,RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_8,\
														RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_9,\
														RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_10,\
														RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_11},
	
	{TIM8,RCC_APB2Periph_TIM8,RCC_APB2Periph_GPIOC,GPIOC,GPIO_Pin_6,\
														RCC_APB2Periph_GPIOC,GPIOC,GPIO_Pin_7,\
														RCC_APB2Periph_GPIOC,GPIOC,GPIO_Pin_8,\
														RCC_APB2Periph_GPIOC,GPIOC,GPIO_Pin_9},
	
};

static void ADVANCE_TIMx_GPIO_Config(uint32_t X) 
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // 输出比较通道1 GPIO 初始化
	RCC_APB2PeriphClockCmd( ATimX[X].ADVANCE_TIMx_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =   ATimX[X].ADVANCE_TIMx_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init( ATimX[X].ADVANCE_TIMx_CH1_PORT, &GPIO_InitStructure);
	
	// 输出比较通道2 GPIO 初始化
	RCC_APB2PeriphClockCmd( ATimX[X].ADVANCE_TIMx_CH2_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =   ATimX[X].ADVANCE_TIMx_CH2_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init( ATimX[X].ADVANCE_TIMx_CH2_PORT, &GPIO_InitStructure);
	
	// 输出比较通道3 GPIO 初始化
	RCC_APB2PeriphClockCmd( ATimX[X].ADVANCE_TIMx_CH3_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =   ATimX[X].ADVANCE_TIMx_CH3_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init( ATimX[X].ADVANCE_TIMx_CH3_PORT, &GPIO_InitStructure);
	
	// 输出比较通道4 GPIO 初始化
	RCC_APB2PeriphClockCmd( ATimX[X].ADVANCE_TIMx_CH4_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =   ATimX[X].ADVANCE_TIMx_CH4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init( ATimX[X].ADVANCE_TIMx_CH4_PORT, &GPIO_InitStructure);

}


///*
// * 注意：TIM_TimeBaseInitTypeDef结构体里面有5个成员，TIM6和TIM7的寄存器里面只有
// * TIM_Prescaler和TIM_Period，所以使用TIM6和TIM7的时候只需初始化这两个成员即可，
// * 另外三个成员是通用定时器和高级定时器才有.
// *-----------------------------------------------------------------------------
// *typedef struct
// *{ TIM_Prescaler            都有
// *	TIM_CounterMode			     TIMx,x[6,7]没有，其他都有
// *  TIM_Period               都有
// *  TIM_ClockDivision        TIMx,x[6,7]没有，其他都有
// *  TIM_RepetitionCounter    TIMx,x[1,8,15,16,17]才有
// *}TIM_TimeBaseInitTypeDef; 
// *-----------------------------------------------------------------------------
// */

/* ----------------   PWM信号 周期和占空比的计算--------------- */
// ARR ：自动重装载寄存器的值
// CLK_cnt：计数器的时钟，等于 Fck_int / (psc+1) = 72M/(psc+1)
// PWM 信号的周期 T = (ARR+1) * (1/CLK_cnt) = (ARR+1)*(PSC+1) / 72M
// 占空比P=CCR/(ARR +1)

static void ADVANCE_TIMx_Mode_Config(uint32_t X ,uint32_t ARR,uint32_t PSC,uint32_t pulse)
{
  // 开启定时器时钟,即内部时钟CK_INT=72M
	ADVANCE_TIM_APBxClock_FUN( ATimX[X].ADVANCE_TIMx_CLK,ENABLE);

/*--------------------时基结构体初始化-------------------------*/
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
	TIM_TimeBaseStructure.TIM_Period= ARR;	     /////////////////////////
	// 驱动CNT计数器的时钟 = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= PSC;	   /////////////////
	// 时钟分频因子 ，配置死区时间时需要用到
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// 计数器计数模式，设置为向上计数
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// 重复计数器的值，没用到不用管
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// 初始化定时器
	TIM_TimeBaseInit( ATimX[X].ADVANCE_TIMx, &TIM_TimeBaseStructure);

	/*--------------------输出比较结构体初始化-------------------*/		
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// 配置为PWM模式1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// 输出使能
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// 互补输出使能
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; 
	// 设置占空比大小
	TIM_OCInitStructure.TIM_Pulse = pulse;  ////////////////////////////
	// 输出通道电平极性配置
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	// 互补输出通道电平极性配置
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	// 输出通道空闲电平极性配置
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	// 互补输出通道空闲电平极性配置
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
	TIM_OC1Init(ATimX[X].ADVANCE_TIMx , &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(ATimX[X].ADVANCE_TIMx, TIM_OCPreload_Enable);

//	/*-------------------刹车和死区结构体初始化-------------------*/
//	// 有关刹车和死区结构体的成员具体可参考BDTR寄存器的描述
//	TIM_BDTRInitTypeDef TIM_BDTRInitStructure;
//  TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Enable;
//  TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Enable;
//  TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_1;
//	// 输出比较信号死区时间配置，具体如何计算可参考 BDTR:UTG[7:0]的描述
//	// 这里配置的死区时间为152ns
//  TIM_BDTRInitStructure.TIM_DeadTime = 11;
//  TIM_BDTRInitStructure.TIM_Break = TIM_Break_Enable;
//	// 当BKIN引脚检测到高电平的时候，输出比较信号被禁止，就好像是刹车一样
//  TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_High;
//  TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Enable;
//  TIM_BDTRConfig(ADVANCE_TIM, &TIM_BDTRInitStructure);
	
	// 使能计数器
	TIM_Cmd(ATimX[X].ADVANCE_TIMx, ENABLE);	
	// 主输出使能，当使用的是通用定时器时，这句不需要
	TIM_CtrlPWMOutputs(ATimX[X].ADVANCE_TIMx, ENABLE);
}


/*
	函数名：ADVANCE_TIMx_Init
	参数：X-选择定时器1或者8具体值为 0对应定时器1；1对应定时器8；ARR-寄存器ARR的值；PSC-寄存器psc的值；pulse-占空比
	返回值：无
	说明：寄存器ARR和PSC共同决定了定时器的周期，具体计算公式为： T = (ARR+1) * (1/CLK_cnt) = (ARR+1)*(PSC+1) / 72M （单位：us）
	
 */
void ADVANCE_TIMx_Init(uint32_t X,uint32_t ARR,uint32_t PSC,uint32_t pulse)
{
	ADVANCE_TIMx_GPIO_Config(X);
	ADVANCE_TIMx_Mode_Config(X ,ARR,PSC,pulse);		
}

/*********************************************END OF FILE**********************/




