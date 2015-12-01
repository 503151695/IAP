#ifndef _BSP_H_
#define _BSP_H_
#include "stm32f4xx.h"   
#include "LCD.h"
#include "SysFunc.h"
#include "DriverUSART.h"
#include "Timer.h"
#include "CRC.h"


//LED
#define GREEN_LED_ON         	GPIO_SetBits(GPIOD,GPIO_Pin_15)
#define GREEN_LED_OFF        	GPIO_ResetBits(GPIOD,GPIO_Pin_15)

#define RED_LED_ON         		GPIO_SetBits(GPIOG,GPIO_Pin_3)
#define RED_LED_OFF        		GPIO_ResetBits(GPIOG,GPIO_Pin_3)

#define DTU_ON    				GPIO_ResetBits(GPIOA,GPIO_Pin_8)
#define DTU_OFF   				GPIO_SetBits(GPIOA,GPIO_Pin_8)

#define LCD_ON 					GPIO_SetBits(GPIOG,GPIO_Pin_1)
#define LCD_OFF					GPIO_ResetBits(GPIOG,GPIO_Pin_1)

#define HARDWARE_WDG_H			GPIO_SetBits(GPIOD,GPIO_Pin_10)
#define HARDWARE_WDG_L		    GPIO_ResetBits(GPIOD,GPIO_Pin_10)


 
extern void BSPInit(void);
extern void Time_init(void);
extern void ADC_Configuration(void);
extern void EXTI_Configuration(void);
extern void GPIO_Configuration(void);
extern void NVIC_Configuration(void);
extern void IWDG_Configuration(void);
extern void SysTick_init(void);
extern void SysVarInit(void);
extern void BAT_ADC(void);


#endif
