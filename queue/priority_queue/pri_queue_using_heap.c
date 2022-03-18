#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int arr[50];
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
	n++;
	arr[n] = val;
	shiftUp_heap(n);
}

int getMax()
{
	int res = arr[0];
	arr[0] = arr[n];
	n--;
	shiftDown_heap(0);
	return res;
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

int maxNode()
{
	return arr[0];
}

void deleteQu(int i)
{
	arr[i] = maxNode() + 1;
	shiftUp_heap(i);
	getMax();
}

void deleteQuRoot()
{
	getMax();
}

void display()
{
	for (int i = 0; i <= n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	insertQu(5);
	insertQu(3);
	insertQu(7);
	insertQu(1);
	insertQu(2);
	insertQu(4);

	display();

	deleteQuRoot();
	deleteQuRoot();
	display();

	return 0;
}
