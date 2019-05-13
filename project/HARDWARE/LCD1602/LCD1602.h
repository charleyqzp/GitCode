#ifndef __LCD1602_H
#define __LCD1602_H
#include "delay.h"
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
/*-----------------------------------------------
  ���ƣ�LCD1602
  ��̳��www.doflye.net
  ��д��shifang
  ���ڣ�2009.5
  �޸ģ���
  ���ݣ�ͨ����׼����̬��ʾ�ַ�
  ���Ŷ������£�1-VSS 2-VDD 3-V0 4-RS 5-R/W 6-E 7-14 DB0-DB7 15-BLA 16-BLK
------------------------------------------------*/

//======��λ�˿�����=
#define      LCD1602_RS0           GPIOC->BRR  = 0x00002000 //��λ  PC.13
//#define      LCD1602_RS0           GPIOB->BRR  = 0x00002000 //��λ  PB.13

#define      LCD1602_RW0           GPIOC->BRR  = 0x00004000 //��λ  PC.14
#define      LCD1602_EN0           GPIOC->BRR  = 0x00008000 //��λ  PC.15

//========����/��λ�˿�����==
#define      LCD1602_RS1           GPIOC->BSRR = 0x00002000 //��λ  PC.13
//#define      LCD1602_RS1           GPIOB->BSRR = 0x00002000 //��λ  PB.13

#define      LCD1602_RW1           GPIOC->BSRR = 0x00004000 //��λ  PC.14
#define      LCD1602_EN1           GPIOC->BSRR = 0x00008000 //��λ  PC.15

 
void LCD_Init(void); 

void LCD_Clear(void); 
 
void  LCD_Check_Busy(void); 
 
void LCD_Write_Com(unsigned char com); 
 
void LCD_Write_Data(unsigned char Data); 
 
void LCD_Write_String(unsigned char x,unsigned char y,unsigned char *s);
	
void LCD_Write_Char(unsigned char x,unsigned char y,unsigned char Data); 

void LCD1602_write_long(unsigned char x,unsigned char y,u32 data,unsigned char num) ;

u8 BitReversed(u8 x);
 
#endif



