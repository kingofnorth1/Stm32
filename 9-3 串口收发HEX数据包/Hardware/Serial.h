#ifndef __SERIAL__H
#define __SERIAL__H

#include <stdint.h>
#include <stdio.h>

extern uint8_t Serial_RxPacket[];
extern uint8_t Serial_TxPacket[];

int Serial_Init(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array, int length);
void Serial_SendString(char *String);
void Serial_SendNumber(uint32_t number, uint8_t length);
void Serial_Printf(char *format, ...);

void Serial_SendPacket(void);

uint8_t Serial_GetRxFlag(void);



#endif
