#include "Menu.h"

uint8_t Menu1(void)
{
    uint8_t menu1_flag=1;  //选择
    //蓝牙连接
    OLED_ShowChinese(1, 3, 0);
    OLED_ShowChinese(1, 5, 1);
    OLED_ShowChinese(1, 7, 2);
    OLED_ShowChinese(1, 9, 3);
    //音量大小
    OLED_ShowChinese(2, 3, 4);
    OLED_ShowChinese(2, 5, 5);
    OLED_ShowChinese(2, 7, 6);
    OLED_ShowChinese(2, 9, 7);
    //通道选择
    OLED_ShowChinese(3, 3, 14);
    OLED_ShowChinese(3, 5, 15);
    OLED_ShowChinese(3, 7, 16);
    OLED_ShowChinese(3, 9, 17);
    
//    OLED_ClearArea(0, 8, 0, 2);
    uint8_t key=0;
    while (1)
    {
        key = Key_GetNum();
        if (key==1)     //控制键
        {
            menu1_flag++;
            if (menu1_flag==4) menu1_flag=1;
        }
        if (key==2)     //选择键
        {
            OLED_Clear();
            return menu1_flag;
        }
        switch(menu1_flag)
        {
            case 1:
            {
                OLED_ShowString(1, 1, "*");
                OLED_ShowString(2, 1, " ");
                OLED_ShowString(3, 1, " ");
            }break;
            case 2:
            {
                OLED_ShowString(1, 1, " ");
                OLED_ShowString(2, 1, "*");
                OLED_ShowString(3, 1, " ");
            }break;
            case 3:
            {
                OLED_ShowString(1, 1, " ");
                OLED_ShowString(2, 1, " ");
                OLED_ShowString(3, 1, "*");
            }break;
        }
    }
}

uint8_t Menu2_Bluetooth(void)
{
    OLED_ShowChinese(1, 3, 0);
    OLED_ShowChinese(1, 5, 1);
    OLED_ShowChinese(1, 7, 8);
    OLED_ShowChinese(1, 9, 9);
    
    uint8_t key=0;
    uint8_t num;
    while(1)
    {
        num++;
        key = Key_GetNum();
        if (key==2)
        {
            OLED_Clear();
            return 0;
        }
        Delay_ms(500);
        OLED_ShowNum(2,3,num,2);
    }
}

uint8_t Menu2_Music(void)
{
    uint8_t Menu2_flag = 1;
    
    OLED_ShowChinese(2, 5, 8);
    OLED_ShowChinese(2, 7, 9);
    OLED_ShowChinese(3, 5, 10);
    OLED_ShowChinese(3, 7, 11);
    
    uint8_t Key=0;
    while (1)
    {
        Key = Key_GetNum();
        if (Key==1)
        {
            Menu2_flag++;
            if (Menu2_flag==3) Menu2_flag = 1;
        }
        if (Key==2)
        {
            OLED_Clear();
            return 0;
        }
        switch(Menu2_flag)
        {
            case 1:
            {
                OLED_ShowString(2, 3, "*");
                OLED_ShowString(3, 3, " ");
            }break;
            case 2:
            {
                OLED_ShowString(2, 3, " ");
                OLED_ShowString(3, 3, "*");
            }break;
        }
    }
}
