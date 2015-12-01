#include "CRC.h"



void CRC_Config(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC, ENABLE);
}

// data_len_L  data_len_H  data(no more than 1K)   index_L index_H CRC

uint8_t CRC_GetVal(uint32_t *pdata, uint16_t len , uint32_t CRC_Val) 
{
	uint32_t temp;
	len -= 1;	
	CRC_ResetDR();
	while(len)
	{
		temp = __rev(*pdata);			//在一个32位reg中翻转字节顺序
		CRC->DR = temp;
		*pdata++;
		len--;
	}
	
	if(CRC_Val != CRC->DR)return 0;
	return 1;
}

