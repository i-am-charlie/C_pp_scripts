//Program to demonstrate classes and private/public member variables/functions
#include <iostream>
using namespace std;

class DayOfYear
{
public:
	void input();
	void output();

	void set(int new_month, int new_day);
	//the date is reset according to the arguments
	
	int get_month();

	int get_day();

private:
	int month;
	int day;
};

int main()
{
	DayOfYear today, bach_birthday;
	cout << "Enter today's date:\n";
	today.input();
	cout << "Today's date is ";
	today.output();

	bach_birthday.set(3,21);
	cout << "J.S. Bach's birthday is ";
	bach_birthday.output();
	
	if ( today.get_month() == bach_birthday.get_month() &&
				today.get_day() == bach_birthday.get_day())
		cout << "Happy Birthday Johann Sebastion!\n";
	else
		cout << "It is not Bach's birthday, today.\n";
	
	return 0;
}

void DayOfYear::input()
{
	cout << "Enter the month as a number: ";
	cin >> month;
	cout << "Enter the day of the month: ";
	cin >> day;
}

void DayOfYear::output()
{
	cout << month << '/' << day;
}


void DayOfYear::set(int new_month, int new_day)
{
	month = new_month;
	day = new_day;
}

int DayOfYear::get_month()
{
	return month;
}

int DayOfYear::get_day()
{
 return day;
}
