#include <stdio.h>
#include <stdlib.h>

int MAX_SIZE = 2;
int *s = NULL;
int top = -1;

int isfull()
{
    return top == MAX_SIZE - 1;
}

int isempty()
{
    return top == -1;
}

void push()
{
    int item;
    if (isfull())
    {
        s = realloc(s, (MAX_SIZE + 1) * sizeof(int));
    }
    printf("Enter an element: ");
    scanf("%d", &item);
    s[++top] = item;
}

void pop()
{
    int item;
    if (isempty())
    {
        printf("No elements to pop\n");
        return;
    }
    item = s[top--];
    printf("The popped element = %d\n", item);
}

void peek()
{
    int item;
    if (isempty())
    {
        printf("No elements to peek\n");
        return;
    }
    printf("The top element = %d\n", s[top]);
}

void display()
{
    int i;
    if (isempty())
        printf("Stack empty\n");
    else
    {
        printf("Stack:-\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", s[i]);
    }
}

void main()
{
    int choice;
    s = (int *)malloc(MAX_SIZE * sizeof(int));
    printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.PEEK\n5.EXIT\n");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
        default:
            printf("\nENter valid choice");
        }
    }
}
