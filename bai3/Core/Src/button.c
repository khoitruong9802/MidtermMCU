/*
 * button.c
 *
 *  Created on: Nov 7, 2022
 *      Author: DELL
 */

#include "button.h"

//////////////////// BUTTON RESET ///////////////////////
int TimerForKeyPressReset = RESET_TIMER_FOR_KEY_PRESS;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

int KeyReg3 = NORMAL_STATE;

int button0_flag = 0;

int singleClickReset() {
	if (button0_flag == 1) {
		button0_flag = 0;
		return 1;
	}
	return 0;
}

int longClickReset() {
	if (button0_flag == 2) {
		button0_flag = 0;
		return 1;
	}
	return 0;
}

int isReleaseReset() {
	if (button0_flag == 3) {
		return 1;
	}
	return 0;
}

void getKeyInputReset() {
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7);
	if (KeyReg0 == KeyReg1 && KeyReg1 == KeyReg2) {
		if (KeyReg3 != KeyReg2) {
			KeyReg3 = KeyReg2;
			if (KeyReg2 == PRESSED_STATE) {
				//TODO
				button0_flag = 1;
				TimerForKeyPressReset = RESET_TIMER_FOR_KEY_PRESS;
			}
			if (KeyReg2 == NORMAL_STATE) {
				//TODO
				button0_flag = 3;
			}
		} else {
			if (KeyReg2 == PRESSED_STATE) {
				TimerForKeyPressReset--;
			}
			if (TimerForKeyPressReset <= 0) {
				//TODO
				button0_flag = 2;
				TimerForKeyPressReset = RESET_TIMER_FOR_KEY_PRESS;
			}
		}
	}
}

//////////////////// BUTTON INC ///////////////////////

int TimerForKeyPressInc = RESET_TIMER_FOR_KEY_PRESS;

int KeyReg4 = NORMAL_STATE;
int KeyReg5 = NORMAL_STATE;
int KeyReg6 = NORMAL_STATE;

int KeyReg7 = NORMAL_STATE;

int button1_flag = 0;

int singleClickInc() {
	if (button1_flag == 1) {
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int longClickInc() {
	if (button1_flag == 2) {
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isReleaseInc() {
	if (button1_flag == 3) {
		return 1;
	}
	return 0;
}

void getKeyInputInc() {
	KeyReg4 = KeyReg5;
	KeyReg5 = KeyReg6;
	KeyReg6 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8);
	if (KeyReg4 == KeyReg5 && KeyReg5 == KeyReg6) {
		if (KeyReg7 != KeyReg6) {
			KeyReg7 = KeyReg6;
			if (KeyReg6 == PRESSED_STATE) {
				//TODO
				button1_flag = 1;
				TimerForKeyPressInc = RESET_TIMER_FOR_KEY_PRESS;
			}
			if (KeyReg6 == NORMAL_STATE) {
				//TODO
				button1_flag = 3;
			}
		} else {
			if (KeyReg6 == PRESSED_STATE) {
				TimerForKeyPressInc--;
			}
			if (TimerForKeyPressInc <= 0) {
				//TODO
				button1_flag = 2;
				TimerForKeyPressInc = RESET_TIMER_FOR_KEY_PRESS;
			}
		}
	}
}

//////////////////// BUTTON DEC ///////////////////////

int TimerForKeyPressDec = RESET_TIMER_FOR_KEY_PRESS;

int KeyReg8 = NORMAL_STATE;
int KeyReg9 = NORMAL_STATE;
int KeyReg10 = NORMAL_STATE;

int KeyReg11 = NORMAL_STATE;

int button2_flag = 0;

int singleClickDec() {
	if (button2_flag == 1) {
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int longClickDec() {
	if (button2_flag == 2) {
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isReleaseDec() {
	if (button2_flag == 3) {
		return 1;
	}
	return 0;
}

void getKeyInputDec() {
	KeyReg8 = KeyReg9;
	KeyReg9 = KeyReg10;
	KeyReg10 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9);
	if (KeyReg8 == KeyReg9 && KeyReg9 == KeyReg10) {
		if (KeyReg11 != KeyReg10) {
			KeyReg11 = KeyReg10;
			if (KeyReg10 == PRESSED_STATE) {
				//TODO
				button2_flag = 1;
				TimerForKeyPressDec = RESET_TIMER_FOR_KEY_PRESS;
			}
			if (KeyReg10 == NORMAL_STATE) {
				//TODO
				button2_flag = 3;
			}
		} else {
			if (KeyReg10 == PRESSED_STATE) {
				TimerForKeyPressDec--;
			}
			if (TimerForKeyPressDec <= 0) {
				//TODO
				button2_flag = 2;
				TimerForKeyPressDec = RESET_TIMER_FOR_KEY_PRESS;
			}
		}
	}
}
