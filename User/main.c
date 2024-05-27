#include "Bsp.h" 
#include "Motor.h"
#include "CH452.h"
#include "stm32f10x_tim.h"
#include "timer.h"
#include "Movement.h"
#include "Routine.h"
#include "Sensor.h"
#include "sys.h"

int Motor_PWM_1=0;	
int Motor_PWM_2=0;
int Motor_PWM_3=0;
int n=0;

int main(void)
{
		BSP_Init();
		delay_ms(20);
		CH452_Clear();
		t_gs	greyscale;

		while (1) 
		{
			delay_ms(10);
			grayscale_read(&greyscale);
			delay_ms(10);
			display_grayscale(greyscale);
			delay_ms(10);
			n = CH452_GetKey();
			delay_ms(10);
			TIM_SetCompare1(TIM2, 100);
			delay_ms(1000);
			TIM_SetCompare1(TIM2, 200);
			delay_ms(1000);
			TIM_SetCompare2(TIM2, 100);
			delay_ms(1000);
			TIM_SetCompare2(TIM2, 200);
			delay_ms(1000);
			TIM_SetCompare3(TIM2, 100);
			delay_ms(1000);
			TIM_SetCompare3(TIM2, 200);
			delay_ms(1000);
			/*if(n != 16)
			{
				if(n == 1)
				{
					delay_ms(20);
					CH452_SetDigit(0, 7);
					delay_ms(20);
					TIM_SetCompare1(TIM2, 30);
					delay_ms(20);
					TIM_SetCompare2(TIM2, 30);
					delay_ms(20);
					TIM_SetCompare3(TIM2, 30);
					delay_ms(20);
					TIM_SetCompare4(TIM2, 30);
				}
			}*/
		}
}

