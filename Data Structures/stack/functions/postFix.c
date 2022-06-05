#include <limits.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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
	// char postfix[] = "128*4/+";
	char postfix[] = "23*681*4//+";
	int res = (int)calcPostFix(postfix);
	printf("Postfix = %d", res);

	return 0;
}
