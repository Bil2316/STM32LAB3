/*
 * output_display.c
 *
 *  Created on: Oct 4, 2024
 *      Author: BilH
 */

#include "output_display.h"

enum TraficLight traficLight1 = RED;
enum TraficLight traficLight2 = GREEN;

char led7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
int display_mode_state1 = 1; // LED 7 segments 1,2
int display_mode_state2 = 3; // LED 7 segments 3,4

int red_counter = 5;
int yellow_counter = 2;
int green_counter = 3;

int counter1 = 0;
int counter2 = 0;

void reset_all_led(void)
{
	HAL_GPIO_WritePin(GPIOB, EN1_Pin | EN2_Pin | EN3_Pin | EN4_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, RED1_Pin | RED2_Pin | YELLOW1_Pin | YELLOW2_Pin
			| GREEN1_Pin | GREEN2_Pin, 1);
	counter1 = red_counter;
	counter2 = green_counter;
	traficLight1 = RED;
	traficLight2 = GREEN;
	display_mode_state1 = 1; // LED 7 segments 1,2
	display_mode_state2 = 3; // LED 7 segments 3,4
	set_timer(0, 500); // Timer of LED 7 segments 1, 2
	set_timer(1, 500); // Timer of LED 7 segments 3, 4
	set_timer(2, 500); // Timer of trafic light (mode)
	set_timer(3, 1000); // Timer of trafic light (normal)
}

void reset_blink(void)
{
	HAL_GPIO_WritePin(GPIOB, RED1_Pin | RED2_Pin | YELLOW1_Pin | YELLOW2_Pin
				| GREEN1_Pin | GREEN2_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, EN1_Pin | EN2_Pin | EN3_Pin | EN4_Pin, 1);
	set_timer(0, 500);
	set_timer(2, 500);
}

void display7SEG1(int num)
{
    HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, (led7seg[num] >> 0) & 1);
    HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, (led7seg[num] >> 1) & 1);
    HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, (led7seg[num] >> 2) & 1);
    HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, (led7seg[num] >> 3) & 1);
    HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, (led7seg[num] >> 4) & 1);
    HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, (led7seg[num] >> 5) & 1);
    HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, (led7seg[num] >> 6) & 1);
}

void display7SEG2(int num)
{
    HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, (led7seg[num] >> 0) & 1);
    HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, (led7seg[num] >> 1) & 1);
    HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, (led7seg[num] >> 2) & 1);
    HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, (led7seg[num] >> 3) & 1);
    HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, (led7seg[num] >> 4) & 1);
    HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, (led7seg[num] >> 5) & 1);
    HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, (led7seg[num] >> 6) & 1);
}

void display_trafic_light(void)
{
	if (timer_flag[0] == 1)
	{
		switch(display_mode_state1)
		{
		case 1:
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			display7SEG1(counter1 / 10);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
			display_mode_state1 = 2;
			break;
		case 2:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			display7SEG1(counter1 % 10);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
			display_mode_state1 = 1;
			counter1--;
			break;
		default:
			break;
		}
		set_timer(0, 500);
	}

	if (timer_flag[1] == 1)
	{
		switch(display_mode_state2)
		{
		case 3:
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, 1);
			display7SEG2(counter2 / 10);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
			display_mode_state2 = 4;
			break;
		case 4:
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			display7SEG2(counter2 % 10);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, 0);
			display_mode_state2 = 3;
			counter2--;
			break;
		default:
			break;
		}
		set_timer(1, 500);
	}

	if (timer_flag[3] == 1)
	{
		switch(traficLight1)
		{
		case RED:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 0);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 1);
			if (counter1 <= 0)
			{
				traficLight1 = GREEN;
				counter1 = green_counter;
			}
			break;
		case YELLOW:
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 0);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 1);
			if (counter1 <= 0)
			{
				traficLight1 = RED;
				counter1 = red_counter;
			}
			break;
		case GREEN:
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 0);
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
			if (counter1 <= 0)
			{
				traficLight1 = YELLOW;
				counter1 = yellow_counter;
			}
			break;
		default:
			break;
		}

		switch(traficLight2)
		{
		case RED:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 0);
			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 1);
			if (counter2 <= 0)
			{
				traficLight2 = GREEN;
				counter2 = green_counter;
			}
			break;
		case YELLOW:
			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 0);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 1);
			if (counter2 <= 0)
			{
				traficLight2 = RED;
				counter2 = red_counter;
			}
			break;
		case GREEN:
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 0);
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 1);
			if (counter2 <= 0)
			{
				traficLight2 = YELLOW;
				counter2 = yellow_counter;
			}
			break;
		default:
			break;
		}
		set_timer(3, 1000);
	}
}

void display_mode(int mode)
{
	if (timer_flag[0] == 1)
	{
		switch(display_mode_state1)
		{
		case 1:
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			display7SEG1(0);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
			display_mode_state1 = 2;
			break;
		case 2:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			display7SEG1(mode);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
			display_mode_state1 = 1;
			break;
		default:
			break;
		}
		set_timer(0, 500);
	}
}

void blink_led(enum TraficLight traficLight)
{
	if (timer_flag[2] == 1)
	{
		switch(traficLight)
		{
		case RED:
			HAL_GPIO_WritePin(GPIOB, YELLOW1_Pin | YELLOW2_Pin
					| GREEN1_Pin | GREEN2_Pin, 1);
			HAL_GPIO_TogglePin(GPIOB, RED1_Pin | RED2_Pin);
			break;
		case YELLOW:
			HAL_GPIO_WritePin(GPIOB, RED1_Pin | RED2_Pin, 1);
			HAL_GPIO_TogglePin(GPIOB, YELLOW1_Pin | YELLOW2_Pin);
			break;
		case GREEN:
			HAL_GPIO_WritePin(GPIOB, YELLOW1_Pin | YELLOW2_Pin, 1);
			HAL_GPIO_TogglePin(GPIOB, GREEN1_Pin | GREEN2_Pin);
			break;
		default:
			break;
		}
		set_timer(2, 500);
	}
}
