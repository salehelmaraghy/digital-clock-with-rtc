/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "app_change_time.h"
#include"../HAL/SEGMENT_ONE.h"
#include "../HAL/RTC.h"
#include "../HAL/buttons.h"
unsigned char secs,mins,hours;
extern unsigned char sec_rtc,min_rtc,hour_rtc;
int main()
{
	buttons_init(); 							//initiate the buttons pins
	seg_init();									//initiate the 7 segment multiplexer
	timer_init();
	RTC_GET_TIME();								//get the time from RTC first if there is time saved as if the device is unplugged
	secs=sec_rtc;mins=min_rtc;hours=hour_rtc;
	while(1)
	{
	call_timer();								//check if a second passed
	check_pressed(); 							//check if a button is pressed to adjust the time
	print(mins,MIN,&update); 				//display the min on the 7 segment.
	print(hours,HOUR,&update); 				//display hours on the 7segment
	}
}




