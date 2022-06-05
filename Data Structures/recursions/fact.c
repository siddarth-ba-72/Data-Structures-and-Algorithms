#include <stdio.h>
#include <stdlib.h>

int factorial_recursive(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * factorial_recursive(n - 1);
}

int factorial_iterative(int n)
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
	int opt;
	printf("Enter 1 for recursive and 2 for iterative\n");
	int n;
	while (1)
	{
		printf("Enter your choice: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			printf("Enter the number: ");
			scanf("%d", &n);
			printf("Factorial of %d is %d\n\n", n, factorial_recursive(n));
			break;
		case 2:
			printf("Enter the number: ");
			scanf("%d", &n);
			printf("Factorial of %d is %d\n\n", n, factorial_iterative(n));
			break;
		default:
			printf("Invalid choice\n");
		}
	}
}
