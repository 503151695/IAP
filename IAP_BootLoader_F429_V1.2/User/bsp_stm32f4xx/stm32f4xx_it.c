/**
  ******************************************************************************
  * @file    Template/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    20-September-2013
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#include "myBSP.h"
#include "iap.h"
/*
		异步分频，秒中断使用
*/
void RTC_WKUP_IRQHandler(void)
{

	if (RTC_GetFlagStatus(RTC_FLAG_WUTF) == SET)	//WK_UP中断?
	{ 
		RTC_ClearFlag(RTC_FLAG_WUTF);				//清除中断标志
	}   
	EXTI_ClearITPendingBit(EXTI_Line22);			//清除中断线22的中断标志 
}
/*******************************
*函数名称：UART1_IRQHandler
*函数功能：中断服务程序
*输入参数：无						  
*输出参数：无
********************************/
void USART1_IRQHandler(void)
{
//	uint8_t temp;
	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
//		temp=USART_ReceiveData(USART1);
		if(USART_GetFlagStatus(USART1, USART_FLAG_ORE)==SET)
		{
			USART_ClearFlag(USART1, USART_FLAG_ORE);
			USART_ReceiveData( USART1);
		}
	}
	if(USART_GetFlagStatus(USART1, USART_FLAG_ORE)==SET)
	{
		USART_ClearFlag(USART1, USART_FLAG_ORE);
		USART_ReceiveData( USART1);
	}
	
}
/*******************************
*函数名称：UART1_IRQHandler
*函数功能：中断服务程序
*输入参数：无						  
*输出参数：无
********************************/
void USART2_IRQHandler(void)
{
//	uint8_t temp;
	if (USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
	{
		USART_ClearITPendingBit(USART2, USART_IT_RXNE);
//		temp=USART_ReceiveData(USART2);
		if(USART_GetFlagStatus(USART2, USART_FLAG_ORE)==SET)
		{
			USART_ClearFlag(USART2, USART_FLAG_ORE);
			USART_ReceiveData( USART2);
		}
	}
	if(USART_GetFlagStatus(USART2, USART_FLAG_ORE)==SET)
	{
		USART_ClearFlag(USART2, USART_FLAG_ORE);
		USART_ReceiveData( USART2);
	}
}
/*******************************
*函数名称：UART3_IRQHandler
*函数功能：中断服务程序
*输入参数：无						  
*输出参数：无
********************************/
void USART3_IRQHandler(void)
{
//	uint8_t temp;
	if (USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
	{
		USART_ClearITPendingBit(USART3, USART_IT_RXNE);
//		temp = USART_ReceiveData(USART3);
		if(USART_GetFlagStatus(USART3, USART_FLAG_ORE)==SET)
		{
			USART_ClearFlag(USART3, USART_FLAG_ORE);
			USART_ReceiveData(USART3);
		}
	}
	if(USART_GetFlagStatus(USART3, USART_FLAG_ORE)==SET)
	{
		USART_ClearFlag(USART3, USART_FLAG_ORE);
		USART_ReceiveData(USART3);
	}
}
/*******************************
*函数名称：UART4_IRQHandler
*函数功能：中断服务程序
*输入参数：无						  
*输出参数：无
********************************/
void UART4_IRQHandler(void)
{
//	uint8_t temp;
	if (USART_GetITStatus(UART4, USART_IT_RXNE) != RESET)
	{
		USART_ClearITPendingBit(UART4, USART_IT_RXNE);
//		temp=USART_ReceiveData(UART4);
		if (USART_GetFlagStatus(UART4, USART_FLAG_ORE)==SET)
		{
					USART_ClearFlag(UART4, USART_FLAG_ORE);
					USART_ReceiveData(UART4);
		}
	}
	if (USART_GetFlagStatus(UART4, USART_FLAG_ORE)==SET)
	{
		USART_ClearFlag(UART4, USART_FLAG_ORE);
		USART_ReceiveData( UART4);
	}

}
/**
  * @brief  This function handles  UART5_IRQHandler
  * @param  None
  * @retval None
  */
void UART5_IRQHandler(void)
{
//	uint8_t u08_Temp;
	if (USART_GetITStatus(UART5, USART_IT_RXNE) != RESET)
	{
		USART_ClearITPendingBit(UART5, USART_IT_RXNE);
//		u08_Temp = USART_ReceiveData(UART5);
		if(USART_GetFlagStatus(UART5, USART_FLAG_ORE)==SET)
		{
			USART_ClearFlag(UART5, USART_FLAG_ORE);
			USART_ReceiveData(UART5);
		}
	}
	if(USART_GetFlagStatus(UART5, USART_FLAG_ORE)==SET)
	{
		USART_ClearFlag(UART5, USART_FLAG_ORE);
		USART_ReceiveData(UART5);
	}
}
/*******************************
*函数名称：USART6_IRQHandler
*函数功能：中断服务程序
*输入参数：无						  
*输出参数：无
********************************/
void USART6_IRQHandler(void)
{
//	uint8_t temp;

	if (USART_GetITStatus(USART6, USART_IT_RXNE) != RESET)
	{
		USART_ClearITPendingBit(USART6, USART_IT_RXNE);
//		temp=USART_ReceiveData(USART6);
		if(USART_GetFlagStatus(USART6, USART_FLAG_ORE)==SET)
		{
				USART_ClearFlag(USART6, USART_FLAG_ORE);
				USART_ReceiveData(USART6);
		}
	}
	if(USART_GetFlagStatus(USART6, USART_FLAG_ORE)==SET)
	{
		USART_ClearFlag(USART6, USART_FLAG_ORE);
		USART_ReceiveData(USART6);
	}
}
/*******************************
*函数名称：UART7_IRQHandler
*函数功能：中断服务程序
*输入参数：无						  
*输出参数：无
********************************/

extern uint8_t usart_buf[1024+8];
//数据长度(2B) 数据(1KB) 序号(2B) [CRC(4B)]
extern uint16_t buf_cnt;
uint8_t usart_buf1;
uint16_t buf_cnt1;

void UART7_IRQHandler(void)
{
	uint8_t temp = 0;
	if (USART_GetITStatus(UART7, USART_IT_RXNE) != RESET)
	{			
		temp = (uint8_t)USART_ReceiveData(UART7);
		if(buf_cnt < (1024+8)  && ((buf_cnt & 0x8000) != 0x8000))
		{
			usart_buf[buf_cnt++] = temp;
		}
		else 
		{ 
			buf_cnt |= 0x8000;
		}
		
	}
	if (USART_GetFlagStatus(UART7, USART_FLAG_ORE)==SET)
	{
		USART_ClearFlag(UART7, USART_FLAG_ORE);
		USART_ReceiveData( UART7);
	}

}
/** @addtogroup Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {

  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}


/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f429_439xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/


/**
  * @}
  */ 


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
