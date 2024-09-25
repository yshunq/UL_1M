#include "CPU_PIN.H"

const unsigned char CHECK_FUN_KEY1 = 1;
const unsigned int  CHECK_FUN_XY1[]=
{
	 0,100,0,100,
};


void main_xs_check_fun(void)
{
	u8 key;
//	UL1Mhz_TypeDef UL1Mhz_Par;
//	UL1Mhz_Par.power = 100;
	
	DIS_PICNUM(Pic_CHECK_FUN);
	DIS_FONT_WEI_NUMBER_CM(Pic_CHECK_FUN,1,0xff,0xff,0x03,UL1Mhz_Par.power,5,0,0);
	UL1Mhz_Par.power = 5;
	DIS_FONT_WEI_NUMBER_CM(Pic_CHECK_FUN,1,0xff,0xff,0x03,UL1Mhz_Par.power,5,0,100);
	do{		
		YS_XXms(1);
		if(KEY_YES!=0x00){	
			ADS7843_KEY(); 
			key=KEY_FANHUI(CHECK_FUN_KEY1,CHECK_FUN_XY1); 
			switch(key){
				case  1://进入工作界面
							XIANG1();
							
							break;
				case  2://进入工作界面
							XIANG1(); 
							//INTERFACE = PAGE_PAOPAO_WORK;
							KEY_YES = 0;
							goto over_main_xs_check_fun;
							//break;
				case  3://进入设置
							break;
				default:
							break;
			}
		}
	}while(1);
	over_main_xs_check_fun:
	__NOP(); 
}


