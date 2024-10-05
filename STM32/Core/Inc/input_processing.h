/*
 * input_processing.h
 *
 *  Created on: Oct 3, 2024
 *      Author: BilH
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

extern int pressed_flag;

enum ButtonState {BUTTON_PRESSED, BUTTON_RELEASED, BUTTON_PRESS_FOR_1S};
enum ButtonState buttonState;

void fsm_for_input_processing(void);

#endif /* INC_INPUT_PROCESSING_H_ */
