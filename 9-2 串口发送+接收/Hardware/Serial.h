#include "stdint.h"
#ifndef __SERIAL__H
#define __SERIAL__H

int Serial_Init();
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array, int length);
void Serial_SendString(char *String);
void Serial_SendNumber(uint32_t number, uint8_t length);
void Serial_Printf(char *format, ...);
int USART_GetFlag();
uint8_t USART_GetRxData();


#endif
