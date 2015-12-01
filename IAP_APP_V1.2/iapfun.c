#include "iapfun.h"
#include "stmflash.h"

//--IAP适配版本：IAP_BootLoader_429 V1.2


//--设置地址偏移
void IAP_AddOffset(void)
{
	#ifdef MAINAPP
		SCB->VTOR = FLASH_BASE | 0x10000;
	#endif
	#ifdef SPAREAPP
		SCB->VTOR = FLASH_BASE | 0x60000;
	#endif
}


//--程序运行状态确定
//----0x55 Main 
//----0xff Spare
void IAP_ProState(void)
{
	#ifdef MAINAPP
		if(STMFLASH_ReadWord(IAP_UPD_OK_ADDR) != 0x55)
	{
		STMFLASH_WriteWord(IAP_UPD_OK_ADDR, 0x55);
	}
	#endif
	#ifdef SPAREAPP
		if(STMFLASH_ReadWord(IAP_UPD_OK_ADDR) == 0x55)
	{
		STMFLASH_WriteWord(IAP_UPD_OK_ADDR, 0xff);
	}
	#endif
}



