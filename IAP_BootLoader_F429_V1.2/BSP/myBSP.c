//SystemInit��ϵͳʱ�ӱ���ΪPLL�����=144MHZ
#include "myBSP.h"


/*   
* �������ƣ�BSP_Init   
* ��    ����ʱ�ӳ�ʼ����Ӳ����ʼ��   
* ��    �룺��   
* ��    ������   
*/  
void BSPInit(void)    
{ 
	GPIO_Configuration();   							//IO����
	
	DTU_ON;																//����DTU
	
	LCD_OFF;
	Delay_ms(100);
	LCD_ON;
	Delay_ms(400);

	USART_Configuration(); 								//���ô���
	//EXTI_Configuration();	  						//�����ⲿ�ж�
	NVIC_Configuration();   							//�����ж�����  
	TIM3Init(5000 - 1,8400 - 1);			  		//����ι���Լ�����
	TIM4Init(5000 - 1,8400 - 1);						//500ms
	CRC_Config();

	Delay_ms(500);
}  

/*************************** 
*�������ƣ�GPIO_Configurtion
*�������ܣ�����GPIO�˿�
****************************/
void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	//��IO����ʱ��
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOE, ENABLE);
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOG, ENABLE);
			 
	//״̬LED 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);				//Green LED
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 ;     		
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOG, &GPIO_InitStructure);				//RED LED
	
//	//����1�ܽ�����,PB6->TX,PB7->RX
//	GPIO_PinAFConfig(GPIOB,GPIO_PinSource6,GPIO_AF_USART3);
//	GPIO_PinAFConfig(GPIOB,GPIO_PinSource7,GPIO_AF_USART3);
//	
//	GPIO_StructInit(&GPIO_InitStructure);    
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; 
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;			//���ù���
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//�ٶ�50MHz
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 			//���츴�����
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; 			
//	GPIO_Init(GPIOB,&GPIO_InitStructure); 
//	//����3�ܽ�����,PB10->TX,PB11->RX
//	GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_USART3);
//	GPIO_PinAFConfig(GPIOB,GPIO_PinSource11,GPIO_AF_USART3);
//	
//	GPIO_StructInit(&GPIO_InitStructure);    
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11; 
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;			//���ù���
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//�ٶ�50MHz
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 			//���츴�����
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; 			
//	GPIO_Init(GPIOB,&GPIO_InitStructure); 
	//����5�ܽ�����
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource12,GPIO_AF_UART5);				
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource2,GPIO_AF_UART5);
	GPIO_StructInit(&GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; 					//TXD5
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; 					//RXD5
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOD, &GPIO_InitStructure);             
//	//����6�ܽ�����,PC6->TX,PC7->RX
//	GPIO_PinAFConfig(GPIOC,GPIO_PinSource6,GPIO_AF_USART6);
//	GPIO_PinAFConfig(GPIOC,GPIO_PinSource7,GPIO_AF_USART6);
//	
//	GPIO_StructInit(&GPIO_InitStructure);    
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; 
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;			//���ù���
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//�ٶ�50MHz
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 			//���츴�����
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; 		
//	GPIO_Init(GPIOC,&GPIO_InitStructure); 
	//����7�ܽ�����,PE7->TX,PE8->RX
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource7,GPIO_AF_UART7);
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource8,GPIO_AF_UART7);
	
	GPIO_StructInit(&GPIO_InitStructure);    
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;			//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//�ٶ�50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 			//���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; 			
	GPIO_Init(GPIOE,&GPIO_InitStructure); 
//	//GPS POWER
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 ;     		
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;
//	GPIO_Init(GPIOD, &GPIO_InitStructure);				//RED LED
	//DTU POWER
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 ;     		
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//HARDWARE WDG
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 ;     		
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	//LCD POWER
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 ;     		
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOG, &GPIO_InitStructure);
}

/************************
**�������ƣ�EXTI_Configuratiuon
**�������ܣ������ⲿ�ж�
************************/
/*void EXTI_Configuration(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); 

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource4); //PD4 for ESC
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource5); //PD5 for UP
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource6); //PD6 for DOWN
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource7); //PD7 for OK
	EXTI_InitStructure.EXTI_Line = EXTI_Line4 | EXTI_Line5 | EXTI_Line6 | EXTI_Line7; //ѡ���ж���·4,5,6,7
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	 	//����Ϊ�ж����󣬷��¼�����
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

}*/

/**************************
�������ƣ�NVIC_Configuration
�������ܣ������ж�����
**************************/
void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	/* Configure the NVIC Preemption Priority Bits */  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel = RTC_WKUP_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//�����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	// Enable the USART1 Interrupt
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 5;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	// Enable the USART2 Interrupt 
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	//Enable the USART3 Interrupt
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	// Enable the UART4 Interrupt
	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	//Enable the UART5 Interrupt 
	NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	//Enable the USART6 Interrupt
	NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	//Enable the UART7 Interrupt 
	NVIC_InitStructure.NVIC_IRQChannel = UART7_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}
