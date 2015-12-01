#ifndef 	__IAP_H
#define 	__IAP_H

#include "stm32f4xx.h"
#include "stmflash.h"

//----实际时间为 time/2
#define BOOT_TIME			60				//等待升级时间
#define WAITNET_TIME	60 				//等待联网时间
#define WatchTime 		120				//数据中断WatchTime后跳入备用程序

//--存储程序大小
#define	IAP_INFO														0x800FC00	
//--升级成功标志位 APP中写入
#define	IAP_UPD_OK_ADDR											0x800FCF0	
//--主要程序区
#define 	APP_ADDR													0x08010000	//0x8010000	
//--备用程序区
#define 	APP_ADDR2													0x08060000	//0x8030000	


typedef  void (*iapfun)(void);				//定义一个函数类型的参数.

void Iap_Write(uint32_t addr);
void Iap_load(uint32_t addr);

uint8_t Iap_wait(void);

#endif


