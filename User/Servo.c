#include "Servo.h"

void	open_claw(void)
{
	TIM_SetCompare2(TIM2, 180);
	return ;
}

void	close_claw(void)
{
	TIM_SetCompare2(TIM2, 189);
	return;
}

void	lower_claw(void)
{
	TIM_SetCompare3(TIM2, 196);
	return;
}

void	raise_claw(void)
{
	TIM_SetCompare3(TIM2, 194);
	return;
}


