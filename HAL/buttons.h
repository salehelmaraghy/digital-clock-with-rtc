/*
 * buttons.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_
#include "../Service_layer/headers.h"
#include"RTC.h"
#define but_dir DDRD
#define but_pin PIND

#define up_min 1
#define down_min 0
#define up_hour 3
#define down_hour 2
void buttons_init();
void check_pressed();
void update_time();

#endif /* BUTTONS_H_ */
