//Program to demonstrate defining an operation on objects
# include <iostream>

using namespace std;

class DayOfYear
{
public:
	friend bool equal(DayOfYear date1, DayOfYear date2);
	//returns true if date1 and date2 represent the same date
	
	DayOfYear(int the_month, int the_day);

	DayOfYear();
	//initializes dat to January first
	
	void input();

	void output();

	int get_month();
	//returns the month, 1 for Jan., 2 for Feb., etc
	
	int get_day();
	//returns the day of the month.
private:
	int month;
	int day;
};

int main()
{
	DayOfYear today, bach_birthday(3, 21);
	
	cout << "Enter today's date:\n";
	today.input();
	cout << "Today's date is ";
	today.output();
	cout << "J.S. Bach's birthday is ";
	bach_birthday.output();

	if (equal(today, bach_birthday))
		cout << "Happy Birthday Johann Sebastion!\n";
	else
		cout << "Well, no happy birthdays.\n";
	return 0;
}

bool equal(DayOfYear date1, DayOfYear date2)
{
	return ( date1.month == date2.month &&
				date1.day == date2.day );
}

DayOfYear::DayOfYear(int the_month, int the_day)
{
	month = the_month;
	day = the_day;
}


DayOfYear::DayOfYear()
{
	month = 1;
	day = 1;
}

int DayOfYear::get_month()
{ 
	return month;
}

int DayOfYear::get_day()
{
	return day;
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
	cout << "month = " << month
		 << " ,day = " << day << endl;
}
