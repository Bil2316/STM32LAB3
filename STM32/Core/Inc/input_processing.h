/*
 * input_processing.h
 *
 *  Created on: Oct 3, 2024
 *      Author: BilH
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

#include "main.h"
#include "input_reading.h"
#include "output_display.h"

extern int pressed_flag[NO_OF_BUTTONS];

enum ButtonState {BUTTON_PRESSED, BUTTON_RELEASED, BUTTON_PRESS_FOR_1S};
enum ButtonState buttonState[NO_OF_BUTTONS];

void fsm_for_input_processing(int index);

#endif /* INC_INPUT_PROCESSING_H_ */
