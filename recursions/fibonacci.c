#include <stdio.h>

// * DISLAY n FIBONACCI NUMBERS

void fib_iter(int n)
{
	int fib[50], i;
	fib[0] = 0;
	fib[1] = 1;
	for (i = 2; i <= n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	printf("Fibo series: ");
	for (i = 0; i <= n; i++)
	{
		printf("%d ", fib[i]);
	}
	printf("\n");
}

int fibonacci(int x)
{
	int fib;
	if (x == 1)
		return 0;
	else if (x == 2)
		return 1;
	else
		fib = fibonacci(x - 1) + fibonacci(x - 2);
	return fib;
}

void main()
{
	int n;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	fib_iter(n);
	printf("The %dth fibonacci number = %d\n", n, fibonacci(n));
}