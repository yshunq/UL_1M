/*
   I2C EEProm
*/

#include "CPU_PIN.H"

#define 	I2C_Speed              400000     //传输时钟400KHz
#define 	I2C1_SLAVE_ADDRESS7    0xA0
//#define 	I2C_PageSize           16
#define 	I2C_PageSize             4  /*  For STM3210B-LK1, as use M24C02 instead of 
										M24C08  , redifine page size */

u16 EEPROM_ADDRESS;

//----------------------
void I2C_GPIO_Configuration(void) //I2C端口初始化
{
	GPIO_InitTypeDef  GPIO_InitStructure; 

	/* 配置I2C: SCL / SDA */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

//----------------------
void I2C_Configuration(void) //I2C寄存器初始化
{
	I2C_InitTypeDef  I2C_InitStructure;
	
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStructure.I2C_OwnAddress1 = I2C1_SLAVE_ADDRESS7;
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitStructure.I2C_ClockSpeed = I2C_Speed;
  
	I2C_Cmd(I2C1, ENABLE);	
	I2C_Init(I2C1, &I2C_InitStructure);
}

//----------------------
void I2C_EE_Init(void) //初始化I2C操作
{
	I2C_GPIO_Configuration();

	I2C_Configuration();
	//-----
	#ifdef EEPROM_Block0_ADDRESS
			EEPROM_ADDRESS = EEPROM_Block0_ADDRESS;
	#endif
	//-----
	#ifdef EEPROM_Block1_ADDRESS
			EEPROM_ADDRESS = EEPROM_Block1_ADDRESS;
	#endif
	//-----
	#ifdef EEPROM_Block2_ADDRESS
			EEPROM_ADDRESS = EEPROM_Block2_ADDRESS;
	#endif
	//-----
	#ifdef EEPROM_Block3_ADDRESS
			EEPROM_ADDRESS = EEPROM_Block3_ADDRESS;
	#endif
}

//----------------------
void I2C_EE_BufferWrite(u8 *pBuffer, u8 WriteAddr, u16 NumByteToWrite) //写多个字节 可以不同页
{
	u8 NumOfPage = 0, NumOfSingle = 0, Addr = 0, count = 0;

	Addr = WriteAddr % I2C_PageSize;
	count = I2C_PageSize - Addr;
	NumOfPage =  NumByteToWrite / I2C_PageSize;
	NumOfSingle = NumByteToWrite % I2C_PageSize;
 
	/* If WriteAddr is I2C_PageSize aligned  */
	if(Addr == 0) 
	{
		/* If NumByteToWrite < I2C_PageSize */
		if(NumOfPage == 0) 
		{
			I2C_EE_PageWrite(pBuffer, WriteAddr, NumOfSingle);
			I2C_EE_WaitEepromStandbyState();
		}
		/* If NumByteToWrite > I2C_PageSize */
		else
		{
			while(NumOfPage--)
			{
				I2C_EE_PageWrite(pBuffer, WriteAddr, I2C_PageSize); 
				I2C_EE_WaitEepromStandbyState();
				WriteAddr +=  I2C_PageSize;
				pBuffer += I2C_PageSize;
			}
			
			if(NumOfSingle!=0)
			{
				I2C_EE_PageWrite(pBuffer, WriteAddr, NumOfSingle);
				I2C_EE_WaitEepromStandbyState();
			}
		}
	}
	/* If WriteAddr is not I2C_PageSize aligned  */
	else 
	{
		/* If NumByteToWrite < I2C_PageSize */
		if(NumOfPage== 0) 
		{
			I2C_EE_PageWrite(pBuffer, WriteAddr, NumOfSingle);
			I2C_EE_WaitEepromStandbyState();
		}
		/* If NumByteToWrite > I2C_PageSize */
		else
		{
			NumByteToWrite -= count;
			NumOfPage =  NumByteToWrite / I2C_PageSize;
			NumOfSingle = NumByteToWrite % I2C_PageSize;	
      
			if(count != 0)
			{  
				I2C_EE_PageWrite(pBuffer, WriteAddr, count);
				I2C_EE_WaitEepromStandbyState();
				WriteAddr += count;
				pBuffer += count;
			} 
			
			while(NumOfPage--)
			{
				I2C_EE_PageWrite(pBuffer, WriteAddr, I2C_PageSize);
				I2C_EE_WaitEepromStandbyState();
				WriteAddr +=  I2C_PageSize;
				pBuffer += I2C_PageSize;  
			}
			if(NumOfSingle != 0)
			{
				I2C_EE_PageWrite(pBuffer, WriteAddr, NumOfSingle); 
				I2C_EE_WaitEepromStandbyState();
			}
		}
	}  
}

//----------------------
void I2C_EE_ByteWrite(u8 *pBuffer, u8 WriteAddr) //写1个字节
{
	I2C_GenerateSTART(I2C1, ENABLE); //产生I2Cx传输START条件
	
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT)); //检查最近一次I2C事件
	
	I2C_Send7bitAddress(I2C1, EEPROM_ADDRESS, I2C_Direction_Transmitter);
  
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)); //检查最近一次I2C事件

	I2C_SendData(I2C1, WriteAddr);
  
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)); //检查最近一次I2C事件

	I2C_SendData(I2C1, *pBuffer); 
   
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)); //检查最近一次I2C事件
  
	I2C_GenerateSTOP(I2C1, ENABLE); //产生I2Cx传输STOP条件
}

