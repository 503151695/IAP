2015.7.2
搭架基本架构，任务能运行
1.解决光纤串口的数据接收问题：根据公式，串口6的Fclk=84M，所以串口6的最小波特率= 84M/16/0XFFF = 1282,我将串口6波特率设置1200，的确不行
修改为#define PLL_N      320
则：
系统时钟SYSCLK = 320 / 2 = 160MHz
RCC_CFGR_PPRE2_DIV8
则：
PCLK2 = HCLK / 4 = 40MHz
2015.7.3
1.重启后RTC时间不能保持
解决办法：if(RTC_ReadBackupRegister(RTC_BKP_DR0)!=0x5050)修改为if(RTC_ReadBackupRegister(RTC_BKP_DR0)!=0x32F2)	
2.电压采集成功,采集为外部供电的电压
2015.7.6
温湿度采集完成，注意修改时序中的时间
2015.7.10
1.串口3 for noise测试通过
2.串口1(TTL) for zigbee测试通过


2015.9.7
bootloader功能实现

2015.10.28 版本V1.1  

1、修改适配到硬件版本STT01V2.2 增加硬件喂狗功能
2、修改界面显示
3、对程序整体优化

2015.11.2 版本V1.2

1、增加网络连接  








