#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 

#define 	KEY1 PBin(7)
#define 	KEY2 PBin(8)
#define 	KEY3 PBin(9)

#define 	BEEP PAout(11)
#define 	DJ PAout(15)
#define 	CL_DJ PBout(11)

#define 	LED1 PBout(14)
#define 	LED2 PBout(15)

void LED_Init(void);//初始化
void BEEP_ENABLE(void);   //BEEP开
void BEEP_DISENABLE(void);   //BEEP开
void KEY_IO_Init(void);
void DJ_Init(void);
void LED_Init(void);
		 				    
#endif
