/*
 * global.h
 *
 *  Created on: Nov 7, 2022
 *      Author: DELL
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"

#define INIT 1

#define WAIT 2
#define RESET 3
#define INCREASE 4
#define DECREASE 5

#define INCREASE_PRESSED_3S 8
#define DECREASE_PRESSED_3S 9

#define AUTO 10

extern int status;
extern int seven_seg_value;
extern int seven_seg_auto_value;

#endif /* INC_GLOBAL_H_ */
