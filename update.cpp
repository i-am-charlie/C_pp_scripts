//Program to change all occurrences of 'C' in a file to 'C++'
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

void add_plus_plus(ifstream& in_stream, ofstream& out_stream);
//all contents from in_stream are copied into out_stream, except that
//all occurrences of 'C' have been changed to 'C++'

int main()
{
	ifstream fin;
	ofstream fout;

	cout << "Beginning editing files.\n";

	fin.open("cad.dat");
	if (fin.fail())
	{
       	    cout << "Input file opening failed.\n";
	    exit(1);
	}

	fout.open("cplusad.dat");
	if (fout.fail())
	{
	    cout << "Output file opening failed.\n";
	    exit(1);
	}

	add_plus_plus(fin, fout);

	fin.close();
	fout.close();

	cout << "End of editing files.\n";
	return 0;
}

void add_plus_plus(ifstream& in_stream, ofstream& out_stream)
{
	char next;

	in_stream.get(next);
	while (! in_stream.eof())
	{
	     if (next == 'C')
	     {
	     	out_stream << "C++";
	     }
	     
	     else
	     {
	        out_stream << next;
	     }
	     
	     in_stream.get(next);
	}
}
