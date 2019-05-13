#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
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

void LED_Init(void);//��ʼ��
void BEEP_ENABLE(void);   //BEEP��
void BEEP_DISENABLE(void);   //BEEP��
void KEY_IO_Init(void);
void DJ_Init(void);
void LED_Init(void);
		 				    
#endif
