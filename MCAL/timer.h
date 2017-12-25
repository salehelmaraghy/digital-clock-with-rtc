/*
 * timer_one_sec.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "../Service_layer/headers.h"
#define LED_DIR DDRD
#define LED_PORT PORTD

void timer_init();
void timer_sec(fn_ptr ptr);



#endif /* TIMER_H_ */
