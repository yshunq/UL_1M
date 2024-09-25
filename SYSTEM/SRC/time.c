#include "time.h"

u32 TimingDelay;

void SysTick_Init(void) //系统定时器SysTick 初始化
{ 
	//选择 AHB 时钟(HCLK)作为 SysTick 时钟源
  SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
  //设置 SysTick 重装载值,假设系统时钟为 72MHz,这里设置每 1ms 产生一次中断
  SysTick->LOAD = 72000 - 1;
  // 清空当前值
  SysTick->VAL = 0;
  // 使能 SysTick 中断
  SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
  // 启动 SysTick 定时器
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}







//通用定时器3中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器3!
//void TIM3_Int_Init(u16 arr,u16 psc)
//{
//  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;

//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟使能
//	
//	//定时器TIM3初始化
//	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
//	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
//	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
// 
//	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断,允许更新中断

//	//中断优先级NVIC设置
//	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //从优先级3级
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
//	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器

//	TIM_Cmd(TIM3, ENABLE);  //使能TIMx					 
//}
////定时器3中断服务程序
//void TIM3_IRQHandler(void)   //TIM3中断
//{
//		if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
//		{
//				TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //清除TIMx更新中断标志 
//				SECONDS_FLAG++;
//				if(START_STOP_FLAG == 0 && FLOW_GEAR > 0)	
//				{
//						FLOW_COUNT++;
//						if(FLOW_COUNT == FLOW_SET_DATA)
//						{
//								FLOW_DCF_OFF;
//						}
//						else if(FLOW_COUNT >= FLOW_CYCLE_DATA)
//						{
//								FLOW_COUNT = 0;
//								FLOW_DCF_ON;
//						}
//				}
//				
//				
//		}
//}













/*
//----------------------
void Timx_UserConfig(void)
{			 
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	// TIM3配置 /
	TIM_DeInit(TIM3);//复位TIMx定时器
	TIM_TimeBaseStructure.TIM_Prescaler = 7199;
	TIM_TimeBaseStructure.TIM_Period = 9999; //1s
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置了时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, & TIM_TimeBaseStructure);

	TIM_ClearFlag(TIM3, TIM_FLAG_Update); //清除TIMx溢出中断标志 
	TIM_ARRPreloadConfig(TIM3, DISABLE); //预装载寄存器的内容被立即传送到影子寄存器
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE); //TIMx溢出中断允许
	TIM_Cmd(TIM3, ENABLE); //允许TIMx计数
}

//TIM1 CH1 PWM输出设置 
//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
//TIM1_PWM_Init(71,0);	//TIM1 PWM初始化, Fpwm=72M/72=1Mhz.
//TIM_SetCompare1(TIM1,36);//初始值为0	初始化值决定脉宽
void TIM1_PWM_Init(u16 arr,u16 psc)
{		 					 
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); //使能TIMx外设
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //使能GPIOA外设时钟使能
	
  //设置该引脚为复用输出功能,输出TIM1 CH1的PWM脉冲波形
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; //TIM1_CH1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用功能输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure); //初始化GPIO
	
	TIM_TimeBaseStructure.TIM_Period = arr; //设置自动重装载周期值
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置预分频值 不分频
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //CH1 PWM2模式	
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //OC1 低电平有效 
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);  //根据指定的参数初始化外设TIMx
	
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);  //CH1 预装载使能
	TIM_ARRPreloadConfig(TIM1, ENABLE); //使能TIMx在ARR上的预装载寄存器
	TIM_CtrlPWMOutputs(TIM1,ENABLE);	//MOE 主输出使能,高级定时器必须开启这个 
	TIM_Cmd(TIM1, ENABLE);  //使能TIMx
} 
*/




