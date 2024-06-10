#ifndef __SHT30__H
#define __SHT30__H
#include "stdint.h"

void SHT30_Init(void);
void SHT30_WriteReg(uint8_t Address);
void SHT30_RepeatReadReg(uint8_t* buff, uint16_t* temperture, uint16_t* huminess);


#endif
