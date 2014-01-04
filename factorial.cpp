int factorial(n);
//Returns the factorial of n.
//The argument n should be non-negative.

int factorial(n)
{
	int product = 1;

	while (n > 0)
	{
		product = n * product;
		n--;
	}

	return product;
}
