#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ? check whether string is palindrome or not using stack

int isPalindrome(char str[])
{
	char stack[50];
	int top = -1, i;
	for (i = 0; i < strlen(str); i++)
	{
		stack[++top] = str[i];
	}
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] != stack[top--])
		{
			return 0;
		}
	}
	return 1;
}

void main()
{
	char str[20];
	printf("Enter your string: ");
	gets(str);
	printf("%s\n", str);
	if (isPalindrome(str))
		printf("Palindrome\n");
	else
		printf("Not a Palindrome\n");
}
