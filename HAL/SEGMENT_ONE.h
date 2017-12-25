/*
 * SEGMENT.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#ifndef SEGMENT_ONE_H_
#define SEGMENT_ONE_H_
#include "../Service_layer/headers.h"
#include "../MCAL/timer.h"

#define SEG_DIR DDRB
#define SEG_OUT PORTB
#define SELECT DDRC
#define SELECT_OUT PORTC

#define MIN 0
#define HOUR 1

#define numbers
//#define one_number

//extern unsigned char digit;
void seg_init();
#ifdef numbers
void display(char a,char b,char type,fn_ptr ptr);
void print(int number,char type,fn_ptr ptr);
#endif
#ifdef one_number
void display();
void button();
#endif

#endif /* SEGMENT_ONE_H_ */
