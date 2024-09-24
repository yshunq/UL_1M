#include "ads7843.h"

//-----扫描一个界面所有按键像素返回按键值-----//
u8 KEY_FANHUI(u8 GS,const unsigned int *ZB_ADD)
{
	u8 key=0x00;
 	u8 loop;
 	u16  add;
 	u16  xl,yl,xh,yh;
 	for(loop=0x00;loop<GS;loop++){
		add=loop*4;
	  xl=ZB_ADD[add];add++;
	  xh=ZB_ADD[add];add++;	 
	  yl=ZB_ADD[add];add++;	 
	  yh=ZB_ADD[add];
	  if(ADS7843_X>=xl&&ADS7843_X<=xh)
			if(ADS7843_Y>=yl&&ADS7843_Y<=yh){
				key=loop;
	   		key++;
	   		break;
	   }
	}return key;
}

void ADS7843_KEY(void) //扫描按键
{
	if(KEY_YES==0xff){
	  ADS7843_X = KEY_XH;
		ADS7843_X <<= 8;
		ADS7843_X |= KEY_XL;
		
		ADS7843_Y = KEY_YH;
		ADS7843_Y <<= 8;
		ADS7843_Y |= KEY_YL;
	} 
}


