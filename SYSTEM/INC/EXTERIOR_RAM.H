/*
  所有用到的全局变量  外部定义
*/
#ifndef  __EXTERIOR_RAM_H
#define  __EXTERIOR_RAM_H
//-----
#ifdef  VARIABLE_DEFINE
#define VAR_GLO
#else
#define VAR_GLO  extern
#endif
//----------------------
VAR_GLO u32 TimingDelay;
//----------------------
VAR_GLO u8  INTERFACE;//跳转标志位
VAR_GLO u8 	LANGUAGE;//语言



#endif 
