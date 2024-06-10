#include "stm32f10x.h"                  // Device header
#include "MyI2C.h"
#include "OLED.h"
#include "Delay.h"

#define SHT30 0x44
#define SingleMSB 0x2C
#define SingleLSB 0x06
#define CycleMSB 0x21
#define CycleLSB 0x30

void SHT30_Init(void)
{
    MyI2C_Init();

}

void SHT30_WriteReg(uint8_t Address)
{
    MyI2C_Start();
    MyI2C_SendByte((SHT30<<1)|0);
    MyI2C_ReceiveAck();
    MyI2C_SendByte(CycleMSB);
    MyI2C_ReceiveAck();
    MyI2C_SendByte(CycleLSB);
    MyI2C_ReceiveAck();
    MyI2C_Stop();
}

void SHT30_RepeatReadReg(uint8_t* buff, uint16_t* temperture, uint16_t* huminess)
{
    uint16_t i,data;

    MyI2C_Start();
    MyI2C_SendByte((SHT30<<1)|1);
    MyI2C_ReceiveAck();
    for (i=0;i<6;i++)
    {
        buff[i] = MyI2C_ReceiveByte() ;
        if (i == 5) MyI2C_SendAck(1);
        else MyI2C_SendAck(0);
    }
    MyI2C_Stop();
    
    data = buff[0];
    data <<= 8;
    data |= buff[1];
    *temperture = 175.0 * ((float)data / (65536-1)) - 45;
    
    data = buff[3];
    data <<= 8;
    data |= buff[4];
    *huminess = 100.0 * ((float)data / (65536-1));
}
