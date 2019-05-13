#ifndef __LCD1602_H
#define __LCD1602_H
#include "delay.h"
#include "sys.h"

/*复位端口设置*/
#define      LCD1602_RS0           GPIOC->BRR  = 0x00002000 //复位  PC.13

#define      LCD1602_RW0           GPIOC->BRR  = 0x00004000 //复位  PC.14
#define      LCD1602_EN0           GPIOC->BRR  = 0x00008000 //复位  PC.15

/*设置/复位端口设置*/
#define      LCD1602_RS1           GPIOC->BSRR = 0x00002000 //置位  PC.13

#define      LCD1602_RW1           GPIOC->BSRR = 0x00004000 //置位  PC.14
#define      LCD1602_EN1           GPIOC->BSRR = 0x00008000 //置位  PC.15

 
void LCD_Init(void); 

void LCD_Clear(void); 
 
void  LCD_Check_Busy(void); 
 
void LCD_Write_Com(unsigned char com); 
 
void LCD_Write_Data(unsigned char Data); 
 
void LCD_Write_String(unsigned char x,unsigned char y,unsigned char *s);
	
void LCD_Write_Char(unsigned char x,unsigned char y,unsigned char Data); 


u8 BitReversed(u8 x);
 
#endif



