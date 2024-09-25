/*
  所有子程序声明 
*/
void jump_interface(void);



//typedef void (*CallbackFunction)(UL1Mhz_TypeDef*);







//----------------------
void RCC_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);

void SysTick_UserConfig(void);
void RTC_Configuration(void); //配置RTC
void Timx_UserConfig(void);

void main_xs_advanced_settings(void);
void main_xs_check_fun(void);

//void USARTx_UserConfig(void);
//void TX1_OUT_0(u8 data);
//void TX1_OUT_2(u8 commd,u8 data);
//void TX1_OUT_2_WAIT(u8 commd,u8 data);
//void TX1_OUT_3_WAIT(u8 commd,u8 data1,u8 data2);
//void TX1_OUT_2_WAIT_ADD(u8 commd,u16 data,u16 YsTime);

void TX3_OUT_0(u8 data);
void TX2_OUT_0(u8 data);

void Exti_UserConfig(void);
//----------------------
void USER_OffInit(void); //用户开机初始化
//----------------------
void main_loop(void);
void init_eeprom(void);
u8 eeprom_compare_uchar(u8 addr); //份备比较
void main_logo(void); //开机Logo显示
void code_enter(void); //开机密码进入
u8 uart_test(void); //开机测试串口联接
void uart_error_dis(u8 data); //串口联接出错显示
//----------------------
//公共函数


void YS_XXus(u32 loop);
void YS_XXms(u32 loop);
//----------------------
//----- I2C EEPROM 读写
u8 I2C_WriteByte(u8 SendByte, u16 WriteAddress, u8 DeviceAddress);
u8 I2C_BufferWrite(u8* pBuffer, u8 length, u16 WriteAddress, u8 DeviceAddress);
u8 I2C_ReadByte(u8 *Buffer, u16 ReadAddress, u8 DeviceAddress);
u8 I2C_ReadBuffer(u8* pBuffer, u8 length, u16 ReadAddress, u8 DeviceAddress);

//void EEProm_Write_ALLTIME(void); //写 总工作时间计数
//void EEProm_Write_ICCARDGS(void); //写 IC卡计数次数
//void EEProm_Write_NULLITY(u8 data); //写 IC卡状态
//void EEProm_Write_PASS2(u8 data); //写 第二位密码
//void EEProm_Write_PASS3(u8 data); //写 第三位密码
//void EEProm_Write_CANPIN(u8 data); //写 产品代号
//void EEProm_Write_YEAR(u8 data); //写 年
//void EEProm_Write_MONTH(u8 data); //写 月
//void EEProm_Write_DAY(u8 data); //写 日
//void EEProm_Write_AddrData(u8 addr, u8 data); //写 地址写数据
//----------------------
//void IC_CARD_DIS(void); //显示PLEASE INSERT IC图标   
//void IC_CARD_DT_DIS(void); //IC卡动态显示插入
////----------------------
////IC卡操作
//void REST_IC(void); //复位IC卡  效证密码时用
//void W3COMD_IC(void); //发送三字节命令到IC卡 效证密码时用
//void READ4_IC(void); //读4字节 效证密码时用
//void PROCESS(void); //开始写过程,提供足够的脉冲

//u8 PSC_IC(u8 pass1,u8 pass2,u8 pass3);
//void READ_N(void);
//void NO_IN(void); //识别IC卡操作
//void WRITE_N(u8 add,u8 data); //写数据一个字节
//void bai_ic(void); //等待拔卡

//void GPIO_IC_DATA_OUT(void);
//void GPIO_IC_DATA_IN(void);
//----------------------
//ADS7843
void ADS7843_KEY(void);
void KEY_YEYNO(void);
void KEY_YEYNO2(void); //等到按键放开 无IC卡判断
void KEY_YEYNO_BMQ(void);
void KEY_YEYNO2_BMQ(void);
void KEY_ON_Wait(void); //等待有键按下
u8 KEY_FANHUI(u8 GS,const unsigned int *ZB_ADD); //扫描一个界面所有按键像素返回按键值
void OFF_CAL_DISPLAY(void); //开机校正显示屏
//----------------------
//语言
void Language_get_time_year(void); //查询实时时间
void Language_get_time_hour(void); //查询实时时间
void Language(void); //语言选择
//----------------------
//设置
void Setting_dis_data(u16 x,u16 y,u8 data); //设置界面数据
u8 PASS_CONTRAST(u8 *pass_data1,u8 *pass_data2); //两组密码对比
void Setting(void); //厂家设置
void SET_SET(void); //厂家高级设置


