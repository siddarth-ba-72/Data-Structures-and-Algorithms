#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int count = 0;

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
			count++;
		}
		else
		{
			arr[k] = R[j];
			j++;
			count++;
		}
		k++;
		count++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
		count++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
		count++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
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
		mergeSort(arr, 0, n - 1);
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