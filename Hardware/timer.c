#include "timer.h"
#define RC_CH1 (TIM2->CCR1)
#define RC_CH2 (TIM2->CCR2)
#define RC_CH3 (TIM2->CCR3)
#define RC_CH4 (TIM2->CCR4)
void RC_Init()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode=GPIO_Mode_IPU;
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	gpio.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
	GPIO_Init(GPIOA,&gpio);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
	EXTI_InitTypeDef exti;
	exti.EXTI_Mode=EXTI_Mode_Interrupt;
	exti.EXTI_Trigger=EXTI_Trigger_Rising;
	exti.EXTI_LineCmd=ENABLE;
	exti.EXTI_Line=EXTI_Line0;
	EXTI_Init(&exti);
	NVIC_InitTypeDef nvic;
	nvic.NVIC_IRQChannelCmd=ENABLE;
	nvic.NVIC_IRQChannelPreemptionPriority=1;
	nvic.NVIC_IRQChannelSubPriority=0;
	nvic.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_Init(&nvic);
	TIM_TimeBaseInitTypeDef tbase;
	tbase.TIM_CounterMode=TIM_CounterMode_Up;
	tbase.TIM_ClockDivision=TIM_CKD_DIV1;
	tbase.TIM_Period=0xffff;
	tbase.TIM_Prescaler=71;
	tbase.TIM_RepetitionCounter=DISABLE;
	TIM_TimeBaseInit(TIM2,&tbase);
	TIM_ICInitTypeDef ici;
	ici.TIM_ICPolarity=TIM_ICPolarity_Falling;
	ici.TIM_ICPrescaler=TIM_ICPSC_DIV1;
	ici.TIM_ICFilter=0;
	ici.TIM_ICSelection=TIM_ICSelection_DirectTI;
	ici.TIM_Channel=TIM_Channel_1;
	TIM_ICInit(TIM2,&ici);
	ici.TIM_Channel=TIM_Channel_2;
	TIM_ICInit(TIM2,&ici);
	ici.TIM_Channel=TIM_Channel_3;
	TIM_ICInit(TIM2,&ici);
}
void EXTI0_IRQHandler()
{
	if(EXTI_GetITStatus(EXTI_Line0)==SET)
	{
		TIM_Cmd(TIM2,DISABLE);
		TIM_SetCounter(TIM2,0);
		TIM_Cmd(TIM2,ENABLE);
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}
