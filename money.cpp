//Program to demonstrate the class 'Money'
#include <iostream>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

//Class for amounts of money in U.S. Currency
class Money
{
public:
	friend Money operator +(const Money& amount1, const Money& amount2);
	//returns the sum of the values of amount1 and amount2
	
	friend bool operator ==(const Money& amount1, const Money& amount2);
	//returns true if amount1 and amount2 are the same value
	
	Money(long dollars, int cents);
	Money(long dollars);
	//initializes the object so its value represents $dollars.00
	Money();
	//initializes to $0.00
	
	double get_value() const;
	void input(istream& ins);
	void output(ostream& outs) const;

private:
	long all_cents;
};


//prototype for use in the definition of Money::input
int digit_to_int(char c);
//returns the integer for the digit; i.e. digit_to_int('3') returns 3.


int main()
{
	Money cost(1, 50), tax(0, 50), total;
	total = cost + tax;

	cout << "cost = ";
	cost.output(cout);
	cout << endl;
	cout << "tax = ";
	tax.output(cout);
	cout << endl;
	cout << "total bill = ";
	total.output(cout);
	cout << endl;

	if( cost == tax )
		cout << "Move to another state.\n";
	else
		cout << "Things seem normal.\n";

	return 0;
}


Money operator +(const Money& amount1, const Money& amount2)
{
	Money temp;
	temp.all_cents = amount1.all_cents + amount2.all_cents;
	return temp;
}

bool operator ==(const Money& amount1, const Money& amount2)
{
	return (amount1.all_cents == amount2.all_cents);
}

Money::Money(long dollars, int cents)
{
	all_cents = dollars*100 + cents;
}

Money::Money(long dollars)
{
	all_cents = dollars*100;
}

Money::Money()
{
	all_cents = 0;
}

double Money::get_value() const
{
	return (all_cents * 0.01);
}


//uses iostream, ctype.h, stdlib.h
void Money::input(istream& ins)
{
	char one_char, decimal_point,
			digit1, digit2; //digits for the amount of cents
	long dollars;
	int cents;
	bool negative; //set to true if input is negative

	ins >> one_char;
	if (one_char == '-')
	{
		negative = true;
		ins >> one_char; //read '$'
	}
	else
		negative = false;
	//if input is legal than one_char == '$'
	
	ins >> dollars >> decimal_point >> digit1 >> digit2;

	if ( one_char != '$' || decimal_point != '.'
			|| !isdigit(digit1) || !isdigit(digit2) )
	{
		cout << "ERROR: illegal form of money input\n";
		exit(1);
	}
	cents = digit_to_int(digit1)*10 + digit_to_int(digit2);

	all_cents = dollars*100 + cents;
	if (negative)
		all_cents = -all_cents;
}


//uses stdlib.h and iostream
void Money::output(ostream& outs) const
{
	long positive_cents, dollars, cents;
	positive_cents = labs(all_cents);
	dollars = positive_cents / 100;
	cents = positive_cents % 100;

	if (all_cents < 0)
		outs << "-$" << dollars << ".";
	else
		outs << "$" << dollars << ".";
	
	if (cents < 10)
		outs << '0';
	outs << cents;
}

int digit_to_int(char c)
{
	return ( int(c) - int('0') );
}
