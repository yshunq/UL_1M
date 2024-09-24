//#include "CPU_PIN.H"



// void count_flow_gear(u16 data)
// {
//	  u16 i;
//	  i = 22*data/(4096/2);
//	  if(i < 2)i=2;
//	  else if(i > 22)i=22;
//	  if(i%2 == 0)FLOW_GEAR = i/2-1;
// }

// void temp_count_flow_gear(u16 data)
// {
//	  u16 i;
//	  i = 22*data/(4096/2);
//	  if(i < 2)i=2;
//	  else if(i > 22)i=22;
//	  FLOW_GEAR = i/2-1;
// }

//u8 count_kp_gear(u16 data)//KP值 计算 KP_GEAR
//{
//		u16 i;
//	  u8 j;
//		i = (MAX_KP_DATA - MIN_KP_DATA)/10;
//		j = 0;
//	  while(j <= 10)
//		{
//		    if(data <= (MIN_KP_DATA + (i*j)))
//				{
//						return j;
//				}
//				j++;
//				if(j >= 11)
//				{
//						return 10;
//				}
//		}
//		if(j >= 11)
//		{
//				return 10;
//		}
//		else
//		{
//				return j;
//		}
//}


//void count_flow_data(void)//KP值 计算 FLOW_SET_DATA
//{
//		FLOW_SET_DATA = (u32)FLOW_GEAR*(FLOW_MAX_DATA - FLOW_MIN_DATA)/10 + FLOW_MIN_DATA;
//}


















//void count_face_work_power_gear(void)//计算能量值
//{
//		//tim1DeadTime(FACE_GEAR_DATA[POWER_GEAR]);
//		u16 data;
//		data = POWER_GEAR;
//		if(WORK_PARAMETERS == 0)
//		{
//			data = data*(MIN_GEAR_DATA_HEADLE1 - MAX_GEAR_DATA_HEADLE1)/10;
//			data = MIN_GEAR_DATA_HEADLE1 - data;
//		}
//		else
//		{
//			data = data*(MIN_GEAR_DATA_HEADLE2 - MAX_GEAR_DATA_HEADLE2)/10;
//			data = MIN_GEAR_DATA_HEADLE2 - data;
//		}
//		tim1DeadTime(data);
//}

//void count_body_work_power_gear(void)//计算能量值
//{
//		u16 data;
//		data = POWER_GEAR;
//		data = data*(MIN_GEAR_DATA_HEADLE3 - MAX_GEAR_DATA_HEADLE3)/9;
//		data = MIN_GEAR_DATA_HEADLE3 - data;
//		tim1DeadTime(data);
//		//tim1DeadTime(BODY_GEAR_DATA[POWER_GEAR]);
//}

//void read_face_work_power_gear(void)
//{
//		u16 data;
//		if(WORK_PARAMETERS == 0)
//		{
//				data = AD_FACE_POWER_GEAR1;
//		}
//		else
//		{
//				data = AD_FACE_POWER_GEAR2;
//		}
//		POWER_GEAR = AT24CXX_ReadOneByte(data);
//		if(POWER_GEAR > 10)
//		{
//				POWER_GEAR = 0;
//				write_face_work_power_gear();
//		}
//}

//void write_face_work_power_gear(void)
//{
//		u16 data;
//		if(WORK_PARAMETERS == 0)
//		{
//				data = AD_FACE_POWER_GEAR1;
//		}
//		else
//		{
//				data = AD_FACE_POWER_GEAR2;
//		}
//		AT24CXX_WriteOneByte(data,POWER_GEAR);
//}

//void read_body_work_power_gear(void)
//{
//		POWER_GEAR = AT24CXX_ReadOneByte(AD_BODY_POWER_GEAR);
//		if(POWER_GEAR > 10)
//		{
//				POWER_GEAR = 0;
//				write_body_work_power_gear();
//		}
//}

