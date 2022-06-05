#include <stdio.h>
#include <stdlib.h>
#define MAX 30

char opr[MAX] = {'\0'};
int top_opr = -1;
char pf[MAX] = {'\0'};
int top_pf = -1;

int getPriority(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
	case '$':
		return 3;
	default:
		return -1;
	}
}

void display(char arr[])
{
	printf("Stack:-\n");
	for (int i = MAX; i >= 0; i--)
	{
		printf("%c\n", arr[i]);
	}
	printf("\n");
}

void infix_to_postFix(char infix[])
{
	char ch, popch;
	int i = 0;
	while (infix[i] != '\0')
	{
		ch = infix[i];
		if (ch == '(')
		{
			opr[++top_opr] = ch;
		}
		else if (ch == ')')
		{
			while (opr[top_opr] != '(')
			{
				popch = opr[top_opr--];
				pf[++top_pf] = popch;
			}
			opr[top_opr--] = '\0';
		}
		else if (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-')
		{
			if (top_opr >= 0)
			{
				while (getPriority(opr[top_opr]) >= getPriority(ch) && top_opr != -1)
				{
					popch = opr[top_opr--];
					pf[++top_pf] = popch;
				}
			}
			opr[++top_opr] = ch;
		}
		else
		{
			pf[++top_pf] = ch;
		}
		i++;
	}
	if (top_opr != -1)
	{
		while (top_opr != -1)
		{
			popch = opr[top_opr--];
			pf[++top_pf] = popch;
		}
	}
	printf("\nPostfix expression: %s\n", pf);
}

int main()
{
	char infix[MAX] = {'\0'};
	printf("Enter the infix expression: ");
	scanf("%s", infix);
	printf("Infix expression: %s\n", infix);
	infix_to_postFix(infix);
}
