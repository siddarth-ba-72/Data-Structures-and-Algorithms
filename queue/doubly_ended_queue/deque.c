#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 5

int qu[SIZE];
int front = 0, rear = 0;

void enqueueRear()
{
	int val;
	char ch;
	if (front == SIZE / 2)
	{
		printf("Queue is full\n");
		return;
	}
	do
	{
		printf("Enter the value to be inserted: ");
		scanf("%d", &val);
		qu[front] = val;
		front++;
		printf("Do you want to insert more elements? (y/n): ");
		scanf(" %c", &ch);
	} while (ch == 'y');
}

void enqueueFront()
{
	int val;
	char ch;
	if (front == SIZE / 2)
	{
		printf("Queue is full\n");
		return;
	}
	do
	{
		printf("Enter the value to be inserted: ");
		scanf("%d", &val);
		rear--;
		qu[rear] = val;
		printf("Do you want to insert more elements? (y/n): ");
		scanf(" %c", &ch);
	} while (ch == 'y');
}

void dequeueRear()
{
	if (front == rear)
	{
		printf("Queue is empty\n");
		return;
	}
	front--;
	int item = qu[front + 1];
	printf("Deleted item is: %d\n", item);
}

void dequeueFront()
{
	if (front == rear)
	{
		printf("Queue is empty\n");
		return;
	}
	rear++;
	int item = qu[rear - 1];
	printf("Deleted item is: %d\n", item);
}

void display()
{
	if (front == rear)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements are: ");
	for (int i = front; i < rear; i++)
		printf("%d ", qu[i]);
	printf("\n");
}

int main()
{
	char ch;
	int choice1, choice2, value;
	printf("\n******* Type of Double Ended Queue *******\n");
	printf("\n1.Input-restricted deque \n");
	printf("2.output-restricted deque \n");
	do
	{
		printf("\nEnter your choice of Queue Type : ");
		scanf("%d", &choice1);
		switch (choice1)
		{
		case 1:
			printf("\nSelect the Operation\n");
			printf("1.Insert\n2.Delete from Rear\n3.Delete from Front\n4. Display");
			do
			{
				printf("\nEnter your choice for the operation in c deque: ");
				scanf("%d", &choice2);
				switch (choice2)
				{
				case 1:
					enqueueRear();
					display();
					break;
				case 2:
					dequeueRear();
					display();
					break;
				case 3:
					dequeueFront();
					display();
					break;
				case 4:
					display();
					break;
				default:
					printf("Wrong choice");
				}
				printf("\nDo you want to perform another operation (Y/N): ");
				scanf("%c", &ch);
			} while (ch == 'y' || ch == 'Y');
			getch();
			break;
		case 2:
			printf("\n---- Select the Operation ----\n");
			printf("1. Insert at Rear\n2. Insert at Front\n3. Delete\n4. Display");
			do
			{
				printf("\nEnter your choice for the operation: ");
				scanf("%d", &choice2);
				switch (choice2)
				{
				case 1:
					enqueueRear();
					display();
					break;
				case 2:
					enqueueFront();
					display();
					break;
				case 3:
					dequeueFront();
					display();
					break;
				case 4:
					display();
					break;
				default:
					printf("Wrong choice");
				}
				printf("\nDo you want to perform another operation (Y/N): ");
				ch = getch();
			} while (ch == 'y' || ch == 'Y');
			getch();
			break;
		}
		printf("\nDo you want to continue(y/n):");
		ch = getch();
	} while (ch == 'y' || ch == 'Y');
}
