#include "LCD1602.h"
#include "delay.h"
#include "sys.h"


/*
函数名：BitReversed
功能：把8位数按位逆序
*/
u8 BitReversed(u8 x)
{
	u8 temp[8];
	u8 i = 0;
	u8 j = 7;
	u8 result = 0;
	for(i = 0;i<8;i++)
	{
		temp[i] = (x>>i)&0x01;
	}
	for(i = 0;i<8;i++)
	{
		result = result|(temp[j]<<(i));
		j--;
	}	
	return result;
}


/*
函数名：LCD_Check_Busy
功能：测忙
*/
void  LCD_Check_Busy(void)  
{
  LCD1602_RS0;				//RS置0
	delay_us(1);
  LCD1602_RW1;    		//RW置1
	delay_us(1);
  LCD1602_EN0;				//EN置0
	delay_us(1);
  GPIO_Write(GPIOC,0Xff);    
	delay_ms(1);
  LCD1602_EN1;    		//EN置1
	delay_us(100);
}

/*
函数名：LCD_Write_Com
功能：写命令
*/
void LCD_Write_Com(unsigned char com) 
{               
  LCD1602_RS0;																							//RS置0
	delay_us(1);
  LCD1602_RW0;
  delay_us(1);																							//RW置1
  LCD1602_EN1;                    													//EN置1
	delay_us(1);
	com = BitReversed(com);
  GPIO_Write(GPIOA,(GPIO_ReadOutputData(GPIOA)&0XFF00)+com);                   
	delay_us(100);
  LCD1602_EN0;
}

/*
函数名：LCD_Write_Data
功能：写数据
*/
void LCD_Write_Data(unsigned char Data) 
{                                    
  LCD1602_RS1;                    //RS置1
	delay_us(1);
  LCD1602_RW0;										//RW置0
  delay_us(1);	
  LCD1602_EN1;                    //EN置1
	delay_us(1);
	Data = BitReversed(Data);
  GPIO_Write(GPIOA,(GPIO_ReadOutputData(GPIOA)&0XFF00)+Data);
	delay_us(100);
  LCD1602_EN0;
}


/*
函数名：LCD_Write_String
功能：写入字符串
*/
void LCD_Write_String(unsigned char x,unsigned char y,unsigned char *s) 
{     
	if (y == 0) 
 	{	
		LCD_Write_Com(0x80 + x);     
 	}
	else 
 	{     
		LCD_Write_Com(0xC0 + x);     
 	}        
	while (*s) 
 	{     
		LCD_Write_Data( *s);     
		s++;     
 	}
}

/*
函数名：LCD_Write_Char
功能：写入字符
*/
void LCD_Write_Char(unsigned char x,unsigned char y,unsigned char Data) 
{     
	if (y == 0) 
 	{     
		LCD_Write_Com(0x80 + x);     
 	}    
	else 
 	{     
		LCD_Write_Com(0xC0 + x);     
 	}        
	LCD_Write_Data( Data);  
}
 
 
/*
函数名：LCD_Clear
功能：清屏
*/
void LCD_Clear(void) 
{ 
	LCD_Write_Com(0x01); 
	delay_ms(5);
}


/*
函数名：LCD_Init
功能：LCD初始化
*/
void LCD_Init(void) 
{
	GPIO_InitTypeDef GPIO_InitStructure;  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB , ENABLE);  //开启GPIOA GPIOB GPIOC时钟
	//LCD1602 D0~D7端口
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 |
	GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //输出速度50MHZ
	GPIO_Init(GPIOA, &GPIO_InitStructure); //初始化GPIOA
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 |GPIO_Pin_14|GPIO_Pin_15;  // LCD1602 RS-RW-EN端口
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   //输出速度50MHZ
	GPIO_Init(GPIOC, &GPIO_InitStructure);   //GPIOC
	
	LCD_Write_Com(0x38);
	delay_ms(5);  
	LCD_Write_Com(0x08);    /*显示关闭*/
	delay_ms(5); 	
	LCD_Write_Com(0x01);    /*显示清屏*/
	delay_ms(5); 	
	LCD_Write_Com(0x06);    /*显示光标移动设置*/ 
	delay_ms(5); 
	LCD_Write_Com(0x0C);    /*显示开及光标设置*/
	delay_ms(5); 
}
   



   


