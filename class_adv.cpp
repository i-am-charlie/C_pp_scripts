//Slightly more advanced demonstration of classes
#include <iostream>
#include <math.h>
using namespace std;

class BankAccount
{
public:
	BankAccount(); //initializes to a blance of $0.00 and rate 0.0%
	
	BankAccount(int dollars, double rate);

	BankAccount(int dollars, int cents, double rate);
	//initializes account balance to $dollars.cents and rate rate%

	void set(int dollars, int cents, double rate);
	void set(int dollars, double rate);
	//these calls set the account balance and rates

	void update();
	//one year of simple interest added to acount balance
	
	double get_balance();
	double get_rate();

	void output(ostream& outs);

private:
	double dollars_part;
	double cents_part;
	double interest_rate; //expressed as a fraction, e.g. 0.057 for 5.7%

	double fraction(double percent);
	//simply converts a percent to a fraction  ex. fraction(50.3) = .503
	
	double percent(double fraction_value);
	//converts a fraction to a percent.  ex. percent(0.503) returns 50.3%
};

int main()
{
	BankAccount account1(100, 2.3), account2;
	
	cout << "account1 initialized as follows:\n";
	account1.output(cout);
	cout << "account2 initialized as follows:\n";
	account2.output(cout);

	account1 = BankAccount(999, 99, 5.5);
	cout << "account1 reset to the following: \n";
	account1.output(cout);

	return 0;
}

BankAccount::BankAccount()
{
	dollars_part = 0;
	cents_part = 0;
	interest_rate = 0.00;
}

BankAccount::BankAccount(int dollars, int cents, double rate)
{
	dollars_part = dollars;
	cents_part = cents;
	interest_rate = fraction(rate);
}

BankAccount::BankAccount(int dollars, double rate)
{
	dollars_part = dollars;
	cents_part = 0;
	interest_rate = fraction(rate);
}

void BankAccount::set(int dollars, int cents, double rate)
{
	dollars_part = dollars;
	cents_part = cents;
	interest_rate = rate;
}

void BankAccount::set(int dollars, double rate)
{
	dollars_part = dollars;
	cents_part = 0;
	interest_rate = rate;
}

void BankAccount::update()
{
	double balance = get_balance();
	balance = balance + interest_rate*balance;
	dollars_part = floor(balance);
	cents_part = floor((balance-dollars_part)*100);
}

double BankAccount::fraction(double percent)
{
	return (percent/100.0);
}

double BankAccount::percent(double fraction_value)
{
	return (fraction_value*100.0);
}
double BankAccount::get_balance()
{
	return (dollars_part + 0.01*cents_part);
}

double BankAccount::get_rate()
{
	return percent(interest_rate);
}

void BankAccount::output(ostream& outs)
{
		outs.setf(ios::fixed);
		outs.setf(ios::showpoint);
		outs.precision(2);
		outs << "Account balance $" << get_balance() << endl;
		outs << "Interest rate " << get_rate() << "%" << endl;
}
