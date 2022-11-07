/*
 * fsm_button.c
 *
 *  Created on: Nov 7, 2022
 *      Author: DELL
 */

#include "fsm_button.h"
#include "button.h"
#include "seven_seg.h"
#include "software_timer.h"

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
			if (timer0_flag == 1) {
				set_timer0(100);
				status = AUTO;
			}
			if (singleClickReset()) {
				status = RESET;
			}
			if (singleClickInc()) {
				set_timer0(200);
				status = INCREASE;
			}
			if (singleClickDec()) {
				set_timer0(200);
				status = DECREASE;
			}
			break;
		case RESET:
			seven_seg_value = 0;
			display7SEG(seven_seg_value);

			if (isReleaseReset()) {
				set_timer0(900);
				status = WAIT;
			}
			break;
		case INCREASE:
			if (control == 1) {
				seven_seg_value++;
				if (seven_seg_value > 9) {
					seven_seg_value = 0;
				}
				control = 0;
			}
				display7SEG(seven_seg_value);

			if (isReleaseInc()) {
				set_timer0(900);
				status = WAIT;
			}
			if (timer0_flag == 1) {
				set_timer0(100);
				status = INCREASE_PRESSED_3S;
			}
			break;
		case DECREASE:
			if (control == 1) {
				seven_seg_value--;
				if (seven_seg_value < 0) {
					seven_seg_value = 9;
				}
				control = 0;
			}
				display7SEG(seven_seg_value);

			if (isReleaseDec()) {
				set_timer0(900);
				status = WAIT;
			}
			if (timer0_flag == 1) {
				set_timer0(100);
				status = DECREASE_PRESSED_3S;
			}
			break;
		case INCREASE_PRESSED_3S:
			if (timer0_flag == 1) {
				seven_seg_value++;
				if (seven_seg_value > 9) {
					seven_seg_value = 0;
				}
				set_timer0(100);
			}
			display7SEG(seven_seg_value);
			if (isReleaseInc()) {
				set_timer0(900);
				status = WAIT;
			}
			break;
		case DECREASE_PRESSED_3S:
			if (timer0_flag == 1) {
				seven_seg_value--;
				if (seven_seg_value < 0) {
					seven_seg_value = 9;
				}
				set_timer0(100);
			}
			display7SEG(seven_seg_value);
			if (isReleaseDec()) {
				set_timer0(900);
				status = WAIT;
			}
			break;
		case AUTO:
			if (timer0_flag == 1) {
				seven_seg_value--;
				if (seven_seg_value < 0) {
					seven_seg_value = 0;
				}
				set_timer0(100);
			}
			display7SEG(seven_seg_value);
			if (singleClickReset()) {
				status = RESET;
			}
			if (singleClickInc()) {
				set_timer0(200);
				status = INCREASE;
			}
			if (singleClickDec()) {
				set_timer0(200);
				status = DECREASE;
			}
			break;
		default:
			break;
	}
}
