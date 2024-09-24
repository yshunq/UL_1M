//#include "CPU_PIN.H"

//void dis_face_work_start_stop_flag(void)
//{
//		if(START_STOP_FLAG == 0)
//		{
//			DIS_DEL_DIS(Pic_FACE_WORK_DOWN,203,415,271,465,203,415);
//		}
//		else
//		{
//			DIS_DEL_DIS(Pic_FACE_WORK,203,415,271,465,203,415);
//		}
//}

//void dis_work_xian_time(u8 data)
//{
//	u16 x,y;
//	u32 temp;
////	static u8 temp_hours = 0;
//	static u8 temp_minutes = 0;
//	static u8 temp_seconds = 0;
//	x = 35;
//	y = 115;
//	if(data == 0)
//	{
//		DIS_DEL_DIS(Pic_FACE_WORK,x,y,x+60,y+24,x,y);
//		//DIS_FONT_NUMBER_C(0xff,0xff,XIAN_HOURS/10,0x02,x,y);//显示字符  颜色  字符  大小  xy轴坐标
//		//DIS_FONT_NUMBER_C(0xff,0xff,XIAN_HOURS%10,0x02,x+12,y);//显示字符  颜色  字符  大小  xy轴坐标
//		//DIS_FONT_C(0xff,0xff,1,0x02,x+24,y,":");
//		DIS_FONT_NUMBER_C(0xff,0xff,XIAN_MINUTES/10,0x02,x,y);//显示字符  颜色  字符  大小  xy轴坐标
//		DIS_FONT_NUMBER_C(0xff,0xff,XIAN_MINUTES%10,0x02,x+12,y);//显示字符  颜色  字符  大小  xy轴坐标
//		DIS_FONT_C(0xff,0xff,1,0x02,x+24,y,":");
//		DIS_FONT_NUMBER_C(0xff,0xff,XIAN_SECONDS/10,0x02,x+36,y);//显示字符  颜色  字符  大小  xy轴坐标
//		DIS_FONT_NUMBER_C(0xff,0xff,XIAN_SECONDS%10,0x02,x+48,y);//显示字符  颜色  字符  大小  xy轴坐标
//	}
//	else
//	{
//		/*
//		if(temp_hours/10 != XIAN_HOURS/10)
//		{
//			DIS_DEL_DIS(Pic_FACE_WORK,x,y,x+12,y+24,x,y);
//			DIS_FONT_NUMBER_C(0xff,0xff,XIAN_HOURS/10,0x02,x,y);//显示字符  颜色  字符  大小  xy轴坐标
//		}
//		if(temp_hours%10 != XIAN_HOURS%10)
//		{
//			DIS_DEL_DIS(Pic_FACE_WORK,x+12,y,x+24,y+24,x+12,y);
//			DIS_FONT_NUMBER_C(0xff,0xff,XIAN_HOURS%10,0x02,x+12,y);//显示字符  颜色  字符  大小  xy轴坐标
//		}
//		*/
//		if(temp_minutes/10 != XIAN_MINUTES/10)
//		{
//			DIS_DEL_DIS(Pic_FACE_WORK,x,y,x+12,y+24,x,y);
//			DIS_FONT_NUMBER_C(0xff,0xff,XIAN_MINUTES/10,0x02,x,y);//显示字符  颜色  字符  大小  xy轴坐标
//		}
//		if(temp_minutes%10 != XIAN_MINUTES%10)
//		{
//			DIS_DEL_DIS(Pic_FACE_WORK,x+12,y,x+24,y+24,x+12,y);
//			DIS_FONT_NUMBER_C(0xff,0xff,XIAN_MINUTES%10,0x02,x+12,y);//显示字符  颜色  字符  大小  xy轴坐标
//		}
//		
//		if(temp_seconds/10 != XIAN_SECONDS/10)
//		{
//			DIS_DEL_DIS(Pic_FACE_WORK,x+36,y,x+48,y+24,x+36,y);
//			DIS_FONT_NUMBER_C(0xff,0xff,XIAN_SECONDS/10,0x02,x+36,y);//显示字符  颜色  字符  大小  xy轴坐标
//		}
//		if(temp_seconds%10 != XIAN_SECONDS%10)
//		{
//			DIS_DEL_DIS(Pic_FACE_WORK,x+48,y,x+60,y+24,x+48,y);
//			DIS_FONT_NUMBER_C(0xff,0xff,XIAN_SECONDS%10,0x02,x+48,y);//显示字符  颜色  字符  大小  xy轴坐标
//		}
//	}
////	temp_hours = XIAN_HOURS;
//	temp_minutes = XIAN_MINUTES;
//	temp_seconds = XIAN_SECONDS;
//	
//	temp = 3600*XIAN_HOURS + (60*XIAN_MINUTES) + XIAN_SECONDS;
//	if(temp > 0)
//	{
//			temp = (17-2)*(temp-1)/(1500-1)+2;
//			if(temp > 16)temp=16;
//	}
//	else
//	{
//			temp = 1;
//	}
//	
//	switch(temp)
//  {
//		case   1:DIS_DEL_DIS(Pic_CUT_TIME4,0,330,199,438,36,7);break;//1
//		case   2:DIS_DEL_DIS(Pic_CUT_TIME4,0,220,199,328,36,7);break;//2
//		case   3:DIS_DEL_DIS(Pic_CUT_TIME4,0,110,199,218,36,7);break;//3
//		case   4:DIS_DEL_DIS(Pic_CUT_TIME4,0,  0,199,108,36,7);break;//4
//		
//		case   5:DIS_DEL_DIS(Pic_CUT_TIME3,0,330,199,438,36,7);break;//5
//		case   6:DIS_DEL_DIS(Pic_CUT_TIME3,0,220,199,328,36,7);break;//6
//		case   7:DIS_DEL_DIS(Pic_CUT_TIME3,0,110,199,218,36,7);break;//7
//		case   8:DIS_DEL_DIS(Pic_CUT_TIME3,0,  0,199,108,36,7);break;//8
//		
//		case   9:DIS_DEL_DIS(Pic_CUT_TIME2,0,330,199,438,36,7);break;//9
//		case  10:DIS_DEL_DIS(Pic_CUT_TIME2,0,220,199,328,36,7);break;//10
//		case  11:DIS_DEL_DIS(Pic_CUT_TIME2,0,110,199,218,36,7);break;//11
//		case  12:DIS_DEL_DIS(Pic_CUT_TIME2,0,  0,199,108,36,7);break;//12
//		
//		case  13:DIS_DEL_DIS(Pic_CUT_TIME1,0,330,199,438,36,7);break;//13
//		case  14:DIS_DEL_DIS(Pic_CUT_TIME1,0,220,199,328,36,7);break;//14
//		case  15:DIS_DEL_DIS(Pic_CUT_TIME1,0,110,199,218,36,7);break;//15
//		case  16:DIS_DEL_DIS(Pic_CUT_TIME1,0,  0,199,108,36,7);break;//16
//	}
//}

