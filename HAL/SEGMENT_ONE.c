/*
 * SEGMENT.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include"SEGMENT_ONE.h"


#ifdef numbers

void seg_init()
{
	//we are using 4 7-segments but instead of using 32 pins for them we connect them all at the same port and display the
	//time by illusion on them,by displaying a single number on one then display the other number on another 7-segment
	//which gives the illusion that they work together while it's only one at a time.
	SEG_DIR|=(1<<0)|(1<<1)|(1<<2)|(1<<3); 							// for the data
	SELECT|=(1<<2)|(1<<3)|(1<<4)|(1<<5);							// for the enable pins of them
}
void display(char a,char b,char type,fn_ptr ptr)
{
		a&=0x0f;	b&=0x0f;
		switch(type)
		{
		case MIN:
			//use the last two segments
			SELECT_OUT&=0xc3;									//display the 1st digit of the minutes.
			SELECT_OUT|=(1<<5);
			SEG_OUT&=0xf0;
			SEG_OUT|=b;
			timer_sec(ptr);										 //here so see the timer if  second passed
																//because the next delay is not good with polling
																//so we check on the timer before the delay.
			_delay_ms(5);
																//display the other digit of the minutes.
			SELECT_OUT&=0xc3;
			SELECT_OUT|=(1<<4);
			SEG_OUT&=0xf0;
			SEG_OUT|=a;
			timer_sec(ptr);
			_delay_ms(5);
			break;
		case HOUR:
			//use the first 2 segments
															//display the 1st digit of the hours
			SELECT_OUT&=0xc3;								//disable the other segments
			SELECT_OUT|=(1<<2);								//enable this segment
			SEG_OUT&=0xf0;									//mask the data that was saved
			SEG_OUT|=b;										//put the digit on the port
			timer_sec(ptr);									//check on the timer before the delay
			_delay_ms(5);
			SELECT_OUT&=0xc3;
			SELECT_OUT|=(1<<3);								//the same for the next digit
			SEG_OUT&=0xf0;
			SEG_OUT|=a;
			timer_sec(ptr);
			_delay_ms(5);
			break;
		default:
			break;
		}



}
void print(int number,char type,fn_ptr ptr)
{//as we will display digit by digit so this function is to separate digits of any number.
	unsigned char a=0,b=0;
	if(number>=0 && number<=9)
	{
		a=number;
		b=0;

	}
	else if(number>=10 && number<=99)
	{
		a=number%10;
		b=number/10;
	}
	switch(type)
	{
	case MIN:
		display(a,b,MIN,ptr);
		break;
	case HOUR:
		display(a,b,HOUR,ptr);
		break;
	default:
		break;
	}

}
#endif
#ifdef one_number

char digit=0;

void seg_init()
{
	DDRB|=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3); //data direction is output
	DDRC|=(1<<PC2);	//enable direction for one 7 segment
	PORTC|=(1<<PC2); //output the 7 segment
	DDRD&=~((1<<PD2)|(1<<PD3)); //for the push buttons
}
void display()
{
	PORTB&=0xf0; 
	if(digit>9)
	{
		digit=9;
	}
	if(digit<0)
	{
		digit=0;
	}
	digit&=0x0f;
	PORTB|=digit;
	_delay_ms(1000);

}
void button()
{
	//static char digit;
	if(PIND&(1<<PD2))
	{
		_delay_ms(100);
		digit++;
		display();
	}
	if(PIND&(1<<PD3))
	{
		_delay_ms(100);
		digit--;
		display();
	}
	//display();
}

#endif
