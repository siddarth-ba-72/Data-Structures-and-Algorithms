#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int QUEUE_SIZE = 5;

int *qu = NULL;
int front = 0, rear = -1;

int isFull()
{
	return (rear == QUEUE_SIZE - 1);
}

int isEmpty()
{
	return (rear < front);
}

void enqueue()
{
	if (isFull())
	{
		qu = (int *)realloc(qu, (++QUEUE_SIZE) * sizeof(int));
	}
	int item;
	printf("Enter the item to be inserted: ");
	scanf("%d", &item);
	qu[++rear] = item;
}

void dequeue()
{
	if (isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	int item = qu[front++];
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
