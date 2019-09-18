#ifndef __USART_H
#define __USART_H

#include "main.h"
	
#define USART_REC_LEN  			200  	//�����������ֽ��� 200
#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
#define MAX_LENGTH 		1024
	  	
extern char  USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART_RX_STA;         		//����״̬���	
extern u16 USART_RX_FG;
extern u8 USART_RX_KEY;
extern int CAN_RX_NUM;


//����봮���жϽ��գ��벻Ҫע�����º궨��
void uart_init(u32 bound);
char* USART_GetString(void);
#endif


