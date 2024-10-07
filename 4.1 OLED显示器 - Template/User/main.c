#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "UC1698.h"

int main(void)
{
	GPIO_Init_Periph();
    Delay_ms(100);
	UC1698_Init();
    Delay_ms(100);                                                                                                                                                                          
//	lcdscan(0x01,0x40);
    character();
	
    while(1)
    {
    
    }
}
