#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
};
typedef struct node *Node;

// * INSERT NODE AT THE FRONT
Node insertFrontCll(Node first)
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
	printf("Enter element to insert at front : ");
	scanf("%d", &elem);
	temp->info = elem;
	temp->link = temp;
	if (first == NULL)
		return temp;
	else
	{
		temp->link = first;
		curr = first;
		while (curr->link != first)
		{
			curr = curr->link;
		}
		curr->link = temp;
		first = temp;
	}
	return first;
}

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

// * INSERT NODE AT THE GIVEN POSITION
Node insertAtPosCll(Node first)
{
	Node temp, curr;
	int elem, pos, k;
	printf("Enter position to insert : ");
	scanf("%d", &pos);
	if (pos == 1)
	{
		first = insertFrontCll(first);
		return first;
	}
	curr = first;
	k = 1;
	while (k < pos - 1)
	{
		curr = curr->link;
		k++;
		if (curr == first)
			break;
	}
	if (curr == first && k != pos - 1)
	{
		printf("Position does not exist \n");
		return first;
	}
	if (curr->link == first)
	{
		first = insertRearCll(first);
		return first;
	}
	temp = (Node)malloc(sizeof(struct node));
	// * check if LinkedList is empty
	if (temp == NULL)
	{
		printf("Insufficient memory \n");
		return first;
	}
	printf("Enter element to insert at front : ");
	scanf("%d", &elem);
	temp->info = elem;
	temp->link = NULL;
	temp->link = curr->link;
	curr->link = temp;
	return first;
}

// * INSERT NODE AFTER GIVEN ELEMENT
Node insertAfterElementCll(Node first)
{
	Node temp, curr;
	int key, elem;
	if (first == NULL)
	{
		printf("LinkedList is empty \n");
		return first;
	}
	printf("Enter element after which to insert : ");
	scanf("%d", &key);
	curr = first;
	while (curr->info != key)
	{
		curr = curr->link;
		if (curr == first)
		{
			printf("%d not found \n", key);
			return first;
		}
	}
	temp = (Node)malloc(sizeof(struct node));
	// * check if LinkedList is empty
	if (temp == NULL)
	{
		printf("Insufficient memory \n");
		return first;
	}
	printf("Enter element to insert after %d : ", key);
	scanf("%d", &elem);
	temp->info = elem;
	temp->link = curr->link;
	curr->link = temp;
	return first;
}

// * INSERT NODE BEFORE GIVEN ELEMENT
Node insertBeforeElementCll(Node first)
{
	Node temp, curr;
	int key, elem;
	if (first == NULL)
	{
		printf("LinkedList is empty \n");
		return first;
	}
	printf("Enter element before which to insert : ");
	scanf("%d", &key);
	curr = first;
	if (first->info == key)
	{
		first = insertFrontCll(first);
		return first;
	}
	while (curr->link->info != key)
	{
		curr = curr->link;
		if (curr->link == first)
		{
			printf("%d not found \n", key);
			return first;
		}
	}
	temp = (Node)malloc(sizeof(struct node));
	// * check if LinkedList is empty
	if (temp == NULL)
	{
		printf("Insufficient memory \n");
		return first;
	}
	printf("Enter element to insert before %d : ", key);
	scanf("%d", &elem);
	temp->info = elem;
	temp->link = curr->link;
	curr->link = temp;
	return first;
}

// * DELETE FIRST NODE
// Node deleteHeadCll(Node first)
// {
// 	Node temp, curr;
// 	if (first == NULL)
// 	{
// 		printf("LinkedList is empty \n");
// 		return first;
// 	}
// 	temp = first;
// 	if (first->link == first)
// 	{
// 		first = NULL;
// 		return first;
// 	}
// 	else
// 	{
// 		curr = first;
// 		while (curr->link == first)
// 		{
// 			curr = curr->link;
// 		}
// 		curr->link = first->link;
// 		first = first->link;
// 	}
// 	free(temp);
// 	return first;
// }

// * DELETE LAST NODE
Node deleteTailCll(Node first)
{
	Node curr;
	if (first == NULL)
	{
		printf("LinkedList is empty \n");
		return first;
	}
	if (first->link == first)
	{
		first = NULL;
		return first;
	}
	curr = first;
	while (curr->link->link != first)
	{
		curr = curr->link;
	}
	Node temp = curr->link;
	curr->link = temp->link;
	free(temp);
	return first;
}

