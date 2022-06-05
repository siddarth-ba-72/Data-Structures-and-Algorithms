#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ? Function to check if the paranthesis are matching or not

int isValidParanthesis(char str[])
{
	char stack[50];
	int top = -1;
	int i;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			stack[++top] = str[i];
		else if (str[i] == ')' && stack[top] == '(')
			stack[top--];
		else if (str[i] == ']' && stack[top] == '[')
			stack[top--];
		else if (str[i] == '}' && stack[top] == '{')
			stack[top--];
		else
			return 0;
	}
	if (top == -1)
		return 1;
	else
		return 0;
}

void main()
{
	char str[20];
	printf("Enter the paranthesis sequence: ");
	gets(str);
	printf("%s\n", str);
	if (isValidParanthesis(str))
		printf("The paranthesis are matching\n");
	else
		printf("The paranthesis are not matching\n");
}
