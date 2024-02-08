#include "stdint.h"
#ifndef __PWM__H
#define __PWM__H

void PWM_Init(void);
void PWM_Compare(uint16_t compare);
void PWM_SetPrescaler(uint16_t Prescaler);


#endif
