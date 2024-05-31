#ifndef __MOTOR_H
#define __MOTOR_H	

#define Motor1_Enable() GPIO_SetBits(GPIOB,GPIO_Pin_12)    // 使能Motor1
#define Motor1_Disable() GPIO_ResetBits(GPIOB,GPIO_Pin_12) // 失能Motor1
#define Motor2_Enable() GPIO_SetBits(GPIOB,GPIO_Pin_13)    // 使能Motor2
#define Motor2_Disable() GPIO_ResetBits(GPIOB,GPIO_Pin_13) // 失能Motor2
#define Motor3_Enable() GPIO_SetBits(GPIOB,GPIO_Pin_14)    // 使能Motor3
#define Motor3_Disable() GPIO_ResetBits(GPIOB,GPIO_Pin_14) // 失能Motor3
#define Motor4_Enable() GPIO_SetBits(GPIOB,GPIO_Pin_15)    // 使能Motor4
#define Motor4_Disable() GPIO_ResetBits(GPIOB,GPIO_Pin_15) // 失能Motor4
#define Arr 49
#define Psc 7199

void Motor_Init(void);
void Set_Motor1_RPM(int RPM);
void Set_Motor2_RPM(int RPM);
void Set_Motor3_RPM(int RPM);
void Set_Motor4_RPM(int RPM);
void ServoMotor_Config(void);
void TIM2_IRQHandler(void); 
void motor(int pwm1,int pwm2);
#endif
