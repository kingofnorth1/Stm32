#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "SHT30.h"

uint8_t buff[6];
uint16_t temperture, huminess;

int main(void)
{
	OLED_Init();
    OLED_ShowString(1, 1, "SHT30:");
    OLED_ShowString(2, 1, "Tem:");
    OLED_ShowString(3, 1, "hum:");
    
    SHT30_Init();
    SHT30_WriteReg(temperture);

	while (1)
	{   Delay_ms(1200);
        SHT30_RepeatReadReg(buff, &temperture, &huminess);
		OLED_ShowNum(2, 5, temperture, 2);
        OLED_ShowNum(3, 5, huminess, 2);
        
	}
}
