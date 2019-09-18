#ifndef __GPIO_H
#define __GPIO_H

#include "main.h"

#define LED1_OFF GPIO_SetBits(GPIOD, GPIO_Pin_2);
#define LED1_ON GPIO_ResetBits(GPIOD, GPIO_Pin_2);

#define	A138_0 GPIO_ResetBits(GPIOF, GPIO_Pin_12);
#define	B138_0 GPIO_ResetBits(GPIOF, GPIO_Pin_13);
#define	C138_0 GPIO_ResetBits(GPIOF, GPIO_Pin_14);
#define	A138_1 GPIO_SetBits(GPIOF, GPIO_Pin_12);
#define	B138_1 GPIO_SetBits(GPIOF, GPIO_Pin_13);
#define	C138_1 GPIO_SetBits(GPIOF, GPIO_Pin_14);


#define	A0_1 GPIO_SetBits(GPIOF, GPIO_Pin_0);
#define	A1_1 GPIO_SetBits(GPIOF, GPIO_Pin_1);
#define	A2_1 GPIO_SetBits(GPIOF, GPIO_Pin_2);
#define	A3_1 GPIO_SetBits(GPIOF, GPIO_Pin_3);
#define	A4_1 GPIO_SetBits(GPIOF, GPIO_Pin_4);
#define	A5_1 GPIO_SetBits(GPIOF, GPIO_Pin_5);
#define	D0_1 GPIO_SetBits(GPIOD, GPIO_Pin_14);

#define	A0_0 GPIO_ResetBits(GPIOF, GPIO_Pin_0);
#define	A1_0 GPIO_ResetBits(GPIOF, GPIO_Pin_1);
#define	A2_0 GPIO_ResetBits(GPIOF, GPIO_Pin_2);
#define	A3_0 GPIO_ResetBits(GPIOF, GPIO_Pin_3);
#define	A4_0 GPIO_ResetBits(GPIOF, GPIO_Pin_4);
#define	A5_0 GPIO_ResetBits(GPIOF, GPIO_Pin_5);
#define	D0_0 GPIO_ResetBits(GPIOD, GPIO_Pin_14);
 
void GPIO__Init(void);
void LED_ENABLE(void);
void LED_DISABLE(void);
void LED_SHOW(void);
void LED_Init(void);
 
#endif /* __GPIO_H */


