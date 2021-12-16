#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
};
typedef struct node *Node;

// * INSERT NODE AT FIRST
Node insertFront(Node first)
{
	Node temp;
	temp = (Node)malloc(sizeof(struct node));
	// * check if LinkedList is empty
	if (temp == NULL)
	{
		printf("Insufficient memory \n");
		return first;
	}
	printf("Enter element to insert at front : ");
	scanf("%d", &temp->info);
	temp->link = NULL;
	if (first == NULL)
	{
		first = temp;
		return first;
	}
	temp->link = first;
	first = temp;
	return first;
}

// * INSERT NODE AT LAST
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

// * INSERT NODE AFTER THE GIVEN ELEMENT
Node insertAfterElement(Node first)
{
	Node temp = NULL;
	Node prev = NULL;
	int key;
	if (first == NULL)
	{
		printf("Linked list does not exists \n");
		return first;
	}
	printf("Enter the key element: ");
	scanf("%d", &key);
	prev = first;
	while (prev != NULL && prev->info != key)
	{
		prev = prev->link;
		if (prev == NULL)
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
	temp->link = NULL;
	temp->link = prev->link;
	prev->link = temp;
	return first;
}

// * INSERT THE NODE BEFORE THE GIVEN ELEMENT
Node insertBefore(Node first)
{
	Node temp = NULL;
	Node ptr = NULL;
	int key;
	if (first == NULL)
	{
		printf("Linked list does not exists \n");
		return first;
	}
	printf("Enter the key element: ");
	scanf("%d", &key);
	ptr = first;
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
		temp->link = NULL;
		temp->link = first;
		first = temp;
		return first;
	}
	while (ptr != NULL && ptr->link->info != key)
	{
		ptr = ptr->link;
		if (ptr->link == NULL)
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
	temp->link = NULL;
	temp->link = ptr->link;
	ptr->link = temp;
	return first;
}

// * INSERT ELEMENT AT GIVEN POSITION
Node insertAtPosition(Node first)
{
	int pos;
	Node temp = NULL;
	if (first == NULL)
	{
		printf("Linked List is empty\n");
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
		temp->link = NULL;
		temp->link = first;
		first = temp;
		return first;
	}
	Node curr = first;
	while (pos - 2 != 0)
	{
		curr = curr->link;
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
	temp->link = NULL;
	if (curr->link == NULL)
	{
		curr->link = temp;
		return first;
	}
	temp->link = curr->link;
	curr->link = temp;
	return first;
}

// * DELETE FIRST NODE
Node deleteHead(Node first)
{
	if (first == NULL)
	{
		printf("Linked list does not exists \n");
		return first;
	}
	Node temp = first;
	first = first->link;
	free(temp);
	return first;
}

// * DELETE LAST NODE
Node deleteTail(Node first)
{
	if (first == NULL)
	{
		printf("Linked list does not exists \n");
		return first;
	}
	Node curr = first;
	while (curr->link->link != NULL)
	{
		curr = curr->link;
	}
	Node temp = curr->link;
	curr->link = NULL;
	free(temp);
	return first;
}

// * DELETE THE GIVEN ELEMENT
Node deleteElement(Node first)
{
	int k;
	printf("Enter the element to delete: ");
	scanf("%d", &k);
	if (first->info == k)
	{
		Node firstElem = first;
		first = first->link;
		free(firstElem);
		return first;
	}
	Node curr = first;
	while (curr != NULL && curr->link->info != k)
	{
		curr = curr->link;
		if (curr->info != k && curr->link == NULL)
		{
			printf("%d Not found \n", k);
			return first;
			break;
		}
	}
	Node temp = curr->link;
	curr->link = temp->link;
	free(temp);
	return first;
}

// * DELETE THE NODE AFTER GIVEN ELEMENT
Node deleteAfterElement(Node first)
{
	int k;
	printf("Enter the element after which you want to delete: ");
	scanf("%d", &k);
	Node curr = first;
	while (curr != NULL && curr->info != k)
	{
		curr = curr->link;
		if (curr->info != k && curr->link == NULL)
		{
			printf("%d Not found \n", k);
			return first;
			break;
		}
	}
	if (curr->link == NULL)
	{
		printf("No element after %d \n", k);
		return first;
	}
	Node temp = curr->link;
	curr->link = temp->link;
	free(temp);
	return first;
}

// * DELETE NODE BEFORE THE GIVEN ELEMENT
Node deleteBeforeElement(Node first)
{
	int k;
	printf("Enter the element before which you want to delete: ");
	scanf("%d", &k);
	Node curr = first;
	if (first == NULL)
	{
		printf("Linked list does not exists \n");
		return first;
	}
	if (first->info == k)
	{
		printf("No element before %d \n", k);
		return first;
	}
	if (first->link->info == k)
	{
		Node t = first;
		first = first->link;
		free(t);
		return first;
	}
	while (curr != NULL && curr->link->link->info != k)
	{
		curr = curr->link;
		if (curr->info != k && curr->link->link == NULL)
		{
			printf("%d Not found \n", k);
			return first;
			break;
		}
	}
	Node temp = curr->link;
	curr->link = temp->link;
	free(temp);
	return first;
}

// * DELETE THE ELEMENT AT GIVEN POSITION
Node deleteElementByPosition(Node first)
{
	int pos;
	if (first == NULL)
	{
		printf("Linked List is empty\n");
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
		Node t = first;
		first = first->link;
		free(t);
		return first;
	}
	Node curr = first;
	while (pos - 2 != 0)
	{
		curr = curr->link;
		pos--;
		if (curr->link == NULL)
		{
			printf("Position exceeds the limit of Linked List \n");
			return first;
		}
	}
	Node temp = curr->link;
	curr->link = temp->link;
	free(temp);
	return first;
}

// * SEARCH AN ELEMENT IN LINKED LIST
void searchKeyElement(Node first)
{
	int key, cnt = 0, i = 1;
	Node curr = NULL;
	printf("Enter the element you want search: ");
	scanf("%d", &key);
	if (first == NULL)
	{
		printf("Linked List is empty\n");
		return;
	}
	curr = first;
	while (curr != NULL)
	{
		if (curr->info == key)
		{
			printf("%d found at %d\n", key, i);
			cnt++;
		}
		i++;
		curr = curr->link;
	}
	if (cnt == 0)
		printf("%d not found\n", key);
}

// * REVERSE SINGLY LINKED LIST
Node reverseSll(Node first)
{
	Node curr, temp;
	curr = NULL;
	while (first != NULL)
	{
		temp = first->link;
		first->link = curr;
		curr = first;
		first = temp;
	}
	return curr;
}

// * DISPLAY LINKED LIST
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

/*
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT GIVEN POSITION
4. INSERT AFTER GIVEN ELEMENT
5. INSERT BEFORE GIVEN ELEMENT
6. DELETE FIRST NODE
7. DELETE LAST NODE
8. DELETE GIVEN ELEMENT
9. DELETE NODE AFTER GIVEN ELEMENT
10. DELETE NODE BEFORE GIVEN ELEMENT
11. DELETE ELEMENT AT GIVEN POSITION
12. SEARCH AN ELEMENT IN LINKED LIST
13. REVERSE LINKED LIST
*/

void main()
{
	Node head = NULL;
	int choice;
	printf("\nSINGLY LINKED LIST\n");
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
	printf("13 -> REVERSE LINKED LIST\n");
	while (choice != 0)
	{
		printf("Enter your Choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			head = insertFront(head);
			displayLinkedList(head);
			break;
		case 2:
			head = insertRare(head);
			displayLinkedList(head);
			break;
		case 3:
			head = insertAtPosition(head);
			displayLinkedList(head);
			break;
		case 4:
			head = insertAfterElement(head);
			displayLinkedList(head);
			break;
		case 5:
			head = insertBefore(head);
			displayLinkedList(head);
			break;
		case 6:
			head = deleteHead(head);
			displayLinkedList(head);
			break;
		case 7:
			head = deleteTail(head);
			displayLinkedList(head);
			break;
		case 8:
			head = deleteElement(head);
			displayLinkedList(head);
			break;
		case 9:
			head = deleteAfterElement(head);
			displayLinkedList(head);
			break;
		case 10:
			head = deleteBeforeElement(head);
			displayLinkedList(head);
			break;
		case 11:
			head = deleteElementByPosition(head);
			displayLinkedList(head);
			break;
		case 12:
			searchKeyElement(head);
			displayLinkedList(head);
			break;
		case 13:
			head = reverseSll(head);
			displayLinkedList(head);
			break;
		case 0:
			displayLinkedList(head);
			break;
		default:
			printf("Please enter a valid choice\n");
			break;
		}
	}
}
