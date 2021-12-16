#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char foodName[100];
	int quantity;
	int price;
	int index;
	struct Node *next;
	struct Node *prev;
};

typedef struct node *Node;
