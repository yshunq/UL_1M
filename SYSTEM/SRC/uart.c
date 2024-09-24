//串口初始化
#include "uart.h"

u8  RX1_GS;
u8 	KEY_YES;
u16 ADS7843_X,ADS7843_Y;
u8 	KEY_XH,KEY_XL;
u8 	KEY_YH,KEY_YL;

void USARTx_UserConfig(void)
{
	USART_InitTypeDef USART_InitStructure;
	
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //8位数据
	USART_InitStructure.USART_StopBits = USART_StopBits_1; //1个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No; //无奇偶
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //无硬件流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; //使能 接收|发送
	USART_InitStructure.USART_BaudRate = 115200;
	USART_Init(USART1, &USART_InitStructure);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); //使能 接收中断
	USART_ITConfig(USART1, USART_IT_TXE, DISABLE); //关闭 发送中断
	USART_Cmd(USART1, ENABLE); //使能USART外设
	
	/*
	USART_InitStructure.USART_BaudRate = 115200;
	USART_Init(USART3, &USART_InitStructure);
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE); //使能 接收中断
	USART_ITConfig(USART3, USART_IT_TXE, DISABLE); //关闭 发送中断
	USART_Cmd(USART3, ENABLE); //使能USART外设
	USART_InitStructure.USART_BaudRate = 115200;
	USART_Init(USART2, &USART_InitStructure);
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); //使能 接收中断
	USART_ITConfig(USART2, USART_IT_TXE, DISABLE); //关闭 发送中断
	USART_Cmd(USART2, ENABLE); //使能USART外设
	*/
}

void TX1_OUT_0(u8 data)
{
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	USART_SendData(USART1,data);
}



