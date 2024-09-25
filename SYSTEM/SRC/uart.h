#ifndef __UART_H
#define __UART_H
#include "stm32f10x.h"

struct Uart_TypeDef{
	u8 RX_GS;
	u8 KEY_YES;
	u16 ADS7843_X;
	u16 ADS7843_Y;
	u8 KEY_XH;
	u8 KEY_XL;
	u8 KEY_YH;
	u8 KEY_YL;
};
extern struct Uart_TypeDef Uart_LCD;


void USARTx_UserConfig(void);
void TX1_OUT_0(u8 data);




#endif
