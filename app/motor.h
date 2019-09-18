#ifndef __MOTOR_H
#define __MOTOR_H
#include "main.h"



extern u16 testsram[250000];

#define Motor1_EN  testsram[256] 
#define	Motor1_DIR testsram[257]
#define	Motor1_RE  testsram[258]
#define	Motor1_HA  testsram[259]
	
#define	Motor2_EN  testsram[260] 
#define	Motor2_DIR testsram[261]
#define	Motor2_RE  testsram[262]
#define	Motor2_HA  testsram[263]

#define SENSOR GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_3) 
 
void Motor_TIM8_init(u16 arr,u16 psc);
void Motor_Init(void);


#endif /* __DELAY_H */

