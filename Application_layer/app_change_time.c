/*
 * update_time.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "app_change_time.h"
extern unsigned char secs,mins,hours;
extern unsigned char sec_rtc,min_rtc,hour_rtc;
void update()
{
	//this function is to update the time after each second,
	//to be displayed on the 7 segment when a min. pass and update the RTC after a min pass.
	secs++;
	if(secs==60)
	{
		secs=0;
		mins++;
		sec_rtc=secs;
		min_rtc=mins;
		hour_rtc=hours;
		hexa_to_decimal(&sec_rtc);							//as numbers saved in the rtc as hexa so just convert it
															//to decimal (its already decimal but treat it as hexa)
															//so the when its decimal the compiler treat it as decimal
															//but the RTC take it as hexa like 60H = 96 in decimal
		hexa_to_decimal(&min_rtc);
		hexa_to_decimal(&hour_rtc);
		RTC_SET_TIME(sec_rtc,min_rtc,hour_rtc); 			//update the time in the RTC if a min passed so if the circuit
															//is unplugged when it's
															//plugged again start from where it ends.
	}
	if(mins==60)
	{
		mins=0;
		hours++;
		if(hours==25)
		{
			hours=0;
		}
		sec_rtc=secs;
		min_rtc=mins;
		hour_rtc=hours;
		hexa_to_decimal(&sec_rtc); 						  //as RTC take numbers as hex
		hexa_to_decimal(&min_rtc);
		hexa_to_decimal(&hour_rtc);
		RTC_SET_TIME(sec_rtc,min_rtc,hour_rtc);			 //update time in the RTC if an hour passed
	}

}
void call_timer()
{
	timer_sec(&update);
	//this pointer to function is used for sake of the abstraction layer.
	//so when a second pass the timer call the update function which is in the app. layer while timer in the MCAL layer.
}
