#include <limits.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

void push(stack stk, int data)
{
	if (isFull(stk))
		stk->arr = (int *)realloc(stk->arr, (++stk->size) * sizeof(int));
	stk->top++;
	stk->arr[stk->top] = data;
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

// ? USING LINKEDLIST-STACK

// int calcPostFix(char exp[])
// {
// 	stack pfStk = createStack(strlen(exp));
// 	int i;
// 	if (!pfStk)
// 		return -1;
// 	for (i = 0; exp[i]; ++i)
// 	{
// 		if (isdigit(exp[i]))
// 			push(pfStk, exp[i] - '0');
// 		else
// 		{
// 			int v1 = pop(pfStk);
// 			int v2 = pop(pfStk);
// 			switch (exp[i])
// 			{
// 			case '+':
// 				push(pfStk, v2 + v1);
// 				break;
// 			case '-':
// 				push(pfStk, v2 - v1);
// 				break;
// 			case '*':
// 				push(pfStk, v2 * v1);
// 				break;
// 			case '/':
// 				push(pfStk, v2 / v1);
// 				break;
// 			}
// 		}
// 	}
// 	return peek(pfStk);
// }

// ? USING ARRAY-STACK

double compute(char symbol, double op1, double op2)
{
	switch (symbol)
	{
	case '+':
		return op1 + op2;
	case '-':
		return op2 - op1;
	case '*':
		return op1 * op2;
	case '/':
		return op2 / op1;
	case '^':
	case '$':
		return pow(op1, op2);
	}
}

double calcPostFix(char exp[])
{
	double stack[50], res, op1, op2;
	int top = -1, i;
	char symbol;
	for (i = 0; i < strlen(exp); i++)
	{
		symbol = exp[i];
		if (isdigit(symbol))
			stack[++top] = symbol - '0';
		else
		{
			op1 = stack[top--];
			op2 = stack[top--];
			res = compute(symbol, op1, op2);
			stack[++top] = res;
		}
	}
	res = stack[top--];
	return res;
}

int main()
{
	// char postfix[] = "231*+9-";
	char postfix[] = "128*4/+";
	int res = (int)calcPostFix(postfix);
	printf("Postfix = %d", res);

	return 0;
}
