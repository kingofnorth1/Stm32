#ifndef __MYRTC__H
#define __MYRTC__H
#include "stdint.h"

extern uint16_t MyRTC_Time[];

void MyRTC_Init(void);
void RTC_SetTime(void);
void MyRTC_ReadTime(void);


#endif
