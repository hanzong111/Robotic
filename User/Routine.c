#include "Routine.h"

void	ft_left_turn(void)
{
	t_gs grayscale;
	
	while (1)
  {
		grayscale_read(&grayscale);
		if (turn_left_signal(grayscale)) /* Check if the line goes to the left */
    {
      turn_left(ROBOT_SPEED);
      break;
    }
		else if(correct_left_2(grayscale))
			follow_line_2(LEFT, ROBOT_SPEED);
		else if (correct_right_2(grayscale))
			follow_line_2(RIGHT, ROBOT_SPEED);
		else if(correct_left(grayscale))
			follow_line(LEFT, ROBOT_SPEED);
		else if (correct_right(grayscale))
			follow_line(RIGHT, ROBOT_SPEED);
  }
}

void	ft_right_turn(void)
{
	t_gs grayscale;
	
	while (1)
  {
		grayscale_read(&grayscale);
		if (turn_right_signal(grayscale)) /* Check if the line goes to the left */
    {
      /*Turn Right*/
      break;
    }
		else if(correct_left_2(grayscale))
			follow_line_2(LEFT, ROBOT_SPEED);
		else if (correct_right_2(grayscale))
			follow_line_2(RIGHT, ROBOT_SPEED);
		else if(correct_left(grayscale))
			follow_line(LEFT, ROBOT_SPEED);
		else if (correct_right(grayscale))
			follow_line(RIGHT, ROBOT_SPEED);
  }
}

void	ft_robot_noline(void)
{
	t_gs grayscale;
	
	while(1)
	{
		grayscale_read(&grayscale);
		if(No_line(grayscale))
			break;
	}
}

void	ft_ore_right_turn(void)
{
	t_gs grayscale;
	int rightTurnCount = 0;
	
	while (1)
  {
		grayscale_read(&grayscale);
		if (turn_right_signal(grayscale)) /* Check if the line goes to the right */
    {
      rightTurnCount++;
			CH452_SetDigit(5, rightTurnCount);
			if (rightTurnCount <= 2)
				delay_ms(300);
      if (rightTurnCount == 3) /* Check if it's the third right turn */
      {
				delay_ms(800);
				turn_right(ROBOT_SPEED);
				break;
      }
    }
		else if(correct_left_2(grayscale))
			follow_line_2(LEFT, ROBOT_SPEED);
		else if (correct_right_2(grayscale))
			follow_line_2(RIGHT, ROBOT_SPEED);
		else if(correct_left(grayscale))
			follow_line(LEFT, ROBOT_SPEED);
		else if (correct_right(grayscale))
			follow_line(RIGHT, ROBOT_SPEED);
  }
}

void	place_ore_sequence(void)
{
	t_gs grayscale;
	
	while(1)
	{
		grayscale_read(&grayscale);
		if(No_line(grayscale))
		{
			robot_stop();
			/*Turn left*/
			/*Hover Right*/
			lower_claw();
			delay_s(1);
			Place_Ore();
			/* Hover Left */
			/* Turn Left */
			break;
		}
	}
}

void	Routine_1()
{	
	t_gs grayscale;
	CH452_SetDigit(0, 1);
  Grab_Ore(); /* Robot starts with ore in its claw */
	delay_ms(1000);
	raise_claw();
	
	/*	Robot following line */
	CH452_SetDigit(7, 1);
	move_foward(ROBOT_SPEED);
  ft_left_turn();
	delay_s(1);
	while(1)
	{
		grayscale_read(&grayscale);
		if(grayscale._5 == 1 && grayscale._6 == 1)
			break;
	}
	
	/*Turned left , check 3 lines before turning right */
	CH452_SetDigit(7, 2);
	move_foward(ROBOT_SPEED);
	ft_ore_right_turn();
	delay_ms(600);
	while(1)
	{
		grayscale_read(&grayscale);
		if(grayscale._2 == 1 && grayscale._3 == 1)
			break;
	}
	move_foward(ROBOT_SPEED);
	while (1)
  {
		grayscale_read(&grayscale);
		if (No_line(grayscale)) /* Check if the line goes to the left */
    {
      robot_stop(); 
      break;
    }
		else if(correct_left_2(grayscale))
			follow_line_2(LEFT, ROBOT_SPEED);
		else if (correct_right_2(grayscale))
			follow_line_2(RIGHT, ROBOT_SPEED);
		else if(correct_left(grayscale))
			follow_line(LEFT, ROBOT_SPEED);
		else if (correct_right(grayscale))
			follow_line(RIGHT, ROBOT_SPEED);
  }
	turn_left(ROBOT_SPEED);
	delay_ms(1100);
	robot_stop();
	delay_ms(500);
	lower_claw();
	delay_ms(500);
	Place_Ore();
	delay_ms(500);
	turn_left(ROBOT_SPEED);
	delay_ms(1500);
	move_foward(ROBOT_SPEED);
	delay_s(2);
	while (1)
  {
		grayscale_read(&grayscale);
		if(correct_left_2(grayscale))
			follow_line_2(LEFT, ROBOT_SPEED);
		else if (correct_right_2(grayscale))
			follow_line_2(RIGHT, ROBOT_SPEED);
		else if(correct_left(grayscale))
			follow_line(LEFT, ROBOT_SPEED);
		else if (correct_right(grayscale))
			follow_line(RIGHT, ROBOT_SPEED);
  }
}

void	Routine_2()
{
	t_gs grayscale;
	
	Place_Ore();
	delay_ms(1000);
	raise_claw();
	move_foward(ROBOT_SPEED);
	while (1)
  {
		grayscale_read(&grayscale);
		if (turn_right_signal(grayscale)) /* Check if the line goes to the left */
    {
      turn_right(ROBOT_SPEED);
			delay_ms(100);
			turn_left(ROBOT_SPEED);
			delay_ms(100);
			robot_stop();
      break;
    }
		else if(correct_left_2(grayscale))
			follow_line_2(LEFT, ROBOT_SPEED);
		else if (correct_right_2(grayscale))
			follow_line_2(RIGHT, ROBOT_SPEED);
		else if(correct_left(grayscale))
			follow_line(LEFT, ROBOT_SPEED);
		else if (correct_right(grayscale))
			follow_line(RIGHT, ROBOT_SPEED);
  }
	
	return ;
}

void	Routine_3()
{
	CH452_SetDigit(0, 3);
	delay_ms(20);
}
