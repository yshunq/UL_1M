/*
  �����жϳ�ʼ��
*/
#include "CPU_PIN.H"

//----------------------
void Exti_UserConfig(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	
	/* ѡ��GPIOx�ܽ������ⲿ�ж���· */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource12);
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line12;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; //����EXTI��·Ϊ�ж�����
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //�½����ж�
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

    EXTI_GenerateSWInterrupt(EXTI_Line12);
}
