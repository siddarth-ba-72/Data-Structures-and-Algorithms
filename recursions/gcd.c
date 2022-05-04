#include <stdio.h>

// * GCD USING MODULUS

int gcd_mod_iter(int m, int n)
{
	int r;
	while (n != 0)
	{
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}

int gcd_mod(int m, int n)
{
	if (n == 0)
		return m;
	return gcd_mod(n, m % n);
}

// * GCD USING CONSECUTIVE INTEGER CHECKING

int gcd_consecutive_int_iter(int m, int n)
{
	int small = m < n ? m : n;
	while (1)
	{
		if (m % small == 0 && n % small == 0)
			return small;
		small--;
	}
}

// * GCD USING REPETETIVE SUBTRACTION METHOD

int gcd_rep_sub(int m, int n)
{
	if (m == n)
		return m;
	if (m > n)
		return gcd_rep_sub(m - n, n);
	return gcd_rep_sub(m, n - m);
}

void main()
{
	int m, n;
	printf("Enter two numbers: ");
	scanf("%d %d", &m, &n);
	int res1 = gcd_mod(m, n);
	int res2 = gcd_consecutive_int_iter(m, n);
	int res3 = gcd_rep_sub(m, n);

	printf("GCD of %d and %d using modulus function is %d\n", m, n, res1);
	printf("GCD of %d and %d using consecutive integer checking function is %d\n", m, n, res2);
	printf("GCD of %d and %d using repetitive subtraction function is %d\n", m, n, res3);
}
