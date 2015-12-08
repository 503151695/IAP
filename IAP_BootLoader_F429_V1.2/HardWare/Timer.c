#include "Timer.h"
#include "softreset.h"
#include "iap.h"

extern uint8_t u08_UpdateFlag;
/************************
*�������ƣ�TIM3Init
*�������ܣ�ͨ�ö�ʱ��3�жϳ�ʼ��
		  ��ʱ�����ʱ����㷽��:Tout=((arr+1)*(psc+1))/Ft us.
		  Ft=��ʱ������Ƶ��,��λ:Mhz
*��    �룺arr���Զ���װֵ��psc��ʱ��Ԥ��Ƶ��
*��    ������
*************************/
u16 Tick_Cnt=0;

void TIM3Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  					//ʹ��TIM3ʱ��
	
	TIM_TimeBaseInitStructure.TIM_Period = arr; 							//�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  							//��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; 			//���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);						//��ʼ��TIM3
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); 								//����ʱ��3�����ж�
	TIM_Cmd(TIM3,ENABLE); 													//ʹ�ܶ�ʱ��3
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; 							//��ʱ��3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; 				//��ռ���ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; 					//�����ȼ�3
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
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);  					//ʹ��TIM3ʱ��
	
	TIM_TimeBaseInitStructure.TIM_Period = arr; 							//�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  							//��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; 			//���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);						//��ʼ��TIM3
	
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE); 								//����ʱ��3�����ж�
//	TIM_Cmd(TIM4,ENABLE); 													//ʹ�ܶ�ʱ��3
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn; 							//��ʱ��3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x02; 				//��ռ���ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; 					//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);

//	TIM_Cmd(TIM4, ENABLE);  //�������º���	 
}

void TIM4_IRQHandler(void)  
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET) 
		{
			TIM_ClearITPendingBit(TIM4, TIM_IT_Update  ); 
			Watch_Cnt++;

		}
}





