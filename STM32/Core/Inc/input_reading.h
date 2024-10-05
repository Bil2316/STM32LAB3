/*
 * input_reading.h
 *
 *  Created on: Oct 3, 2024
 *      Author: BilH
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#define NO_OF_BUTTONS				3
#define DURATION_FOR_INCREASING		1000
#define BUTTON_IS_PRESSED			GPIO_PIN_RESET
#define BUTTON_IS_RELEASED			GPIO_PIN_SET

void button_reading(void);
unsigned char is_button_press(unsigned char index);
unsigned char is_button_press_1s(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
