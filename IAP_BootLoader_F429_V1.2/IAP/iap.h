#ifndef 	__IAP_H
#define 	__IAP_H

#include "stm32f4xx.h"
#include "stmflash.h"

//----ʵ��ʱ��Ϊ time/2
#define BOOT_TIME			60				//�ȴ�����ʱ��
#define WAITNET_TIME	60 				//�ȴ�����ʱ��
#define WatchTime 		120				//�����ж�WatchTime�����뱸�ó���

//--�洢�����С
#define	IAP_INFO														0x800FC00	
//--�����ɹ���־λ APP��д��
#define	IAP_UPD_OK_ADDR											0x800FCF0	
//--��Ҫ������
#define 	APP_ADDR													0x08010000	//0x8010000	
//--���ó�����
#define 	APP_ADDR2													0x08060000	//0x8030000	


typedef  void (*iapfun)(void);				//����һ���������͵Ĳ���.

void Iap_Write(uint32_t addr);
void Iap_load(uint32_t addr);

uint8_t Iap_wait(void);

#endif


