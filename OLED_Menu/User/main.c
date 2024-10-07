#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"

int main(void)
{
	OLED_Init();

	OLED_ShowString(1, 2, "Music+");
    OLED_ShowString(2, 2, "Music-");
    OLED_ShowString(3, 2, "Channel+");
    OLED_ShowString(4, 2, "Channel-");
	while (1)
	{

	}
}
