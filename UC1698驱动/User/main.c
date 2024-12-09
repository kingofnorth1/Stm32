#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "UC1698.h"

int main(void)
{   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
 
    GPIO_Init_Periph();
	UC1698_Init();
    Delay_ms(100);                                                                                                                                                                          
//	lcdscan(0xFF,0x40);
    character();
	while (1)
	{
		
	}
}
