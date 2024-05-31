#include "Routine.h"

void	ft_left_turn(void)
{
	t_gs grayscale;
	
	while (1)
  {
		grayscale_read(&grayscale);
		if (turn_left_signal(grayscale)) /* Check if the line goes to the left */
    {
			robot_stop();
			delay_s(2);
      /*Turn Left*/
      break;
    }
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
			delay_s(2);
      if (rightTurnCount == 3) /* Check if it's the third right turn */
      {
        /*Turn Right */
				break;
      }
    }
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
	CH452_SetDigit(0, 1);
  Grab_Ore(); /* Robot starts with ore in its claw */
	delay_ms(1000);
	raise_claw();
	
	/*	Robot following line */
	CH452_SetDigit(7, 1);
	move_foward(ROBOT_SPEED);
  ft_left_turn();
	
	/*Turned left , check 3 lines before turning right */
	CH452_SetDigit(7, 2);
	move_foward(ROBOT_SPEED);
	ft_ore_right_turn();
	
	/* Turned right , execute put ore sequence */
	CH452_SetDigit(7, 3);
	move_foward(ROBOT_SPEED);
	place_ore_sequence();
	
	/* Turn 180degrees around following line back to main line */
	CH452_SetDigit(7, 4);
	move_foward(ROBOT_SPEED);
	ft_right_turn();
	
	/* Turn right */
	CH452_SetDigit(7, 5);
	move_foward(ROBOT_SPEED);
	ft_left_turn();
	
	/* Turned left */
	CH452_SetDigit(7, 6);
	move_foward(ROBOT_SPEED);
	
	/* Follow line till no line */
	CH452_SetDigit(7, 7);
	ft_robot_noline();
	delay_s(1);
	robot_stop();
	CH452_SetDigit(7, 10);
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
