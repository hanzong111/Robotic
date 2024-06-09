#ifndef ROUTINE_H
#define ROUTINE_H	

#include "Bsp.h" 
#include "Motor.h"
#include "CH452.h"
#include "stm32f10x_tim.h"
#include "timer.h"
#include "Movement.h"
#include "Routine.h"
#include "Sensor.h"
#include "Servo.h"

/* Routine Functions */
/**
  * @brief  1st Routine
  * @param  None
  * @retval None
  */
void Routine_1(void);
/** 
  * @brief  2nd Routine
  * @param  None
  * @retval None
  */
void Routine_2(void);
/**
  * @brief  3rd Routine
  * @param  None
  * @retval None
  */
void Routine_3(void);

#endif
