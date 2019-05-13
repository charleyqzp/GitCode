#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

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
