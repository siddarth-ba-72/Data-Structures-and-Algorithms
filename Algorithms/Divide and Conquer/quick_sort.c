// * Quick Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

int partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low + 1, j = high + 1;
	while (i < j)
	{
		while (arr[i] <= pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		count++;
	}
	int temp = pivot;
	pivot = arr[j];
	arr[j] = temp;
	count++;
	return j;
}

void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}

int main()
{
	int n = 10;
	while (n < 10001)
	{
		printf("Size of Array = %d\n", n);
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 1000;
		}

		clock_t start, end;

		start = clock();
		quick_sort(arr, 0, n - 1);
		for (int j = 0; j < 500000; j++)
		{
			int temp = 38 / 500;
		}
		end = clock();

		printf("Count = %d", count);
		printf("\nTime taken to sort %d numbers = %f secs\n\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);

		n = n * 10;
	}
}
