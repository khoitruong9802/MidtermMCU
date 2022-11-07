/*
 * software_timer.c
 *
 *  Created on: Nov 7, 2022
 *      Author: DELL
 */

#include "software_timer.h"

int timer0_flag = 0;
int timer0_counter = 0;

void set_timer0(int duration) {
	timer0_counter = duration;
	timer0_flag = 0;
}

void clear_timer0() {
	timer0_flag = 0;
	timer0_counter = 0;
}

int timer1_flag = 0;
int timer1_counter = 0;

void set_timer1(int duration) {
	timer1_counter = duration;
	timer1_flag = 0;
}

void clear_timer1() {
	timer1_flag = 0;
	timer1_counter = 0;
}

void timer_run() {
	if (timer0_counter > 0) {
		timer0_counter--;
		if (timer0_counter <= 0) {
			timer0_flag = 1;
		}
	}
	if (timer1_counter > 0) {
		timer1_counter--;
		if (timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}
}
