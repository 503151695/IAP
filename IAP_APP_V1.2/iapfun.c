#include "iapfun.h"
#include "stmflash.h"

//--IAP����汾��IAP_BootLoader_429 V1.2


//--���õ�ַƫ��
void IAP_AddOffset(void)
{
	#ifdef MAINAPP
		SCB->VTOR = FLASH_BASE | 0x10000;
	#endif
	#ifdef SPAREAPP
		SCB->VTOR = FLASH_BASE | 0x60000;
	#endif
}


//--��������״̬ȷ��
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



