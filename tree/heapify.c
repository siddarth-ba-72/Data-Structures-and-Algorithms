#include <stdio.h>
#include <stdlib.h>
#define max_size 10

void heapify(int arr[], int n, int i)
{
	int parent = (i - 1) / 2;
	if (arr[parent] > 0)
	{
		if (arr[i] > arr[parent])
		{
			int temp = arr[i];
			arr[i] = arr[parent];
			arr[parent] = temp;
			heapify(arr, n, parent);
		}
	}
}

void insertNode(int arr[], int n, int item)
{
	if (n == max_size)
	{
		printf("Heap is full\n");
		return;
	}
	n = n + 1;
	arr[n - 1] = item;
	heapify(arr, n, n - 1);
}

void deleteRoot(int arr[], int n)
{
	int leaf = arr[n - 1];
	arr[0] = leaf;
	n = n - 1;
	heapify(arr, n, n - 1);
}

void displayHeap(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[max_size], n = 0, item, choice;
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	do
	{
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the item to be inserted: ");
			scanf("%d", &item);
			insertNode(arr, n, item);
			displayHeap(arr, n);
			break;
		case 2:
			deleteRoot(arr, n);
			displayHeap(arr, n);
			break;
		case 3:
			displayHeap(arr, n);
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Invalid choice\n");
		}
	} while (choice != 4);
	return 0;
}
