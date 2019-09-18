#include "main.h"

extern u16 testsram[250000];

int main(void)
{
	GPIO__Init();                   	//GPIO��ʼ��
	TIM__Init();                      //��ʱ���жϳ�ʼ��
	FSMC_SRAM_Init();	                //FSMC��ʼ��
	CAN1_Mode_Init(CAN_Mode_Normal);  //����ģʽ	
	uart_init(115200);	              //���ڳ�ʼ��������Ϊ115200
	LED_Init();                       //LED FSMC��д��ʼ��
	Adc_Init();                       //ADC������ʼ��
	Flash_Init();                     //Flash��ʼ��
	List_Init(32);                    //��ʼ�����г���
	Motor_Init();                     //�����ʼ��
	
	while (1){	
		//���Ͷ������һ������	
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


