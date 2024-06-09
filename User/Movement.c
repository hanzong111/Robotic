#include "Movement.h"

#define Correct_FL 0.8
#define Correct_FR 0.7
#define Correct_BL 1     /*0.7*/
#define Correct_BR 1.5

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

void	move_backwards(int speed)
{
	Front_L_motor(-speed * Correct_FL);
	Front_R_motor(speed * Correct_FR);
	Back_L_motor(-speed * Correct_BL);
	Back_R_motor(speed * Correct_BR);
}

void	turn_left(int speed)
{
	Front_L_motor(-(speed * Correct_FL) * 0.4);
	Front_R_motor(-speed * Correct_FR);
	Back_L_motor(-(speed * Correct_BL) * 0.4);
	Back_R_motor(-speed * Correct_BR);
}

void	turn_right(int speed)
{
	Front_L_motor(speed * Correct_FL);
	Front_R_motor(speed * Correct_FR * 0.4);
	Back_L_motor(speed * Correct_BL);
	Back_R_motor(speed * Correct_BR * 0.4);
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
		Front_L_motor((speed * Correct_FL) * 0.6);
		Back_L_motor((speed * Correct_BL) * 0.6);
		Front_R_motor((-speed * Correct_FR));
		Back_R_motor((-speed * Correct_BR));
	}
	else if (dir == RIGHT)
	{
		Front_L_motor((speed * Correct_FL));
		Back_L_motor((speed * Correct_BL));
		Front_R_motor((-speed * Correct_FR) * 0.8);
		Back_R_motor((-speed * Correct_BR) * 0.8);
	}
}

void	follow_line_2(int dir, int speed)
{
	if (dir == LEFT)
	{
		Front_L_motor((speed * Correct_FL) * 0.6);
		Back_L_motor((speed * Correct_BL) * 0.6);
		Front_R_motor((-speed * Correct_FR));
		Back_R_motor((-speed * Correct_BR));
	}
	else if (dir == RIGHT)
	{
		Front_L_motor((speed * Correct_FL));
		Back_L_motor((speed * Correct_BL));
		Front_R_motor((-speed * Correct_FR) * 0.6);
		Back_R_motor((-speed * Correct_BR) * 0.6);
	}
}

void right_correction(int speed)
{
	Front_L_motor((speed * Correct_FL));
	Back_L_motor((speed * Correct_BL));
	Front_R_motor((-speed * Correct_FR) * 0.8);
	Back_R_motor((-speed * Correct_BR) * 0.8);
}

void	Hover_right(int speed)
{
	Front_L_motor(-speed * Correct_FL);
	Front_R_motor(-speed * Correct_FR);
	Back_L_motor(speed * Correct_BL);
	Back_R_motor(speed * Correct_BR);
}

