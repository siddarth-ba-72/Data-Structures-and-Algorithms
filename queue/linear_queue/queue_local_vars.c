#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define QUEUE_SIZE 5

int isEmpty(int front, int rear)
{
	return rear < front;
}

int isFull(int rear)
{
	return rear == QUEUE_SIZE - 1;
}

void enqueue(int qu[], int *rear, int val)
{
	if (isFull(*rear))
	{
		printf("Queue is full\n");
		return;
	}
	qu[++(*rear)] = val;
}

int dequeue(int qu[], int rear, int *front)
{
	if (isEmpty(rear, *front))
	{
		printf("Queue is empty\n");
		return -1;
	}
	int item = qu[(*front)++];
	return item;
}

void display(int qu[], int front, int rear)
{
	if (isEmpty(front, rear))
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
	int qu[QUEUE_SIZE];
	int front = 0, rear = -1;
	int choice;
	int val;
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
			printf("Enter the item to be enqueued: ");
			scanf("%d", &val);
			enqueue(qu, &rear, val);
			display(qu, front, rear);
			break;
		case 2:
			val = dequeue(qu, rear, &front);
			if (val != INT_MIN)
				printf("Dequeued item is: %d\n", val);
			display(qu, front, rear);
			break;
		case 3:
			display(qu, front, rear);
			break;
		case 4:
			exit(0);
		default:
			printf("Invalid choice\n");
		}
	}
}
