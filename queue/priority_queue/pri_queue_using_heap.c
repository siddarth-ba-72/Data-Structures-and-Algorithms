#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 50

int arr[MAX];
int n = -1;

int parent(int i)
{
	return (i - 1) / 2;
}

int leftChild(int i)
{
	return (2 * i) + 1;
}

int rightChild(int i)
{
	return (2 * i) + 2;
}

void shiftUp_heap(int i)
{
	while (i >= 0 && arr[parent(i)] < arr[i])
	{
		int temp = arr[i];
		arr[i] = arr[parent(i)];
		arr[parent(i)] = temp;
		i = parent(i);
	}
}

void shiftDown_heap(int i)
{
	int maxIdx = i;
	int l = leftChild(i);
	int r = rightChild(i);
	if (l <= n && arr[l] > arr[maxIdx])
		maxIdx = l;
	if (r <= n && arr[r] > arr[maxIdx])
		maxIdx = r;
	if (i != maxIdx)
	{
		int temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
		shiftDown_heap(maxIdx);
	}
}

void insertQu(int val)
{
	if (n == MAX)
	{
		printf("Heap is Full\n");
		return;
	}
	printf("Enter the element to insert: ");
	scanf("%d", &val);
	n++;
	arr[n] = val;
	shiftUp_heap(n);
}

void changePriority(int i, int val)
{
	int old_priority = arr[i];
	arr[i] = val;
	if (old_priority < val)
		shiftUp_heap(i);
	else
		shiftDown_heap(i);
}

void deleteQuRoot()
{
	int res = arr[0];
	arr[0] = arr[n];
	n--;
	shiftDown_heap(0);
	printf("Root deleted = %d\n", res);
}

void display()
{
	for (int i = 0; i <= n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int choice, val;
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
			insertQu(val);
			display();
			break;
		case 2:
			deleteQuRoot();
			display();
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("Enter the valid choice \n");
			break;
		}
	}

	return 0;
}
