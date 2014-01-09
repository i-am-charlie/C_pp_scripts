//Slightly more advanced demonstration of classes
#include <iostream>
using namespace std;

class BankAccount
{
public:
	void set(int dollars, int cents, double rate);
	void set(int dollars, double rate);
	//these calls set the account balance and rates

	void update();
	//one year of simple interest added to acount balance
	
	double get_balance();
	double get_rate();

	void output(ostream& outs);

private:
	double balance;
	double interest_rate;

	double fraction(double percent);
	//simply converts a percent to a fraction  ex. fraction(50.3) = .503
};

int main()
{
	BankAccount account1, account2;
	cout << "Start of Test:\n";
	
	account1.set(123,99,3.0);
	cout << "account1 initial statement:\n";
	account1.output(cout);

	account1.set(100,5.0);
	cout << "account1 with new setup:\n";
	account1.output(cout);

	account1.update();
	cout << "account1 after accumulating interest will be: \n";
	account1.output(cout);

	account2 = account1;
	cout << "account2:\n";
	account2.output(cout);

	return 0;
}

void BankAccount::set(int dollars, int cents, double rate)
{
	balance = dollars + 0.01*cents;
	interest_rate = rate;
}

void BankAccount::set(int dollars, double rate)
{
	balance = dollars;
	interest_rate = rate;
}

void BankAccount::update()
{
	balance = balance + fraction(interest_rate)*balance;
}

double BankAccount::fraction(double percent)
{
	return (percent/100.0);
}

double BankAccount::get_balance()
{
	return balance;
}

double BankAccount::get_rate()
{
	return interest_rate;
}

void BankAccount::output(ostream& outs)
{
		outs.setf(ios::fixed);
		outs.setf(ios::showpoint);
		outs.precision(2);
		outs << "Account balance $" << balance << endl;
		outs << "Interest rate " << interest_rate << "%" << endl;
}
