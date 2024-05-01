#include "stdint.h"
#ifndef __AD__H
#define __AD__H

extern uint16_t ADC_Value[4];

void AD_Init(void);
void AD_GetValue(void);

#endif
