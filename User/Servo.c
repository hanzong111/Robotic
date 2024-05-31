#include "Servo.h"

void	Grab_Ore(void)
{
	TIM_SetCompare2(TIM2, 185);
	return ;
}

void	Place_Ore(void)
{
	TIM_SetCompare2(TIM2, 180);
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


