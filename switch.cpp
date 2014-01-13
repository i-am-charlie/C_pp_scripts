//Don't forget your breaks!
//Program to illustrate the switch-statement for flow of control
#include <iostream>
using namespace std;

int main()
{
	char grade;

	cout << "Enter your Midterm grade and press Return: ";
	cin >> grade;

	switch (grade)
	{
		case 'A':
		case 'a':
			cout << "Excellent."
				 << "You need not take the final, then.\n";
			break;
		case 'B':
		case 'b':
			cout << "Very Good. ";
			grade = 'A';
			cout << "Your midterm grade is now "
				 << grade << endl;
			break;
		case 'C':
		case 'c':
			cout << "Passing.\n";
			break;
		case 'D':
		case 'd':
		case 'F':
		case 'f':
			cout << "Not good at all. "
				 << "You need to go and study.\n";
			break;
		default:
			cout << "That is not a possible grade.\n";
	}

	cout << "End of Program.\n";
	return 0;
}
