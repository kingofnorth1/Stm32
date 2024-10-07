#ifndef __UC1698__H
#define __UC1698__H
#include "stdint.h"
#include "delay.h"

#define LCD_SDA_Clr GPIO_ResetBits(GPIOA, GPIO_Pin_15)
#define LCD_SDA_Set GPIO_SetBits(GPIOA, GPIO_Pin_15)
#define LCD_SCL_Clr GPIO_ResetBits(GPIOA, GPIO_Pin_12)
#define LCD_SCL_Set GPIO_SetBits(GPIOA, GPIO_Pin_12)
#define LCD_RES_Clr GPIO_ResetBits(GPIOA, GPIO_Pin_11) 
#define LCD_RES_Set GPIO_SetBits(GPIOA, GPIO_Pin_11)
#define LCD_DC_Clr  GPIO_ResetBits(GPIOA, GPIO_Pin_10)
#define LCD_DC_Set  GPIO_SetBits(GPIOA, GPIO_Pin_10)                       
#define LCD_CS_Clr  GPIO_ResetBits(GPIOA, GPIO_Pin_9)
#define LCD_CS_Set  GPIO_SetBits(GPIOA, GPIO_Pin_9)

void GPIO_Init_Periph(void);
void UC1698_Init(void);
void Send_Data(unsigned char Data);  
void Send_Command(unsigned char Command);
void lcdscan(unsigned char dat1,unsigned char dat2);
void words(unsigned char x,unsigned char y,unsigned char type,unsigned char *p);
void character(void);        
#endif
