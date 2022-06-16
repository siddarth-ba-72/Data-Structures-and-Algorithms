// * Selection Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n)
{
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
				count++;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
	printf("Count = %d\n", count);
}

int main()
{
	double tyme;
	clock_t start, end;

	int n;
	printf("n: ");
	scanf("%d", &n);

	int arr[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 1000;
	}

	start = clock();
	selectionSort(arr, n);
	end = clock();
	tyme = (double)(end - start) / CLOCKS_PER_SEC;

	printf("Time taken: %f\n", tyme);

	return 0;
}

// * Time Complexity: O(n^2)
