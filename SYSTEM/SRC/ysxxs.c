#include "CPU_PIN.H"

void YS_XXus(u32 loop) //延时xx us 
{
	u8 i;
	do{
		for(i=0;i<14;i++);
	}while(--loop);
}

//----------------------
void YS_XXms(u32 loop) //延时多少MS
{
	u32 i;
	i=TimingDelay;
	do{
		if((TimingDelay-i)>=loop)
			break;
	}while(1); 
}
