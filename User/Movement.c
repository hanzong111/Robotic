#include "Movement.h"

#define Correct_FL 0.5
#define Correct_FR 0.7
#define Correct_BL 0.7
#define Correct_BR 1

void	Front_L_motor(int speed)
{
	Set_Motor1_RPM(speed);
}

void	Front_R_motor(int speed)
{
	Set_Motor4_RPM(speed);
}

void	Back_L_motor(int speed)
{
	Set_Motor2_RPM(speed);
}

void	Back_R_motor(int speed)
{
	Set_Motor3_RPM(speed);
}
void	move_foward(int speed)
{
	Front_L_motor(speed * Correct_FL);
	Front_R_motor(-speed * Correct_FR);
	Back_L_motor(speed * Correct_BL);
	Back_R_motor(-speed * Correct_BR);
}
