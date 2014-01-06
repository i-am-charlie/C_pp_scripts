//This program simply reads in 3 numbers from infile.dat and sums them,
//writing the ouput to the file outfile.dat
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	ifstream in_stream;
	ofstream out_stream;

	in_stream.open("infile.dat");
	if (in_stream.fail())
	{
		cout << "Input file opening has failed.\n";
		exit(1);
	}

	out_stream.open("outfile.dat");
	if (out_stream.fail())
	{
		cout << "Output file opening has failed.\n";
		exit(1);
	}

	int first, second, third;
	in_stream >> first >> second >> third;
	out_stream << "The sum of the first 3\n"
		   << "numbers in the file infile.dat\n"
		   << "is " << (first + second + third)
		   << endl;

	in_stream.close();
	out_stream.close();

	return 0;
}

