#include "softreset.h"



void SoftReset(void)
{
		__set_FAULTMASK(1);
		NVIC_SystemReset();
}

