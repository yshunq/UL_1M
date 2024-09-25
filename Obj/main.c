#define  VARIABLE_DEFINE
#include "CPU_PIN.H"

//typedef struct CountTime_st{
//	u8 clear;
//	u32 value;
//	u8 (*iscount_time)(struct CountTime_st*);
//}CountTime;

//u8 count_time(CountTime *ct)
//{
//	static u8 flag = 0;
//	static u32 buff = 0;
//	
//	if(ct->clear == 0){
//		flag = 0;
//		ct->clear = 1;
//	}
//	if(flag == 0){
//		buff = TimingDelay;
//		flag = 1;
//	}else{
//		if((TimingDelay - buff) >= ct->value){
//			return 0;
//		}
//	}
//	return 1;
//}




//UL1Mhz_TypeDef UL1Mhz_Par;


int main(void)
{
//	UL1Mhz_TypeDef UL1Mhz_Par;
//	UL1Mhz_Par.power = 100;
//	
	
	SystemInit();
	RCC_Configuration(); //开启模块时钟
	NVIC_Configuration();
	GPIO_Configuration();//设置IO口，全部
	SysTick_Init();//系统定时器SysTick 初始化
	USARTx_UserConfig();//串口初始化
	LED_OFF;
	YS_XXms(1000);
	INTERFACE = PAGE_CHECK_FUN;
	
	UL1Mhz_Par.power = 100;
	passStructToFunction(&UL1Mhz_Par);
	
	//INTERFACE = UL1Mhz_Par.power;
	
	
	
	
	while(1){
//		LED_OFF;
//		YS_XXms(100);
//		LED_ON;
//		YS_XXms(100);
		jump_interface();
	}
}



