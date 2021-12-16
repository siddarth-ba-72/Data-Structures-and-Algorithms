#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
};

typedef struct node *Node;

Node insertFront(Node head)
{
	Node temp;
	temp = (Node)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Unable to allocate memory\n");
		return head;
	}
	printf("Enter an element to be inserted at the beginning: ");
	scanf("%d", &temp->info);
	temp->link = NULL;
	if (head == NULL)
	{
		head->link = temp;
		head->info++;
		return head;
	}
	temp->link = head->link;
	head->link = temp;
	head->info++;
	return head;
}

Node insertRare(Node head)
{
	Node temp;
	temp = (Node)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Unable to allocate memory\n");
		return head;
	}
	printf("Enter an element to be inserted at the end: ");
	scanf("%d", &temp->info);
	temp->link = NULL;
	if (head == NULL)
	{
		head->link = temp;
		head->info++;
		return head;
	}
	Node curr = head;
	while (curr->link != NULL)
	{
		curr = curr->link;
	}
	curr->link = temp;
	head->info++;
	return head;
}

Node insertAfterElement(Node head)
{
	Node temp, curr;
	int key;
	printf("Enter the element after which you want to insert: ");
	scanf("%d", &key);
	if (head == NULL)
	{
		printf("List is empty\n");
		return head;
	}
	curr = head;
	while (curr->info != key)
	{
		curr = curr->link;
		if (curr == NULL)
		{
			printf("%d not found\n", key);
			return head;
		}
	}
	temp = (Node)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Unable to allocate memory\n");
		return head;
	}
	printf("Enter an element to be inserted after %d: ", key);
	scanf("%d", &temp->info);
	if (curr->link == NULL) //* if curr is last element
	{
		curr->link = temp;
		temp->link = NULL;
		head->info++;
		return head;
	}
	temp->link = curr->link;
	curr->link = temp;
	head->info++;
	return head;
}

Node insertBeforeElement(Node head)
{
	Node temp, curr;
	int key;
	printf("Enter the element before which you want to insert: ");
	scanf("%d", &key);
	if (head == NULL)
	{
		printf("List is empty\n");
		return head;
	}
	curr = head;
	if (key == head->link->info)
	{
		temp = (Node)malloc(sizeof(struct node));
		if (temp == NULL)
		{
			printf("Unable to allocate memory\n");
			return head;
		}
		printf("Enter an element to be inserted before %d: ", key);
		scanf("%d", &temp->info);
		temp->link = head->link;
		head->link = temp;
		head->info++;
		return head;
	}
	while (curr->link->info != key)
	{
		curr = curr->link;
		if (curr->link == NULL)
		{
			printf("%d not found\n", key);
			return head;
		}
	}
	temp = (Node)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Unable to allocate memory\n");
		return head;
	}
	printf("Enter an element to be inserted before %d: ", key);
	scanf("%d", &temp->info);
	temp->link = curr->link;
	curr->link = temp;
	head->info++;
	return head;
}

Node insertAtPosition(Node head)
{
	int pos;
	Node temp = NULL;
	if (head == NULL)
	{
		printf("Linked List is empty\n");
		return head;
	}
	printf("Enter the position to insert the element: ");
	scanf("%d", &pos);
	if (pos <= 0)
	{
		printf("Please enter a valid position\n");
		return head;
	}
	if (pos == 1)
	{
		temp = (Node)malloc(sizeof(struct node));
		if (temp == NULL)
		{
			printf("Insufficient memory \n");
			return head;
		}
		printf("Enter the element to insert: ");
		scanf("%d", &temp->info);
		temp->link = NULL;
		temp->link = head->link;
		head->link = temp;
		head->info++;
		return head;
	}
	Node curr = head->link;
	while (pos - 2 != 0)
	{
		curr = curr->link;
		pos--;
		if (curr == NULL)
		{
			printf("Position exceeds the limit of Linked List \n");
			return head;
		}
	}
	temp = (Node)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Insufficient memory \n");
		return head;
	}
	printf("Enter the element to insert: ");
	scanf("%d", &temp->info);
	temp->link = NULL;
	if (curr->link == NULL)
	{
		curr->link = temp;
		temp->link = NULL;
		head->info++;
		return head;
	}
	temp->link = curr->link;
	curr->link = temp;
	head->info++;
	return head;
}

