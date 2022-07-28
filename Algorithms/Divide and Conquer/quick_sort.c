// * Quick Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

int partition(int arr[], int low, int high)
{
	int i = low;
	int j = high;
	int pivot = arr[low];
	while (i < j)
	{
		while (pivot >= arr[i])
			i++;
		while (pivot < arr[j])
			j--;
		if (i < j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[low];
	arr[low] = arr[j];
	arr[j] = temp;
	return j;
}

void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int j = partition(arr, low, high);
		quick_sort(arr, low, j - 1);
		quick_sort(arr, j + 1, high);
	}
}

int main()
{
	// int n = 10;
	// while (n < 10001)
	// {
	// 	printf("Size of Array = %d\n", n);
	// 	int arr[n];
	// 	for (int i = 0; i < n; i++)
	// 	{
	// 		arr[i] = rand() % 1000;
	// 	}

	// 	clock_t start, end;

	// 	start = clock();
	// 	quick_sort(arr, 0, n - 1);
	// 	for (int j = 0; j < 5000000; j++)
	// 	{
	// 		int temp = 38 / 500;
	// 	}
	// 	end = clock();

	// 	printf("Count = %d", count);
	// 	printf("\nTime taken to sort %d numbers = %f secs\n\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);

	// 	n = n * 10;
	// }

	int n;
	printf("n: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter the elements: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	quick_sort(arr, 0, n - 1);
	printf("Sorted array: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}
