#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
};
typedef struct node *Node;

Node insertRare(Node first)
{
	Node temp;
	temp = (Node)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Insufficient memory \n");
		return first;
	}
	printf("Enter element to insert at end : ");
	scanf("%d", &temp->info);
	temp->link = NULL;
	// * check if LinkedList is empty
	if (first == NULL)
		return temp;
	if (first->link == NULL)
	{
		first->link = temp;
		return first;
	}
	Node current = first;
	while (current->link != NULL)
	{
		current = current->link;
	}
	current->link = temp;
	return first;
}

Node concateLinkedList(Node first, Node second)
{
	Node current;
	current = first;
	if (first == NULL)
	{
		if (second == NULL)
			return first;
		else
			return second;
	}
	while (current->link != NULL)
	{
		current = current->link;
	}
	current->link = second;
	return first;
}

void displayLinkedList(Node first)
{
	if (first == NULL)
		printf("Linked List empty \n");
	Node current = first;
	while (current != NULL)
	{
		printf("%d -> ", current->info);
		current = current->link;
	}
	printf("NULL \n");
}

void main()
{
	Node first = NULL;
	Node second = NULL;
	int choice;
	printf("1 -> CREATION OF SLL-1\n");
	printf("2 -> CREATION OF SLL-2\n");
	printf("3 -> DISPLAY OF SLL-1\n");
	printf("4 -> DISPLAY OF SLL-2\n");
	printf("5 -> CONCATENATION OF SLL\n");
	printf("6 -> EXIT\n");
	printf("\n");
	while (1)
	{
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			first = insertRare(first);
			displayLinkedList(first);
			printf("\n");
			break;
		case 2:
			second = insertRare(second);
			displayLinkedList(second);
			printf("\n");
			break;
		case 3:
			displayLinkedList(first);
			printf("\n");
			break;
		case 4:
			displayLinkedList(second);
			printf("\n");
			break;
		case 5:
			first = concateLinkedList(first, second);
			displayLinkedList(first);
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
