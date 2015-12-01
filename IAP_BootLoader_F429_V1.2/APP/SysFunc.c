/************************************************************
  Copyright (C), 1988-2015, Safety Tech. Co., Ltd.
  文 件 名: SysFunc.c
  作    者: 马云玺
  描    述: 通用函数
  修改历史: 
      <作者>   <时间>   		<版本>   			<描述>
      马云玺  2015/4/2     1.0     			建立模块  
***********************************************************/
#include "SysFunc.h"

static char table[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
/*********************************  
* 函数名称：Float2Char   
* 描    述：将浮点数转换为字符 
* 输    入：str:输出字符串指针 number：要转换的数 g:整数部位长度	l：小数点位长度
* 输    出：无   
***********************************/ 
 void Float2Char(char *str, float number, uint8_t g, uint8_t l)
{
	uint8_t i,index;
	char intstr[10],floatstr[10];
	int temp = number/1;
	float t2 = 0.0;
	
	/*********转换整数部分********/
	index = 0;
	for (i = 1; i <= g; i++)
	{
		if (temp == 0)
			intstr[g - i] = table[0];
		else
			intstr[g - i] = table[temp % 10];
		temp = temp / 10;
	}
	for (i = 0; i < g; i++)
	{
			if (intstr[i] == '0')
			{
				 index++;
			}
			else
			{
				break;	
			}	
	}
	if (index == g)
	{
		index = index - 1;
	}
	memcpy(str,&intstr[index],g - index);
	str[g - index] = '.';
	
	/*********转换小数部分********/
	temp = 0;
	t2 = number;
	for(i = 0; i < l; i++)
	{
		temp = t2*10;
		floatstr[i] = table[temp % 10];
		t2 = t2*10;
	}
	memcpy(&str[g - index + 1],floatstr,l);		
	str[g - index + 1 + l] = '\0';
}
void Int2Char(int number,unsigned char *str, uint8_t g)
{
	uint8_t i,index;
	char intstr[10];
	int temp = number/1;
	
	index = 0;
	for (i = 1; i <= g; i++)
	{
		if (temp == 0)
			intstr[g - i] = table[0];
		else
			intstr[g - i] = table[temp % 10];
		temp = temp / 10;
	}
	for (i = 0; i < g; i++)
	{
			if (intstr[i] == '0')
			{
				 index++;
			}
			else
			{
				break;	
			}	
	}
	if (index == g)	//
	{
		index = index - 1;
	}
	memcpy(str,&intstr[index],g - index);
	str[g - index] = '\0';
}

void Delay_ms(unsigned int time)
{    
   unsigned int i = 0;  
   while(time--)
   {
      i = 72000;  //自己定义
      while(i--) ;    
   }
}


