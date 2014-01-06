//This program simply reads in 3 numbers from infile.dat and sums them,
//writing the ouput to the file outfile.dat
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	char in_file_name[16], out_file_name[16];
	ifstream in_stream;
	ofstream out_stream;

	cout << "I will sum up the first three numbers taken from an input\n"
	     << "file and write the sum to an ouput file.\n";
	cout << "Enter the input file name (max. of 15 characters, please):\n";
	cin >> in_file_name;
	cout << "Enter the output file name (max. of 15 characters, please):\n";
	cin >> out_file_name;
	cout << "Ok.  I will read the first three numbers from the file "
	     << in_file_name << " and \n"
	     << "place the sum in the file "
	     << out_file_name << endl;

	in_stream.open(in_file_name);
	if (in_stream.fail())
	{
		cout << "Input file opening has failed.\n";
		exit(1);
	}

	out_stream.open(out_file_name);
	if (out_stream.fail())
	{
		cout << "Output file opening has failed.\n";
		exit(1);
	}

	int first, second, third;
	in_stream >> first >> second >> third;
	out_stream << "The sum of the first 3\n"
		   << "numbers in " << in_file_name << endl
		   << "is " << (first + second + third)
		   << endl;

	in_stream.close();
	out_stream.close();

	cout << "End of Program.\n";
	return 0;
}

