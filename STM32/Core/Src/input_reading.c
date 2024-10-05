/*
 * input_reading.c
 *
 *  Created on: Oct 3, 2024
 *      Author: BilH
 */

#include "main.h"
#include "input_reading.h"

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];

static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];

void button_reading(void)
{
	for (int i = 0; i < NO_OF_BUTTONS; i++)
	{
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(SELECT_MODE_GPIO_Port, SELECT_MODE_Pin);

		if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
		{
			buttonBuffer[i] = debounceButtonBuffer1[i];
			if (buttonBuffer[i] == BUTTON_IS_PRESSED)
			{
				if (counterForButtonPress1s[i] < DURATION_FOR_INCREASING)
				{
					counterForButtonPress1s[i]++;
				}
				else
				{
					flagForButtonPress1s[i] = 1;
					// TO DO
				}
			}
			else
			{
				counterForButtonPress1s[i] = 0;
				flagForButtonPress1s[i] = 0;
			}
		}
	}
}

unsigned char is_button_press(unsigned char index)
{
	if (index >= NO_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char is_button_press_1s(unsigned char index)
{
	if (index >= NO_OF_BUTTONS) return 0;
	if (flagForButtonPress1s[index] == 1)
		{
			flagForButtonPress1s[index] = 0;
			return 1;
		}
	return 0;
}