//void dis_body_work_ic_card_time(u8 data)
//{
//	DIS_FONT_WEI_NUMBER_CM(Pic_FACE_WORK,1,0xff,0xff,0x02,MASTER_DATA,3,185,115);
//	
//	/*u16 x,y;
//	static u8 temp_hours = 0;
//	static u8 temp_minutes = 0;
//	static u8 temp_seconds = 0;
//	x = 160;
//	y = 115;
//	if(data == 0)
//	{
//		DIS_DEL_DIS(Pic_FACE_WORK,x,y,x+96,y+24,x,y);
//		DIS_FONT_NUMBER_C(0xff,0xff,IC_CARD_HOURS/10,0x02,x,y);//显示字符  颜色  字符  大小  xy轴坐标
//		DIS_FONT_NUMBER_C(0xff,0xff,IC_CARD_HOURS%10,0x02,x+12,y);//显示字符  颜色  字符  大小  xy轴坐标
//		DIS_FONT_C(0xff,0xff,1,0x02,x+24,y,":");
//		DIS_FONT_NUMBER_C(0xff,0xff,IC_CARD_MINUTES/10,0x02,x+36,y);//显示字符  颜色  字符  大小  xy轴坐标
//		DIS_FONT_NUMBER_C(0xff,0xff,IC_CARD_MINUTES%10,0x02,x+48,y);//显示字符  颜色  字符  大小  xy轴坐标
//		DIS_FONT_C(0xff,0xff,1,0x02,x+60,y,":");
//		DIS_FONT_NUMBER_C(0xff,0xff,IC_CARD_SECONDS/10,0x02,x+72,y);//显示字符  颜色  字符  大小  xy轴坐标
//		DIS_FONT_NUMBER_C(0xff,0xff,IC_CARD_SECONDS%10,0x02,x+84,y);//显示字符  颜色  字符  大小  xy轴坐标
//	}
//	else
//	{
//		if(temp_hours/10 != IC_CARD_HOURS/10)
//		{
//			DIS_DEL_DIS(Pic_FACE_WORK,x,y,x+12,y+24,x,y);
//			DIS_FONT_NUMBER_C(0xff,0xff,IC_CARD_HOURS/10,0x02,x,y);//显示字符  颜色  字符  大小  xy轴坐标
//		}
//		if(temp_hours%10 != IC_CARD_HOURS%10)
//		{
//			DIS_DEL_DIS(Pic_FACE_WORK,x+12,y,x+24,y+24,x+12,y);
//			DIS_FONT_NUMBER_C(0xff,0xff,IC_CARD_HOURS%10,0x02,x+12,y);//显示字符  颜色  字符  大小  xy轴坐标
//		}
//		
//		if(temp_minutes/10 != IC_CARD_MINUTES/10)
//		{
//			DIS_DEL_DIS(Pic_FACE_WORK,x+36,y,x+48,y+24,x+36,y);
//			DIS_FONT_NUMBER_C(0xff,0xff,IC_CARD_MINUTES/10,0x02,x+36,y);//显示字符  颜色  字符  大小  xy轴坐标
//		}
//		if(temp_minutes%10 != IC_CARD_MINUTES%10)
//		{
//			DIS_DEL_DIS(Pic_FACE_WORK,x+48,y,x+60,y+24,x+48,y);
//			DIS_FONT_NUMBER_C(0xff,0xff,IC_CARD_MINUTES%10,0x02,x+48,y);//显示字符  颜色  字符  大小  xy轴坐标
//		}
//		
//		if(temp_seconds/10 != IC_CARD_SECONDS/10)
//		{
//			DIS_DEL_DIS(Pic_FACE_WORK,x+72,y,x+84,y+24,x+72,y);
//			DIS_FONT_NUMBER_C(0xff,0xff,IC_CARD_SECONDS/10,0x02,x+72,y);//显示字符  颜色  字符  大小  xy轴坐标
//		}
//		if(temp_seconds%10 != IC_CARD_SECONDS%10)
//		{
//			DIS_DEL_DIS(Pic_FACE_WORK,x+84,y,x+96,y+24,x+84,y);
//			DIS_FONT_NUMBER_C(0xff,0xff,IC_CARD_SECONDS%10,0x02,x+84,y);//显示字符  颜色  字符  大小  xy轴坐标
//		}
//	}
//	temp_hours = IC_CARD_HOURS;
//	temp_minutes = IC_CARD_MINUTES;
//	temp_seconds = IC_CARD_SECONDS;
//	*/
//}











