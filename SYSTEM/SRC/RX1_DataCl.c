/*
	串口1接收处理(B板控制联接)
*/
#include "CPU_PIN.H"

//---------------------- 串口1 中断
void USART1_IRQHandler(void)
{
	static u8 flag = 0; 
	u8  data;
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET){
		data = USART_ReceiveData(USART1);
		switch(RX1_GS){
			case 10:if(data==0xAA)RX1_GS--;else{RX1_GS=10;}break;	   
   	  case  9:
				switch(data){
					case 0x73:flag = 0xff;break;//有按键
	  			case 0x72:flag = 0x00;KEY_YES = flag;break;//没按键
	  		}
				RX1_GS--;	  
 	  		break;   
   	  case  8:KEY_XH=data;RX1_GS--;break;// X H	
			case  7:KEY_XL=data;RX1_GS--;break;// X L	
   	  case  6:KEY_YH=data;RX1_GS--;break;// Y H	
   	  case  5:KEY_YL=data;RX1_GS--;KEY_YES = flag;break;// Y L	
   	  case  4:RX1_GS--;break;
   	  case  3:RX1_GS--;break;
   	  case  2:RX1_GS--;break;
			case  1:RX1_GS=10;break;
   	  default:RX1_GS=10;flag = 0x00;break;   		   		   		        
  	}
	}
}
