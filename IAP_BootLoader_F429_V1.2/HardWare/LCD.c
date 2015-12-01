#include "LCD.h"
#include <stdarg.h>

uint8_t g_u08_LCDStatus = LCDSON;
u8 g_u08_DisplayCnt;


void Send_LCD(unsigned char ch)
{
    USART_SendData(UART5,ch);
    while(USART_GetFlagStatus(UART5, USART_FLAG_TXE) == RESET);
}
/*************************************************
  Function:        LCD_DISPLAY
  Description:	   TFT display
  Input:           x:x-axis of TFT
                   y:y-axis of TFT
	               *Str:point of the displayed character
  Output:
  Return:          void
*************************************************/
void LCD_DISPLAY(uint16_t x, uint16_t y, char *Str)
{
  if(g_u08_LCDStatus == LCDSON)
  {
     Send_LCD(0xAA);            //---命令头
     Send_LCD(0x98);			//---命令码，任意点阵，选择字库显示
	 Send_LCD((x&0xFF00)>>8);   //---X坐标
	 Send_LCD((x&0xFF));		
	 Send_LCD((y&0xFF00)>>8);	//---Y轴坐标
	 Send_LCD((y&0xFF));
	 Send_LCD(0x20);			//---选择字库："SDW系列智能显示终端指令集" page=14  0x20=标准字库
	 Send_LCD(0x90);			//---文本显示模式以及编码方式："SDW系列智能显示终端指令集" page=15
	 Send_LCD(0x03);	        //---显示字符点阵大小 0x03 12*24
	 Send_LCD(0x00);			//---字符显示的前景色
	 Send_LCD(0x00);			//---字符显示的背景色
	 Send_LCD(0x00);		    //---字符串数据显示间隔
	 Send_LCD(0x00);
	 while(*Str)
	 {
	     Send_LCD(*Str++);		//---发送字符串
	 }
	 Send_LCD(0xCC);			//---结束码
	 Send_LCD(0x33);
	 Send_LCD(0xC3);
	 Send_LCD(0x3C);
  }
}
void LcdDispValue(uint8_t u08_FontSize,uint16_t x, uint16_t y,const char *fmt,...)
{
	va_list ap;		//初始化指向可变参数列表的指针
	u8 Uart2LCDBuf[150];
	u8 *Str;
	if(g_u08_LCDStatus == LCDSON)
	{
		va_start(ap,fmt); 			//将第一个可变参数的地址赋给ap，即ap指向可变参数列表的开始
		vsnprintf(Uart2LCDBuf,150,fmt,ap);	//将参数ap和fmt进行转化形成格式化字符串，即可以显示的字符串。
		va_end(ap);
		Str = Uart2LCDBuf;

		Send_LCD(0xAA);            //---命令头
		Send_LCD(0x98);			//---命令码，任意点阵，选择字库显示
		Send_LCD((x&0xFF00)>>8);   //---X坐标
		Send_LCD((x&0xFF));		
		Send_LCD((y&0xFF00)>>8);	//---Y轴坐标
		Send_LCD((y&0xFF));
		
		Send_LCD(0x20 + u08_FontSize);	
		
		Send_LCD(0x90);			//---文本显示模式以及编码方式："SDW系列智能显示终端指令集" page=15
		Send_LCD(0x03);	        //---显示字符点阵大小 0x03 12*24
		Send_LCD(0x00);			//---字符显示的前景色
		Send_LCD(0x00);			//---字符显示的背景色
		Send_LCD(0x00);		    //---字符串数据显示间隔
		Send_LCD(0x00);
		while(*Str)
		{
			Send_LCD(*Str++);
		}
		Send_LCD(0xCC);			//---结束码
		Send_LCD(0x33);
		Send_LCD(0xC3);
		Send_LCD(0x3C);
	}
}
void LCD_DISPLAY1(uint16_t x, uint16_t y,unsigned char * Str)//large charact
{
  if(g_u08_LCDStatus==LCDSON)
  {
     Send_LCD(0xAA);
     Send_LCD(0x98);
	 Send_LCD((x&0xFF00)>>8);
	 Send_LCD((x&0xFF));
	 Send_LCD((y&0xFF00)>>8);
	 Send_LCD((y&0xFF));
	 Send_LCD(0x23);
	 Send_LCD(0x90);
	 Send_LCD(0x03);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 while(*Str)
	 {
	    Send_LCD(*Str++);
	 }
	 Send_LCD(0xCC);
	 Send_LCD(0x33);
	 Send_LCD(0xC3);
	 Send_LCD(0x3C);
  }
}

