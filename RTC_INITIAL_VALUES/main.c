/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include"headers.h"
#include"RTC.h"

int main()
{
	RTC_SET_TIME(0x12,0x01,0x17);
	while(1);
}

