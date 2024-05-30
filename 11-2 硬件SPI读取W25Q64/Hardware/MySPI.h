#ifndef __MYSPI__H
#define __MYSPI__H
#include <stdint.h>

void MySPI_Init(void);
void MySPI_Start(void);
void MySPI_Stop(void);
uint8_t MySPI_SwapByte(uint8_t ByteSend);

#endif
