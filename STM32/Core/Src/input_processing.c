/*
 * input_processing.c
 *
 *  Created on: Oct 3, 2024
 *      Author: BilH
 */

#include "input_processing.h"

int pressed_flag = 0;
enum ButtonState buttonState = BUTTON_RELEASED;

void button_init(void)
{
	buttonState = BUTTON_RELEASED;
}

void fsm_for_input_processing(void)
{
	switch(buttonState)
	{
	case BUTTON_RELEASED:
		if (is_button_press(0))
		{
			buttonState = BUTTON_PRESSED;
		}
		break;
	case BUTTON_PRESSED:
		if (!is_button_press(0))
		{
			buttonState = BUTTON_RELEASED;
			pressed_flag = 0;
		}
		else
		{
			if (is_button_press_1s(0))
			{
				buttonState = BUTTON_PRESS_FOR_1S;
			}
		}
		break;
	case BUTTON_PRESS_FOR_1S:
		if (!is_button_press(0))
		{
			buttonState = BUTTON_RELEASED;
			pressed_flag = 0;
		}
		break;
	default:
		break;
	}
}
