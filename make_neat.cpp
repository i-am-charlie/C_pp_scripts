//This program takes in a messy file, rawdata.dat, and writes the numbers to the screen
//and to the file neat.dat in a neatly formatted way.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void make_neat(ifstream& messy_file, ofstream& neat_file, 
		int number_after_decimal, int field_width);
//This function essentially completes all tasks listed above.
//Numbers are written one per line, in fixed point notation (not in e-notation),
//with number_after_decimal digits after the decimal, preceded by a plus/minus,
//and each number is in a field of width field_width.

int main()
{
	ifstream fin;
	ofstream fout;

	fin.open("rawdata.dat");
	if (fin.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}

	fout.open("neat.dat");
	if (fout.fail())
	{
		cout << "Output file opening failed.\n";
		exit(1);
	}

	make_neat(fin, fout, 5, 12);

	fin.close();
	fout.close();

	cout << "End of Program.\n";
	return 0;
}

void make_neat(ifstream& messy_file, ofstream& neat_file,
		int number_after_decimal, int field_width)
{
	neat_file.setf(ios::fixed);
	neat_file.setf(ios::showpoint);
	neat_file.setf(ios::showpos);
	neat_file.precision(number_after_decimal);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.setf(ios::showpos);
	cout.precision(number_after_decimal);

	double next;
	while (messy_file >> next)
	{
		cout << setw(field_width) << next << endl;
		neat_file << setw(field_width) << next << endl;
	}
}

