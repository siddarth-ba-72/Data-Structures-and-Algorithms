#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define QUEUE_SIZE 5

int isFuLL(int count)
{
	return count == QUEUE_SIZE;
}

int isEmpty(int count)
{
	return count == 0;
}

void enqueue(int qu[], int *rear, int *count)
{
	if (isFuLL(*count))
	{
		printf("Queue is full\n");
		return;
	}
	int item;
	printf("Enter the item to be enqueued: ");
	scanf("%d", &item);
	qu[++(*rear)] = item;
	(*count)++;
}

void dequeue(int qu[], int *front, int *count)
{
	if (isEmpty(*count))
	{
		printf("Queue is empty\n");
		return;
	}
	int item = qu[(*front)++];
	(*count)--;
	printf("Dequeued item is: %d\n", item);
}

void display(int qu[], int front, int rear, int count)
{
	if (isEmpty(count))
	{
		printf("Queue is empty\n");
		return;
	}
	int i;
	printf("Queue is: ");
	for (int i = front; i <= rear; i++)
	{
		printf("%d ", qu[i]);
	}
	printf("\n");
}

int main()
{
	int qu[QUEUE_SIZE];
	int front = 0, rear = -1, count = 0;
	int choice;
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	while (1)
	{
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			enqueue(qu, &rear, &count);
			display(qu, front, rear, count);
			break;
		case 2:
			dequeue(qu, &front, &count);
			display(qu, front, rear, count);
			break;
		case 3:
			display(qu, front, rear, count);
			break;
		case 4:
			exit(0);
		default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}
