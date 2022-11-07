/*
 * fsm_button.c
 *
 *  Created on: Nov 7, 2022
 *      Author: DELL
 */

#include "fsm_button.h"
#include "button.h"
#include "seven_seg.h"

int seven_seg_value = 0;
int control = 1;

void fsm_simple_buttons_run() {
	switch (status) {
		case INIT:
			display7SEG(seven_seg_value);

			status = WAIT;
			break;
		case WAIT:
			control = 1;
			if (singleClickReset()) {
				status = RESET;
			}
			if (singleClickInc()) {
				status = INCREASE;
			}
			if (singleClickDec()) {
				status = DECREASE;
			}
			break;
		case RESET:
			seven_seg_value = 0;
			display7SEG(seven_seg_value);

			if (isReleaseReset()) {
				status = WAIT;
			}
			break;
		case INCREASE:
			if (control == 1) {
				seven_seg_value++;
				if (seven_seg_value > 9) {
					seven_seg_value = 0;
				}
				display7SEG(seven_seg_value);
				control = 0;
			}

			if (isReleaseInc()) {
				status = WAIT;
			}
			break;
		case DECREASE:
			if (control == 1) {
				seven_seg_value--;
				if (seven_seg_value < 0) {
					seven_seg_value = 9;
				}
				display7SEG(seven_seg_value);
				control = 0;
			}

			if (isReleaseDec()) {
				status = WAIT;
			}
			break;
		default:
			break;
	}
}
