#ifndef _SYS_FUNC_H_
#define _SYS_FUNC_H_
//#include <stdio.h>
#include <stdint.h>
#include <string.h>

extern void Float2Char(char *str, float number, uint8_t g, uint8_t l);
extern void Int2Char( int number,unsigned char *str ,uint8_t g);
extern void Delay_ms(unsigned int time);

#endif
