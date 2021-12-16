#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *next;
	int info;
	struct node *prev;
};
typedef struct node *Node;

// * INSERTION OF NODE AT BEGINNING OF DOUBLY LINKED LIST
Node insertFrontDll(Node first)
{
	Node temp;
	temp = (Node)malloc(sizeof(struct node));
	printf("Enter the element to be inserted: ");
	scanf("%d", &temp->info);
	temp->next = first;
	temp->prev = NULL;
	if (first != NULL)
		first->prev = temp;
	first = temp;
	return first;
}

Node insertRareDll(Node first)
{
	Node temp;
	temp = (Node)malloc(sizeof(struct node));
	// * check if LinkedList is empty
	if (temp == NULL)
	{
		printf("Insufficient memory \n");
		return first;
	}
	printf("Enter element to insert at the end : ");
	scanf("%d", &temp->info);
	temp->next = NULL;
	temp->prev = NULL;
	if (first == NULL)
	{
		first = temp;
		return first;
	}
	Node curr = first;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = temp;
	temp->prev = curr;
	temp->next = NULL;
	return first;
}

Node insertAfterElementDll(Node first)
{
	Node temp;
	int key;
	if (first == NULL)
	{
		printf("Linked list does not exists \n");
		return first;
	}
	printf("Enter the key element: ");
	scanf("%d", &key);
	Node curr = first;
	while (curr != NULL && curr->info != key)
	{
		curr = curr->next;
		if (curr->next == NULL && curr->info != key)
		{
			printf("%d not not found\n", key);
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
	temp->next = NULL;
	if (curr->next == NULL)
	{
		curr->next = temp;
		temp->prev = curr;
		return first;
	}
	temp->next = curr->next;
	curr->next->prev = temp;
	curr->next = temp;
	temp->prev = curr;
	return first;
}

Node insertBeforeElementDll(Node first)
{
	Node temp;
	if (first == NULL)
	{
		printf("Linked list does not exists \n");
		return first;
	}
	int key;
	printf("Enter the element before which you want to insert: ");
	scanf("%d", &key);
	Node curr = first;
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
		temp->next = first;
		first->prev = temp;
		temp->prev = NULL;
		first = temp;
		return first;
	}
	while (curr->next->info != key)
	{
		curr = curr->next;
		if (curr->next == NULL)
		{
			printf("%d not found\n", key);
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
	curr->next->prev = temp;
	curr->next = temp;
	temp->prev = curr;
	return first;
}

Node insertAtPositionDll(Node first)
{
	Node temp = NULL;
	Node curr;
	int pos;
	if (first == NULL)
	{
		printf("Linked list does not exists \n");
		return first;
	}
	printf("Enter the position: ");
	scanf("%d", &pos);
	if (pos <= 0)
	{
		printf("Please enter a valid position\n");
		return first;
	}
	if (pos == 1)
	{
		temp = (Node)malloc(sizeof(struct node));
		if (temp == NULL)
		{
			printf("Insufficient memory \n");
			return first;
		}
		printf("Enter the element to insert: ");
		scanf("%d", &temp->info);
		temp->next = first;
		first->prev = temp;
		temp->prev = NULL;
		first = temp;
		return first;
	}
	curr = first;
	while (pos - 2 != 0)
	{
		curr = curr->next;
		pos--;
		if (curr == NULL)
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
	temp->next == NULL;
	temp->prev = NULL;
	if (curr->next == NULL)
	{
		curr->next = temp;
		temp->prev = curr;
		temp->next = NULL;
		return first;
	}
	temp->next = curr->next;
	curr->next->prev = temp;
	curr->next = temp;
	temp->prev = curr;
	return first;
}

Node deleteHeadDll(Node first)
{
	if (first == NULL)
	{
		printf("Linked list does not exists \n");
		return first;
	}
	Node temp = first;
	first = first->next;
	first->prev = NULL;
	free(temp);
	return first;
}

Node deleteTailDll(Node first)
{
	if (first == NULL)
	{
		printf("Linked list does not exists \n");
		return first;
	}
	Node curr = first;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	Node temp = curr;
	temp->prev->next = NULL;
	temp->prev = NULL;
	free(temp);
	return first;
}

Node deleteGivenNodeDll(Node first)
{
	Node curr;
	int key;
	if (first == NULL)
	{
		printf("Linked list does not exists \n");
		return first;
	}
	printf("Enter the element you want to delete: ");
	scanf("%d", &key);
	if (first->info == key)
	{
		Node temp = first;
		first = first->next;
		free(temp);
		first->prev = NULL;
		return first;
	}
	curr = first;
	while (curr->next->info != key)
	{
		curr = curr->next;
		if (curr->next == NULL)
		{
			printf("%d not found\n", key);
			return first;
		}
	}
	if (curr->next->next == NULL)
	{
		Node temp = curr->next;
		curr->next = NULL;
		free(temp);
		return first;
	}
	Node temp = curr->next;
	curr->next = temp->next;
	temp->next->prev = curr;
	temp->next = NULL;
	temp->prev = NULL;
	free(temp);
	return first;
}

Node deleteAfterElementDll(Node first)
{
	Node curr, temp;
	int key;
	if (first == NULL)
	{
		printf("Linked list does not exists \n");
		return first;
	}
	printf("Enter the element after which you want to delete: ");
	scanf("%d", &key);
	curr = first;
	while (curr->info != key)
	{
		curr = curr->next;
		if (curr->next == NULL)
		{
			if (curr->info == key)
			{
				printf("No more elements to delete after this node.\n");
				return first;
			}
			else
			{
				printf("%d not found\n", key);
				return first;
			}
		}
	}
	temp = curr->next;
	curr->next = temp->next;
	temp->next->prev = curr;
	temp->next = NULL;
	temp->prev = NULL;
	free(temp);
	return first;
}

Node deleteBeforeElementDll(Node first)
{
	Node curr, temp;
	int key;
	if (first == NULL)
	{
		printf("Linked list does not exists \n");
		return first;
	}
	printf("Enter the element before which you want to delete: ");
	scanf("%d", &key);
	curr = first;
	if (first->info == key)
	{
		printf("No element before this node.\n");
		return first;
	}
	while (curr->info != key)
	{
		curr = curr->next;
		if (curr->next == NULL && curr->info != key)
		{
			printf("%d not found\n", key);
			return first;
		}
	}
	temp = curr->prev;
	curr->prev = temp->prev;
	temp->prev->next = curr;
	temp->prev = NULL;
	temp->next = NULL;
	free(temp);
	return first;
}

Node deleteAtGivenPositionDll(Node first)
{
	Node curr, temp;
	int pos;
	if (first == NULL)
	{
		printf("Linked list does not exists \n");
		return first;
	}
	printf("Enter the position to delete: ");
	scanf("%d", &pos);
	if (pos <= 0)
	{
		printf("Invalid position.\n");
		return first;
	}
	if (pos == 1)
	{
		Node temp = first;
		first = first->next;
		first->prev = NULL;
		free(temp);
		return first;
	}
	curr = first;
	while (pos != 1)
	{
		curr = curr->next;
		pos--;
		if (curr == NULL)
		{
			printf("Position exceeds the limit of Linked List \n");
			return first;
		}
	}
	if (curr->next == NULL)
	{
		temp = curr;
		temp->prev->next = NULL;
		temp->prev = NULL;
		temp->next = NULL;
		free(temp);
		return first;
	}
	temp = curr;
	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	temp->next = NULL;
	temp->prev = NULL;
	free(temp);
	return first;
}

void searchElementDll(Node first)
{
	int key, cnt = 0, i = 1;
	Node curr = NULL;
	printf("Enter the element you want to search: ");
	scanf("%d", &key);
	curr = first;
	if (curr == NULL)
		printf("DLL is empty\n");
	while (curr != NULL)
	{
		if (key == curr->info)
		{
			printf("%d found at %d\n", key, i);
			cnt++;
		}
		i++;
		curr = curr->next;
	}
	if (cnt == 0)
		printf("%d not found\n", key);
}

void displayDll(Node first)
{
	Node temp;
	temp = first;
	if (temp == NULL)
	{
		printf("List is empty\n");
		return;
	}
	while (temp != NULL)
	{
		printf("%d ", temp->info);
		temp = temp->next;
	}
	printf("\n");
}

void main()
{
	Node head = NULL;
	int choice;
	printf("------DOUBLY LINKED LIST------ \n");
	printf("Enter your choices according to the below parameters\n");
	printf("1 -> INSERT AT BEGINNING\n");
	printf("2 -> INSERT AT END\n");
	printf("3 -> INSERT AT GIVEN POSITION\n");
	printf("4 -> INSERT AFTER GIVEN ELEMENT\n");
	printf("5 -> INSERT BEFORE GIVEN ELEMENT\n");
	printf("6 -> DELETE FIRST NODE\n");
	printf("7 -> DELETE LAST NODE\n");
	printf("8 -> DELETE GIVEN ELEMENT\n");
	printf("9 -> DELETE NODE AFTER GIVEN ELEMENT\n");
	printf("10 -> DELETE NODE BEFORE GIVEN ELEMENT\n");
	printf("11 -> DELETE ELEMENT AT GIVEN POSITION\n");
	printf("12 -> SEARCH AN ELEMENT IN LINKED LIST\n");
	printf("13 -> EXIT\n");
	printf("\n");
	while (1)
	{
		printf("Enter yout choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			head = insertFrontDll(head);
			displayDll(head);
			break;
		case 2:
			head = insertRareDll(head);
			displayDll(head);
			break;
		case 3:
			head = insertAtPositionDll(head);
			displayDll(head);
			break;
		case 4:
			head = insertAfterElementDll(head);
			displayDll(head);
			break;
		case 5:
			head = insertBeforeElementDll(head);
			displayDll(head);
			break;
		case 6:
			head = deleteHeadDll(head);
			displayDll(head);
			break;
		case 7:
			head = deleteTailDll(head);
			displayDll(head);
			break;
		case 8:
			head = deleteGivenNodeDll(head);
			displayDll(head);
			break;
		case 9:
			head = deleteAfterElementDll(head);
			displayDll(head);
			break;
		case 10:
			head = deleteBeforeElementDll(head);
			displayDll(head);
			break;
		case 11:
			head = deleteAtGivenPositionDll(head);
			displayDll(head);
			break;
		case 12:
			searchElementDll(head);
			displayDll(head);
			break;
		case 13:
			exit(0);
			break;
		default:
			printf("\nInvalid choice... please enter valid choice....\n");
		}
	}
}
