/************************************************************
  Copyright (C), 1988-2015, Safety Tech. Co., Ltd.
  �� �� ��: SysFunc.c
  ��    ��: ������
  ��    ��: ͨ�ú���
  �޸���ʷ: 
      <����>   <ʱ��>   		<�汾>   			<����>
      ������  2015/4/2     1.0     			����ģ��  
***********************************************************/
#include "SysFunc.h"

static char table[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
/*********************************  
* �������ƣ�Float2Char   
* ��    ������������ת��Ϊ�ַ� 
* ��    �룺str:����ַ���ָ�� number��Ҫת������ g:������λ����	l��С����λ����
* ��    ������   
***********************************/ 
 void Float2Char(char *str, float number, uint8_t g, uint8_t l)
{
	uint8_t i,index;
	char intstr[10],floatstr[10];
	int temp = number/1;
	float t2 = 0.0;
	
	/*********ת����������********/
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
	
	/*********ת��С������********/
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
      i = 72000;  //�Լ�����
      while(i--) ;    
   }
}


