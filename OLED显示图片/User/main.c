#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"

int main(void)
{
	OLED_Init();
//    OLED_ShowString(1, 1, "hxt");
    
    OLED_UpdateImg();
    OLED_ShowImg();
	while (1)
	{
		
	}
}
