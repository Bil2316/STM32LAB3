/*
 * output_display.c
 *
 *  Created on: Oct 4, 2024
 *      Author: BilH
 */

#include "main.h"
#include "output_display.h"

void display7SEG1(int num)
{
    char led7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

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
    char led7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

    HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, (led7seg[num] >> 0) & 1);
    HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, (led7seg[num] >> 1) & 1);
    HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, (led7seg[num] >> 2) & 1);
    HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, (led7seg[num] >> 3) & 1);
    HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, (led7seg[num] >> 4) & 1);
    HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, (led7seg[num] >> 5) & 1);
    HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, (led7seg[num] >> 6) & 1);
}


