#ifndef SENSOR_H
#define SENSOR_H	

#include "Bsp.h" 
#include "Motor.h"
#include "CH452.h"
#include "stm32f10x_tim.h"
#include "timer.h"
#include "Movement.h"
#include "Routine.h"

typedef struct s_gs
{
    int _1;
    int _2;
		int _3;
		int _4;
		int _5;
		int _6;
		int _7;
		int _8;
} t_gs;

void	grayscale_read(t_gs *port);
void	grayscale_display(t_gs greyscale);

int	correct_left(t_gs port);
int correct_right(t_gs port);
int		turn_left_signal(t_gs grayscale);
int		turn_right_signal(t_gs grayscale);
int   No_line(t_gs grayscale);

#endif
