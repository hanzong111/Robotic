#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Bsp.h" 
#include "Motor.h"
#include "CH452.h"
#include "stm32f10x_tim.h"
#include "timer.h"
#include "Movement.h"
#include "Routine.h"
#include "Sensor.h"

#define ROBOT_SPEED 100
#define LEFT 2
#define RIGHT 3

void	Front_L_motor(int speed);
void	Front_R_motor(int speed);
void	Back_L_motor(int speed);
void	Back_R_motor(int speed);

void	move_foward(int speed);
void	move_backwards(void);
void	move_left(void);
void	move_right(void);
void	turn_left(void);
void	turn_right(void);
void	robot_stop(void);

void	follow_line(int dir, int speed);

void	ft_left_turn(void);
void	ft_right_turn(void);
void	ft_robot_noline(void);
void	ft_ore_right_turn(void);
void	place_ore_sequence(void);
#endif
