//Determines which of two pizza sizes is a better bang for your buck,
//given two pizza sizes and their corresponding prices.
#include <iostream>
#include <math.h>
using namespace std;

double unitprice(int diam, double price);
//Returns the price per square inch of a pizza.

int main(){
	int diam_sm, diam_lg;
	double price_sm, unitprice_sm,
	       price_lg, unitprice_lg;
	
	cout << "Welcome to the Pizza Consumers for a More Just World group!\n";
	cout << "Enter the diameter of a small pizza (in inches): ";
	cin >> diam_sm;
	cout << "Enter the price of a small pizza: $";
	cin >> price_sm;
	cout << "Enter the diameter of a large pizza (in inches): ";
	cin >> diam_lg;
	cout << "Enter the price of a large pizza: $";
	cin >> price_lg;

	unitprice_sm = unitprice(diam_sm, price_sm);
      	unitprice_lg = unitprice(diam_lg, price_lg);
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "Small pizza:\n" << "Diameter = " << diam_sm << " inches\n"
	     << "Price = $" << price_sm << " Per square inch = $" << unitprice_sm << endl;
	cout << "Large pizza:\n" << "Diameter = " << diam_lg << " inches\n"
	     << "Price = $" << price_lg << " Per square inch = $" << unitprice_lg << endl
	     << endl;
	
	if (unitprice_lg < unitprice_sm)
		cout << "The Large pizza is the better buy.\n";
	else
		cout <<"The Small pizza is the better buy.\n";
	cout << "Buon Appetito!\n";

}

double unitprice(int diam, double price)
{
	const double PI = 3.14159;
	double radius, area;

	radius = diam / double(2);  //the double allows for odd-sized pizzas
	area = PI * pow(radius, 2);
	return (price/area);
}
