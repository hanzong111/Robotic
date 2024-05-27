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

void	display_grayscale(t_gs greyscale)
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
