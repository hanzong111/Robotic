#ifndef _TIMER_H
#define _TIMER_H
#include "bsp.h"
#define RC_CH1 (TIM2->CCR1)
#define RC_CH2 (TIM2->CCR2)
#define RC_CH3 (TIM2->CCR3)
//zhong 1500 min 1000 max 2000
void RC_Init(void);


#endif