//void write_body_work_power_gear(void)
//{
//		AT24CXX_WriteOneByte(AD_BODY_POWER_GEAR,POWER_GEAR);
//}




//void read_min_gear_data_headle1(void)
//{
//		MIN_GEAR_DATA_HEADLE1 = AT24CXX_ReadOneByte(AD_MIN_GEAR_DATA_HEADLE1);
//}

//void write_min_gear_data_headle1(void)
//{
//		AT24CXX_WriteOneByte(AD_MIN_GEAR_DATA_HEADLE1,MIN_GEAR_DATA_HEADLE1);
//}

//void read_max_gear_data_headle1(void)
//{
//		MAX_GEAR_DATA_HEADLE1 = AT24CXX_ReadOneByte(AD_MAX_GEAR_DATA_HEADLE1);
//}

//void write_max_gear_data_headle1(void)
//{
//		AT24CXX_WriteOneByte(AD_MAX_GEAR_DATA_HEADLE1,MAX_GEAR_DATA_HEADLE1);
//}






//void read_min_gear_data_headle2(void)
//{
//		MIN_GEAR_DATA_HEADLE2 = AT24CXX_ReadOneByte(AD_MIN_GEAR_DATA_HEADLE2);
//}

//void write_min_gear_data_headle2(void)
//{
//		AT24CXX_WriteOneByte(AD_MIN_GEAR_DATA_HEADLE2,MIN_GEAR_DATA_HEADLE2);
//}

//void read_max_gear_data_headle2(void)
//{
//		MAX_GEAR_DATA_HEADLE2 = AT24CXX_ReadOneByte(AD_MAX_GEAR_DATA_HEADLE2);
//}

//void write_max_gear_data_headle2(void)
//{
//		AT24CXX_WriteOneByte(AD_MAX_GEAR_DATA_HEADLE2,MAX_GEAR_DATA_HEADLE2);
//}




//void read_min_gear_data_headle3(void)
//{
//		MIN_GEAR_DATA_HEADLE3 = AT24CXX_ReadOneByte(AD_MIN_GEAR_DATA_HEADLE3);
//}

//void write_min_gear_data_headle3(void)
//{
//		AT24CXX_WriteOneByte(AD_MIN_GEAR_DATA_HEADLE3,MIN_GEAR_DATA_HEADLE3);
//}

//void read_max_gear_data_headle3(void)
//{
//		MAX_GEAR_DATA_HEADLE3 = AT24CXX_ReadOneByte(AD_MAX_GEAR_DATA_HEADLE3);
//}

//void write_max_gear_data_headle3(void)
//{
//		AT24CXX_WriteOneByte(AD_MAX_GEAR_DATA_HEADLE3,MAX_GEAR_DATA_HEADLE3);
//}




///*
//void read_body_gear_data0(void)
//{
//		BODY_GEAR_DATA[0] = AT24CXX_ReadOneByte(AD_BODY_GEAR_DATA0);
//}

//void write_body_gear_data0(void)
//{
//		AT24CXX_WriteOneByte(AD_BODY_GEAR_DATA0,BODY_GEAR_DATA[0]);
//}

//void read_body_gear_data1(void)
//{
//		BODY_GEAR_DATA[1] = AT24CXX_ReadOneByte(AD_BODY_GEAR_DATA1);
//}

//void write_body_gear_data1(void)
//{
//		AT24CXX_WriteOneByte(AD_BODY_GEAR_DATA1,BODY_GEAR_DATA[1]);
//}

//void read_body_gear_data2(void)
//{
//		BODY_GEAR_DATA[2] = AT24CXX_ReadOneByte(AD_BODY_GEAR_DATA2);
//}

//void write_body_gear_data2(void)
//{
//		AT24CXX_WriteOneByte(AD_BODY_GEAR_DATA2,BODY_GEAR_DATA[2]);
//}

//void read_body_gear_data3(void)
//{
//		BODY_GEAR_DATA[3] = AT24CXX_ReadOneByte(AD_BODY_GEAR_DATA3);
//}

