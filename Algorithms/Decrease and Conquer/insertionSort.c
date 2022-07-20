#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
			count++;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	int arr[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}

	clock_t start, end;

	start = clock();
	insertionSort(arr, n);
	end = clock();

	printf("Count = %d", count);
	printf("\nTime taken to sort %d numbers = %f secs\n\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);

	return 0;
}