//void dis_work_kp_gear(void)
//{
//     u16 x,y;
//		 x = 61;
//		 y = 149;
//		 switch(KP_GEAR)
//  	 {
//          case  0:DIS_DEL_DIS(Pic_FACE_WORK, 61,149,213,301, x,y);break;//0
//					case  1:DIS_DEL_DIS(Pic_CUT_KP_GEAR1,  0,  0,152,152, x,y);break;//1
//					case  2:DIS_DEL_DIS(Pic_CUT_KP_GEAR1,  0,154,152,306, x,y);break;//2
//					case  3:DIS_DEL_DIS(Pic_CUT_KP_GEAR1,  0,308,152,460, x,y);break;//3
//					case  4:DIS_DEL_DIS(Pic_CUT_KP_GEAR2,  0,  0,152,152, x,y);break;//4
//					case  5:DIS_DEL_DIS(Pic_CUT_KP_GEAR2,  0,154,152,306, x,y);break;//5
//					case  6:DIS_DEL_DIS(Pic_CUT_KP_GEAR2,  0,308,152,460, x,y);break;//6
//					case  7:DIS_DEL_DIS(Pic_CUT_KP_GEAR3,  0,  0,152,152, x,y);break;//7
//					case  8:DIS_DEL_DIS(Pic_CUT_KP_GEAR3,  0,154,152,306, x,y);break;//8
//					case  9:DIS_DEL_DIS(Pic_CUT_KP_GEAR3,  0,308,152,460, x,y);break;//9
//					case 10:DIS_DEL_DIS(Pic_CUT_KP_GEAR4,  0,  0,152,152, x,y);break;//:
//  	}
//}

