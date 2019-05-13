#include "led.h"
#include "delay.h"
#include "sys.h"
#include "adc.h"
#include "usart1.h"
#include "LCD1602.h"
#include "string.h"
#include "stdio.h"

int main(void)
{	
	unsigned int test=0;
	u16 test_adc, adc_add_value, adc_value=0;
	unsigned char adc_cnt=0;
	
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�                                                                               
	Usart1_Init(9600);
	delay_ms(300);
	LCD_Init();          // 1602��ʼ�� 
	Adc_Init();
	LCD_Write_String(0,0,"Heartbeats:     ");
	LCD_Write_String(0,1,"                ");
	while(1)
	{
		  if(test++ > 100)
			{
				test = 0;
				test_adc = Get_Adc_Average(ADC_Channel_9,20);
				adc_add_value += test_adc;
				adc_cnt++;
				if(adc_cnt >= 5)
				{
					adc_value = adc_add_value / 5;
					adc_value =(adc_value * 3.3)	* 40 / 4095;
					if(adc_value >= 100) adc_value = 0;
					else if(adc_value <= 65) adc_value = 0;
						
					adc_cnt = 0; 
					adc_add_value = 0;
				}
				LCD_Write_Char(12,0,adc_value/10+0x30);
				LCD_Write_Char(13,0,adc_value%10+0x30);
			}				
			delay_ms(1);
	}
}

