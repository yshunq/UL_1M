#include "uart.h"

void USART1_IRQHandler(void)//串口1 中断
{
	static u8 flag = 0; 
	u8  data;
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET){
		data = USART_ReceiveData(USART1);
		switch(Uart_LCD.RX_GS){
			case 10:if(data==0xAA)Uart_LCD.RX_GS--;else{Uart_LCD.RX_GS=10;}break;	   
   	  case  9:
				switch(data){
					case 0x73:flag = 0xff;break;//有按键
	  			case 0x72:flag = 0x00;Uart_LCD.KEY_YES = flag;break;//没按键
	  		}
				Uart_LCD.RX_GS--;	  
 	  		break;   
   	  case  8:Uart_LCD.KEY_XH=data;Uart_LCD.RX_GS--;break;// X H	
			case  7:Uart_LCD.KEY_XL=data;Uart_LCD.RX_GS--;break;// X L	
   	  case  6:Uart_LCD.KEY_YH=data;Uart_LCD.RX_GS--;break;// Y H	
   	  case  5:Uart_LCD.KEY_YL=data;Uart_LCD.RX_GS--;Uart_LCD.KEY_YES = flag;break;// Y L	
   	  case  4:Uart_LCD.RX_GS--;break;
   	  case  3:Uart_LCD.RX_GS--;break;
   	  case  2:Uart_LCD.RX_GS--;break;
			case  1:Uart_LCD.RX_GS=10;break;
   	  default:Uart_LCD.RX_GS=10;flag = 0x00;break;   		   		   		        
  	}
	}
}
