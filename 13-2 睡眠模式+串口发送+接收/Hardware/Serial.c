#include "stm32f10x.h"                  // Device header
#include "stdio.h"
#include <stdarg.h>

uint8_t Serial_RxData;
uint8_t Serial_Flag;

int Serial_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    
    GPIO_InitTypeDef GPIO_Structure;
    GPIO_Structure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Structure.GPIO_Pin = GPIO_Pin_9;
    GPIO_Structure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_Structure);
    
    GPIO_Structure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Structure.GPIO_Pin = GPIO_Pin_10;
    GPIO_Structure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_Structure);
    
    USART_InitTypeDef USART_Structure;
    USART_Structure.USART_BaudRate = 9600;
    USART_Structure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Structure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    USART_Structure.USART_Parity = USART_Parity_No;
    USART_Structure.USART_StopBits = USART_StopBits_1;
    USART_Structure.USART_WordLength = USART_WordLength_8b;
    USART_Init(USART1, &USART_Structure);
    
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
    
    NVIC_InitTypeDef NVIC_Structure;
    NVIC_Structure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_Structure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Structure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_Structure.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_Structure);
    
    USART_Cmd(USART1, ENABLE);
    
    return 1;
}

void Serial_SendByte(int8_t Byte)
{
    USART_SendData(USART1, Byte);
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

void Serial_SendArray(uint8_t *Array, int length)
{
    for (int i=0;i<length;i++)
    {
        Serial_SendByte(Array[i]);
    }
}

void Serial_SendString(char *String)
{
    uint8_t i;
    for (i=0;String[i] != '\0';i++)
    {
        Serial_SendByte(String[i]);
    }
}

uint32_t Serial_SendPow(uint32_t x, uint32_t y)
{
    uint32_t Result = 1;
    while (y--)
    {
        Result *= x;
    }
    return Result;
}

void Serial_SendNumber(uint32_t Number, uint8_t Length)
{
    uint8_t i;
    for (i=0;i<Length;i++)
    {
        Serial_SendByte(Number / (Serial_SendPow(10, Length - i - 1)) %10 + '0');
    }
}

int fputc(int ch, FILE *f)
{
    Serial_SendByte(ch);
    return 1;
}

void Serial_Printf(char *format, ...)
{
    char String[100];
    va_list arg;
    va_start(arg, format);
    vsprintf(String, format, arg);
    va_end(arg);
    Serial_SendString(String);
}

int Serial_GetFlag()
{
    if (Serial_Flag == 1)
    {
        Serial_Flag = 0;
        return 1;
    }
    return 0;
}

uint8_t Serial_GetRxData()
{
    return Serial_RxData;
}

void USART1_IRQHandler()
{
    if (USART_GetITStatus(USART1, USART_IT_RXNE) == SET)
    {
        Serial_RxData = USART_ReceiveData(USART1);
        Serial_Flag = 1;
        USART_ClearITPendingBit(USART1, USART_IT_RXNE);
    }
}
