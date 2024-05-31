#ifndef SERVO_H
#define SERVO_H	

#include "Bsp.h" 
#include "Motor.h"
#include "CH452.h"
#include "stm32f10x_tim.h"
#include "timer.h"
#include "Movement.h"
#include "Routine.h"

void	Grab_Ore(void);
void	Place_Ore(void);
void	lower_claw(void);
void	raise_claw(void);

#endif
