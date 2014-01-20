//this is the Implementation File for the ADT DigitalTime
//the interface for the class DigitalTime is in the header file dtime.h
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include "dtime.h"

//the following prototypes are for the def of the overloaded input operator
void read_hour(istream& ins, int& the_hour);
void read_minute(istream& ins, int& the_minute);
int digit_to_int(char c);

bool operator ==(const DigitalTime& time1, const DigitalTime& time2)
{
	return( time1.hour == time2.hour && time1.minute == time2.minute);
}

//uses iostream.h and stdlib.h
DigitalTime::DigitalTime(int the_hour, int the_minute)
{
	if (the_hour < 0 || the_hour > 23 || the_minute < 0 || the_minute > 59)
	{
		cout << "Illegal argument to DigitalTime constructor.";
		exit(1);
	}
	else
	{
		hour = the_hour;
		minute = the_minute;
	}
}

DigitalTime::DigitalTime()
{
	hour = 0;
	minute = 0;
}

void DigitalTime::advance(int minutes_added)
{
	int gross_minutes = minute + minutes_added;
	minute = gross_minutes%60;

	int hour_adjustment = gross_minutes/60;
	hour = (hour + hour_adjustment)%24;
}

void DigitalTime::advance(int hours_added, int minutes_added)
{
	hour = (hour + hours_added)%24;
	advance(minutes_added);
}

//uses iostream
istream& operator >>(istream& ins, DigitalTime& the_object)
{
	read_hour(ins, the_object.hour);
	read_minute(ins, the_object.minute);
	return ins;
}

ostream& operator <<(ostream& outs, const DigitalTime& the_object)
{
	outs << the_object.hour << ':';
	if (the_object.minute < 10)
		outs << '0';
	outs << the_object.minute;
	return outs;
}

int digit_to_int(char c)
{
	return ( int(c) - int('0') );
}

//uses iostream, ctype.h, and stdlib.h
void read_hour(istream& ins, int& the_hour)
{
	char c1, c2;
	ins >> c1 >> c2;
	if ( !( isdigit(c1) && (isdigit(c2) || c2 == ':' ) ) )
	{
		cout << "Error: Illegal input to read_hour\n";
		exit(1);
	}

	if (isdigit(c1) && c2 == ':' )
	{
		the_hour = digit_to_int(c1);
	}
	else // (isdigit(c1) && isdigit(c2))
	{
		the_hour = digit_to_int(c1)*10 + digit_to_int(c2);
		ins >> c2; //discard ':'
		if (c2 != ':')
		{
			cout << "Error: Illegal input to hour_read\n";
			exit(1);
		}
	}

	if (the_hour < 0 || the_hour > 23)
	{
		cout << "Error: Illegal input to hour_read\n";
		exit(1);
	}
}

//uses iostream, ctype.h, stdlib.h
void read_minute(istream& ins, int& the_minute)
{
	char c1, c2;
	ins >> c1 >> c2;

	if(!(isdigit(c1) && isdigit(c2)))
	{
		cout << "Error: Illegal input to read_minute\n";
		exit(1);
	}

	the_minute = digit_to_int(c1)*10 + digit_to_int(c2);

	if (the_minute < 0 || the_minute > 59)
	{
		cout << "Error: Illegal input to read_minute\n";
		exit(1);
	}

}
