//this is a small program that Jack wants us to learn strings in C++
#include <iostream>
#include <string>

using namespace std;

int lb_to_kg(int pound);
const double KG_PER_LB = 0.45359237;

int main() 
{
	int weight, kilo, count = 0;
	string name;

	cout << "Your name? ";
	getline(cin, name);

	cout << "Your name, \"" << name << "\", is ";
	
	for (unsigned long i =0; i < name.length(); i++){
		count += 1;
	}

	if (count > 6){
		cout << "longer than \"Barack\".\n";
	}
	else if (count < 6){
		cout << "shorter than \"Barack\".\n";
	}
	else{
		cout << "the same length as \"Barack\".\n";
	}
	
	cout << "Your weight in pounds? ";
	cin >> weight;

	kilo = lb_to_kg(weight);

	cout << "That's " << kilo << " kilograms.\n";

	return 0;
}

int lb_to_kg(int pound)
{
	int kilo;
	kilo = (pound * KG_PER_LB);

	return kilo;
}
