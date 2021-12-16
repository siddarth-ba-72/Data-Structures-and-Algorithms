#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
};
typedef struct node *Node;

// * INSERT NODE AT THE END
Node insertRearCll(Node first)
{
	Node temp, curr;
	int elem;
	temp = (Node)malloc(sizeof(struct node));
	// * check if LinkedList is empty
	if (temp == NULL)
	{
		printf("Insufficient memory \n");
		return first;
	}
	printf("Enter element to insert at end : ");
	scanf("%d", &elem);
	temp->info = elem;
	temp->link = temp;
	if (first == NULL)
	{
		return temp;
	}
	else
	{
		curr = first;
		while (curr->link != first)
		{
			curr = curr->link;
		}
		curr->link = temp;
		temp->link = first;
	}
	return first;
}

// * CONCATE TWO CIRCULAR SINGLY LINKED LIST
Node concateCSll(Node first, Node second)
{
	Node curr;
	curr = first;
	if (first == NULL)
	{
		if (second == NULL)
			return first;
		else
			return second;
	}
	if (second == NULL)
		return first;
	while (curr->link != first)
	{
		curr = curr->link;
	}
	curr->link = second;
	do
	{
		curr = curr->link;
	} while (curr->link != second);
	curr->link = first;
	return first;
}

// * DISPLAY CIRCULAR LINKED LIST
void displayCll(Node first)
{
	Node curr;
	if (first == NULL)
	{
		printf("LinkedList is empty \n");
		return;
	}
	else
	{
		curr = first;
		do
		{
			printf("%d  ", curr->info);
			curr = curr->link;
		} while (curr != first);
	}
	printf("\n");
}

void main()
{
	Node first = NULL;
	Node second = NULL;
	int choice;
	printf("1 -> CREATION OF CSLL-1\n");
	printf("2 -> CREATION OF CSLL-2\n");
	printf("3 -> DISPLAY OF CSLL-1\n");
	printf("4 -> DISPLAY OF CSLL-2\n");
	printf("5 -> CONCATENATION OF CSLL\n");
	printf("6 -> EXIT\n");
	printf("\n");
	while (1)
	{
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			first = insertRearCll(first);
			displayCll(first);
			printf("\n");
			break;
		case 2:
			second = insertRearCll(second);
			displayCll(second);
			printf("\n");
			break;
		case 3:
			displayCll(first);
			printf("\n");
			break;
		case 4:
			displayCll(second);
			printf("\n");
			break;
		case 5:
			first = concateCSll(first, second);
			displayCll(first);
			printf("\n");
			second = NULL;
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("Wrong choice \n");
		}
	}
}
