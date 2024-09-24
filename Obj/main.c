#define  VARIABLE_DEFINE
#include "CPU_PIN.H"

typedef struct CountTime_st{
	u8 clear;
	u32 value;
	u8 (*iscount_time)(struct CountTime_st*);
}CountTime;

u8 count_time(CountTime *ct)
{
	static u8 flag = 0;
	static u32 buff = 0;
	
	if(ct->clear == 0){
		flag = 0;
		ct->clear = 1;
	}
	if(flag == 0){
		buff = TimingDelay;
		flag = 1;
	}else{
		if((TimingDelay - buff) >= ct->value){
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	CountTime c1,c2;
	//u8 i,j;
	
	SystemInit();
	RCC_Configuration(); //开启模块时钟
	NVIC_Configuration();
	GPIO_Configuration();//设置IO口，全部
	SysTick_Init();//系统定时器SysTick 初始化
	USARTx_UserConfig();//串口初始化
	LED_OFF;
	YS_XXms(1000);
	
	XIANG1();
	
	INTERFACE = PAGE_CHECK_FUN;
	
	
	
	c1.clear = 0;
	c1.value = 5;
	c1.iscount_time = count_time;
	
	c2.clear = 0;
	c2.value = 8;
	c2.iscount_time = count_time;
	
	while(1){
		if(c1.iscount_time(&c1) == 0){
		  //if(i==0){i=1;LED_ON;}else{i=0;LED_OFF;}
			LED_ON;
			c1.clear = 0;
		}
		
		if(c2.iscount_time(&c2) == 0){
		  //if(i==0){i=1;LED_ON;}else{i=0;LED_OFF;}
			LED_OFF;
			c2.clear = 0;
		}
		
//		if(c2.count_time == 0){
//		   //if(i==0){i=1;LED_ON;}else{i=0;LED_OFF;}
//			LED_OFF;
//			c2.clear = 0;
//		}
		
		
//		LED_OFF;
//		YS_XXms(100);
//		LED_ON;
//		YS_XXms(100);
		//jump_interface();
	}
}



