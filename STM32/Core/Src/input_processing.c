/*
 * input_processing.c
 *
 *  Created on: Oct 3, 2024
 *      Author: BilH
 */

#include "main.h"
#include "input_processing.h"
#include "input_reading.h"

enum ButtonState {BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1S};
enum ButtonState buttonState = BUTTON_RELEASED;

void fsm_for_input_processing(void)
{
	switch(buttonState)
	{
	case BUTTON_RELEASED:
		if (is_button_press(0))
		{
			buttonState = BUTTON_PRESSED;
		}
		// Increasing value
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
				buttonState = BUTTON_PRESSED_MORE_THAN_1S;
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1S:
		if (!is_button_press(0))
		{
			buttonState = BUTTON_RELEASED;
		}
		// Increasing value after each 500ms
		break;
	}
}
