/*
 * input_processing.c
 *
 *  Created on: Oct 3, 2024
 *      Author: BilH
 */

#include "main.h"
#include "input_processing.h"
#include "input_reading.h"
#include "output_display.h"

enum ButtonState {BUTTON_PRESSED, BUTTON_RELEASED, BUTTON_PRESS_FOR_1S};
enum ButtonState buttonState = BUTTON_RELEASED;

int mode_value = 0;

void fsm_for_input_processing(void)
{
	switch(buttonState)
	{
	case BUTTON_RELEASED:
		if (!is_button_press(0))
		{
			buttonState = BUTTON_PRESSED;
		}
		break;
	case BUTTON_PRESSED:
		if (!is_button_press(0))
		{
			buttonState = BUTTON_RELEASED;
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
		}
		break;
	default:
		break;
	}
}
