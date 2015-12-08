/*
*********************************************************************************************************
*	                                  
*	模块名称 : 主程序模块
*	文件名称 : main.c
*	版    本 : V1.0
*	说    明 : 例程
*	修改记录 :
*		版本号   日期         作者          说明

*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/
                                                               
#include "myBSP.h"
#include "Timer.h"
#include "iap.h"


uint8_t u08_UpdateFlag = 0;
uint8_t u08_UpdateOKFlag = 0;
uint8_t u08_NetOnlineFlag = 0;
/*
*********************************************************************************************************
*	函 数 名: main
*	功能说明: 标准c程序入口。
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
int main(void)
{
	uint8_t temp = 0;
	
  BSPInit();
	
	//--清屏
	LcdDispValue(1,50,10,"OS-8在线监测系统 BOOTLOADER");
	LcdDispValue(0,30,30,"*******************************************\r\n");
	LcdDispValue(0,30,190,"*******************************************\r\n");
	LcdDispValue(1,X_Height,Y_Height,"Waiting for network connection...");

	while (1)
	{
		//--等待网络连接
		while((Tick_Cnt < WAITNET_TIME) && (u08_NetOnlineFlag == 0))
		{
			while (USART_GetFlagStatus(UART7, USART_IT_RXNE) != RESET)
			{
				temp = (uint8_t)USART_ReceiveData(UART7);
				if(temp == '@')
				{
					u08_NetOnlineFlag = 1;
					Tick_Cnt = 0;
					printf("#NETWORKON*\r\n");
					LcdDispValue(1,X_Height,Y_Height+20,"Network has been connected...");
				}
			}
		}
		//--网络情况确认
		if(u08_NetOnlineFlag == 0)
			LcdDispValue(1,X_Height,Y_Height+20,"Network is not connected...");	
		else
		{
			LcdDispValue(1,X_Height,Y_Height+40,"Waiting for remote command...");
		}
		//--倒计时等待升级命令
		while((Tick_Cnt < BOOT_TIME) && (u08_UpdateFlag == 0))	
		{
			//--收到升级命令
			if(Iap_wait() == 8)	
			{
				USART_ITConfig(UART7, USART_IT_RXNE, ENABLE);
				u08_UpdateFlag = 1;
				LcdDispValue(1,X_Height,Y_Height+60,"Waiting for the firmware package...");
				printf("#F7C|HEARTOFF*");
				TIM_Cmd(TIM4, ENABLE);	//开启升级监视定时器
				STMFLASH_WriteWord(IAP_UPD_OK_ADDR, 0xff);
			}
		}
		//--执行升级
		if(u08_UpdateFlag)
		{
			Iap_Write(APP_ADDR);
			u08_UpdateFlag = 0;				
			u08_UpdateOKFlag = 1;		
			LcdDispValue(1,X_Height,Y_Height+100,"Upgrade is completed...");
		}
		//--
		Delay_ms(500);
		//--执行跳转
		if(u08_UpdateFlag == 0) 
		{
			TIM_ITConfig(TIM4,TIM_IT_Update,DISABLE );	
			LcdDispValue(1,X_Height,Y_Height+120,"Jump into application...");
			Delay_ms(500);
			TIM_ITConfig(TIM3,TIM_IT_Update,DISABLE );												

			if((STMFLASH_ReadWord(IAP_UPD_OK_ADDR) == 0x55) || u08_UpdateOKFlag == 1)
			{
				u08_UpdateOKFlag = 0;
				printf("#F7C|HEARTON*");
				Delay_ms(50);
				printf("#MAINAPP*\r\n");
				Delay_ms(50);
				Iap_load(APP_ADDR);					//启用新程序
			}
			else
			{
				printf("#F7C|HEARTON*");
				Delay_ms(50);
				printf("#SPAREAPP*\r\n");
				Delay_ms(50);
				Iap_load(APP_ADDR2);				//启用备份区程序
			}
		}
			
	}
}

