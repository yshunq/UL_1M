#include "CPU_PIN.H"

const unsigned char MAIN_KEY_ADIN1 = 14;
const unsigned int 	MAIN_ADIN1[]=
{
	 700, 783,479,563,
	 807, 890,479,563,
	 914, 997,479,563,
	1021,1104,479,563,
	1128,1211,479,563,
	
	 700, 783,598,682,
	 807, 890,598,682,
	 914, 997,598,682,
	1021,1104,598,682,
	1128,1211,598,682,

	 778,1072,350,436,
	 803, 923,710,779,
	1086,1118,377,409,
	 995,1115,710,779,
};

void dis_adv_password(u8 wei);
u8 comparison_password(u8 wei,u8 *buf);

void main_xs_advanced_settings(void)
{
	u8 key,wei,adv_psw[6];
	DIS_PICNUM(Pic_ADVANCED_SETTINGS);
	adv_psw[0] = 0;
	adv_psw[1] = 0;
	adv_psw[2] = 0;
	adv_psw[3] = 0;
	adv_psw[4] = 0;
	adv_psw[5] = 0;
	wei = 0;
	
	DIS_FONT_C(0xff,0xff,4,0x05,100,220,"V1.0");
	
	do{
		YS_XXms(1);
		if(KEY_YES!=0x00){
			ADS7843_KEY();
		  key=KEY_FANHUI(MAIN_KEY_ADIN1,MAIN_ADIN1); 
	 	  switch(key){
				case  1:if(wei < 6){XIANG1();adv_psw[wei] = 1;wei++;dis_adv_password(wei);}break;
        case  2:if(wei < 6){XIANG1();adv_psw[wei] = 2;wei++;dis_adv_password(wei);}break;
        case  3:if(wei < 6){XIANG1();adv_psw[wei] = 3;wei++;dis_adv_password(wei);}break;
				case  4:if(wei < 6){XIANG1();adv_psw[wei] = 4;wei++;dis_adv_password(wei);}break;
				case  5:if(wei < 6){XIANG1();adv_psw[wei] = 5;wei++;dis_adv_password(wei);}break;
				case  6:if(wei < 6){XIANG1();adv_psw[wei] = 6;wei++;dis_adv_password(wei);}break;
				case  7:if(wei < 6){XIANG1();adv_psw[wei] = 7;wei++;dis_adv_password(wei);}break;
				case  8:if(wei < 6){XIANG1();adv_psw[wei] = 8;wei++;dis_adv_password(wei);}break;
				case  9:if(wei < 6){XIANG1();adv_psw[wei] = 9;wei++;dis_adv_password(wei);}break;
				case 10:if(wei < 6){XIANG1();adv_psw[wei] = 0;wei++;dis_adv_password(wei);}break;
				case 11:
					XIANG1();
					adv_psw[0] = 0;
	   			adv_psw[1] = 0;
	   			adv_psw[2] = 0;
	   			adv_psw[3] = 0;
	   			adv_psw[4] = 0;
	   			adv_psw[5] = 0;
	   			wei = 0;
					dis_adv_password(wei);
					break;
				case 12:
					XIANG1();
					//INTERFACE = PAGE_LOADING;
					goto over_main_xs_advanced_settings;
				case 13:
					XIANG1();
					adv_psw[wei] = 0;
					if(wei > 0)wei--;
					dis_adv_password(wei);
					break;
				case 14:
					XIANG1();
					comparison_password(wei,adv_psw);
					goto over_main_xs_advanced_settings;
			}
			KEY_YES = 0;
		}
	}while(1);
	over_main_xs_advanced_settings:
	__NOP(); 
}

void dis_adv_password(u8 wei)
{
  u16 x,y;
	u8 add,i;
	x = 990;
	y = 370;
	add = 25;
	DIS_DEL_DIS(Pic_ADVANCED_SETTINGS,778,350,1072,436,778,350);
	
	if(wei > 0 && wei <= 6){
		for(i=0;i<wei;i++){
			DIS_FONT_C(0xff,0xff,1,0x05,x,y,"*");
			x -= add;
		}
	}
}


u8 comparison_password(u8 wei,u8 *buf)
{
	if(wei == 6){
		if(buf[0] == 1 && buf[1] == 7 && buf[2] == 1 && buf[3] == 2 && buf[4] == 1 && buf[5] == 2){
		  	return 0; 
		}
		buf[0] = 0;
		buf[1] = 0;
		buf[2] = 0;
		buf[3] = 0;
		buf[4] = 0;
		buf[5] = 0;
		wei = 0;
		dis_adv_password(wei);
  }else{
		buf[0] = 0;
	  buf[1] = 0;
	  buf[2] = 0;
	  buf[3] = 0;
	  buf[4] = 0;
	  buf[5] = 0;
	  wei = 0;
	  dis_adv_password(wei);
  }
	return 1; 
}







 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

