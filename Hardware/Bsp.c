#include "Bsp.h"
#include "math.h"
#include "Motor.h"
#include "CH452.h"
#include "timer.h"
extern u32 duty;
extern u16 freq;
/********************************************* 主初始化 *********************************************/
/******/
void BSP_Init(){
	// 初始化时钟  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2  | RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
						   RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD |
						   RCC_APB2Periph_AFIO  | RCC_APB2Periph_TIM1, ENABLE); //APB2外设时钟使能 
	Motor_Init();
	Digital_Input_Init();
	//TT_Motor_Init();
	CH452_Init();
  RC_Init();
	//Steering_Init();	
}

/************************************* 舵机初始化(test)*************************************/
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
 TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; // 选择PWM模式 2
 TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; // 比较输出使能
 TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;// 输出极性高
 TIM_OCInitStructure.TIM_Pulse = 0;
 TIM_OC1Init(TIM2, &TIM_OCInitStructure); // 初始化外设TIM2 OC1
 TIM_OC2Init(TIM2, &TIM_OCInitStructure); // 初始化外设TIM2 OC2
 TIM_OC3Init(TIM2, &TIM_OCInitStructure); // 初始化外设TIM2 OC3
 
 TIM_Cmd(TIM2,ENABLE);
 
}
/********************************************* ---------- *********************************************/
/***************************************** 数字量输入初始化 ****************************************/
/******/
void Digital_Input_Init(){	
	/*********************************************
	***2x12的排针，自Reset按键向下，依次为***	**
	** PA12   5V							    **
	** PA15   5V								**
	** PB3    5V								**
	** PB4    5V								**
	** PB5    空（防止不小心将5V和3.3V短路）	**
	** PB8    3.3V								**
	** PB9    3.3V								**
	** PC13   3.3V								**
	** PC14   空（防止不小心将3.3V和GND短路）	**
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
	这个函数读取io口输入信号值0或1
	实例：读取PA12（见板子上的字）信号值
	      a=GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12);
	****/
	
}
/********************************************* ---------- *********************************************/
/*******************************************  TT马达初始化 ******************************************/
/******/
void TT_Motor_Init(){
	GPIO_InitTypeDef GPIO_TTMotor;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	// PA3控制A、B相电机的启动和停止（可调）
	GPIO_TTMotor.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_TTMotor.GPIO_Pin = GPIO_Pin_3;
	GPIO_TTMotor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_TTMotor);
	// PA4控制C、D相电机的启动和停止（满速，不可调 or Think independently?）
	GPIO_TTMotor.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_TTMotor.GPIO_Pin = GPIO_Pin_4;
	GPIO_TTMotor.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_TTMotor);
	TT_MotorCD_Disable(); // CD相电机失能
	
	// 配置TIM2定时器参数
	TIM_TimeBaseStructure.TIM_Period = (1000-1); // 设置在自动重装载周期值
	TIM_TimeBaseStructure.TIM_Prescaler = 719; // 设置预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; // 设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); // 初始化TIM2

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; // 选择PWM模式 2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; // 比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;// 输出极性高
	TIM_OC4Init(TIM2, &TIM_OCInitStructure); // 初始化外设TIM2 OC4
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable); // 使能TIM2 OC4预装载寄存器
	TIM_Cmd(TIM2, ENABLE); // 使能TIM2
	TIM_SetCompare4(TIM2, 1000); // 初始化AB相转速为0
}

// 设置AB相TT马达占空比  Duty范围为 [0,1] 闭区间
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
/************************************* 延时程序 *************************************/
/******/
void delay_us(u32 uS){ //uS微秒级延时程序（参考值即是延时数，72MHz时最大值233015）	
	SysTick->LOAD=AHB_INPUT*uS;      //重装计数初值（当主频是72MHz，72次为1微秒）
	SysTick->VAL=0x00;        //清空定时器的计数器
	SysTick->CTRL=0x00000005;//时钟源HCLK，打开定时器
	while(!(SysTick->CTRL&0x00010000)); //等待计数到0
	SysTick->VAL=0x00;        //清空定时器的计数器
	SysTick->CTRL=0x00000004;//关闭定时器
}

void delay_ms(u16 ms){ //mS毫秒级延时程序（参考值即是延时数，最大值65535=2^16）	 		  	  
	while( ms-- != 0){
		delay_us(1000);	//调用1000微秒的延时
	}
}
 
void delay_s(u16 s){ //S秒级延时程序（参考值即是延时数，最大值65535）	 		  	  
	while( s-- != 0){
		delay_ms(1000);	//调用1000毫秒的延时
	}
}
/************************************* ---------- *************************************/
/*************************************  IIC程序 *************************************/
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
//// 产生 IIC 起始信号
//void IIC_Start(void){
//	SDAout = 1;
//	SCL = 1;
//	delay_us(2);
//	SDAout = 0;// START:when CLK is high,DATA change form high to low
//	delay_us(2);
//	SCL = 0;// 钳住 I2C 总线，准备发送或接收数据
//}
//// 产生 IIC 停止信号
//void IIC_Stop(void){
//	SCL = 0;
//	SDAout = 0;// STOP:when CLK is high DATA change form low to high
//	delay_us(2);
//	SCL=1;
//	SDAout=1;//发送 I2C 总线结束信号
//	delay_us(2);
//}
//// 等待应答信号到来
//// 返回值：1，接收应答失败
//// 0，接收应答成功
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
//	SCL=0;//时钟输出 0 
//	return 0; 
//}
////产生 ACK 应答
//void IIC_Ack(void)
//{
//	SCL=0;
//	SDAout=0;
//	delay_us(2);
//	SCL=1;
//	delay_us(2);
//	SCL=0;
//}
////不产生 ACK 应答 
//void IIC_NAck(void)
//{
//	SCL=0;
//	SDAout=1;
//	delay_us(2);
//	SCL=1;
//	delay_us(2);
//	SCL=0;
//}
//// IIC 发送一个字节
//// 返回从机有无应答
//// 1，有应答
//// 0，无应答 
//void IIC_Send_Byte(u8 txd)
//{ 
//	u8 t;  
//	SCL=0;// 拉低时钟开始数据传输
//	for(t=0;t<8;t++)
//	{ 
//		SDAout=(txd&0x80)>>7;
//		txd<<=1; 
//		delay_us(2); // 对 TEA5767 这三个延时都是必须的
//		SCL=1;
//		delay_us(2); 
//		SCL=0;
//		delay_us(2);
//	}
//}
//// 读 1 个字节，ack=1 时，发送 ACK，ack=0，发送 nACK 
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
//		IIC_NAck();//发送 nACK
//	else
//		IIC_Ack(); //发送 ACK 
//	return receive;
//}
/************************************* ---------- *************************************/
/*************************************   备 注   *************************************/
/*
	GPIO_Mode_AIN 模拟输入
	GPIO_Mode_IN_FLOATING 浮空输入
	GPIO_Mode_IPD 下拉输入
	GPIO_Mode_IPU 上拉输入
	GPIO_Mode_Out_OD 开漏输出
	GPIO_Mode_Out_PP 推挽输出
	GPIO_Mode_AF_OD 复用开漏输出
	GPIO_Mode_AF_PP 复用推挽输出
*/
/************************************* ---------- *************************************/
