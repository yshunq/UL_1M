#ifndef __TIME_H
#define __TIME_H
#include "stm32f10x.h"

extern u32 TimingDelay;

//struct UL1Mhz_TypeDef{
//	u8 power;
//};

//extern struct UL1Mhz_TypeDef UL1Mhz_Par;

//void passStructToFunction(struct UL1Mhz_TypeDef *s);









void SysTick_Init(void);















#endif
