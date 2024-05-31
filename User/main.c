#include "Bsp.h" 
#include "Motor.h"
#include "CH452.h"
#include "stm32f10x_tim.h"
#include "timer.h"
#include "Movement.h"
#include "Routine.h"
#include "Sensor.h"
#include "Servo.h"
#include "sys.h"
#include "Test.h"

int Motor_PWM_1=0;	
int Motor_PWM_2=0;
int Motor_PWM_3=0;

int main(void)
{
		int n = 16;
	
		BSP_Init();
	  ServoMotor_Config();
		delay_ms(20);
		CH452_Clear();
		lower_claw();
		Place_Ore();
		CH452_SetDigit(0 ,0);
		while (1) 
		{
			n = CH452_GetKey();
			delay_ms(20);
			if (n == 1)
			{
				Routine_1();
				break;
			}
			else if (n == 2)
			{
				Routine_2();
				break;
			}
		}
		CH452_SetDigit(0 ,3);
}
