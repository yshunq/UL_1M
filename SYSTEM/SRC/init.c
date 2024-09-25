#include "CPU_PIN.H"
#include "init.h"


void GPIO_Configuration(void)				
{  						 
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// ���������   
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12; //DD
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //����������50MHz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
	GPIO_Init(GPIOB,&GPIO_InitStructure);	
	DD_OFF;
	
	//��
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;				 //LED1-->PA.4 �˿�����
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
//	GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.4
//	GPIO_SetBits(GPIOB,GPIO_Pin_4);						 //PA.4 �����
//	
//	
//	//��ŷ�1
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_3; //
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //����������50MHz
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
//	GPIO_Init(GPIOB,&GPIO_InitStructure);	
//	
//	
//	//��ŷ�5
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7; //
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //����������50MHz
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
//	GPIO_Init(GPIOB,&GPIO_InitStructure);	
//	
//	//��ŷ�4
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6; //
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //����������50MHz
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
//	GPIO_Init(GPIOB,&GPIO_InitStructure);	
//	
//	//���˱�����
//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9;//KEY0-KEY2
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //���ó���������
// 	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOE2,3,4
//	
//	
	//LED
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8; //
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //����������50MHz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
	GPIO_Init(GPIOA,&GPIO_InitStructure);	
	
//	
//	//LED2
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5; //
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //����������50MHz
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
//	GPIO_Init(GPIOB,&GPIO_InitStructure);	
//	
//	
//	//׼������
//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8;//KEY0-KEY2
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
// 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
	/*
	//�̵���
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7; //
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //����������50MHz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
	GPIO_Init(GPIOA,&GPIO_InitStructure);	
	
	
	

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	    		 //LED2-->PA.6 �˿�����, �������
	GPIO_Init(GPIOA, &GPIO_InitStructure);	  				 //������� ��IO���ٶ�Ϊ50MHz
	//GPIO_SetBits(GPIOA,GPIO_Pin_6); 						 //PA.6 ����� 
	
	
	//��������
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3|GPIO_Pin_5;//KEY0-KEY2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOE2,3,4
	
	//card
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6;//KEY0-KEY2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB6
	
	
	//PWM
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	*/
	
	
	/*
	//card
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_7|GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	*/
	
	/*
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9; //ICDATA ICCLK ICRST
	GPIO_Init(GPIOC,&GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10; //KEY_LEDO
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	
	// ���� 
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6; //ICKK
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //��������	
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	*/
	//GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13; //KEY_INTB KEY_INTA KEY_FS0
	//GPIO_Init(GPIOD,&GPIO_InitStructure);
	
	// ���ô��� 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //RX1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //��������
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //TX1
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //����������50MHz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�����������
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	/*
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11; //RX3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //��������
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //TX3
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //����������50MHz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�����������
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3; //RX2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //��������
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //TX3
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //����������50MHz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�����������
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	*/
}



//----------------------
void NVIC_Configuration(void)
{	
	NVIC_InitTypeDef  NVIC_InitStructure;
	
	#if VECT_BOOT_APP //BOOT������ַ
		NVIC_SetVectorTable(FLASH_APP_ADDR, 0x0);  
	#else //����0x00������ַ
		NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
	#endif

	// �������ȼ��� 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	// ��ʱ��3 
//	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
	
	
	// ����1 
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	/*
		// ����2 
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	// ����3 
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	*/
	/*
	// EXTI12 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	*/
}



//----------------------
void RCC_Configuration(void) //����ģ��ʱ��
{
	// APB2ʱ�� 72MHz 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC
								|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE
								|RCC_APB2Periph_AFIO, ENABLE); //ʹ�� GPIOA~E AFIO ʱ��
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); //USART1ʱ��
	//APB1ʱ�� 36MHz 
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //TIM3ʱ��
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE); //USART3ʱ��
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); //USART2ʱ��
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE); //I2Cʱ��
}

////-------------------------------------------------------------------------------------
//void USER_OffInit(void) //�û�������ʼ��
//{
//	DD_OFF;
//	RX1_GS=10;	
//	//WORK_PARAMETERS = 1;
//	//START_STOP_FLAG = 1;
//	//�Ĵ�������
//	TimingDelay=0;
//}

/*
//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//0��û���κΰ�������
//1��KEY0����
//2��KEY1����
//3��KEY2���� 
//4��KEY3���� WK_UP
//ע��˺�������Ӧ���ȼ�,KEY0>KEY1>KEY2>KEY3!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//�������ɿ���־
	if(mode)key_up=1;  //֧������		  
	if(key_up&&(KEY0==0||KEY1==0||KEY2==0||WK_UP==1))
	{
		delay_ms(10);//ȥ���� 
		key_up=0;
		if(KEY0==0)return KEY0_PRES;
		else if(KEY1==0)return KEY1_PRES;
		else if(KEY2==0)return KEY2_PRES;
		else if(WK_UP==1)return WKUP_PRES;
	}else if(KEY0==1&&KEY1==1&&KEY2==1&&WK_UP==0)key_up=1; 	    
 	return 0;// �ް�������
}
*/

 void rfPwmInit(void)
 {
 TIM_OCInitTypeDef  TIM_OCInitStruct;
 TIM_TimeBaseInitTypeDef   TIM_TimeBaseInitStruct;
 TIM_BDTRInitTypeDef  TIM_BDTRInitStruct;

 RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

 TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
 TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
 TIM_TimeBaseInitStruct.TIM_Period = 119;  // 159 = 450khz �Զ���������
 TIM_TimeBaseInitStruct.TIM_Prescaler = 0;
 TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
 TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStruct);
 TIM_ARRPreloadConfig(TIM1, ENABLE);

 TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
 TIM_OCInitStruct.TIM_OCIdleState = TIM_OCIdleState_Reset;
 TIM_OCInitStruct.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
 TIM_OCInitStruct.TIM_OCNPolarity = TIM_OCNPolarity_High;
 TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
 TIM_OCInitStruct.TIM_OutputNState = TIM_OutputNState_Enable;
 TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
 TIM_OCInitStruct.TIM_Pulse = 59;    // 79
 TIM_OC1Init(TIM1, &TIM_OCInitStruct);
 TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);

 TIM_BDTRInitStruct.TIM_AutomaticOutput = TIM_AutomaticOutput_Disable;
 TIM_BDTRInitStruct.TIM_Break = TIM_Break_Disable;
 TIM_BDTRInitStruct.TIM_BreakPolarity = TIM_BreakPolarity_Low;
 TIM_BDTRInitStruct.TIM_DeadTime = 50;    //  
 TIM_BDTRInitStruct.TIM_LOCKLevel = TIM_LOCKLevel_OFF;
 TIM_BDTRInitStruct.TIM_OSSIState = TIM_OSSIState_Disable;
 TIM_BDTRInitStruct.TIM_OSSRState = TIM_OSSRState_Disable;
 TIM_BDTRConfig(TIM1, &TIM_BDTRInitStruct);
 
 TIM_Cmd(TIM1, ENABLE);
}

void tim1DeadTime(u8 time){
    TIM1->BDTR &= 0xFF00;
    TIM1->BDTR |= time;
}








