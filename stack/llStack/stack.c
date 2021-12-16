#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int top;
	int size;
	int *arr;
};

typedef struct Stack *stack;

stack createStack(int size)
{
	stack stk = (stack)malloc(sizeof(struct Stack));
	stk->size = size;
	stk->top = -1;
	stk->arr = (int *)malloc(stk->size * sizeof(int));
	return stk;
}

int isFull(stack stk)
{
	return stk->top == stk->size - 1;
}

int isEmpty(stack stk)
{
	return stk->top == -1;
}

void push(stack stk)
{
	if (isFull(stk))
		stk->arr = (int *)realloc(stk->arr, (++stk->size) * sizeof(int));
	int data;
	printf("Enter the element that you want to push: ");
	scanf("%d", &data);
	stk->arr[++stk->top] = data;
}

int pop(stack stk)
{
	if (isEmpty(stk))
	{
		printf("stack is empty\n");
		return INT_MIN;
	}
	return stk->arr[stk->top--];
}

int peek(stack stk)
{
	if (isEmpty(stk))
	{
		printf("stack is empty\n");
		return INT_MIN;
	}
	return stk->arr[stk->top];
}

void displayStack(stack stk)
{
	if (isEmpty(stk))
	{
		printf("stack is empty\n");
		return;
	}
	int i;
	printf("\nStack:-\n");
	for (i = stk->top; i >= 0; i--)
	{
		printf("%d\n", stk->arr[i]);
	}
	printf("\n");
}

void main()
{
	int len;
	printf("Enter the size of the stack: ");
	scanf("%d", &len);
	stack stk = createStack(len);
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Peek\n");
	printf("4. Display\n");
	printf("5. Exit\n");
	while (1)
	{
		int choice;
		printf("Enter the choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			push(stk);
			displayStack(stk);
			break;
		case 2:
			pop(stk);
			displayStack(stk);
			break;
		case 3:
			printf("%d\n", peek(stk));
			break;
		case 4:
			displayStack(stk);
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("Invalid choice\n");
		}
	}
}
