/*
 * timer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "timer.h"

volatile unsigned char cnt=0;
ISR(TIMER0_OVF_vect)
{
	cnt++;
}
void timer_init()
{
	LED_DIR|=(1<<4);
	LED_PORT&=~(1<<4);									//toggle this led each second
	TCNT0=0;
	TCCR0=0x04;											//prescaler 256
	TIMSK|=(1<<TOIE0);									//enable timer overflow interrupt
	SREG|=(1<<7);										//enable global interrupt
}
void timer_sec(fn_ptr ptr)
{
	if(cnt==122)
	{
		cnt=0;
		(*ptr)(); 										 //call a function in the application layer when a second pass.
		LED_PORT^=(1<<4);								 //toggle this led when a second pass.
	}
}

