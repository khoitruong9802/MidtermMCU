/*
 * software_timer.h
 *
 *  Created on: Nov 7, 2022
 *      Author: DELL
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer0_flag;
extern int timer1_flag;

void set_timer0(int duration);
void clear_timer0();
void set_timer1(int duration);
void clear_timer1();

void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
