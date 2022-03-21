#include <stdio.h>

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
	printf("The %dth fibonacci number = %d\n", n, fibonacci(n));
	printf("Fibonacci series: ");
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", fibonacci(i));
	}
}