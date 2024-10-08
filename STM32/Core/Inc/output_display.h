/*
 * output_display.h
 *
 *  Created on: Oct 4, 2024
 *      Author: BilH
 */

#ifndef INC_OUTPUT_DISPLAY_H_
#define INC_OUTPUT_DISPLAY_H_

#include "main.h"
#include "timer.h"

extern int red_counter, yellow_counter, green_counter;

enum TraficLight {RED, YELLOW, GREEN};

void reset_all_led(void);
void reset_blink(void);
void display7SEG1(int num);
void display7SEG2(int num);
void display_trafic_light(void);
void blink_led(enum TraficLight);
void display_mode(int mode);

#endif /* INC_OUTPUT_DISPLAY_H_ */
