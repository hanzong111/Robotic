#include "Bsp.h"
#include "math.h"
#include "Motor.h"
#include "CH452.h"
#include "timer.h"
extern u32 duty;
extern u16 freq;
/********************************************* ����ʼ�� *********************************************/
/******/
void BSP_Init(){
	// ��ʼ��ʱ��  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2  | RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
						   RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD |
						   RCC_APB2Periph_AFIO  | RCC_APB2Periph_TIM1, ENABLE); //APB2����ʱ��ʹ�� 
	Motor_Init();
	Digital_Input_Init();
	//TT_Motor_Init();
	CH452_Init();
  RC_Init();
	//Steering_Init();	
}

/************************************* �����ʼ��(test)*************************************/
/******/
void Steering_Init(){
 GPIO_InitTypeDef GPIO_InitStructure;
 TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
 TIM_OCInitTypeDef TIM_OCInitStructure;
 
 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA,&GPIO_InitStructure);
 
 TIM_InternalClockConfig(TIM2);
 
 TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
 TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
 TIM_TimeBaseStructure.TIM_Period = 7199;
 TIM_TimeBaseStructure.TIM_Prescaler = 199;
 TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
 TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);
 
 TIM_OCStructInit(&TIM_OCInitStructure);
 TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; // ѡ��PWMģʽ 2
 TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; // �Ƚ����ʹ��
 TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;// ������Ը�
 TIM_OCInitStructure.TIM_Pulse = 0;
 TIM_OC1Init(TIM2, &TIM_OCInitStructure); // ��ʼ������TIM2 OC1
 TIM_OC2Init(TIM2, &TIM_OCInitStructure); // ��ʼ������TIM2 OC2
 TIM_OC3Init(TIM2, &TIM_OCInitStructure); // ��ʼ������TIM2 OC3
 
 TIM_Cmd(TIM2,ENABLE);
 
}
/********************************************* ---------- *********************************************/
/***************************************** �����������ʼ�� ****************************************/
/******/
void Digital_Input_Init(){	
	/*********************************************
	***2x12�����룬��Reset�������£�����Ϊ***	**
	** PA12   5V							    **
	** PA15   5V								**
	** PB3    5V								**
	** PB4    5V								**
	** PB5    �գ���ֹ��С�Ľ�5V��3.3V��·��	**
	** PB8    3.3V								**
	** PB9    3.3V								**
	** PC13   3.3V								**
	** PC14   �գ���ֹ��С�Ľ�3.3V��GND��·��	**
	** PC15   GND								**
	** PB11   GND								**
	** PB10   GND								**
	**********************************************/
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);  
	GPIO_InitTypeDef GPIO_Input;
	// PA12
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_12;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Input);
	// PA15
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_15;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Input);
	// PB3
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_3;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Input);
	// PB4
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_4;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Input);
	// PB5
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_5;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Input);
	// PB8
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_8;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Input);
	// PB9
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_9;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Input);
	// PC13
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_13;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_Input);
	// PC14
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_14;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_Input);
	// PC15
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_15;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_Input);
	// PB11
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_11;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Input);
	// PB10
	GPIO_Input.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Input.GPIO_Pin = GPIO_Pin_10;
	GPIO_Input.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Input);
	/****
	GPIO_ReadInputDataBit(GPIOx, GPIO_Pin);
	���������ȡio�������ź�ֵ0��1
	ʵ������ȡPA12���������ϵ��֣��ź�ֵ
	      a=GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12);
	****/
	
}
/********************************************* ---------- *********************************************/
/*******************************************  TT����ʼ�� ******************************************/
/******/
void TT_Motor_Init(){
	GPIO_InitTypeDef GPIO_TTMotor;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	// PA3����A��B������������ֹͣ���ɵ���
	GPIO_TTMotor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_TTMotor.GPIO_Pin = GPIO_Pin_3;
	GPIO_TTMotor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_TTMotor);
	// PA4����C��D������������ֹͣ�����٣����ɵ� or Think independently?��
	GPIO_TTMotor.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_TTMotor.GPIO_Pin = GPIO_Pin_4;
	GPIO_TTMotor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_TTMotor);
	TT_MotorCD_Disable(); // CD����ʧ��
	
	// ����TIM2��ʱ������
	TIM_TimeBaseStructure.TIM_Period = (1000-1); // �������Զ���װ������ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = 719; // ����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; // ����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); // ��ʼ��TIM2

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; // ѡ��PWMģʽ 2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; // �Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;// ������Ը�
	TIM_OC4Init(TIM2, &TIM_OCInitStructure); // ��ʼ������TIM2 OC4
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable); // ʹ��TIM2 OC4Ԥװ�ؼĴ���
	TIM_Cmd(TIM2, ENABLE); // ʹ��TIM2
	TIM_SetCompare4(TIM2, 1000); // ��ʼ��AB��ת��Ϊ0
}

