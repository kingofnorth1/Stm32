#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "time.h"  
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

struct Time{
    char day[20];
    char minute[20];
    char hour[20];
    char second[20];
};

int main(void)
{
	OLED_Init();
	
//	OLED_ShowChar(1, 1, 'A');
//	OLED_ShowString(1, 3, "HelloWorld");
//	OLED_ShowNum(2, 1, 12345, 6);
//	OLED_ShowSignedNum(2, 7, -66, 2);
//	OLED_ShowHexNum(3, 1, 0xAA55, 4);
//	OLED_ShowBinNum(4, 1, 0xAA55, 16);
//	OLED_Clear();
	
	while (1)
	{
		char date[20] = "24:01:25 ";
		for (int i=21;i<24;i++){
			struct Time TimeTemp;
			strcpy(TimeTemp.day, date);
			sprintf(TimeTemp.hour, "%d", i);
			strcat(TimeTemp.day, TimeTemp.hour);
			// printf("day and minute : %s\n", TimeTemp.day);
			for (int j=6;j<60;j++){
				char strMinute[20];
				strcpy(strMinute, TimeTemp.day);
				sprintf(TimeTemp.minute, "%d", j);
				strcat(strMinute, ":");
				strcat(strMinute, TimeTemp.minute);
				for (int j=1;j<60;j++){
					Delay_ms(1000);
					char strSecond[20];
					strcpy(strSecond, strMinute);
					sprintf(TimeTemp.second, "%d", j);
					strcat(strSecond, ":");
					strcat(strSecond, TimeTemp.second);
					OLED_ShowString(1, 1, strSecond);
				}
				// printf("The String : %s\n", str);
			}
			
		}
	}
}
