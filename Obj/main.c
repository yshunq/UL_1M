#define  VARIABLE_DEFINE
#include "CPU_PIN.H"

int main(void)
{
	SystemInit();
	RCC_Configuration(); //����ģ��ʱ��
	NVIC_Configuration();
	GPIO_Configuration();//����IO�ڣ�ȫ��
	SysTick_Init();//ϵͳ��ʱ��SysTick ��ʼ��
	USARTx_UserConfig();//���ڳ�ʼ��
	LED_OFF;
	YS_XXms(1000);
	INTERFACE = PAGE_CHECK_FUN;
	
//	UL1Mhz_Par.power = 100;
//	passStructToFunction(&UL1Mhz_Par);
	
	while(1){
		jump_interface();
	}
}









