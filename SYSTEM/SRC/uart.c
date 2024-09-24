//���ڳ�ʼ��
#include "uart.h"

u8  RX1_GS;
u8 	KEY_YES;
u16 ADS7843_X,ADS7843_Y;
u8 	KEY_XH,KEY_XL;
u8 	KEY_YH,KEY_YL;

void USARTx_UserConfig(void)
{
	USART_InitTypeDef USART_InitStructure;
	
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //8λ����
	USART_InitStructure.USART_StopBits = USART_StopBits_1; //1��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No; //����ż
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //��Ӳ��������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; //ʹ�� ����|����
	USART_InitStructure.USART_BaudRate = 115200;
	USART_Init(USART1, &USART_InitStructure);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); //ʹ�� �����ж�
	USART_ITConfig(USART1, USART_IT_TXE, DISABLE); //�ر� �����ж�
	USART_Cmd(USART1, ENABLE); //ʹ��USART����
	
	/*
	USART_InitStructure.USART_BaudRate = 115200;
	USART_Init(USART3, &USART_InitStructure);
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE); //ʹ�� �����ж�
	USART_ITConfig(USART3, USART_IT_TXE, DISABLE); //�ر� �����ж�
	USART_Cmd(USART3, ENABLE); //ʹ��USART����
	USART_InitStructure.USART_BaudRate = 115200;
	USART_Init(USART2, &USART_InitStructure);
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); //ʹ�� �����ж�
	USART_ITConfig(USART2, USART_IT_TXE, DISABLE); //�ر� �����ж�
	USART_Cmd(USART2, ENABLE); //ʹ��USART����
	*/
}

void TX1_OUT_0(u8 data)
{
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	USART_SendData(USART1,data);
}



