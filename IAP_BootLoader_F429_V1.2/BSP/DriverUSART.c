#include "DriverUSART.h"

//--LCD DTU
uint32_t g_u32_Usart1BaudRate=BAUD115200;   
uint32_t g_u32_Usart2BaudRate=BAUD19200;	  //
uint32_t g_u32_Usart3BaudRate=BAUD115200;	//for noise probe
uint32_t g_u32_Uart4BaudRate=BAUD115200;	//
uint32_t g_u32_Uart5BaudRate=BAUD9600;		//TX for LCD,RX for GPS
uint32_t g_u32_Usart6BaudRate=BAUD1200;		//光纤
uint32_t g_u32_Uart7BaudRate = BAUD115200; 	//for DTU


void USART_Configuration(void)
{ 
	USART_InitTypeDef USART_InitStructure;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);  //使能USART1的时钟
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);  
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);  
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE); 
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART7, ENABLE);
	
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	
//	/* Configure USART1 */
//	USART_InitStructure.USART_BaudRate = g_u32_Usart1BaudRate;
//	USART_Init(USART1, &USART_InitStructure);
//	/* Configure USART2 */
//	USART_InitStructure.USART_BaudRate = g_u32_Usart2BaudRate;
//	USART_Init(USART2, &USART_InitStructure);
//	/* Configure USART3 */
//	USART_InitStructure.USART_BaudRate = g_u32_Usart3BaudRate;
//	USART_Init(USART3, &USART_InitStructure);
//	/* Configure USART4 */
//	USART_InitStructure.USART_BaudRate = g_u32_Uart4BaudRate;
//	USART_Init(UART4, &USART_InitStructure);
	/* Configure USART5 */
	USART_InitStructure.USART_BaudRate = g_u32_Uart5BaudRate;
	USART_Init(UART5, &USART_InitStructure);
//	/* Configure USART6 */
//	USART_InitStructure.USART_BaudRate = g_u32_Usart6BaudRate;
//	USART_Init(USART6, &USART_InitStructure);
	/* Configure UART7 */
	USART_InitStructure.USART_BaudRate = g_u32_Uart7BaudRate;
	USART_Init(UART7, &USART_InitStructure);
		
//	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
//	//USART_ITConfig(USART1, USART_IT_TXE, ENABLE);
//	/* Enable USART2 Receive and Transmit interrupts */
//	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
//	//USART_ITConfig(USART2, USART_IT_TXE, ENABLE);
//	/* Enable USART3 Receive and Transmit interrupts */
//	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
//	//USART_ITConfig(USART3, USART_IT_TXE, ENABLE);
//	/* Enable UART4 Receive and Transmit interrupts */
//	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
//	//USART_ITConfig(UART4, USART_IT_TXE, ENABLE);
	/* Enable UART5 Receive and Transmit interrupts */
	USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);
	//USART_ITConfig(UART5, USART_IT_TXE, ENABLE);
//	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);
	//Enable UART7 不开启7中断
	USART_ITConfig(UART7, USART_IT_RXNE, DISABLE);
	/* Enable the USART1,2,3,4,5 */
//	USART_Cmd(USART1, ENABLE);
//	USART_Cmd(USART2, ENABLE);
//	USART_Cmd(USART3, ENABLE);
//	USART_Cmd(UART4, ENABLE);
	USART_Cmd(UART5, ENABLE);
//	USART_Cmd(USART6, ENABLE);
	USART_Cmd(UART7, ENABLE);
	
//	USART_ClearFlag(USART1, USART_FLAG_TC);
//	USART_ClearFlag(USART2, USART_FLAG_TC);
//	USART_ClearFlag(USART3, USART_FLAG_TC);
//	USART_ClearFlag(UART4, USART_FLAG_TC);
	USART_ClearFlag(UART5, USART_FLAG_TC);
//	USART_ClearFlag(USART6, USART_FLAG_TC);
//	USART_ClearFlag(UART7, USART_FLAG_TC);
}
/*************************************************
  Function       :SendtoUsart6
  Description    :
  Input          :u08_Date
  Output         :
  Return         :void
*************************************************/
void Send2Usart6(u8 u08_Date)
{
	USART_ClearFlag(USART6, USART_FLAG_TC);
	USART_SendData(USART6, u08_Date);
	while(USART_GetFlagStatus(USART6, USART_FLAG_TXE)==RESET);
	
}
/*************************************************
  Function       :SendtoUsart3
  Description    :
  Input          :u08_Date
  Output         :
  Return         :void
*************************************************/
void Send2Usart3(u8 u08_Date)
{
	USART_ClearFlag(USART3, USART_FLAG_TC);
	USART_SendData(USART3, u08_Date);
	while(USART_GetFlagStatus(USART3, USART_FLAG_TXE)==RESET);
	
}
void Send2Usart1(u8 u08_Date)
{
	USART_ClearFlag(USART1, USART_FLAG_TC);
	USART_SendData(USART1, u08_Date);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE)==RESET);
	
}


//////////////////////////////////////////////////////////////////
//加入以下代码,支持printf函数,而不需要选择use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       
//定义_sys_exit()以避免使用半主机模式    
_sys_exit(int x) 
{ 
	x = x; 
} 
//重定义fputc函数 
int fputc(int ch, FILE *f)
{      
	while((UART7->SR&0X40)==0);//循环发送,直到发送完毕   1
    UART7->DR = (u8) ch;      
	return ch;
}
#endif 


