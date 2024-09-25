#include "ads7843.h"

//-----ɨ��һ���������а������ط��ذ���ֵ-----//
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
	  if(Uart_LCD.ADS7843_X>=xl&&Uart_LCD.ADS7843_X<=xh)
			if(Uart_LCD.ADS7843_Y>=yl&&Uart_LCD.ADS7843_Y<=yh){
				key=loop;
	   		key++;
	   		break;
	   }
	}return key;
}

void ADS7843_KEY(void) //ɨ�谴��
{
	if(Uart_LCD.KEY_YES==0xff){
	  Uart_LCD.ADS7843_X = Uart_LCD.KEY_XH;
		Uart_LCD.ADS7843_X <<= 8;
		Uart_LCD.ADS7843_X |= Uart_LCD.KEY_XL;
		
		Uart_LCD.ADS7843_Y = Uart_LCD.KEY_YH;
		Uart_LCD.ADS7843_Y <<= 8;
		Uart_LCD.ADS7843_Y |= Uart_LCD.KEY_YL;
	} 
}