Node deleteHead(Node head)
{
	if (head == NULL)
	{
		printf("Linked List is empty\n");
		return head;
	}
	Node temp = head->link;
	head->link = temp->link;
	head->info--;
	free(temp);
	return head;
}

Node deleteTail(Node head)
{
	if (head == NULL)
	{
		printf("Linked List is empty\n");
		return head;
	}
	Node curr = head;
	while (curr->link->link != NULL)
	{
		curr = curr->link;
	}
	Node temp = curr->link;
	curr->link = NULL;
	free(temp);
	head->info--;
	return head;
}

Node deleteAfterElement(Node head)
{
	Node temp, curr;
	int key;
	printf("Enter the element after which you want to delete: ");
	scanf("%d", &key);
	if (head == NULL)
	{
		printf("Linked List is empty\n");
		return head;
	}
	curr = head->link;
	while (curr->info != key)
	{
		curr = curr->link;
		if (curr->link == NULL)
		{
			if (curr->info == key)
			{
				printf("No element after %d\n", key);
				return head;
			}
			else
			{
				printf("%d not found\n", key);
				return head;
			}
		}
	}
	temp = curr->link;
	curr->link = temp->link;
	free(temp);
	head->info--;
	return head;
}

Node deleteBeforeElement(Node head)
{
	Node temp, curr, prev;
	int key;
	printf("Enter the element before which you want to delete: ");
	scanf("%d", &key);
	if (head == NULL)
	{
		printf("Linked List is empty\n");
		return head;
	}
	curr = head->link;
	if (key == curr->info)
	{
		printf("No element before %d\n", key);
		return head;
	}
	while (curr->link->info != key)
	{
		prev = curr;
		curr = curr->link;
		if (curr->link == NULL)
		{
			printf("%d not found\n", key);
			return head;
		}
	}
	temp = curr;
	prev->link = temp->link;
	free(temp);
	head->info--;
	return head;
}

Node deleteAtPosition(Node head)
{
	int pos;
	Node temp, curr;
	if (head == NULL)
	{
		printf("Linked List is empty\n");
		return head;
	}
	printf("Enter the position to delete the element: ");
	scanf("%d", &pos);
	if (pos <= 0)
	{
		printf("Please enter a valid position\n");
		return head;
	}
	if (pos == 1)
	{
		temp = head->link;
		head->link = temp->link;
		free(temp);
		head->info--;
		return head;
	}
	curr = head->link;
	while (pos - 2 != 0)
	{
		curr = curr->link;
		pos--;
		if (curr->link == NULL)
		{
			printf("Position exceeds the limit of Linked List \n");
			return head;
		}
	}
	temp = curr->link;
	curr->link = temp->link;
	free(temp);
	head->info--;
	return head;
}

void searchElement(Node head)
{
	int key, cnt = 0, i = 1;
	Node curr = NULL;
	printf("Enter the element you want search: ");
	scanf("%d", &key);
	if (head == NULL)
	{
		printf("Linked List is empty\n");
		return;
	}
	curr = head->link;
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

void displaySllHeader(Node head)
{
	Node cur;
	if (head == NULL)
		printf("List is empty, no elements to display\n");
	else
	{
		cur = head->link;
		while (cur != NULL)
		{
			printf("%d  ", cur->info);
			cur = cur->link;
		}
		printf("\n");
		printf("Header data = %d\n", head->info);
	}
}

void main()
{
	Node header;
	header = (Node)malloc(sizeof(struct node));
	header->info = 0;
	header->link = NULL;

	header = insertRare(header);
	displaySllHeader(header);
	header = insertRare(header);
	displaySllHeader(header);
	header = insertRare(header);
	displaySllHeader(header);
	header = insertRare(header);
	displaySllHeader(header);
	header = deleteAfterElement(header);
	displaySllHeader(header);
}
