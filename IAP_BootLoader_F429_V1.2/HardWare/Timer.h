#ifndef _TIMER_H
#define _TIMER_H
#include "stm32f4xx.h"
#include "myBSP.h"

extern u16 g_u16_Timer3IntCnt;
extern u16 Tick_Cnt;	//µÈ´ı¸üĞÂÃüÁî

void TIM3Init(u16 arr,u16 psc);
void TIM4Init(u16 arr,u16 psc);
#endif
