//Program to demonstrate the functions new_line and get_input
#include <iostream>
using namespace std;

void new_line();
//discards all input remaining on current input line, including '\n'
//this version only works for keyboard input

void get_int(int& number);
//the variable number will be given a value that the user approves of


int main()
{

	int n;

	get_int(n);
	cout << "Final value read in and approved of = " << n << endl
	     << "End of demonstration.\n";

	return 0;
}

void new_line()
{
	char symbol;

	do
	{
		cin.get(symbol);
	} while (symbol != '\n');
}

void get_int(int& number)
{
	char ans;

	do
	{
	     cout << "Enter input number: ";
	     cin >> number;
	     cout << "You entered: " << number
	          << " Is that what you wanted? (yes/no)";
	     cin >> ans;
	     new_line();
	} while ((ans != 'Y') && (ans != 'y'));
}
