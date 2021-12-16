#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

int isFull()
{
	return top == MAX - 1;
}

int isEmpty()
{
	return top == -1;
}

void push()
{
	if (isFull())
	{
		printf("Stack is full\n");
		return;
	}
	int data;
	printf("Enter data: ");
	scanf("%d", &data);
	stack[++top] = data;
}

void pop()
{
	if (isEmpty())
	{
		printf("Stack is empty\n");
		return;
	}
	printf("Popped element = %d\n", stack[top--]);
}

int peek()
{
	if (isEmpty())
	{
		printf("Stack is empty\n");
		return -1;
	}
	return stack[top];
}

void displayStack()
{
	if (isEmpty())
	{
		printf("Stack is empty\n");
		return;
	}
	printf("Stack:-\n");
	for (int i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}

void main()
{
	int choice;
	while (1)
	{
		printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			push();
			displayStack();
			break;
		case 2:
			pop();
			displayStack();
			break;
		case 3:
			displayStack();
			break;
		case 4:
			printf("Peek element = %d\n", peek());
		case 5:
			exit(0);
		default:
			printf("Wrong choice\n");
		}
	}
}
