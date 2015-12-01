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
     Send_LCD(0xAA);            //---����ͷ
     Send_LCD(0x98);			//---�����룬�������ѡ���ֿ���ʾ
	 Send_LCD((x&0xFF00)>>8);   //---X����
	 Send_LCD((x&0xFF));		
	 Send_LCD((y&0xFF00)>>8);	//---Y������
	 Send_LCD((y&0xFF));
	 Send_LCD(0x20);			//---ѡ���ֿ⣺"SDWϵ��������ʾ�ն�ָ�" page=14  0x20=��׼�ֿ�
	 Send_LCD(0x90);			//---�ı���ʾģʽ�Լ����뷽ʽ��"SDWϵ��������ʾ�ն�ָ�" page=15
	 Send_LCD(0x03);	        //---��ʾ�ַ������С 0x03 12*24
	 Send_LCD(0x00);			//---�ַ���ʾ��ǰ��ɫ
	 Send_LCD(0x00);			//---�ַ���ʾ�ı���ɫ
	 Send_LCD(0x00);		    //---�ַ���������ʾ���
	 Send_LCD(0x00);
	 while(*Str)
	 {
	     Send_LCD(*Str++);		//---�����ַ���
	 }
	 Send_LCD(0xCC);			//---������
	 Send_LCD(0x33);
	 Send_LCD(0xC3);
	 Send_LCD(0x3C);
  }
}
void LcdDispValue(uint8_t u08_FontSize,uint16_t x, uint16_t y,const char *fmt,...)
{
	va_list ap;		//��ʼ��ָ��ɱ�����б��ָ��
	u8 Uart2LCDBuf[150];
	u8 *Str;
	if(g_u08_LCDStatus == LCDSON)
	{
		va_start(ap,fmt); 			//����һ���ɱ�����ĵ�ַ����ap����apָ��ɱ�����б�Ŀ�ʼ
		vsnprintf(Uart2LCDBuf,150,fmt,ap);	//������ap��fmt����ת���γɸ�ʽ���ַ�������������ʾ���ַ�����
		va_end(ap);
		Str = Uart2LCDBuf;

		Send_LCD(0xAA);            //---����ͷ
		Send_LCD(0x98);			//---�����룬�������ѡ���ֿ���ʾ
		Send_LCD((x&0xFF00)>>8);   //---X����
		Send_LCD((x&0xFF));		
		Send_LCD((y&0xFF00)>>8);	//---Y������
		Send_LCD((y&0xFF));
		
		Send_LCD(0x20 + u08_FontSize);	
		
		Send_LCD(0x90);			//---�ı���ʾģʽ�Լ����뷽ʽ��"SDWϵ��������ʾ�ն�ָ�" page=15
		Send_LCD(0x03);	        //---��ʾ�ַ������С 0x03 12*24
		Send_LCD(0x00);			//---�ַ���ʾ��ǰ��ɫ
		Send_LCD(0x00);			//---�ַ���ʾ�ı���ɫ
		Send_LCD(0x00);		    //---�ַ���������ʾ���
		Send_LCD(0x00);
		while(*Str)
		{
			Send_LCD(*Str++);
		}
		Send_LCD(0xCC);			//---������
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
