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

void	robot_stop()
{
	Front_L_motor(0);
	Front_R_motor(0);
	Back_L_motor(0);
	Back_R_motor(0);
}

void	follow_line(int dir, int speed)
{
	if (dir == LEFT)
	{
		Front_L_motor((speed * Correct_FL) * 0);
		Back_L_motor((speed * Correct_BL) * 0);
		Front_R_motor((-speed * Correct_FR));
		Back_R_motor((-speed * Correct_BR));
		delay_ms(30);
		Front_L_motor((speed * Correct_FL));
		Back_L_motor((speed * Correct_BL));
	}
	else if (dir == RIGHT)
	{
		Front_L_motor((speed * Correct_FL));
		Back_L_motor((speed * Correct_BL));
		Front_R_motor((-speed * Correct_FR) * 0);
		Back_R_motor((-speed * Correct_BR) * 0);
		delay_ms(30);
		Front_R_motor((-speed * Correct_FR));
		Back_R_motor((-speed * Correct_BR));
	}
}
