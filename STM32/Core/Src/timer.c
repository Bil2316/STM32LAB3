/*
 * timer.c
 *
 *  Created on: Oct 3, 2024
 *      Author: BilH
 */

#include "main.h"
#include "timer.h"

#define NO_OF_TIMER			10
#define TIMER_CYCLE			10

int timer_counter[NO_OF_TIMER];
int timer_flag[NO_OF_TIMER];

void set_timer(int duration, int index)
{
	timer_counter[index] = duration / TIMER_CYCLE;
	timer_flag[index] = 0;
}

void timer_run()
{
	for (int i = 0; i < NO_OF_TIMER; i++)
	{
		timer_counter[i]--;
		if (timer_counter[i] <= 0) timer_flag[i] = 1;
	}
}
