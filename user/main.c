#include "main.h"

extern u16 testsram[250000];

int main(void)
{
	GPIO__Init();                   	//GPIO初始化
	TIM__Init();                      //定时器中断初始化
	FSMC_SRAM_Init();	                //FSMC初始化
	CAN1_Mode_Init(CAN_Mode_Normal);  //正常模式	
	uart_init(115200);	              //串口初始化波特率为115200
	LED_Init();                       //LED FSMC读写初始化
	Adc_Init();                       //ADC采样初始化
	Flash_Init();                     //Flash初始化
	List_Init(32);                    //初始化队列长度
	Motor_Init();                     //电机初始化
	
	while (1){	
		//发送队列里的一个数据	
		if(top != tail){
			CAN1_Send_Msg(top->StdId, (u8 *)top->data, 8);
			top = top->next;
		}	
		
		if(SENSOR == 0){
			LED1_OFF;
			if(testsram[257] == 0){
				Motor1_DIR = 1;
				Motor2_DIR = 1;
			}
			else{
				Motor1_DIR = 0;
				Motor2_DIR = 0;
			}		
			delay_ms(100);
		}
		else{
			LED1_ON;
		}
	}
}


