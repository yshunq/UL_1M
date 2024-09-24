#include "CPU_PIN.H"
 
void jump_interface(void)
{
	while(1){
		YS_XXms(1);
		switch(INTERFACE){
			case  PAGE_CHECK_FUN:
				main_xs_check_fun();
				break;
			case	PAGE_ADVAN_SET:
				main_xs_advanced_settings();
				break;
			default:
					        
				break; 
		} 
 	}
}



