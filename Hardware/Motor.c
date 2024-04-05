#include "Motor.h"
#include "sys.h" // STM头文件
void Motor_Init(){
	GPIO_InitTypeDef GPIO_Motor;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM1,ENABLE); // TIM1需要重映射
	
	// PB12控制Motor1的使能
	GPIO_Motor.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Motor.GPIO_Pin = GPIO_Pin_12;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Motor);
	Motor1_Enable(); // 使能Motor1,详见Motor.h
	
	// PB13控制Motor2的使能
	GPIO_Motor.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Motor.GPIO_Pin = GPIO_Pin_13;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Motor);
	Motor2_Enable(); // 使能Motor2
	
	// PB14控制Motor3的使能
	GPIO_Motor.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Motor.GPIO_Pin = GPIO_Pin_14;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Motor);
	Motor3_Enable(); // 使能Motor3
	
	// PB15控制Motor4的使能
	GPIO_Motor.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Motor.GPIO_Pin = GPIO_Pin_15;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Motor);
	Motor4_Enable(); // 使能Motor4
	
	// PA6为TIM3的CH1通道，Motor1+
	GPIO_Motor.GPIO_Pin = GPIO_Pin_6;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Motor);

	// PA7为TIM3的CH2通道，Motor1-
	GPIO_Motor.GPIO_Pin = GPIO_Pin_7;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Motor);
	
	// PB0为TIM3的CH3通道，Motor2+
	GPIO_Motor.GPIO_Pin = GPIO_Pin_0;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Motor);

	// PB1为TIM3的CH4通道，Motor2-
	GPIO_Motor.GPIO_Pin = GPIO_Pin_1;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Motor);
	
	// PA8为TIM1的CH1通道，Motor3+
	GPIO_Motor.GPIO_Pin = GPIO_Pin_8;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Motor);

	// PA9为TIM1的CH2通道，Motor3-
	GPIO_Motor.GPIO_Pin = GPIO_Pin_9;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Motor);
	
	// PA10为TIM1的CH3通道，Motor4+
	GPIO_Motor.GPIO_Pin = GPIO_Pin_10;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Motor);

	// PA11为TIM1的CH4通道，Motor4-
	GPIO_Motor.GPIO_Pin = GPIO_Pin_11;
	GPIO_Motor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Motor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Motor);
	
	// 配置TIM1、TIM3定时器参数
	TIM_TimeBaseStructure.TIM_Period = (1000-1); // 设置在自动重装载周期值
	TIM_TimeBaseStructure.TIM_Prescaler = 0; // 设置预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; // 设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // TIM向上计数模式
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); // 初始化TIM1
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); // 初始化TIM3
	
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; // 选择PWM模式 2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; // 比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;// 输出极性高
	TIM_OC1Init(TIM1, &TIM_OCInitStructure); // 初始化外设TIM1 OC1
	TIM_OC2Init(TIM1, &TIM_OCInitStructure); // 初始化外设TIM1 OC2
	TIM_OC3Init(TIM1, &TIM_OCInitStructure); // 初始化外设TIM1 OC3
	TIM_OC4Init(TIM1, &TIM_OCInitStructure); // 初始化外设TIM1 OC4
	TIM_OC1Init(TIM3, &TIM_OCInitStructure); // 初始化外设TIM3 OC1
	TIM_OC2Init(TIM3, &TIM_OCInitStructure); // 初始化外设TIM3 OC2
	TIM_OC3Init(TIM3, &TIM_OCInitStructure); // 初始化外设TIM3 OC3
	TIM_OC4Init(TIM3, &TIM_OCInitStructure); // 初始化外设TIM3 OC4
	
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); // 使能TIM1 OC1预装载寄存器
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable); // 使能TIM1 OC2预装载寄存器
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable); // 使能TIM1 OC3预装载寄存器
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable); // 使能TIM1 OC4预装载寄存器
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable); // 使能TIM3 OC1预装载寄存器
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable); // 使能TIM3 OC2预装载寄存器
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable); // 使能TIM3 OC3预装载寄存器
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable); // 使能TIM3 OC4预装载寄存器
	TIM_CtrlPWMOutputs(TIM1,ENABLE); // TIM1需要加
	TIM_Cmd(TIM1, ENABLE); // 使能TIM1
	TIM_Cmd(TIM3, ENABLE); // 使能TIM3	
}

void Set_Motor1_RPM(int RPM){
	if(RPM > 720)
		RPM = 720;
	if(RPM < -720)
		RPM = -720;
	if(RPM == 0){
		TIM_SetCompare1(TIM3, 1000-RPM);
		TIM_SetCompare2(TIM3, 1000);
	}
	else if(RPM > 0){
		RPM = RPM*0.8+280;
		TIM_SetCompare1(TIM3, 1000-RPM);
		TIM_SetCompare2(TIM3, 1000);
	}
	else{
		RPM = RPM*0.8-280;
		TIM_SetCompare1(TIM3, 1000);
		TIM_SetCompare2(TIM3, 1000+RPM);
	}
}
void Set_Motor2_RPM(int RPM){
	if(RPM > 720)
		RPM = 720;
	if(RPM < -720)
		RPM = -720;
	if(RPM == 0){
		TIM_SetCompare3(TIM3, 1000-RPM);
		TIM_SetCompare4(TIM3, 1000);
	}
	else if(RPM > 0){
		RPM = RPM*0.8+280;
		TIM_SetCompare3(TIM3, 1000-RPM);
		TIM_SetCompare4(TIM3, 1000);
	}
	else{
		RPM = RPM*0.8-280;
		TIM_SetCompare3(TIM3, 1000);
		TIM_SetCompare4(TIM3, 1000+RPM);
	}
}
void Set_Motor3_RPM(int RPM){
	if(RPM > 720)
		RPM = 720;
	if(RPM < -720)
		RPM = -720;
	if(RPM == 0){
		TIM_SetCompare1(TIM1, 1000-RPM);
		TIM_SetCompare2(TIM1, 1000);
	}
	else if(RPM > 0){
		RPM = RPM*0.8+280;
		TIM_SetCompare1(TIM1, 1000-RPM);
		TIM_SetCompare2(TIM1, 1000);
	}
	else{
		RPM = RPM*0.8-280;
		TIM_SetCompare1(TIM1, 1000);
		TIM_SetCompare2(TIM1, 1000+RPM);
	}
}
void Set_Motor4_RPM(int RPM){
	if(RPM > 720)
		RPM = 720;
	if(RPM < -720)
		RPM = -720;
	if(RPM == 0){
		TIM_SetCompare3(TIM1, 1000-RPM);
		TIM_SetCompare4(TIM1, 1000);
	}
	else if(RPM > 0){
		RPM = RPM*0.8+280;
		TIM_SetCompare3(TIM1, 1000-RPM);
		TIM_SetCompare4(TIM1, 1000);
	}
	else{
		RPM = RPM*0.8-280;
		TIM_SetCompare3(TIM1, 1000);
		TIM_SetCompare4(TIM1, 1000+RPM);
	}
}




