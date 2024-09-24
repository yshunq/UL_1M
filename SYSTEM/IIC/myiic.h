#ifndef __MYIIC_H
#define __MYIIC_H

#include "sys.h"
#include "CPU_PIN.H"
//IO��������
#define SDA_IN()  {GPIOB->CRL&=0XFFFFFFF0;GPIOB->CRL|=0X00000008;}
#define SDA_OUT() {GPIOB->CRL&=0XFFFFFFF0;GPIOB->CRL|=0X00000003;}

//IO��������	 
#define IIC_SCL    PBout(1) //SCL
#define IIC_SDA    PBout(0) //SDA	 
#define READ_SDA   PBin(0)  //����SDA 

//IIC���в�������
void IIC_Init(void);                //��ʼ��IIC��IO��				 
void IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC_Read_One_Byte(u8 daddr,u8 addr);	  
#endif
