//void write_body_gear_data3(void)
//{
//		AT24CXX_WriteOneByte(AD_BODY_GEAR_DATA3,BODY_GEAR_DATA[3]);
//}

//void read_body_gear_data4(void)
//{
//		BODY_GEAR_DATA[4] = AT24CXX_ReadOneByte(AD_BODY_GEAR_DATA4);
//}

//void write_body_gear_data4(void)
//{
//		AT24CXX_WriteOneByte(AD_BODY_GEAR_DATA4,BODY_GEAR_DATA[4]);
//}

//void read_body_gear_data5(void)
//{
//		BODY_GEAR_DATA[5] = AT24CXX_ReadOneByte(AD_BODY_GEAR_DATA5);
//}

//void write_body_gear_data5(void)
//{
//		AT24CXX_WriteOneByte(AD_BODY_GEAR_DATA5,BODY_GEAR_DATA[5]);
//}

//void read_body_gear_data6(void)
//{
//		BODY_GEAR_DATA[6] = AT24CXX_ReadOneByte(AD_BODY_GEAR_DATA6);
//}

//void write_body_gear_data6(void)
//{
//		AT24CXX_WriteOneByte(AD_BODY_GEAR_DATA6,BODY_GEAR_DATA[6]);
//}

//void read_body_gear_data7(void)
//{
//		BODY_GEAR_DATA[7] = AT24CXX_ReadOneByte(AD_BODY_GEAR_DATA7);
//}

//void write_body_gear_data7(void)
//{
//		AT24CXX_WriteOneByte(AD_BODY_GEAR_DATA7,BODY_GEAR_DATA[7]);
//}

//void read_body_gear_data8(void)
//{
//		BODY_GEAR_DATA[8] = AT24CXX_ReadOneByte(AD_BODY_GEAR_DATA8);
//}

//void write_body_gear_data8(void)
//{
//		AT24CXX_WriteOneByte(AD_BODY_GEAR_DATA8,BODY_GEAR_DATA[8]);
//}

//void read_body_gear_data9(void)
//{
//		BODY_GEAR_DATA[9] = AT24CXX_ReadOneByte(AD_BODY_GEAR_DATA9);
//}

//void write_body_gear_data9(void)
//{
//		AT24CXX_WriteOneByte(AD_BODY_GEAR_DATA9,BODY_GEAR_DATA[9]);
//}

//void read_face_gear_data0(void)
//{
//		FACE_GEAR_DATA[0] = AT24CXX_ReadOneByte(AD_FACE_GEAR_DATA0);
//}

//void write_face_gear_data0(void)
//{
//		AT24CXX_WriteOneByte(AD_FACE_GEAR_DATA0,FACE_GEAR_DATA[0]);
//}

//void read_face_gear_data1(void)
//{
//		FACE_GEAR_DATA[1] = AT24CXX_ReadOneByte(AD_FACE_GEAR_DATA1);
//}

//void write_face_gear_data1(void)
//{
//		AT24CXX_WriteOneByte(AD_FACE_GEAR_DATA1,FACE_GEAR_DATA[1]);
//}

//void read_face_gear_data2(void)
//{
//		FACE_GEAR_DATA[2] = AT24CXX_ReadOneByte(AD_FACE_GEAR_DATA2);
//}

//void write_face_gear_data2(void)
//{
//		AT24CXX_WriteOneByte(AD_FACE_GEAR_DATA2,FACE_GEAR_DATA[2]);
//}

//void read_face_gear_data3(void)
//{
//		FACE_GEAR_DATA[3] = AT24CXX_ReadOneByte(AD_FACE_GEAR_DATA3);
//}

//void write_face_gear_data3(void)
//{
//		AT24CXX_WriteOneByte(AD_FACE_GEAR_DATA3,FACE_GEAR_DATA[3]);
//}
//*/
















