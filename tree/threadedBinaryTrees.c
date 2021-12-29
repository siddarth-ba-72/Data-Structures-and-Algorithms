#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20
#ifndef _BOOL
typedef unsigned char bool;
static const bool False = 0;
static const bool True = 1;
#endif

struct node
{
	int data;
	struct node *left;
	struct node *right;
	bool isThreaded;
};

typedef struct node *Node;

// ? Creating a new Tree Node
Node newNode(int value)
{
	Node temp = (Node)malloc(sizeof(struct node));
	temp->data = value;
	temp->left = temp->right = NULL;
	temp->isThreaded = False;
	return temp;
}

// ? Inserting a new Node into the tree
Node insert(Node root, int value)
{
	if (root == NULL)
		return newNode(value);
	if (value < root->data)
		root->left = insert(root->left, value);
	else if (value > root->data)
		root->right = insert(root->right, value);
	return root;
}

// ? Inorder Traversal of Tree
void inorderTraversal(Node root)
{
	if (root != NULL)
	{
		inorderTraversal(root->left);
		printf("%d ", root->data);
		inorderTraversal(root->right);
	}
}

// ? Preorder traversal of a node
void preorderTraversal(Node root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
	printf("\n");
}

// ? Postorder traversal of a node
void postorderTraversal(Node root)
{
	if (root == NULL)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d ", root->data);
	printf("\n");
}

// ? Level order traversal of a tree
void levelOrderTraversal(Node root)
{
	Node qu[MAX], curr;
	int front = 0, rear = -1;
	qu[++rear] = root;
	while (front <= rear)
	{
		curr = qu[front++];
		printf("%d ", curr->data);
		if (curr->left != NULL)
			qu[++rear] = curr->left;
		if (curr->right != NULL)
			qu[++rear] = curr->right;
	}
	printf("\n");
}

// ? Function to create Threads in Binary Tree
Node createThreads(Node root)
{
	if (root == NULL)
		return NULL;
	if (root->left == NULL && root->right == NULL)
		return root;
	if (root->left != NULL)
	{
		root->left = createThreds(root->left);
		if (root->left->right == NULL)
		{
			root->left->right = root;
			root->left->isThreaded = True;
		}
	}
	if (root->right != NULL)
	{
		root->right = createThreds(root->right);
		if (root->right->left == NULL)
		{
			root->right->left = root;
			root->right->isThreaded = True;
		}
	}
	return root;
}

int main()
{
}
