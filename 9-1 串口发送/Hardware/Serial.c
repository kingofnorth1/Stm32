#include "stm32f10x.h"                  // Device header

int Serial_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    
    GPIO_InitTypeDef GPIO_Structure;
    GPIO_Structure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Structure.GPIO_Pin = GPIO_Pin_9;
    GPIO_Structure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_Structure);
    
    USART_InitTypeDef USART_Structure;
    USART_Structure.USART_BaudRate = 9600;
    USART_Structure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Structure.USART_Mode = USART_Mode_Tx;
    USART_Structure.USART_Parity = USART_Parity_No;
    USART_Structure.USART_StopBits = USART_StopBits_1;
    USART_Structure.USART_WordLength = USART_WordLength_8b;
    USART_Init(USART1, &USART_Structure);
    
    USART_Cmd(USART1, ENABLE);
    
    return 1;
}

int Serial_SendByte(int8_t Byte)
{
    USART_SendData(USART1, Byte);
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}
