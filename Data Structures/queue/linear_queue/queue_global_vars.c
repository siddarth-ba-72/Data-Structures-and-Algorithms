#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define QUEUE_SIZE 5

int qu[QUEUE_SIZE];
int front = 0;
int rear = -1;
int size = 0;

int isEmpty()
{
	return size == 0;
}

int isFull()
{
	return size == QUEUE_SIZE;
}

void enQueue()
{
	if (isFull())
	{
		printf("Queue is full\n");
		return;
	}
	int item;
	printf("Enter the item to be enqueued: ");
	scanf("%d", &item);
	rear++;
	qu[rear] = item;
	size++;
}

int dequeue()
{
	if (isEmpty())
	{
		printf("Queue is empty\n");
		return INT_MIN;
	}
	int item = qu[front++];
	size--;
	return item;
}

void diplayQueue()
{
	if (isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue is: ");
	for (int i = front; i <= rear; i++)
	{
		printf("%d ", qu[i]);
	}
	printf("\n");
}

int main()
{
	int choice;
	printf("1. Add to Queue \n");
	printf("2. Delete from Queue \n");
	printf("3. Display Queue \n");
	printf("4. Exit \n");

	while (1)
	{
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			enQueue();
			diplayQueue();
			break;
		case 2:
			printf("%d \n", dequeue());
			diplayQueue();
			break;
		case 3:
			diplayQueue();
			break;
		case 4:
			exit(0);
		default:
			printf("Invalid choice\n");
		}
	}

	return 0;
}
