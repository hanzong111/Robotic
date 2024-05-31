#include "Bsp.h"
#include "math.h"
#include "Motor.h"

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
	CH452_Init();
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
}
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

void EXTIX_Init(void){
    EXTI_InitTypeDef EXTI_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;
    Digital_Input_Init();
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource3);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource15); // ��Ӷ� PC15 ���ŵ��ⲿ�ж�����
    EXTI_InitStruct.EXTI_Line = EXTI_Line3;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_Init(&EXTI_InitStruct);
    
    NVIC_InitStruct.NVIC_IRQChannel = EXTI3_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
    NVIC_Init(&NVIC_InitStruct);
    
    // ��Ӷ� PC15 ���ŵ��ⲿ�ж�����
    EXTI_InitStruct.EXTI_Line = EXTI_Line15;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_Init(&EXTI_InitStruct);
    
    NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
    NVIC_Init(&NVIC_InitStruct);
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
//		delay_us(2); // ��ʱ�Ǳ����
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


