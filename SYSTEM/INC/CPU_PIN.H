#ifndef  __CPU_PIN_H
#define  __CPU_PIN_H

#include "stm32f10x.h"
#include "EXTERIOR_RAM.H"
#include "ALL_PROGRAM.H"
#include "PICTURE.H"
#include "sound.h"
#include "time.h"
#include "uart.h"
#include "display.h"
#include "ads7843.h"
#include "init.h"


#define  PAGE_CHECK_FUN        0
#define  PAGE_ADVAN_SET        1

#define  Picture_Language    23

#define  DD_ON   	GPIOB->BRR  = GPIO_Pin_12 //�˿� ��0
#define  DD_OFF  	GPIOB->BSRR = GPIO_Pin_12 //�˿� ��1

//#define READY_KEY  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)//��ȡ����0

#define  LED_OFF  GPIOA->BRR  = GPIO_Pin_8 //�˿� ��0
#define  LED_ON  	GPIOA->BSRR = GPIO_Pin_8 //�˿� ��1

//#define LED0 PAout(4)// PA4
//#define LED1 PAout(6)// PA6

//#define KEY0  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)//��ȡ����0
//#define KEY1  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)//��ȡ����1

//#define FALSE 0
//#define TRUE  !FALSE





#endif

























