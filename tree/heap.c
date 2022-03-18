#include <stdio.h>
#include <stdlib.h>
#define max_size 10

int insertHeap(int item, int arr[], int n)
{
	int c, p;
	if (n == max_size)
	{
		printf("Heap is full\n");
		return n;
	}
	c = n;
	p = (c - 1) / 2;
	while (c != 0 && item > arr[p])
	{
		arr[c] = arr[p];
		c = p;
		p = (c - 1) / 2;
	}
	arr[c] = item;
	return n + 1;
}

int deleteHeap(int arr[], int n)
{
	int p, c;
	if (n == 0)
	{
		printf("Heap is empty\n");
		return n;
	}
	printf("Item deleted is %d\n", arr[0]);
	p = 0;
	c = 1;
	while (c < n)
	{
		if (c + 1 < n)
		{
			if (arr[c] < arr[c + 1])
				c++;
		}
		arr[p] = arr[c];
		p = c;
		c = 2 * p + 1;
	}
	return n - 1;
}

void display(int arr[], int n)
{
	int i;
	if (n == 0)
	{
		printf("Heap is empty\n");
		return;
	}
	printf("The priority queue contents: ");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int a[max_size];
	int n = 0;
	int choice, item;
	printf("Max Heap implementation\n");
	printf("1.Insert\n2.Delete\n");
	printf("3.Display\n4.Exit\n");
	while (1)
	{
		printf("Enter the choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the item to be inserted: ");
			scanf("%d", &item);
			n = insertHeap(item, a, n);
			display(a, n);
			break;
		case 2:
			n = deleteHeap(a, n);
			display(a, n);
			break;
		case 3:
			display(a, n);
			break;
		case 4:
			printf("Program terminates now\n");
			exit(0);
		default:
			printf("Please enter a valid choice...\n");
		}
	}
}
