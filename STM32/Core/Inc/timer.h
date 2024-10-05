/*
 * timer.h
 *
 *  Created on: Oct 3, 2024
 *      Author: BilH
 */
#include "main.h"
#include "input_reading.h"

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define NO_OF_TIMERS		1
#define TIMER_CYCLE			10

extern int timer_counter[NO_OF_TIMERS];
extern int timer_flag[NO_OF_TIMERS];

void set_timer(int index, int duration);
void timer_run();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* INC_TIMER_H_ */
