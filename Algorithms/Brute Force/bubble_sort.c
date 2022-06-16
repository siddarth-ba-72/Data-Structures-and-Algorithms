#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n)
{
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				count++;
			}
		}
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
	bubbleSort(arr, n);
	end = clock();
	tyme = (double)(end - start) / CLOCKS_PER_SEC;

	printf("Time taken: %f\n", tyme);

	return 0;
}
