/*
 * timer.c
 *
 *  Created on: Oct 3, 2024
 *      Author: BilH
 */

#include "main.h"
#include "timer.h"
#include "input_reading.h"

#define NO_OF_TIMERS		10
#define TIMER_CYCLE			10

int timer_counter[NO_OF_TIMERS] = {0};
int timer_flag[NO_OF_TIMERS] = {0};

void set_timer(int index, int duration)
{
	timer_counter[index] = duration / TIMER_CYCLE;
	timer_flag[index] = 0;
}

void timer_run()
{
	for (int i = 0; i < NO_OF_TIMERS; i++)
	{
		if (timer_counter[i] >0) timer_counter[i]--;
		if (timer_counter[i] <= 0) timer_flag[i] = 1;
	}
}

void HAL_TIM_PeriodElapedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2)
	{
		button_reading();
	}
}
