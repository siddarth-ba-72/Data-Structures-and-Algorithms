#include <stdio.h>

int arr_sum(int arr[], int n)
{
	if (n == 1)
		return arr[0];
	return arr[n - 1] + arr_sum(arr, n - 1);
}

int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("Sum of the elements is %d\n", arr_sum(arr, n));
	return 0;
}
