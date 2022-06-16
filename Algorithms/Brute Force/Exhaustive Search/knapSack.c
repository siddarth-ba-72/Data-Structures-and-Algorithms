// * KnapSack problem
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int knap_sack(int W, int wts[], int vals[], int n)
{
	if (n == 0 || W == 0)
		return 0;
	if (wts[n - 1] > W)
		return knap_sack(W, wts, vals, n - 1);
	else
	{
		return max(
			vals[n - 1] + knap_sack(W - wts[n - 1], wts, vals, n - 1),
			knap_sack(W, wts, vals, n - 1));
	}
}

int main()
{
	int n;
	printf("Enter the number of items: ");
	scanf("%d", &n);
	int wts[n], vals[n];
	printf("Enter the weights: ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &wts[i]);
	}
	printf("Enter the values: ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vals[i]);
	}
	int W;
	printf("Enter the weight capacity: ");
	scanf("%d", &W);
	printf("The maximum value that can be put in the knapsack is: %d\n", knap_sack(W, wts, vals, n));

	return 0;
}
