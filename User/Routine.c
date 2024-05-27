#include "Routine.h"

void	Routine_1()
{
	CH452_SetDigit(0, 1);
	delay_ms(20);
	Set_Motor1_RPM(100);
	Set_Motor2_RPM(100);
	Set_Motor3_RPM(100);
	Set_Motor4_RPM(100);
	delay_ms(1000);
	Set_Motor1_RPM(0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
	Set_Motor2_RPM(0);
	Set_Motor3_RPM(0);
	Set_Motor4_RPM(0);
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
