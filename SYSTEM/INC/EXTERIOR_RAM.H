/*
  所有用到的全局变量  外部定义
*/
#ifndef  __EXTERIOR_RAM_H
#define  __EXTERIOR_RAM_H

#ifdef  VARIABLE_DEFINE
#define VAR_GLO
#else
#define VAR_GLO  extern
#endif

//typedef struct{
//	u8 power;
//}UL1Mhz_TypeDef;








//----------------------
VAR_GLO u32 TimingDelay;
//----------------------
VAR_GLO u8  INTERFACE;//跳转标志位
VAR_GLO u8 	LANGUAGE;//语言

//UL1Mhz_TypeDef UL1Mhz_Par;



#endif 
