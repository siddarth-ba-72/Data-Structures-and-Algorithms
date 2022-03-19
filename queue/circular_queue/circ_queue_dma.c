#include <stdio.h>
#include <stdlib.h>

int QSIZE = 2;
int *q = NULL, front = 0, rear = -1, count = 0;

int isQfull()
{
	if (count == QSIZE)
		return 1;
	return 0;
}

int isQempty()
{
	if (count == 0)
		return 1;
	return 0;
}

void insertQ()
{
	int item, i;
	if (isQfull())
	{
		q = realloc(q, (++QSIZE) * sizeof(int));
		// if (front > rear)
		// {
		// 	for (i = QSIZE - 2; i >= front; i--)
		// 		q[i + 1] = q[i];
		// 	front++;
		// }
	}
	printf("Enter an item: ");
	scanf("%d", &item);
	rear = (rear + 1) % QSIZE;
	q[rear] = item;
	count++;
}

void deleteQ()
{
	int item;
	if (isQempty())
		printf("Queue is empty\n");
	else
	{
		item = q[front];
		front = (front + 1) % QSIZE;
		count--;
		printf("Item deleted: %d\n", item);
	}
}

void displayQ()
{
	int i, f;
	if (isQempty())
		printf("Queue is empty\n");
	else
	{
		printf("Items in the Queue : ");
		f = front;
		for (i = 1; i <= count; i++)
		{
			printf("%d ", q[f]);
			f = (f + 1) % QSIZE;
		}
		printf("\n");
	}
}

void main()
{
	int choice;
	q = (int *)malloc(QSIZE * sizeof(int));
	printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
	while (1)
	{
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			insertQ();
			displayQ();
			break;
		case 2:
			deleteQ();
			displayQ();
			break;
		case 3:
			displayQ();
			break;

		case 4:
			printf("\nThank you... The circular program exits now\n");
			exit(0);

		default:
			printf("\nInvalid choice... Please enter correct choice");
		}
	}
}
