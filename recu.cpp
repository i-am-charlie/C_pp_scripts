#include <iostream>
using namespace std;

void write_vert(int n)
{
	if (n < 10)
	{	
		cout << n << endl;
	}
	else
	{
		write_vert(n / 10);
		cout << n % 10 << endl;
	}
}

int main()
{
	int number;

	cout << "Please enter a number to be written to the screen vertically: ";
	cin >> number;

	write_vert(number);

	cout << "Taa - Daa!!" << endl;

	return 0;
}


	
