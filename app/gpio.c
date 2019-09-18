#include "gpio.h"
	
u16 testsram[250000] __attribute__((at(0X6b000000)));//测试用数组
u16 ts;

void GPIO__Init(void){
	
		GPIO_InitTypeDef  GPIO_InitStructure;

		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_6|
																	GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用输出;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
		GPIO_Init(GPIOC, &GPIO_InitStructure);	
	
		GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM3);
		GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM3); 
		GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM3);
		GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_TIM3); 
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//复用输出;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(GPIOD, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//复用输出;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(GPIOD, &GPIO_InitStructure);

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14|
																	GPIO_Pin_5|GPIO_Pin_7;	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用输出;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(GPIOD, &GPIO_InitStructure);
		
		
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|
																	GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|
																	GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14
																	|GPIO_Pin_11|GPIO_Pin_7;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用输出;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(GPIOF, &GPIO_InitStructure);		
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_15 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用输出;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(GPIOE, &GPIO_InitStructure);		
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用输出;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(GPIOG, &GPIO_InitStructure);		
		
		GPIO_PinAFConfig(GPIOF,GPIO_PinSource0,GPIO_AF_FSMC);//PF0,AF12
		GPIO_PinAFConfig(GPIOF,GPIO_PinSource1,GPIO_AF_FSMC);//PF1,AF12
		GPIO_PinAFConfig(GPIOF,GPIO_PinSource2,GPIO_AF_FSMC);//PF2,AF12
		GPIO_PinAFConfig(GPIOF,GPIO_PinSource3,GPIO_AF_FSMC);//PF3,AF12
		GPIO_PinAFConfig(GPIOF,GPIO_PinSource4,GPIO_AF_FSMC);//PF4,AF12
		GPIO_PinAFConfig(GPIOF,GPIO_PinSource5,GPIO_AF_FSMC);//PF5,AF12
		GPIO_PinAFConfig(GPIOF,GPIO_PinSource12,GPIO_AF_FSMC);//PF12,AF12
		GPIO_PinAFConfig(GPIOF,GPIO_PinSource13,GPIO_AF_FSMC);//PF13,AF12
		GPIO_PinAFConfig(GPIOF,GPIO_PinSource14,GPIO_AF_FSMC);//PF14,AF12
		GPIO_PinAFConfig(GPIOF,GPIO_PinSource15,GPIO_AF_FSMC);//PF15,AF12
		
		GPIO_PinAFConfig(GPIOD,GPIO_PinSource14,GPIO_AF_FSMC);
		
		GPIO_PinAFConfig(GPIOD,GPIO_PinSource5,GPIO_AF_FSMC); 
    GPIO_SetBits(GPIOD, GPIO_Pin_5);		 // WR = 1 
		
		GPIO_SetBits(GPIOF, GPIO_Pin_7);//-24V使能

		GPIO_ResetBits(GPIOD, GPIO_Pin_5);  //NE1
		GPIO_ResetBits(GPIOD, GPIO_Pin_7);	//NWE

		//	A138_1;
		//	B138_0;
		//	C138_0;

		GPIO_ResetBits(GPIOC, GPIO_Pin_2);  //FAULT_XZB
		GPIO_ResetBits(GPIOG, GPIO_Pin_0);  //FAULT_XZA
		GPIO_ResetBits(GPIOE, GPIO_Pin_15);  //FAULT_SJA

		GPIO_SetBits(GPIOF, GPIO_Pin_11);  //FAULT_XZC
		GPIO_SetBits(GPIOC, GPIO_Pin_3);  //FAULT_XZD
		GPIO_SetBits(GPIOG, GPIO_Pin_1);  //FAULT_SJB
}	
void LED_ENABLE(void){
		//复位
	testsram[38]=1;
	testsram[39]=1;
	testsram[38+64]=1;
	testsram[39+64]=1;
	testsram[38]=0;
	testsram[39]=0;
	testsram[38+64]=0;
	testsram[39+64]=0;
	//使能信号6'b000_000 ~ 6'b001_111
	for(ts=16;ts<32;ts++){	
		testsram[ts]=1;
	}
	//使能信号6'b000_000 ~ 6'b001_111
	for(ts=80;ts<96;ts++){	
		testsram[ts]=1;
	}
}
void LED_DISABLE(void){
	//复位
	testsram[38]=1;
	testsram[39]=1;
	testsram[38]=0;
	testsram[39]=0;
	testsram[38+64]=1;
	testsram[39+64]=1;
	testsram[38+64]=0;
	testsram[39+64]=0;
	//使能信号6'b000_000 ~ 6'b001_111
	for(ts=16;ts<32;ts++){	
		testsram[ts]=0;
	}
	//使能信号6'b000_000 ~ 6'b001_111
	for(ts=80;ts<96;ts++){	
		testsram[ts]=0;
	}
	//熄灭2/6'b100_000 ~ 6'b100_101//6'b101_000 ~ 6'b101_101
	for(ts=96;ts<102;ts++){			
		testsram[ts]=0;
	}
	for(ts=104;ts<110;ts++){			
		testsram[ts]=0;
	}
}
void LED_SHOW(void){
		//点亮1/6'b010_000 ~ 6'b011_111
		for(ts=8;ts<16;ts++){
			testsram[ts]=1;
			delay_ms(30);
		}	
		for(ts=0;ts<8;ts++){
			testsram[ts]=1;
			delay_ms(30);
		}
		//点亮1/6'b100_000 ~ 6'b100_101//6'b101_000 ~ 6'b101_101
		for(ts=32;ts<38;ts++){			
			testsram[ts]=1;
			delay_ms(30);
		}
		for(ts=40;ts<46;ts++){			
			testsram[ts]=1;
			delay_ms(30);
		}
		//熄灭2/6'b010_000 ~ 6'b011_111
		for(ts=72;ts<80;ts++){
			testsram[ts]=0;
			delay_ms(30);
		}	
		for(ts=64;ts<72;ts++){
			testsram[ts]=0;
			delay_ms(30);
		}
		//熄灭2/6'b100_000 ~ 6'b100_101//6'b101_000 ~ 6'b101_101
		for(ts=96;ts<102;ts++){			
			testsram[ts]=0;
			delay_ms(30);
		}
		for(ts=104;ts<110;ts++){			
			testsram[ts]=0;
			delay_ms(30);
		}

		
		
		//熄灭1/6'b010_000 ~ 6'b011_111
		for(ts=8;ts<16;ts++){
			testsram[ts]=0;
			delay_ms(30);
		}	
		for(ts=0;ts<8;ts++){
			testsram[ts]=0;
			delay_ms(30);
		}		
		//熄灭1/6'b100_000 ~ 6'b100_101//6'b101_000 ~ 6'b101_101
		for(ts=32;ts<38;ts++){			
			testsram[ts]=0;
			delay_ms(30);
		}		
		for(ts=40;ts<46;ts++){			
			testsram[ts]=0;
			delay_ms(30);
		}
		//点亮2/6'b010_000 ~ 6'b011_111
		for(ts=72;ts<80;ts++){
			testsram[ts]=1;
			delay_ms(30);
		}	
		for(ts=64;ts<72;ts++){
			testsram[ts]=1;
			delay_ms(30);
		}
		//点亮2/6'b100_000 ~ 6'b100_101//6'b101_000 ~ 6'b101_101
		for(ts=96;ts<102;ts++){			
			testsram[ts]=1;
			delay_ms(30);
		}
		for(ts=104;ts<110;ts++){			
			testsram[ts]=1;
			delay_ms(30);
		}
}
void LED_Init(void){
		LED_ENABLE();
		for(ts=1;ts<=2;ts++){
			LED_SHOW();
		}
		LED_DISABLE();


}

