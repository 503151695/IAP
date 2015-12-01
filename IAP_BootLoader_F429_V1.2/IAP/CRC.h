#ifndef __CRC_H
#define ___CRC_H

#include "stm32f4xx.h"



void CRC_Config(void);
uint8_t CRC_GetVal(uint32_t *pdata, uint16_t len , uint32_t CRC_Val) ;



#endif


