#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"
#include "Menu.h"

int MenuNum = 0;

int main(void)
{
	OLED_Init();
    Key_Init();
    

	while (1)
	{
        MenuNum=Menu1();
        if (MenuNum==1) Menu2_Bluetooth();
        if (MenuNum==2) Menu2_Music();
	}
}
