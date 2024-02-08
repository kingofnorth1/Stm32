#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"

uint8_t i;

int main(void)
{
    OLED_Init();
    PWM_Init();
    
    while (1)
    {
        for (i=0;i<100;i++)
        {
            PWM_Compare(i);
            Delay_ms(30);
        }
        for (i=0;i<100;i++)
        {
            PWM_Compare(100 - i);
            Delay_ms(30);
        }
    }
}
