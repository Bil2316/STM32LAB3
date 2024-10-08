/*
 * input_processing.c
 *
 *  Created on: Oct 3, 2024
 *      Author: BilH
 */

#include "input_processing.h"

int pressed_flag[NO_OF_BUTTONS] = {0};

void fsm_for_input_processing(int index)
{
	switch(buttonState[index])
	{
	case BUTTON_RELEASED:
		if (is_button_press(index))
		{
			buttonState[index] = BUTTON_PRESSED;
		}
		break;
	case BUTTON_PRESSED:
		if (!is_button_press(index))
		{
			buttonState[index] = BUTTON_RELEASED;
			pressed_flag[index] = 0;
		}
		else
		{
			if (is_button_press_1s(index))
			{
				buttonState[index] = BUTTON_PRESS_FOR_1S;
			}
		}
		break;
	case BUTTON_PRESS_FOR_1S:
		if (!is_button_press(index))
		{
			buttonState[index] = BUTTON_RELEASED;
			pressed_flag[index] = 0;
		}
		break;
	default:
		break;
	}
}
