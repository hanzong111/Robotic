#include "Test.h"

void	claw_test(int n)
{
	if(n == 1)
	{
		CH452_SetDigit(0,1);
		raise_claw();
		delay_ms(20);
	}
	if (n == 2)
	{
		lower_claw();
		CH452_SetDigit(0,2);
	}
	if (n == 3)
	{
		Place_Ore();
		CH452_SetDigit(0,3);
	}
	if (n == 4)
	{
		Grab_Ore();
		CH452_SetDigit(0,4);
	}
}
