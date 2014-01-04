//Program to convert a temperature given in Fahrenheit to a Celsius temperature.
#include <iostream>
using namespace std;

void initialize_screen();
//This function simply separates the output from the previously-run program
//by adding a blank line.

double celsius(double fahrenheit);
//Converts the fahrenheit temperature to a celsius temp.

void show_results(double f_temp, double c_temp);
//Displays output.
//Assumes that f_temp is equivalent to c_temp.

void get_input(double& f_temp);
//A call to this function will set the variable f_temp to a value read from the keyboard

int main()
{
	double f_temp, c_temp;

	initialize_screen();

	get_input(f_temp);

	initialize_screen();

	c_temp = celsius(f_temp);

	show_results(f_temp, c_temp);
	return 0;
}

void get_input(double& f_temp)
{
	cout << "I will convert a Fahrenheit temperature to Celsius.\n"
	     << "Enter a temperature in Fahrenheit: ";
	cin >> f_temp;
}

void initialize_screen()
{
	cout << endl;
	return;
}

void show_results(double f_temp, double c_temp)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);
	cout << f_temp << " degrees Fahrenheit is equivalent to\n"
	     << c_temp << " degrees Celsius.\n";
	return;
}

double celsius(double fahrenheit)
{
	return (5.0/9) * (fahrenheit - 32);
}
