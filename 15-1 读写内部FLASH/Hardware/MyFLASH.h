#ifndef __MYFLASH__H
#define __MYFLASH__H
#include "stdint.h"

uint32_t MyFLASH_ReadWord(uint32_t Address);
uint16_t MyFLASH_ReadHalfWord(uint32_t Address);
uint8_t MyFLASH_ReadByte(uint32_t Address);
void MyFLASH_EraseAllPages(void);
void MyFLASH_ErasePages(uint32_t PageAddress);
void MyFlash_ProgramWord(uint32_t Address, uint32_t Data);
void MyFlash_ProgramHalfWord(uint32_t Address, uint16_t Data);

#endif
