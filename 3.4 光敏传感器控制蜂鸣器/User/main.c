#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "Buzzer.h"

uint8_t KeyNum;

int main(void)
{
	BUZZER_Init();
	Key_Init();
	while (1)
	{
		BUZZER_OFF();
		Delay_ms(500);
		BUZZER_ON();
		Delay_ms(500);
	}
}
