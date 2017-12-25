/*
 * buttons.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include"buttons.h"


extern unsigned char mins,hours;
extern unsigned char sec_rtc,min_rtc,hour_rtc;
void buttons_init()
{
	but_dir&=0xf0; 										//portD from 0 to 4 as inputs

}
void check_pressed()
{
	if(but_pin&(1<<up_min)) 							//If button is pressed
	{
		_delay_ms(200);
		mins++;
		min_rtc=mins;
		hexa_to_decimal(&min_rtc);						//as the RTC take the time as hexa so treat the decimal number as hexa
														//then convert it to decimal so the RTC take the number thinking it's hexa
														//while you converted it..[think about it it's tricky somehow].

		RTC_SET_TIME(sec_rtc,min_rtc,hour_rtc);			//update the RTC by time if time changed by the buttons.
	}
	if(but_pin&(1<<down_min))
	{
		_delay_ms(200);
		mins--;
		min_rtc=mins;
		hexa_to_decimal(&min_rtc);
		RTC_SET_TIME(sec_rtc,min_rtc,hour_rtc);

	}
	if(but_pin&(1<<up_hour))
	{
		_delay_ms(200);
		hours++;
		hour_rtc=hours;
		//hexa_to_decimal(&sec_rtc);
		//hexa_to_decimal(&min_rtc);
		hexa_to_decimal(&hour_rtc);
		RTC_SET_TIME(sec_rtc,min_rtc,hour_rtc);
	}
	if(but_pin&(1<<down_hour))
	{
		_delay_ms(200);
		hours--;
		hour_rtc=hours;
		//hexa_to_decimal(&sec_rtc);
		//hexa_to_decimal(&min_rtc);
		hexa_to_decimal(&hour_rtc);
		RTC_SET_TIME(sec_rtc,min_rtc,hour_rtc);
	}
	update_time();
}
void update_time()
{
	//this function is to update the time.
	if(mins==60)
	{
		mins=0;
		hours++;
	}
	if(hours==25)
	{
		hours=0;
	}
}
