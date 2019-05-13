#include "led.h"

void KEY_IO_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
 	
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PB,PA端口时钟
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;				 //继电器输出 端口配置
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
   GPIO_Init(GPIOB, &GPIO_InitStructure);	
}

void BEEP_ENABLE(void)   //BEEP开
{
	 GPIO_InitTypeDef  GPIO_InitStructure;
		
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PA端口时钟
		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;				 //端口配置
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	 GPIO_Init(GPIOA, &GPIO_InitStructure);					 
	 GPIO_SetBits(GPIOA,GPIO_Pin_11); 						 //PB.11 输出低
}


void BEEP_DISENABLE(void) //BEEP关
{
	 GPIO_InitTypeDef  GPIO_InitStructure;
		
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PA端口时钟
		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;				 // 端口配置
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	 GPIO_Init(GPIOA, &GPIO_InitStructure);	
	 GPIO_ResetBits(GPIOA,GPIO_Pin_11); 						 //PB.11 输出低
}

void DJ_Init(void) 
{
	 GPIO_InitTypeDef  GPIO_InitStructure;
		
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);	 //使能PA端口时钟
		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				 // 端口配置
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	 GPIO_Init(GPIOA, &GPIO_InitStructure);	
	 GPIO_ResetBits(GPIOA,GPIO_Pin_15); 						 //PB.11 输出低
	
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;				 // 端口配置
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	 GPIO_Init(GPIOB, &GPIO_InitStructure);	
	 GPIO_ResetBits(GPIOB,GPIO_Pin_11); 						 //PB.11 输出低
}

void LED_Init(void) 
{
	 GPIO_InitTypeDef  GPIO_InitStructure;
		
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PA端口时钟
		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;				 // 端口配置
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	 GPIO_Init(GPIOB, &GPIO_InitStructure);	
	 GPIO_ResetBits(GPIOB,GPIO_Pin_14); 						 //PB.11 输出低
	
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				 // 端口配置
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	 GPIO_Init(GPIOB, &GPIO_InitStructure);	
	 GPIO_ResetBits(GPIOB,GPIO_Pin_15); 						 //PB.11 输出低
}

