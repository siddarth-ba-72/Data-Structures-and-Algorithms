#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * factorial(n - 1);
}

int factorialIterative(int n)
{
	int fact = 1;
	for (int i = 2; i < n; i++)
	{
		fact = fact * i;
	}
	return fact;
}

int main()
{
	int k;
	printdf("Enter number: ");
	scanf("%d", &k);
	printf("%d! = %d\n", k, factorial(k));
	return 0;
}
