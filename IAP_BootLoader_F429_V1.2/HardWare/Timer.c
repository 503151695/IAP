#include "Timer.h"
#include "softreset.h"
#include "iap.h"

extern uint8_t u08_UpdateFlag;
/************************
*函数名称：TIM3Init
*函数功能：通用定时器3中断初始化
		  定时器溢出时间计算方法:Tout=((arr+1)*(psc+1))/Ft us.
		  Ft=定时器工作频率,单位:Mhz
*输    入：arr：自动重装值。psc：时钟预分频数
*输    出：无
*************************/
u16 Tick_Cnt=0;

void TIM3Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  					//使能TIM3时钟
	
	TIM_TimeBaseInitStructure.TIM_Period = arr; 							//自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  							//定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; 			//向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);						//初始化TIM3
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); 								//允许定时器3更新中断
	TIM_Cmd(TIM3,ENABLE); 													//使能定时器3
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; 							//定时器3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; 				//抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; 					//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}


void TIM3_IRQHandler(void)
{
	static u8 s_u08_HardWareWDGFlg = 0;
	
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  
	{
			TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  
			Tick_Cnt++;
			
			s_u08_HardWareWDGFlg = ~s_u08_HardWareWDGFlg;
			if (s_u08_HardWareWDGFlg)
			{
				HARDWARE_WDG_H;
				GREEN_LED_ON;
			}
			else
			{
				HARDWARE_WDG_L;
				GREEN_LED_OFF;
			}
			if(u08_UpdateFlag == 0)
			{
				LcdDispValue(1,280,10,"%ds  ",31-Tick_Cnt/2);
			}

	}
}


u16 Watch_Cnt=0;

void TIM4Init(u16 arr,u16 psc)
{
   	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);  					//使能TIM3时钟
	
	TIM_TimeBaseInitStructure.TIM_Period = arr; 							//自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  							//定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; 			//向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);						//初始化TIM3
	
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE); 								//允许定时器3更新中断
//	TIM_Cmd(TIM4,ENABLE); 													//使能定时器3
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn; 							//定时器3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x02; 				//抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; 					//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);

//	TIM_Cmd(TIM4, ENABLE);  //启动更新后开启	 
}

void TIM4_IRQHandler(void)  
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET) 
		{
			TIM_ClearITPendingBit(TIM4, TIM_IT_Update  ); 
			Watch_Cnt++;

		}
}