//void dis_work_flow_gear(void)
//{
//     u16 x,y;
//		 x = 61;
//		 y = 306;
//		 switch(FLOW_GEAR)
//  	 {
//          case  0:DIS_DEL_DIS(Pic_FACE_WORK, 61,306,213,458, x,y);break;//0
//					case  1:DIS_DEL_DIS(Pic_CUT_FLOW_GEAR1,  0,  0,152,152, x,y);break;//1
//					case  2:DIS_DEL_DIS(Pic_CUT_FLOW_GEAR1,  0,154,152,306, x,y);break;//2
//					case  3:DIS_DEL_DIS(Pic_CUT_FLOW_GEAR1,  0,308,152,460, x,y);break;//3
//					case  4:DIS_DEL_DIS(Pic_CUT_FLOW_GEAR2,  0,  0,152,152, x,y);break;//4
//					case  5:DIS_DEL_DIS(Pic_CUT_FLOW_GEAR2,  0,154,152,306, x,y);break;//5
//					case  6:DIS_DEL_DIS(Pic_CUT_FLOW_GEAR2,  0,308,152,460, x,y);break;//6
//					case  7:DIS_DEL_DIS(Pic_CUT_FLOW_GEAR3,  0,  0,152,152, x,y);break;//7
//					case  8:DIS_DEL_DIS(Pic_CUT_FLOW_GEAR3,  0,154,152,306, x,y);break;//8
//					case  9:DIS_DEL_DIS(Pic_CUT_FLOW_GEAR3,  0,308,152,460, x,y);break;//9
//					case 10:DIS_DEL_DIS(Pic_CUT_FLOW_GEAR4,  0,  0,152,152, x,y);break;//:
//  	}
//}






















//void dis_face_work_parameters(void)
//{
//		if(WORK_PARAMETERS == 0)
//		{
//				DIS_DEL_DIS(Pic_FACE_WORK,388,268,752,341,388,268);
//				DIS_DEL_DIS(Pic_FACE_WORK_DOWN,388,189,752,261,388,189);
//		}
//	  else
//		{
//				DIS_DEL_DIS(Pic_FACE_WORK,388,189,752,261,388,189);
//				DIS_DEL_DIS(Pic_FACE_WORK_DOWN,388,268,752,341,388,268);
//		}
//}


///*
//void dis_time_number(u8 data,u16 x,u16 y)
//{
//     switch(data)
//  	 {
//          case  0:DIS_DEL_DIS(Pic_CUT_POWER1,  0,274, 12,292, x,y);break; //0   //XH YH XL YLX
//					case  1:DIS_DEL_DIS(Pic_CUT_POWER1, 14,274, 26,292, x,y);break;//1
//					case  2:DIS_DEL_DIS(Pic_CUT_POWER1, 28,274, 40,292, x,y);break;//2
//					case  3:DIS_DEL_DIS(Pic_CUT_POWER1, 42,274, 54,292, x,y);break;//3
//					case  4:DIS_DEL_DIS(Pic_CUT_POWER1, 56,274, 68,292, x,y);break;//4
//					case  5:DIS_DEL_DIS(Pic_CUT_POWER1, 70,274, 82,292, x,y);break;//5
//					case  6:DIS_DEL_DIS(Pic_CUT_POWER1, 84,274, 96,292, x,y);break;//6
//					case  7:DIS_DEL_DIS(Pic_CUT_POWER1, 98,274,110,292, x,y);break;//7
//					case  8:DIS_DEL_DIS(Pic_CUT_POWER1,112,274,124,292, x,y);break;//8
//					case  9:DIS_DEL_DIS(Pic_CUT_POWER1,126,274,138,292, x,y);break;//9
//					case 10:DIS_DEL_DIS(Pic_CUT_POWER1,140,274,150,292, x,y);break;//:
//  	}
//}