//----------------------
//锁定
void LOCK_ReadEepromData(void); //读Eeprom数据

void RandomNum(void); //利用锁定的时刻产生随机码，实现公式
u8 CompareThisTime(u8 *pass_data1); //试用解锁比较
u8 CompareForever(u8 *pass_data1); //永久解锁比较

void MainSysLock(void); //系统锁定
void SysLockSet(void); //系统锁定设置

void SysLockSet_Dis_McuID(void); //显示 锁定时显示芯片ID

void SysLockSet_Dis_Init(void); //显示 锁定初始状态
void SysLockSet_Dis_LockZt(void); //显示 锁定状态
void SysLockSet_Dis_DelDv(void); //显示 删除定位
void SysLockSet_Dis_Dv(void); //显示 定位
void SysLockSet_Dis_Pass(u16 x,u16 y,u8 *data); //显示 密码

void SysLockSet_Dis_Date1(void); //显示 日期1
void SysLockSet_Dis_Date2(void); //显示 日期2
void SysLockSet_Dis_Date3(void); //显示 日期3
void SysLockSet_Dis_Date4(void); //显示 日期4
void SysLockSet_Dis_Date5(void); //显示 日期5
void SysLockSet_Dis_Date6(void); //显示 日期6
void SysLockSet_Dis_DateDv(void); //显示 日期选中

void SysLockSet_Dis_Time1(void); //显示 累计时间1
void SysLockSet_Dis_Time2(void); //显示 累计时间2
void SysLockSet_Dis_Time3(void); //显示 累计时间3
void SysLockSet_Dis_Time4(void); //显示 累计时间4
void SysLockSet_Dis_Time5(void); //显示 累计时间5
void SysLockSet_Dis_Time6(void); //显示 累计时间6
u16 SysLockSet_Dis_TimeCl(u16 ydata,u8 data);
void SysLockSet_Dis_TimeDv(void); //显示 累计时间选中

void SysLockSet_Dis_InData(void); //显示数据输入
//----------------------
//----- TFT液晶操作
void  TX3_OUT_OVER(void);
void  TX3_OUT(u8 gs); //数据传输
void  DIS_PICNUM(u8 picnum);
void  DIS_ZF_CUAN(u8 gs,u16 x,u16 y,u8 *buf); //显示白色字符
void  DIS_ZF_CUAN_R(u8 gs,u16 x,u16 y,u8 *buf); //显示红色字符
void  DIS_ZF_CUAN_24_Black(u8 gs,u16 x,u16 y,u8 *buf); //显示12*24字符串 黑
void  DIS_DATA(u8 picnum,const unsigned int *DIS_DATA_ADD,u16 x,u16 y,u8 data);
void  DIS_DEL_DIS(u8 picnum,u16 xs,u16 ys,u16 xe,u16 ye,u16 x,u16 y);
void  YUYAN_DINW_PIC(void); //语言图片定位

void DIS_DATA_3uchar_CL(u8 data,u8 *dis);
void DIS_DATA_k3uchar_CL(u8 data,u8 *dis);
void DIS_DATA_5uint_CL(u16 data,u8 *dis);
void DIS_DATA_k5uint_CL(u16 data,u8 *dis);
void DIS_DATA_5kuint_CL(u16 data,u8 *dis);
void DIS_DATA_10ulong_CL(u32 data,u8 *dis);
//实时时钟
void DIS_READ_TIME(void); //读实时时钟
void DIS_SET_TIME(void); //SET实时时钟
void SYS_Init_TimeData(void); //初始实时时钟数据
//----------------------
void  main_loop_dis(void); //主程序 显示
void  main_loop_key(void);  
void  main_loop_key_start(void); //进入开始按键
void  XUAN_ZE_JM(void); //选择界面
//==============================================================================
//void FUNCTION(void); //功能界面
void FUNCTION_DIS(void); //功能显示 进入
void FUNCTION_INIT(void); //进入功能显示初始化
void  FUNCTION_FANHUI(void); //返回








































