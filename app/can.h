#ifndef __CAN_H
#define __CAN_H	    
#include "main.h"

	
//CAN1����RX0�ж�ʹ��
#define CAN1_RX0_INT_ENABLE	1		//0,��ʹ��;1,ʹ��.								    
										 							 				    
u8 CAN1_Mode_Init(u8 mode);//CAN��ʼ��
 
u8 CAN1_Send_Msg(u16 id, u8* msg,u8 len);						//��������

u8 CAN1_Receive_Msg(u8 *buf);							//��������
#endif

















