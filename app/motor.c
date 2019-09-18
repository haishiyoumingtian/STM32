#include "motor.h"



void Motor_TIM8_init(u16 arr,u16 psc){
		TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
		TIM_OCInitTypeDef  TIM_OCInitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);

		TIM_TimeBaseStructure.TIM_Period = arr;
		TIM_TimeBaseStructure.TIM_Prescaler = psc;
		TIM_TimeBaseStructure.TIM_ClockDivision = 0;
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
		TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure);

		TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
		TIM_OCInitStructure.TIM_Pulse = 0;
		TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
		TIM_OC1Init(TIM8, &TIM_OCInitStructure);
		TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable);

		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
		TIM_OCInitStructure.TIM_Pulse = 0;
		TIM_OC2Init(TIM8, &TIM_OCInitStructure);
		TIM_OC2PreloadConfig(TIM8, TIM_OCPreload_Enable);

		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
		TIM_OCInitStructure.TIM_Pulse = 0;
		TIM_OC3Init(TIM8, &TIM_OCInitStructure);
		TIM_OC3PreloadConfig(TIM8, TIM_OCPreload_Enable);

		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
		TIM_OCInitStructure.TIM_Pulse = 0;
		TIM_OC4Init(TIM8, &TIM_OCInitStructure);
		TIM_OC4PreloadConfig(TIM8, TIM_OCPreload_Enable);

		TIM_ARRPreloadConfig(TIM8, ENABLE);             
		TIM_CtrlPWMOutputs(TIM8, ENABLE); 
		TIM_Cmd(TIM8,ENABLE);            
}
void Motor_Init(void){
		TIM3_CH1_ENABLE;
		TIM3_CH2_ENABLE;

		Motor1_EN = 0;
		Motor1_DIR = 0;
		Motor1_RE = 1;
		Motor1_HA = 1;

		Motor2_EN = 0;  
		Motor2_DIR = 0;	
		Motor2_RE = 1;
		Motor2_HA = 1;
}

