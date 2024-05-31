#include "Routine.h"

void	Routine_1()
{
	CH452_SetDigit(0,1);
	delay_ms(1000);
	close_claw();
	delay_ms(1000);
	raise_claw();
	delay_ms(1000);
	lower_claw();
	delay_ms(1000);
	open_claw();
	delay_ms(1000);
	return ;
}

void	Routine_2()
{
	CH452_SetDigit(0, 2);
	delay_ms(20);
}

void	Routine_3()
{
	CH452_SetDigit(0, 3);
	delay_ms(20);
}
