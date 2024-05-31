#include "Sensor.h"

void	grayscale_read(t_gs *port)
{
	port->_1 = Read_IO1;
	port->_2 = Read_IO2;
	port->_3 = Read_IO3;
	port->_4 = Read_IO4;
	port->_5 = Read_IO5;
	port->_6 = Read_IO6;
	port->_7 = Read_IO7;
	port->_8 = Read_IO8;
}

void	grayscale_display(t_gs greyscale)
{
	CH452_SetDigit(0, greyscale._1);
	CH452_SetDigit(1, greyscale._2);
	CH452_SetDigit(2, greyscale._3);
	CH452_SetDigit(3, greyscale._4);
	CH452_SetDigit(4, greyscale._5);
	CH452_SetDigit(5, greyscale._6);
	CH452_SetDigit(6, greyscale._7);
	CH452_SetDigit(7, greyscale._8);
}

/*	Time to turn left	*/
int		turn_left_signal(t_gs port)
{
	if(port._1 == 1 && port._2 == 1 && port._3 == 1)
		return(1);
	return(0);
}

/*	Time to turn right	*/
int		turn_right_signal(t_gs port)
{
	if(port._8 == 1 && port._7 == 1 && port._6 == 1)
		return(1);
	return(0);
}

/*	Robot slanting towards the right	*/
int	correct_left(t_gs port)
{
	if (port._3 == 1 && port._4 == 1 && port._5 == 1)
		return (1);
	return (0);
}

/*	Robot slanting towards the left	*/
int	correct_right(t_gs port)
{
	if (port._4 == 1 && port._5 == 1 && port._6 == 1)
		return (1);
	return (0);
}

int	No_line(t_gs port)
{
	if(port._1 == 0 && port._2 == 0 && port._3 == 0 
	&& port._4 == 0 && port._5 == 0 && port._6 == 0
	&& port._7 == 0 && port._8 == 0)
		return (1);
	return(0);
}