//----------------------
void I2C_EE_PageWrite(u8 *pBuffer, u8 WriteAddr, u8 NumByteToWrite) //写同页多个字节
{
	I2C_GenerateSTART(I2C1, ENABLE); //产生I2Cx传输START条件
	
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT)); //检查最近一次I2C事件
	
	I2C_Send7bitAddress(I2C1, EEPROM_ADDRESS, I2C_Direction_Transmitter); //向指定的从I2C设备传送地址字
	
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)); //检查最近一次I2C事件
  
	I2C_SendData(I2C1, WriteAddr); //通过外设I2Cx发送一个数据 
	
	while(! I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)); //检查最近一次I2C事件

	//-----
	while(NumByteToWrite--)  
	{
		I2C_SendData(I2C1, *pBuffer); //通过外设I2Cx发送一个数据
		
		pBuffer++; 
		
		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)); //检查最近一次I2C事件
	}
	
	I2C_GenerateSTOP(I2C1, ENABLE); //产生I2Cx传输STOP条件
}

//----------------------
void I2C_EE_BufferRead(u8* pBuffer, u8 ReadAddr, u16 NumByteToRead) //读多个字节
{  
	I2C_GenerateSTART(I2C1, ENABLE); //产生I2Cx传输START条件
	
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT)); //检查最近一次I2C事件是否是输入的事件
	
	if(NumByteToRead==1) 
	{
		I2C_AcknowledgeConfig(I2C1, DISABLE); //使能或者失能指定I2C的应答功能
	}
	
	I2C_Send7bitAddress(I2C1, EEPROM_ADDRESS, I2C_Direction_Transmitter); //向指定的从I2C设备传送地址字
	
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)); //检查最近一次I2C事件是否是输入的事件
		
	I2C_Cmd(I2C1, ENABLE); //使能或者失能I2C外设
	
	I2C_SendData(I2C1, ReadAddr); //通过外设I2Cx发送一个数据
	
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)); //检查最近一次I2C事件
	
	I2C_GenerateSTART(I2C1, ENABLE); //产生I2Cx传输START条件
	
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT)); //检查最近一次I2C事件
	
	I2C_Send7bitAddress(I2C1, EEPROM_ADDRESS, I2C_Direction_Receiver); //向指定的从I2C设备传送地址字
	
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED)); //检查最近一次I2C事件
	
	//-----
	while(NumByteToRead)  
	{
		if(I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED)) //检查最近一次I2C事件
		{
			if(NumByteToRead == 2)
			{
				I2C_AcknowledgeConfig(I2C1, DISABLE); //使能或者失能指定I2C的应答功能
			}
			
			if(NumByteToRead == 1)
			{
				I2C_GenerateSTOP(I2C1, ENABLE); //产生I2Cx传输STOP条件
			}
			
			*pBuffer = I2C_ReceiveData(I2C1); //返回通过I2Cx最近接收的数据
			
			pBuffer++;			
			NumByteToRead--;    
		}   
	}
	
	I2C_AcknowledgeConfig(I2C1, ENABLE); //使能或者失能指定I2C的应答功能
}

//----------------------
void I2C_EE_WaitEepromStandbyState(void) //检查原操作是否完成
{
	do
	{	
		I2C_GenerateSTART(I2C1, ENABLE); //产生I2Cx传输START条件
		
		I2C_ReadRegister(I2C1, I2C_Register_SR1); //读取指定的I2C寄存器并返回其值
		
		I2C_Send7bitAddress(I2C1, EEPROM_ADDRESS, I2C_Direction_Transmitter); //向指定的从I2C设备传送地址字		
		
	}while(!(I2C_ReadRegister(I2C1, I2C_Register_SR1) & 0x0002)); //读取指定的I2C寄存器
	
	I2C_ClearFlag(I2C1, I2C_FLAG_AF); //清除I2Cx的待处理标志位
}
