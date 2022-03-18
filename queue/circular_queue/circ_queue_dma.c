#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int QUEUE_SIZE = 5;

int *qu = NULL;
int front = 0, rear = -1, count = 0;

int isFull()
{
	return (count == QUEUE_SIZE);
}

int isEmpty()
{
	return (count == 0);
}

void enqueue()
{
	if (isFull())
	{
		qu = (int *)realloc(qu, 1 * sizeof(int));
		QUEUE_SIZE++;
		if (front > rear)
		{
			for (int i = QUEUE_SIZE - 2; i >= 0; i--)
				qu[i + 1] = qu[i];
			front++;
		}
	}
	int item;
	printf("Enter the item to be inserted: ");
	scanf("%d", &item);
	rear = (rear + 1) % QUEUE_SIZE;
	qu[rear] = item;
	count++;
}

void dequeue()
{
	if (isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	int item = qu[front];
	front = (front + 1) % QUEUE_SIZE;
	count--;
	printf("Deleted item is: %d\n", item);
}

void display()
{
	if (isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue is: ");
	for (int i = front; i <= rear; i++)
		printf("%d ", qu[i]);
	printf("\n");
}

int main()
{
	qu = (int *)malloc(QUEUE_SIZE * sizeof(int));
	int choice;
	printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
	while (1)
	{
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			enqueue();
			display();
			break;
		case 2:
			dequeue();
			display();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}
