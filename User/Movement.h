#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Bsp.h" 
#include "Motor.h"
#include "CH452.h"
#include "stm32f10x_tim.h"
#include "timer.h"
#include "Movement.h"
#include "Routine.h"

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
#endif
