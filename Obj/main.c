#define  VARIABLE_DEFINE
#include "CPU_PIN.H"

int main(void)
{
	SystemInit();
	RCC_Configuration(); //开启模块时钟
	NVIC_Configuration();
	GPIO_Configuration();//设置IO口，全部
	SysTick_Init();//系统定时器SysTick 初始化
	USARTx_UserConfig();//串口初始化
	LED_OFF;
	YS_XXms(1000);
	INTERFACE = PAGE_CHECK_FUN;
	
//	UL1Mhz_Par.power = 100;
//	passStructToFunction(&UL1Mhz_Par);
	
	while(1){
		jump_interface();
	}
}