// * DELETE GIVEN ELEMENT
Node deleteGivenElementCll(Node first)
{
	Node curr;
	int key;
	if (first == NULL)
	{
		printf("LinkedList is empty \n");
		return first;
	}
	printf("Enter element to delete : ");
	scanf("%d", &key);
	curr = first;
	if (first->info == key)
	{
		// first = deleteHeadCll(first);
		return first;
	}
	while (curr->link->info != key)
	{
		curr = curr->link;
		if (curr->link == first && curr->info != key)
		{
			printf("%d not found \n", key);
			return first;
		}
	}
	Node temp = curr->link;
	curr->link = temp->link;
	free(temp);
	return first;
}

// * DELETE AFTER GIVEN ELEMENT
Node deleteAfterElemCll(Node first)
{
	Node curr;
	int key;
	if (first == NULL)
	{
		printf("LinkedList is empty \n");
		return first;
	}
	printf("Enter element after which to delete : ");
	scanf("%d", &key);
	curr = first;
	while (curr->info != key)
	{
		curr = curr->link;
		if (curr->link == first && curr->info != key)
		{
			printf("%d not found \n", key);
			return first;
		}
	}
	if (curr->link == first)
	{
		printf("%d is the last element \n", key);
		return first;
	}
	Node temp = curr->link;
	curr->link = temp->link;
	free(temp);
	return first;
}

// * DELETE BEFORE GIVEN ELEMENT
Node deleteBeforeElemCll(Node first)
{
	Node curr;
	int key;
	if (first == NULL)
	{
		printf("LinkedList is empty \n");
		return first;
	}
	printf("Enter element before which to delete : ");
	scanf("%d", &key);
	curr = first;
	if (first->info == key)
	{
		printf("%d is the first element \n", key);
		return first;
	}
	if (first->link->info == key)
	{
		// first = deleteTailCll(first);
		return first;
	}
	while (curr->link->link->info != key)
	{
		curr = curr->link;
		if (curr->link == first && curr->info != key)
		{
			printf("%d not found \n", key);
			return first;
		}
	}
	Node temp = curr->link;
	curr->link = temp->link;
	free(temp);
	return first;
}

// * DELETE ELEMENT AT GIVEN POSITION
Node deleteElemAtPos(Node first)
{
	int pos;
	if (first == NULL)
	{
		printf("LinkedList is empty \n");
		return first;
	}
	printf("Enter position of element to delete : ");
	scanf("%d", &pos);
	if (pos < 0)
	{
		printf("Invalid position \n");
		return first;
	}
	if (pos == 1)
	{
		// first = deleteHeadCll(first);
		return first;
	}
	Node curr = first;
	while (pos - 2 != 0)
	{
		curr = curr->link;
		if (curr->link == first)
		{
			printf("Invalid position \n");
			return first;
		}
		pos--;
	}
	Node temp = curr->link;
	curr->link = temp->link;
	free(temp);
	return first;
}

// * COMPUTE THE LENGTH OF CIRCULAR SINGLY LINKED LIST
int lengthCll(Node first)
{
	int len = 1;
	Node curr = first;
	if (first == NULL)
	{
		printf("LinkedList is empty \n");
		len = 0;
		return len;
	}
	while (curr->link != first)
	{
		curr = curr->link;
		len++;
	}
	return len;
}

// * SEARCH AN ELEMENT IN CIRCULAR SINGLY LINKED LIST
void searchCll(Node first)
{
	int key;
	if (first == NULL)
	{
		printf("LinkedList is empty \n");
		return;
	}
	printf("Enter element to search : ");
	scanf("%d", &key);
	int counter = 1;
	if (first->info == key)
	{
		printf("%d found at position %d \n", key, counter);
		return;
	}
	Node curr = first;
	while (curr->link != first)
	{
		curr = curr->link;
		counter++;
		if (curr->info == key)
		{
			printf("%d found at position %d \n", key, counter);
			return;
		}
		if (curr->link == first && curr->info != key)
		{
			printf("%d not found \n", key);
			return;
		}
	}
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
	Node head = NULL;
	head = insertRearCll(head);
	displayCll(head);
	head = insertRearCll(head);
	displayCll(head);
	head = insertRearCll(head);
	displayCll(head);
	head = insertRearCll(head);
	displayCll(head);
	printf("Length of CIRCULAR SINGLY LINKED LIST = %d \n", lengthCll(head));
	searchCll(head);
	// head = deleteElemAtPos(head);
	// displayCll(head);
}
