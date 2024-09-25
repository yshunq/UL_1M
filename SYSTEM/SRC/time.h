#ifndef __TIME_H
#define __TIME_H
#include "CPU_PIN.H"

struct UL1Mhz_TypeDef{
	u8 power;
};

extern struct UL1Mhz_TypeDef UL1Mhz_Par;

void passStructToFunction(struct UL1Mhz_TypeDef *s);









void SysTick_Init(void);















#endif