// ����AB��TT���ռ�ձ�  Duty��ΧΪ [0,1] ������
void TT_MotorCD_Set_Duty(float Duty){
	if(Duty > 1)
		Duty = 1;
	if(Duty < 0){
		Duty = 0;
	}
	if(Duty == 0)
		TIM_SetCompare4(TIM2, 1000);
	else if(Duty == 1)
		TIM_SetCompare4(TIM2, 10);
	else{
		Duty = Duty*500;
		TIM_SetCompare4(TIM2, 700-Duty);
	}
}
/************************************* ---------- *************************************/
/************************************* ��ʱ���� *************************************/
/******/
void delay_us(u32 uS){ //uS΢�뼶��ʱ���򣨲ο�ֵ������ʱ����72MHzʱ���ֵ233015��	
	SysTick->LOAD=AHB_INPUT*uS;      //��װ������ֵ������Ƶ��72MHz��72��Ϊ1΢�룩
	SysTick->VAL=0x00;        //��ն�ʱ���ļ�����
	SysTick->CTRL=0x00000005;//ʱ��ԴHCLK���򿪶�ʱ��
	while(!(SysTick->CTRL&0x00010000)); //�ȴ�������0
	SysTick->VAL=0x00;        //��ն�ʱ���ļ�����
	SysTick->CTRL=0x00000004;//�رն�ʱ��
}

void delay_ms(u16 ms){ //mS���뼶��ʱ���򣨲ο�ֵ������ʱ�������ֵ65535=2^16��	 		  	  
	while( ms-- != 0){
		delay_us(1000);	//����1000΢�����ʱ
	}
}
 
void delay_s(u16 s){ //S�뼶��ʱ���򣨲ο�ֵ������ʱ�������ֵ65535��	 		  	  
	while( s-- != 0){
		delay_ms(1000);	//����1000�������ʱ
	}
}
/************************************* ---------- *************************************/
/*************************************  IIC���� *************************************/
/******/
//void IIC_Init(void){
//	GPIO_InitTypeDef GPIO_IIC;
//	GPIO_IIC.GPIO_Pin = GPIO_Pin_6;
//	GPIO_IIC.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_IIC.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_IIC);
//	
//	GPIO_IIC.GPIO_Pin = GPIO_Pin_7;
//	GPIO_IIC.GPIO_Mode = GPIO_Mode_Out_OD;
//	GPIO_IIC.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_IIC);
//	SCL = 1;
//	SDAout = 1;
//}
//// ���� IIC ��ʼ�ź�
//void IIC_Start(void){
//	SDAout = 1;
//	SCL = 1;
//	delay_us(2);
//	SDAout = 0;// START:when CLK is high,DATA change form high to low
//	delay_us(2);
//	SCL = 0;// ǯס I2C ���ߣ�׼�����ͻ��������
//}
//// ���� IIC ֹͣ�ź�
//void IIC_Stop(void){
//	SCL = 0;
//	SDAout = 0;// STOP:when CLK is high DATA change form low to high
//	delay_us(2);
//	SCL=1;
//	SDAout=1;//���� I2C ���߽����ź�
//	delay_us(2);
//}
//// �ȴ�Ӧ���źŵ���
//// ����ֵ��1������Ӧ��ʧ��
//// 0������Ӧ��ɹ�
//u8 IIC_Wait_Ack(void)
//{
//	u8 ucErrTime = 0;
//	SDAout = 1;
//	delay_us(1); 
//	SCL=1;
//	delay_us(1);
//	while(SDAin)
//	{
//		ucErrTime++;
//		if(ucErrTime>250)
//		{
//			IIC_Stop();
//			return 1;
//		}
//	}
//	SCL=0;//ʱ����� 0 
//	return 0; 
//}
////���� ACK Ӧ��
//void IIC_Ack(void)
//{
//	SCL=0;
//	SDAout=0;
//	delay_us(2);
//	SCL=1;
//	delay_us(2);
//	SCL=0;
//}
////������ ACK Ӧ�� 
//void IIC_NAck(void)
//{
//	SCL=0;
//	SDAout=1;
//	delay_us(2);
//	SCL=1;
//	delay_us(2);
//	SCL=0;
//}
//// IIC ����һ���ֽ�
//// ���شӻ�����Ӧ��
//// 1����Ӧ��
//// 0����Ӧ�� 
//void IIC_Send_Byte(u8 txd)
//{ 
//	u8 t;  
//	SCL=0;// ����ʱ�ӿ�ʼ���ݴ���
//	for(t=0;t<8;t++)
//	{ 
//		SDAout=(txd&0x80)>>7;
//		txd<<=1; 
//		delay_us(2); // �� TEA5767 ��������ʱ���Ǳ����
//		SCL=1;
//		delay_us(2); 
//		SCL=0;
//		delay_us(2);
//	}
//}
//// �� 1 ���ֽڣ�ack=1 ʱ������ ACK��ack=0������ nACK 
//u8 IIC_Read_Byte(unsigned char ack)
//{
//	unsigned char i,receive=0;
//	for(i=0;i<8;i++ )
//	{
//	SCL=0; delay_us(2);
//	SCL=1;
//	receive<<=1;
//	if(SDAin)
//		receive++; 
//	delay_us(1); 
//	}
//	if (!ack)
//		IIC_NAck();//���� nACK
//	else
//		IIC_Ack(); //���� ACK 
//	return receive;
//}
/************************************* ---------- *************************************/
/*************************************   �� ע   *************************************/
/*
	GPIO_Mode_AIN ģ������
	GPIO_Mode_IN_FLOATING ��������
	GPIO_Mode_IPD ��������
	GPIO_Mode_IPU ��������
	GPIO_Mode_Out_OD ��©���
	GPIO_Mode_Out_PP �������
	GPIO_Mode_AF_OD ���ÿ�©���
	GPIO_Mode_AF_PP �����������
*/
/************************************* ---------- *************************************/
