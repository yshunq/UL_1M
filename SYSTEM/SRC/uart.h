#ifndef __UART_H
#define __UART_H
#include "CPU_PIN.H"

extern u8  	RX1_GS;
extern u8 	KEY_YES;
extern u16  ADS7843_X,ADS7843_Y;
extern u8 	KEY_XH,KEY_XL;
extern u8 	KEY_YH,KEY_YL;



void USARTx_UserConfig(void);
void TX1_OUT_0(u8 data);















#endif