//void dis_body_work_start_stop_flag(void)
//{
//		if(START_STOP_FLAG == 0)
//		{
//			DIS_DEL_DIS(Pic_BODY_WORK_DOWN,408,411,799,479,408,411);
//		}
//		else
//		{
//			DIS_DEL_DIS(Pic_BODY_WORK,408,411,799,479,408,411);
//		}
//}

//void dis_work_power_gear(void)
//{
//		u8 pic;
//		if(BODY_FACE_FLAG == 0)//身体
//		{
//				pic = Pic_CUT_BODY_POWER1;
//		}
//		else//眼部
//		{
//				pic = Pic_CUT_POWER1;
//		}
//		switch(POWER_GEAR)
//		{
//				case  0:
//						DIS_DEL_DIS(pic,0,0,249,272,54,94);
//						break;
//				case  1:
//						DIS_DEL_DIS(pic,251,0,500,272,54,94);
//						break;
//				case  2:
//						DIS_DEL_DIS(pic,502,0,751,272,54,94);
//						break;
//				case  3:
//						DIS_DEL_DIS(pic+1,0,0,249,272,54,94);
//						break;
//				case  4:
//						DIS_DEL_DIS(pic+1,251,0,500,272,54,94);
//						break;
//				case  5:
//						DIS_DEL_DIS(pic+1,502,0,751,272,54,94);
//						break;
//				case  6:
//						DIS_DEL_DIS(pic+2,0,0,249,272,54,94);
//						break;
//				case  7:
//						DIS_DEL_DIS(pic+2,251,0,500,272,54,94);
//						break;
//				case  8:
//						DIS_DEL_DIS(pic+2,502,0,751,272,54,94);
//						break;
//				case  9:
//						DIS_DEL_DIS(pic+3,0,0,249,272,54,94);
//						break;
//				case  10:
//						DIS_DEL_DIS(pic+3,251,0,500,272,54,94);
//						break;
//		}
//}


//void dis_single_used_time(u8 data)
//{
//	u16 x,y;
//	static u8 temp_hours = 0;
//	static u8 temp_minutes = 0;
//	static u8 temp_seconds = 0;
//	x = 524;
//	y = 150;
//	if(data == 0)
//	{
//		dis_time_number(SINGLE_HOURS/10,x,y);
//		dis_time_number(SINGLE_HOURS%10,x+13,y);
//		dis_time_number(10,x+26,y);
//		dis_time_number(SINGLE_MINUTES/10,x+37,y);
//		dis_time_number(SINGLE_MINUTES%10,x+50,y);
//		dis_time_number(10,x+63,y);
//		dis_time_number(SINGLE_SECONDS/10,x+74,y);
//		dis_time_number(SINGLE_SECONDS%10,x+87,y);
//	}
//	else
//	{
//		if(temp_hours/10 != SINGLE_HOURS/10)
//		{
//			dis_time_number(SINGLE_HOURS/10,x,y);
//		}
//		if(temp_hours%10 != SINGLE_HOURS%10)
//		{
//			dis_time_number(SINGLE_HOURS%10,x+13,y);
//		}
//		
//		if(temp_minutes/10 != SINGLE_MINUTES/10)
//		{
//			dis_time_number(SINGLE_MINUTES/10,x+37,y);
//		}
//		if(temp_minutes%10 != SINGLE_MINUTES%10)
//		{
//			dis_time_number(SINGLE_MINUTES%10,x+50,y);
//		}
//		
//		if(temp_seconds/10 != SINGLE_SECONDS/10)
//		{
//			dis_time_number(SINGLE_SECONDS/10,x+74,y);
//		}
//		if(temp_seconds%10 != SINGLE_SECONDS%10)
//		{
//			dis_time_number(SINGLE_SECONDS%10,x+87,y);
//		}
//	}
//	temp_hours = SINGLE_HOURS;
//	temp_minutes = SINGLE_MINUTES;
//	temp_seconds = SINGLE_SECONDS;
//}

//*/














