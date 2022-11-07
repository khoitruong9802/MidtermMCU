/*
 * seven_seg.c
 *
 *  Created on: Nov 7, 2022
 *      Author: DELL
 */

#include "seven_seg.h"

unsigned char SEG[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
void display7SEG(int num) {
	GPIOB->ODR = SEG[num];
}
