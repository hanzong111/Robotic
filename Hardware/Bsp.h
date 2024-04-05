#ifndef __BSP_H
#define __BSP_H	 
#include "sys.h" //STM头文件
#include "stdio.h"

//#define SCL PBout(6)
//#define SDAout PBout(7)
//#define SDAin PBin(7)

#define AHB_INPUT  72  //请按RCC中设置的AHB时钟频率填写到这里（单位MHz）

#define Read_IO1  GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12)
#define Read_IO2  GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15)
#define Read_IO3  GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3)
#define Read_IO4  GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4)
#define Read_IO5  GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)
#define Read_IO6  GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)
#define Read_IO7  GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9)
#define Read_IO8  GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)
#define Read_IO9  GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14)
#define Read_IO10 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15)
#define Read_IO11 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)
#define Read_IO12 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10)
#define TT_MotorCD_Enable()  GPIO_SetBits(GPIOA, GPIO_Pin_4)
#define TT_MotorCD_Disable() GPIO_ResetBits(GPIOA, GPIO_Pin_4)

void BSP_Init(void);
void Digital_Input_Init(void);
void TT_Motor_Init(void);
void TT_MotorCD_Set_Duty(float Duty);
void Steering_Init(void);
void TIM3_IRQHandler(void);
void pwmIC_Init(void);


////IIC所有操作函数
//void IIC_Init(void);                //初始化IIC的IO口				 
//void IIC_Start(void);				//发送IIC开始信号
//void IIC_Stop(void);	  			//发送IIC停止信号
//void IIC_Send_Byte(u8 txd);			//IIC发送一个字节
//u8 IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
//u8 IIC_Wait_Ack(void); 				//IIC等待ACK信号
//void IIC_Ack(void);					//IIC发送ACK信号
//void IIC_NAck(void);				//IIC不发送ACK信号

void delay_us(u32 uS);
void delay_ms(u16 ms);
void delay_s(u16 s);

#endif


