#include <stdio.h>

int gcd_mod(int m, int n)
{
	if (n == 0)
		return m;
	return gcd_mod(n, m % n);
}

void main()
{
	int m, n, res;
	printf("Enter two numbers: ");
	scanf("%d %d", &m, &n);
	res = gcd_mod(m, n);
	printf("GCD of %d and %d is %d\n", m, n, res);
}
