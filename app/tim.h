#ifndef __TIM_H
#define __TIM_H

#include "main.h"

#define TIM3_CH1_ENABLE	TIM_SetCompare1(TIM3,1500)
#define TIM3_CH2_ENABLE	TIM_SetCompare2(TIM3,1500)
#define TIM3_CH3_ENABLE	TIM_SetCompare3(TIM3,1500)
#define TIM3_CH4_ENABLE	TIM_SetCompare4(TIM3,1500)

#define TIM3_CH1_DISABLE TIM_SetCompare1(TIM3,0)
#define TIM3_CH2_DISABLE TIM_SetCompare2(TIM3,0)
#define TIM3_CH3_DISABLE TIM_SetCompare3(TIM3,0)
#define TIM3_CH4_DISABLE TIM_SetCompare4(TIM3,0)

void TIM__Init(void);
extern u8 time[8];
 
#endif /* __DELAY_H */

