#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *next;
	int info;
	struct node *prev;
};
typedef struct node *Node;

Node insertFront(Node first)
{
	Node temp = NULL;
	temp = (Node)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Insufficient memory \n");
		return first;
	}
	printf("Enter the element to insert: ");
	scanf("%d", &temp->info);
	// temp->next = temp->prev = NULL;
	if (first == NULL)
	{
		first = temp;
		first->next = first;
		first->prev = first;
		return first;
	}
	temp->next = first->next;
	first->next = temp;
	temp->prev = first;
	temp->next->prev = temp;
	int t = temp->info;
	temp->info = first->info;
	first->info = t;
	return first;

	// Node curr = first->prev;
	// first->prev = temp;
	// temp->prev = curr;
	// curr->next = temp;
	// temp->next = first;
	// first = temp;
	// return first;
}

Node insertRare(Node first)
{
	Node temp;
	temp = (Node)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Insufficient memory \n");
		return first;
	}
	printf("Enter the element to insert: ");
	scanf("%d", &temp->info);
	if (first == NULL)
	{
		first = temp;
		first->next = first;
		first->prev = first;
		return first;
	}
	if (first->next == first)
	{

		first->next = temp;
		temp->prev = first;
		first->prev = temp;
		temp->next = first;
		return first;
	}
	temp->next = first->next;
	first->next = temp;
	temp->prev = first;
	temp->next->prev = temp;
	int t = temp->info;
	temp->info = first->info;
	first->info = t;
	return temp;

	// Node curr = first->prev;
	// curr->next = temp;
	// temp->prev = curr;
	// temp->next = first;
	// first->prev = temp;
	// return first;
}

Node insertAfterGivenElementCDLL(Node first)
{
	Node temp, curr;
	int key;
	printf("Enter the element after which you want to insert: ");
	scanf("%d", &key);
	curr = first;
	while (curr->info != key)
	{
		curr = curr->next;
		if (curr->next == first && curr->info != key)
		{
			printf("%d not found \n", key);
			return first;
		}
	}
	temp = (Node)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Insufficient memory \n");
		return first;
	}
	printf("Enter the element to insert: ");
	scanf("%d", &temp->info);
	if (curr->next == first)
	{
		temp->next = first->next;
		first->next = temp;
		temp->prev = first;
		temp->next->prev = temp;
		int t = temp->info;
		temp->info = first->info;
		first->info = t;
		return temp;
	}
	temp->next = curr->next;
	curr->next = temp;
	temp->prev = curr;
	temp->next->prev = temp;
	return first;
}

Node insertBeforeElementCDLL(Node first)
{
	Node temp, curr;
	int key;
	printf("Enter the element before which you want to insert: ");
	scanf("%d", &key);
	curr = first;
	if (first->info == key)
	{
		temp = (Node)malloc(sizeof(struct node));
		if (temp == NULL)
		{
			printf("Insufficient memory \n");
			return first;
		}
		printf("Enter the element to insert: ");
		scanf("%d", &temp->info);
		temp->next = first->next;
		first->next = temp;
		temp->prev = first;
		temp->next->prev = temp;
		int t = temp->info;
		temp->info = first->info;
		first->info = t;
		return first;
	}
	while (curr->info != key)
	{
		curr = curr->next;
		if (curr->next == first && curr->info != key)
		{
			printf("%d not found \n", key);
			return first;
		}
	}
	temp = (Node)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Insufficient memory \n");
		return first;
	}
	printf("Enter the element to insert: ");
	scanf("%d", &temp->info);
	temp->next = curr;
	temp->prev = curr->prev;
	curr->prev = temp;
	temp->prev->next = temp;
	return first;
}

Node insertAtGivenPositionCDLL(Node first)
{
	Node temp, curr;
	int key, pos;
	printf("Enter the position at which you want to insert: ");
	scanf("%d", &pos);
	if (pos == 1)
	{
		return insertFront(first);
	}
	curr = first;
	while (pos - 2 != 0)
	{
		curr = curr->next;
		pos--;
		if (curr == first)
		{
			printf("Position exceeds the limit of Linked List \n");
			return first;
		}
	}
	temp = (Node)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Insufficient memory \n");
		return first;
	}
	printf("Enter the element to insert: ");
	scanf("%d", &temp->info);
	temp->next = curr->next;
	temp->prev = curr;
	curr->next = temp;
	temp->next->prev = temp;
	return first;
}

void displayDll(Node first)
{
	Node temp;
	if (first == NULL)
	{
		printf("Linked list is empty\n");
		return;
	}
	temp = first;
	do
	{
		printf("%d  ", temp->info);
		temp = temp->next;
	} while (temp != first);
	printf("\n");
}

void main()
{
	Node head = NULL;
	int num;
	printf("Enter the number of elements to insert in LINKED LIST: ");
	scanf("%d", &num);
	while (num-- > 0)
	{
		head = insertRare(head);
		displayDll(head);
	}
	int testCases;
	printf("Enter the number of test cases: ");
	scanf("%d", &testCases);
	while (testCases-- > 0)
	{
		head = insertAtGivenPositionCDLL(head);
		displayDll(head);
	}
}
