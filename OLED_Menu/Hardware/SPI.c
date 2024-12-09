#include "SPI.h"

void MySPI_W_SS(uint8_t BitValue)
{
    GPIO_WriteBit(GPIOB, GPIO_Pin_6, (BitAction)BitValue);
}

void MySPI_W_SCK(uint8_t BitValue)
{
    GPIO_WriteBit(GPIOB, GPIO_Pin_7, (BitAction)BitValue);
}

void MySPI_W_MOSI(uint8_t BitValue)
{
    GPIO_WriteBit(GPIOB, GPIO_Pin_9, (BitAction)BitValue);
}

uint8_t MySPI_R_MISO(void)
{
    return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8);
}

void MySPI_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    MySPI_W_SS(1);
    MySPI_W_SCK(0);
}

void MySPI_Start(void)
{
    MySPI_W_SS(0);
}

void MySPI_Stop(void)
{
    MySPI_W_SS(1);
}

uint8_t MySPI_SwapByte(uint8_t ByteSend) //模式0
{
    uint8_t i, ByteReceive = 0x00;
    for (i=0;i<8;i++)
    {
        MySPI_W_MOSI(ByteSend & 0x80 >> i);
        MySPI_W_SCK(1);
        if (MySPI_R_MISO() == 1){ByteReceive |= (0x80 >> i);}
        MySPI_W_SCK(0);
    }
    return ByteReceive;
}

//uint8_t MySPI_SwapByte1(uint8_t ByteSend)  //移位寄存器模型
//{
//    uint8_t i, ByteReceive = 0x00;
//    for (i=0;i<8;i++)
//    {
//        MySPI_W_MOSI(ByteSend & 0x80);
//        ByteSend <<= 1;
//        if (MySPI_R_MISO() == 1){ByteSend |= 0x01;}
//        MySPI_W_SCK(0);
//    }
//    return ByteSend;
//}
