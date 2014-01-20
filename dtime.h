//this is the header file for the class DigitalTime.
//The values of this class are input and output in 24hr notation,
//as in 9:30 for 9:30AM and 14:40 for 2:40PM
#include <iostream>

using namespace std;

class DigitalTime
{
public:
	friend bool operator ==(const DigitalTime& time1, const DigitalTime& time2);

	DigitalTime(int the_hour, int the_minute);
	DigitalTime();
	//initializes the time to 0:00 (midnight)
	
	void advance(int minutes_added);
	void advance(int hours_added, int minutes_added);

	friend istream& operator >>(istream& ins, DigitalTime& the_object);
	friend ostream& operator <<(ostream& outs, const DigitalTime& the_object);

private:
	int hour;
	int minute;
};