void LCD_DISPLAY2(uint16_t x, uint16_t y, unsigned char * Str)
{
if(g_u08_LCDStatus==LCDSON)
{
	Send_LCD(0xAA);
     Send_LCD(0x98);
	 Send_LCD((x&0xFF00)>>8);
	 Send_LCD((x&0xFF));
	  Send_LCD((y&0xFF00)>>8);
	 Send_LCD((y&0xFF));
	 Send_LCD(0x20);
	 Send_LCD(0x90);
	 Send_LCD(0x03);
	 Send_LCD(0xff);
	 Send_LCD(0xff);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 while(*Str)
	 	{Send_LCD(*Str++);
	 	}
	 Send_LCD(0xCC);
	 Send_LCD(0x33);
	 Send_LCD(0xC3);
	 Send_LCD(0x3C);
}
}
void LCD_DISPLAY_LENGTH(uint16_t x, uint16_t y, uint8_t length, unsigned char * Str)
{
	if(g_u08_LCDStatus==LCDSON)
	{
	Send_LCD(0xAA);
     Send_LCD(0x98);
	 Send_LCD((x&0xFF00)>>8);
	 Send_LCD((x&0xFF));
	  Send_LCD((y&0xFF00)>>8);
	 Send_LCD((y&0xFF));
	 Send_LCD(0x20);
	 Send_LCD(0x90);
	 Send_LCD(0x03);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 while(length--)
	 {
	 	Send_LCD(*Str++);
	 }
	 Send_LCD(0xCC);
	 Send_LCD(0x33);
	 Send_LCD(0xC3);
	 Send_LCD(0x3C);
}
}
void LCD_DISPLAY1_LENGTH(uint16_t x, uint16_t y, uint8_t length, unsigned char * Str)
{
if(g_u08_LCDStatus==LCDSON)
{
Send_LCD(0xAA);
     Send_LCD(0x98);
	 Send_LCD((x&0xFF00)>>8);
	 Send_LCD((x&0xFF));
	  Send_LCD((y&0xFF00)>>8);
	 Send_LCD((y&0xFF));
	 Send_LCD(0x23);
	 Send_LCD(0x90);
	 Send_LCD(0x03);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 while(length--)
	 	{Send_LCD(*Str++);
	 	}
	 Send_LCD(0xCC);
	 Send_LCD(0x33);
	 Send_LCD(0xC3);
	 Send_LCD(0x3C);
}
}
void LCD_DISPLAY2_LENGTH(uint16_t x, uint16_t y, uint8_t length, unsigned char * Str)
{
if(g_u08_LCDStatus==LCDSON)
{
Send_LCD(0xAA);
     Send_LCD(0x98);
	 Send_LCD((x&0xFF00)>>8);
	 Send_LCD((x&0xFF));
	  Send_LCD((y&0xFF00)>>8);
	 Send_LCD((y&0xFF));
	 Send_LCD(0x20);
	 Send_LCD(0x90);
	 Send_LCD(0x03);
	 Send_LCD(0xff);
	 Send_LCD(0xff);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 while(length--)
	 	{Send_LCD(*Str++);
	 	}
	 Send_LCD(0xCC);
	 Send_LCD(0x33);
	 Send_LCD(0xC3);
	 Send_LCD(0x3C);
}
}
void LCD_CLEAR_LENGTH(uint16_t x, uint16_t y, uint8_t length)
{
   if(g_u08_LCDStatus==LCDSON)
   {
     Send_LCD(0xAA);
     Send_LCD(0x98);
	 Send_LCD((x&0xFF00)>>8);
	 Send_LCD((x&0xFF));
	 Send_LCD((y&0xFF00)>>8);
	 Send_LCD((y&0xFF));
	 Send_LCD(0x20);
	 Send_LCD(0x90);
	 Send_LCD(0x03);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 while(length--)
	 {
	    Send_LCD(0x20);
	 }
	 Send_LCD(0xCC);
	 Send_LCD(0x33);
	 Send_LCD(0xC3);
	 Send_LCD(0x3C);
  }
}
void LCD_CLEAR_LENGTH1(uint16_t x, uint16_t y, uint8_t length)
{
   if(g_u08_LCDStatus==LCDSON)
   {
     Send_LCD(0xAA);
     Send_LCD(0x98);
	 Send_LCD((x&0xFF00)>>8);
	 Send_LCD((x&0xFF));
	 Send_LCD((y&0xFF00)>>8);
	 Send_LCD((y&0xFF));
	 Send_LCD(0x23);
	 Send_LCD(0x90);
	 Send_LCD(0x03);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 Send_LCD(0x00);
	 while(length--)
	 {
	    Send_LCD(0x20);
	 }
	 Send_LCD(0xCC);
	 Send_LCD(0x33);
	 Send_LCD(0xC3);
	 Send_LCD(0x3C);
  }
}
void LCD_CLEAR_ALL(void)
{
   if(g_u08_LCDStatus==LCDSON)
   {
     Send_LCD(0xAA);
     Send_LCD(0x52);
	 Send_LCD(0xCC);
	 Send_LCD(0x33);
	 Send_LCD(0xC3);
	 Send_LCD(0x3C);
  }
}
