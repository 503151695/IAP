#ifndef _DRIVER_USART_H_
#define _DRIVER_USART_H_
#include "stdint.h"
#include "stdarg.h"
#include "stdio.h"
#include "stm32f4xx.h"



#define BAUD4800 	(4800)
#define BAUD7200 	(7200)
#define BAUD9600 	(9600)
#define BAUD14400 	(14400)
#define BAUD19200 	(19200)
#define BAUD38400 	(38400)
#define BAUD57600 	(57600)
#define BAUD115200	(115200)
#define BAUD1200 	(1200)


extern uint32_t g_u32_Usart1BaudRate;
extern uint32_t g_u32_Usart2BaudRate;
extern uint32_t g_u32_Usart3BaudRate;
extern uint32_t g_u32_Uart4BaudRate;
extern uint32_t g_u32_Uart5BaudRate;
extern uint32_t g_u32_Usart6BaudRate;

extern void USART_Configuration(void);

extern void Send2Usart1(u8 u08_Date);
extern void Send2Usart3(u8 u08_Date);
extern void Send2Usart6(u8 u08_Date);


#endif
