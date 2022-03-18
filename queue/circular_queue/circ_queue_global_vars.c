#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define QUEUE_SIZE 5

int qu[QUEUE_SIZE];
int front = 0, rear = -1, count = 0;

int isFull()
{
	return count == QUEUE_SIZE;
}

int isEmpty()
{
	return count == 0;
}

void enqueue()
{
	if (isFull())
	{
		printf("Queue is full\n");
		return;
	}
	int item;
	printf("Enter the item to be enqueued: ");
	scanf("%d", &item);
	rear = (rear + 1) % QUEUE_SIZE;
	qu[rear] = item;
	count++;
}

int dequeue()
{
	if (isEmpty())
	{
		printf("Queue is empty\n");
		return INT_MIN;
	}
	int item = qu[front];
	front = (front + 1) % QUEUE_SIZE;
	count--;
	return item;
}

void display()
{
	if (isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	int i, f;
	f = front;
	printf("Queue is: ");
	for (i = 1; i <= count; i++)
	{
		printf("%d ", qu[f]);
		f = (f + 1) % QUEUE_SIZE;
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
			enqueue();
			display();
			break;
		case 2:
			printf("Deleted item is: %d\n", dequeue());
			display();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Invalid choice\n");
			break;
		}
	}
}
