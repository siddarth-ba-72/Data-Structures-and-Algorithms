#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
	int front, rear, size;
	int capacity;
	int *arr;
};

typedef struct Queue *queue;

queue createQueue(int capacity)
{
	queue qu = (queue)malloc(sizeof(struct Queue));
	qu->capacity = capacity;
	qu->front = qu->size = 0;
	qu->rear = -1;
	qu->arr = (int *)malloc(qu->capacity * sizeof(int));
	return qu;
}

int isFull(queue qu)
{
	return (qu->size == qu->capacity);
}

int isEmpty(queue qu)
{
	return (qu->size == 0);
}

void addToQueue(queue qu)
{
	if (isFull(qu))
		qu->arr = (int *)realloc(qu->arr, (++qu->capacity) * sizeof(int));
	int data;
	printf("Enter the element to add to queue: ");
	scanf("%d", &data);
	qu->arr[++qu->rear] = data;
	qu->size++;
}

int removeFromQueue(queue qu)
{
	if (isEmpty(qu))
		return INT_MIN;
	int popped = qu->arr[qu->front++];
	qu->size--;
	return popped;
}

int firstItemInQueue(queue qu)
{
	if (isEmpty(qu))
		return INT_MIN;
	return qu->arr[qu->front];
}

int lastItemInQueue(queue qu)
{
	if (isEmpty(qu))
		return INT_MIN;
	return qu->arr[qu->rear];
}

void displayQueue(queue qu)
{
	if (isEmpty(qu))
	{
		printf("Queue is empty\n");
		return;
	}
	int i;
	for (i = qu->front; i <= qu->rear; i++)
	{
		printf("%d ", qu->arr[i]);
	}
	printf("\n");
}

int main()
{
	int cap;
	printf("Enter the capacity of the queue: ");
	scanf("%d", &cap);
	queue qu = createQueue(cap);
	int choice;
	printf("1. Add to queue\n");
	printf("2. Remove from queue\n");
	printf("3. First item in queue\n");
	printf("4. Last item in queue\n");
	printf("5. Display queue\n");
	printf("6. Exit\n\n");
	while (1)
	{
		printf("Enter your Choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			addToQueue(qu);
			displayQueue(qu);
			break;
		case 2:
			printf("Popped element = %d\n", removeFromQueue(qu));
			displayQueue(qu);
			break;
		case 3:
			printf("First element = %d\n", firstItemInQueue(qu));
			break;
		case 4:
			printf("Last element = %d\n", lastItemInQueue(qu));
			break;
		case 5:
			displayQueue(qu);
			break;
		case 6:
			exit(0);
		default:
			printf("Invalid Choice\n");
		}
	}

	return 0;
}
