#include "Bsp.h" 
#include "Motor.h"
#include "CH452.h"
#include "stm32f10x_tim.h"
#include "timer.h"
#include "ft_usart.h"
#include "Movement.h"

int Motor_PWM_1=0;
int Motor_PWM_2=0;
int Motor_PWM_3=0;
int n=0;

int main(void)
{
 BSP_Init();
 CH452_Init();
 delay_ms(20);
 CH452_SetDigit(1,1);
 delay_ms(2000);
 CH452_Clear();
	UART_Configuration();
	while(1)
	{
		n = CH452_GetKey();
		CH452_SetDigit(1,n);
		Set_Motor1_RPM(200);
	}
}

/*int main(void)
{
	 GPIO_InitTypeDef GPIO_InitStructure;

    // Enable GPIOA clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // Configure PA12 as output push-pull (LED)
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		while (1) {
        // Toggle the LED GPIO pin to turn the LED on/off
        GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_SET); // Turn on LED
        delay_ms(10000); // Delay for a short period
        GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_RESET); // Turn off LED
        delay_ms(10000); // Delay for a short period
    }
}*/

