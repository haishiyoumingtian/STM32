#ifndef __USART_H
#define __USART_H

#include "main.h"
	
#define USART_REC_LEN  			200  	//定义最大接收字节数 200
#define EN_USART1_RX 			1		//使能（1）/禁止（0）串口1接收
#define MAX_LENGTH 		1024
	  	
extern char  USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern u16 USART_RX_STA;         		//接收状态标记	
extern u16 USART_RX_FG;
extern u8 USART_RX_KEY;
extern int CAN_RX_NUM;


//如果想串口中断接收，请不要注释以下宏定义
void uart_init(u32 bound);
char* USART_GetString(void);
#endif


