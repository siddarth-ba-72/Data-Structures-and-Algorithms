#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
	int front, rear, count;
	int capacity;
	int *arr;
};

typedef struct CircularQueue *cqueue;

cqueue createCircularQueue(int capacity)
{
	cqueue cq = (cqueue)malloc(sizeof(struct CircularQueue));
	cq->capacity = capacity;
	cq->front = 0;
	cq->rear = -1;
	cq->count = 0;
	cq->arr = (int *)malloc(cq->capacity * sizeof(int));
	return cq;
}

int isFull(cqueue cq)
{
	return cq->count == cq->capacity;
}

int isEmpty(cqueue cq)
{
	return cq->count == 0;
}

void enqueue(cqueue cq)
{
	if (isFull(cq))
	{
		cq->arr = (int *)realloc(cq->arr, (++cq->capacity) * sizeof(int));
	}
	cq->rear = (cq->rear + 1) % cq->capacity;
	printf("Enter the element to be inserted: ");
	scanf("%d", &cq->arr[cq->rear]);
	cq->count++;
}

void dequeue(cqueue cq)
{
	if (isEmpty(cq))
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Popped element = %d\n", cq->arr[cq->front]);
	cq->front = (cq->front + 1) % cq->capacity;
	cq->count--;
}

void displayCircularQueue(cqueue cq)
{
	int i;
	if (isEmpty(cq))
		printf("Queue is empty\n");
	else
	{
		printf("Queue elements are: ");
		for (i = cq->front; i != cq->rear; i = (i + 1) % cq->capacity)
			printf("%d ", cq->arr[i]);
		printf("%d\n", cq->arr[i]);
	}
}

int main()
{
	int cap;
	printf("Enter the capacity of the queue: ");
	scanf("%d", &cap);
	cqueue cq = createCircularQueue(cap);
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
			enqueue(cq);
			displayCircularQueue(cq);
			break;
		case 2:
			dequeue(cq);
			displayCircularQueue(cq);
			break;
		case 3:
			displayCircularQueue(cq);
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}
