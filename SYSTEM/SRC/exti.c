/*
  处部中断初始化
*/
#include "CPU_PIN.H"

//----------------------
void Exti_UserConfig(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	
	/* 选择GPIOx管脚用作外部中断线路 */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource12);
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line12;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; //设置EXTI线路为中断请求
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿中断
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

    EXTI_GenerateSWInterrupt(EXTI_Line12);
}
