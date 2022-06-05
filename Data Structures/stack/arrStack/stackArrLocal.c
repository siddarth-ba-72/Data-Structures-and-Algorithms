#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int isFull(int top)
{
	return top == MAX - 1;
}

int isEmpty(int top)
{
	return top == -1;
}

void push(int stack[], int *top)
{
	if (isFull(*top))
	{
		printf("Stack is full\n");
		return;
	}
	int value;
	printf("Enter the value to be pushed: ");
	scanf("%d", &value);
	stack[++(*top)] = value;
}

int pop(int stack[], int *top)
{
	if (isEmpty(*top))
		printf("Stack is empty\n");
	return stack[(*top)--];
}

int peek(int stack[], int top)
{
	if (isEmpty(top))
		printf("Stack is empty\n");
	return stack[top];
}

void display(int stack[], int top)
{
	int i;
	if (isEmpty(top))
	{
		printf("Stack is empty\n");
		return;
	}
	printf("\nStack:-\n");
	for (i = top; i >= 0; i--)
		printf("%d\n", stack[i]);
	printf("\n");
}

void main()
{
	int stack[MAX], top = -1;
	int choice;
	printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
	while (1)
	{
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			push(stack, &top);
			display(stack, top);
			break;
		case 2:
			printf("Popped element = %d\n", pop(stack, &top));
			display(stack, top);
			break;
		case 3:
			printf("Peek = %d\n", peek(stack, top));
			break;
		case 4:
			display(stack, top);
			break;
		case 5:
			exit(0);
		default:
			printf("Wrong choice\n");
		}
	}
}
