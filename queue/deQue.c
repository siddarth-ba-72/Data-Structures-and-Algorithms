#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct DeQueue
{
	int front, rear, count;
	int capacity;
	int *array;
};

typedef struct DeQueue *deque;

deque createDoublyEndedQueue(int capacity)
{
	deque dq = (deque)malloc(sizeof(struct DeQueue));
	dq->capacity = capacity;
	dq->front = 0;
	dq->rear = -1;
	dq->array = (int *)malloc(dq->capacity * sizeof(int));
	return dq;
}

int isFull(deque dq)
{
	return dq->capacity == dq->count;
}

int isEmpty(deque dq)
{
	return dq->count == 0;
}

void insertFront(deque dq)
{
	if (isFull(dq))
	{
		printf("Queue is full\n");
		return;
	}
	int data;
	printf("Enter the data to be inserted: ");
	scanf("%d", &data);
	dq->rear++;
	dq->array[dq->rear] = data;
	dq->count++;
}

void insertRear(deque dq, int data)
{
	// if (isFull(dq))
	// {
	// 	printf("Queue is full\n");
	// 	return;
	// }
	// if (dq->rear == dq->capacity - 1)
	// {
	// 	dq->rear = 0;
	// }
	// else
	// {
	// 	dq->rear++;
	// }
	// dq->array[dq->rear] = data;
	// dq->count++;
}

void deleteFront(deque dq)
{
	if (isEmpty(dq))
	{
		printf("Queue is empty\n");
		return;
	}
	int del = dq->array[dq->rear];
	dq->rear--;
	dq->count--;
	printf("Deleted element = %d\n", del);
}

void deleteRear(deque dq)
{
	if (isEmpty(dq))
	{
		printf("Queue is empty\n");
		return;
	}
	int del = dq->array[dq->front];
	dq->front++;
	dq->count--;
	printf("Deleted element = %d\n", del);
}

int frontElem(deque dq)
{
	if (isEmpty(dq))
	{
		printf("Queue is empty\n");
		return INT_MIN;
	}
	return dq->array[dq->front];
}

int rearElement(deque dq)
{
	if (isEmpty(dq))
	{
		printf("Queue is empty\n");
		return INT_MIN;
	}
	return dq->array[dq->rear];
}

void displayDq(deque dq)
{
	if (isEmpty(dq))
	{
		printf("Queue is empty\n");
		return;
	}
	int i;
	for (i = dq->front; i <= dq->rear; i++)
	{
		printf("%d ", dq->array[i]);
	}
	printf("\n");
}

int main()
{
	deque dq = createDoublyEndedQueue(5);
	printf("1. Insert Front \n");
	printf("2. Insert Rear \n");
	printf("3. Delete Front \n");
	printf("4. Delete Rear \n");
	printf("5. Front Element \n");
	printf("6. Rear Element \n");
	printf("7. Display \n");
	printf("8. Exit \n");
	int choice;
	while (1)
	{
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			insertFront(dq);
			displayDq(dq);
			break;
		case 2:
			insertRear(dq, 20);
			displayDq(dq);
			break;
		case 3:
			deleteFront(dq);
			displayDq(dq);
			break;
		case 4:
			deleteRear(dq);
			displayDq(dq);
			break;
		case 5:
			printf("Front element = %d\n", frontElem(dq));
			break;
		case 6:
			printf("Rear element = %d\n", rearElement(dq));
			break;
		case 7:
			displayDq(dq);
			break;
		case 8:
			exit(0);
			break;
		default:
			printf("Invalid choice\n");
			break;
		}
	}
	return 0;
}
